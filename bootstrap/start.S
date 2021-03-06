/*
 *  armboot - Startup Code for ARM926EJS CPU-core
 *
 *  Copyright (c) 2003  Texas Instruments
 *
 *  ----- Adapted for OMAP1610 OMAP730 from ARM925t code ------
 *
 *  Copyright (c) 2001	Marius Gr� <mag@sysgo.de>
 *  Copyright (c) 2002	Alex Z�azu@sysgo.de>
 *  Copyright (c) 2002	Gary Jennejohn <gj@denx.de>
 *  Copyright (c) 2003	Richard Woodruff <r-woodruff2@ti.com>
 *  Copyright (c) 2003	Kshitij <kshitij@ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */


#include "config.h"

/*
 *************************************************************************
 *
 * Jump vector table as in table 3.1 in [1]
 *
 *************************************************************************
 */


.globl _start
_start:
	b	reset
	ldr	pc, _undefined_instruction
	ldr	pc, _software_interrupt
	ldr	pc, _prefetch_abort
	ldr	pc, _data_abort
	ldr	pc, _not_used
	ldr	pc, _irq
	ldr	pc, _fiq

_undefined_instruction:
	b _undefined_instruction
_software_interrupt:
	b _software_interrupt
_prefetch_abort:
	b _prefetch_abort
_data_abort:
	b _data_abort
_not_used:
	b _not_used
_irq:
	b _irq
_fiq:
	b _fiq
_pad:
	b _pad
/* now 16*4=64 */


.global _end_vect
_end_vect:


/* Virtual table start 16 words */
.global uboot_entry
uboot_entry:
	.word 0x00000000

.global uboot_image_len
uboot_image_len:
	.word 0x00030000

.global post_daytona_mem_test_entry
post_daytona_mem_test_entry:
	.word 0x12345678   /* daytona_mem_test */
	.word 0x12345678   /* mem_test_burst_1 */

/* Endof Virtual table */
	.balignl 16,0xdeadbeef


/*
 *************************************************************************
 *
 * Startup Code (reset vector)
 *
 * do important init only if we don't start from memory!
 * setup Memory and board specific bits prior to relocation.
 * relocate armboot to ram
 * setup stack
 *
 *************************************************************************
 */

.globl _armboot_start
_armboot_start:
	.word _start

_TEXT_BASE:
   .word TEXT_BASE
/*
 * These are defined in the board-specific linker script.
 */
.globl _bss_start
_bss_start:
	.word __bss_beg__

.globl _bss_end
_bss_end:
	.word _end

#ifdef CONFIG_USE_IRQ
/* IRQ stack memory (calculated at run-time) */
.globl IRQ_STACK_START
IRQ_STACK_START:
	.word	0x0badc0de

/* IRQ stack memory (calculated at run-time) */
.globl FIQ_STACK_START
FIQ_STACK_START:
	.word 0x0badc0de
#endif


/*
 * the actual reset code
 */

reset:
	/*
	 * set the cpu to SVC32 mode
	 */
	mrs	r0,cpsr
	bic	r0,r0,#0x1f
	orr	r0,r0,#0xd3
	msr	cpsr,r0

//#ifdef CONFIG_FM_A9_SMP
/*
 *************************************************************************
 * Start SMP - all except core 0 to WFI or WFE
 *************************************************************************
 */
 	mov r5, #0
	MRC    p15, 0, r0, c0, c0, 5
	ANDS   r0, r0, #0x03
	BEQ    pre_init

	CPSID  aif
	/*
	 * 0x10000030 is the system wide flags register( On Motherboard )
	 * platsmp.c::poke_milo() writes the address of secondary startup there
	 */
#ifdef CONFIG_CORTINA_FPGA
	cmp		r0, #0x02	/* Only CPU0/1 can boot, let CPU2/3 sleep always  */
	blt		wait_boot

sleep_always:
	WFI
	nop
	B	sleep_always
#endif

wait_boot:
	LDR	r0, =CORTEX_SCU_BASE
	/* Read ACK */
	LDR	r7, [r0, #0x10C]

	LDR	r0, =CORTEX_GIC_DIST_BASE
	/* Pending clear */
	LDR	r3, =0x00000001
//	STR	r3, [r0,#0x280]

	/* Disable interrupt */
	LDR	r3, =0x0000FFFF
//	STR	r3, [r0,#0x180]

	LDR	r0, =CORTEX_SCU_BASE
	/* EOI */
//	STR	r7, [r0,#0x110]
	MOV	r7, #0


	LDR	r0, =CORTEX_GIC_DIST_BASE
	/* Enable interrupt */
	LDR	r3, =0x0000FFFF
	STR	r3, [r0,#0x100]

	LDR	r0, =CORTEX_SCU_BASE
	/* Enable CPU interface */
	LDR	r3, =0x00000001
	STR	r3, [r0,#0x100]

	/* Set Interrupt Priority */
	LDR	r3, =0x000000F0
	STR	r3, [r0,#0x104]

	LDR    r0, =GLOBAL_SOFTWARE1
	MOV		r2, #0
	STR		r2, [r0]

loop_this:
	WFI
	LDR	r1, [r0]
	CMP	r1, #0
	BEQ     loop_this
	BX	r1
	B	loop_this

pre_init:

//#endif /* CONFIG_FM_A9_SMP */

	/*
	 * we do sys-critical inits only at reboot,
	 * not when booting from ram!
	 */
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
	bl	cpu_init_crit
	bl  v7_invalidate_dcache_all

/*******************************************************
 * L2 address filtering start address, for memory swap *
 *******************************************************/
#ifdef 	CONFIG_CORTINA_FPGA
	LDR	r0, =0xF5010C00
	LDR	r3, =DDR_BASE_ADDR
	ORR	r3, r3, #0x1
	STR	r3, [r0]
	LDR	r3, =DDR_BASE_ADDR
	ADD	r3, r3, #0x08000000	/* 128M */
	STR	r3, [r0,#04]
#else
	/* Reset all block except flash */
        LDR     r0, =0xF0000000
        LDR     r3, =0xFFFFBFFF
	STR     r3, [r0,#4]
	MOV     r1, #0x0
reset_delay:
        CMP     r1, #0x400
        ADD     r1, r1, #1
        BLT     reset_delay
        LDR     r3, =0x00600000
        STR     r3, [r0,#4]
#endif

#endif
#ifndef CONFIG_CORTINA_FPGA
/* if the system runs in secure mode, not to copy code to packet bubber. */
	LDR	r0, =GLOBAL_STRAP
	LDR	r0, [r0]
	AND	r0, r0, #01
	CMP	r0, #0
	BNE	skip_copy
/* --> Use BMC to copy image(flash -> packet buffer) */
	LDR	r0, =0xf0090000
	/* Enable RX */
	LDR	r1, =0x0d
	STR	r1, [r0]
	/* Enable TX */
	STR	r1, [r0, #4]

	/* SRC */
	LDR	r1, =0xe0000000
	STR	r1, [r0, #428]
	/* Dest */
	LDR	r1, =0xf6a00000
	STR	r1, [r0, #432]
	/* count */
	LDR	r1, =0x10000
	STR	r1, [r0, #436]
	/* Start */
	LDR	r1, =1
	STR	r1, [r0, #424]

	MOV	r2, #0x1
wait_bmc:
	LDR	r1, [r0, #616]
	CMP	r1, r2
	bne	wait_bmc
	STR	r2, [r0, #616]
	LDR	r2, =0x0
	STR	r2, [r0, #424]

	MOV	r0, pc
	LDR	r1, =0xF6a00000
	ORR	r0, r0,r1
	ADD	r0, r0,#0x10
	BX	r0
	NOP
	NOP
	NOP
	NOP
/* <-- go ahead */
skip_copy:

#endif

#if 0 //ndef CONFIG_SKIP_RELOCATE_UBOOT
relocate:				/* relocate U-Boot to RAM	    */
	adr	r0, _start		/* r0 <- current position of code   */
	ldr	r1, _TEXT_BASE		/* test if we run from flash or RAM */
	cmp     r0, r1                  /* don't reloc during debug         */
	beq     stack_setup

	ldr	r2, _armboot_start
	ldr	r3, _bss_start
	sub	r2, r3, r2		/* r2 <- size of armboot            */
	add	r2, r0, r2		/* r2 <- source end address         */

copy_loop:
	ldmia	r0!, {r3-r10}		/* copy from source address [r0]    */
	stmia	r1!, {r3-r10}		/* copy to   target address [r1]    */
	cmp	r0, r2			/* until source end addreee [r2]    */
	ble	copy_loop
#endif	/* CONFIG_SKIP_RELOCATE_UBOOT */

    /* Since it is first stage bootloader no stact setup */
    /* Set up the stack						    */
stack_setup:
	/* ldr sp, =0xf6a3a000 */
	ldr sp, =0xf6404000

clear_bss:
	ldr	r0, _bss_start		/* find start of bss segment        */
	ldr	r1, _bss_end		/* stop here                        */
	mov 	r2, #0x00000000		/* clear                            */

clbss_l:str	r2, [r0]		/* clear loop...                    */
	add	r0, r0, #4
	cmp	r0, r1
	ble	clbss_l

	ldr	pc, _start_armboot

_start_armboot:
	.word main


/*
 *************************************************************************
 *
 * CPU_init_critical registers
 *
 * setup important registers
 * setup memory timing
 *
 *************************************************************************
 */
#ifndef CONFIG_SKIP_LOWLEVEL_INIT

cpu_init_crit:
	/*
	 * Invalidate L1 I/D
	 */
	mov	r0, #0			@ set up for MCR
	mcr	p15, 0, r0, c8, c7, 0	@ invalidate TLBs
	mcr	p15, 0, r0, c7, c5, 0	@ invalidate icache

	/*
	 * disable MMU stuff and caches
	 */
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002000	@ clear bits 13 (--V-)
	bic	r0, r0, #0x00000007	@ clear bits 2:0 (-CAM)
	orr	r0, r0, #0x00000002	@ set bit 1 (--A-) Align
	orr	r0, r0, #0x00000800	@ set bit 12 (Z---) BTB
	mcr	p15, 0, r0, c1, c0, 0

	/*
	 * Jump to board specific initialization...
	 * The Mask ROM will have already initialized
	 * basic memory. Go here to bump up clock rate and handle
	 * wake up conditions.
	 */
	mov	ip, lr			@ persevere link reg across call
#ifdef CONFIG_CORTINA_FPGA
	bl	lowlevel_init		@ go setup pll,mux,memory
#endif
	mov	lr, ip			@ restore link
	mov	pc, lr			@ back to my caller

/*
*  v7_invalidate_dcache_all()
*
*  Invalidate the whole D-cache.
*
*  Corrupted registers: r0-r7, r9-r11 (r6 only in Thumb mode)
*
*  - mm    - mm_struct describing address space
*/
v7_invalidate_dcache_all:
  	dmb         				@ ensure ordering with previous memory accesses
  	mrc p15, 1, r0, c0, c0, 1   @ read clidr
  	ands  r3, r0, #0x7000000    @ extract loc from clidr
  	mov r3, r3, lsr #23     	@ left align loc bit field
  	beq finished2     			@ if loc is 0, then no need to clean
  	mov r10, #0       			@ start clean at cache level 0

loop11:
  	add r2, r10, r10, lsr #1    @ work out 3x current cache level
  	mov r1, r0, lsr r2      	@ extract cache type bits from clidr
  	and r1, r1, #7      		@ mask of the bits for current cache only
  	cmp r1, #2        			@ see what cache we have at this level
  	blt skip2       			@ skip if no cache, or just i-cache
  	mcr p15, 2, r10, c0, c0, 0  @ select current cache level in cssr
  	isb         				@ isb to sych the new cssr&csidr
  	mrc p15, 1, r1, c0, c0, 0   @ read the new csidr
  	and r2, r1, #7      		@ extract the length of the cache lines
  	add r2, r2, #4      		@ add 4 (line length offset)
  	ldr r4, =0x3ff
  	ands  r4, r4, r1, lsr #3    @ find maximum number on the way size
  	clz r5, r4        			@ find bit position of way size increment
  	ldr r7, =0x7fff
  	ands  r7, r7, r1, lsr #13   @ extract max number of the index size

loop22:
  	mov r9, r4        			@ create working copy of max way size

loop33:
  	orr r11, r10, r9, lsl r5  	@ factor way and cache number into r11
//	THUMB( lsl r6, r9, r5 )
//	THUMB( orr r11, r10, r6 ) 	@ factor way and cache number into r11
  	orr r11, r11, r7, lsl r2   	@ factor index number into r11
//	THUMB( lsl r6, r7, r2 )
//	THUMB( orr r11, r11, r6 ) 	@ factor index number into r11
  	mcr p15, 0, r11, c7, c6, 2  @ invalidate by set/way
  	subs  r9, r9, #1      		@ decrement the way
  	bge loop33
  	subs  r7, r7, #1      		@ decrement the index
  	bge loop22

skip2:
  	add r10, r10, #2      		@ increment cache number
  	cmp r3, r10
  	bgt loop11

finished2:
  	mov r10, #0       			@ swith back to cache level 0
  	mcr p15, 2, r10, c0, c0, 0  @ select current cache level in cssr
  	dsb
  	isb
  	mov pc, lr

#endif /* CONFIG_SKIP_LOWLEVEL_INIT */


/*
 * #========================================================================
 * #	BSS area
 * # 		- Temporary interrupt stack
 * #========================================================================
 */
    .section ".bss"

    .balign 4
    .byte	'.'
    .byte	'B'
    .byte	'S'
    .byte	'S'

	.balign 16
__startup_stack_base:
	.rept 4096
	.byte 0
	.endr
	.balign 16
__startup_stack:
	.word 0x12345678




#if 0
/*
 *************************************************************************
 *
 * Interrupt handling
 *
 *************************************************************************
 */

@
@ IRQ stack frame.
@
#define S_FRAME_SIZE	72

#define S_OLD_R0	68
#define S_PSR		64
#define S_PC		60
#define S_LR		56
#define S_SP		52

#define S_IP		48
#define S_FP		44
#define S_R10		40
#define S_R9		36
#define S_R8		32
#define S_R7		28
#define S_R6		24
#define S_R5		20
#define S_R4		16
#define S_R3		12
#define S_R2		8
#define S_R1		4
#define S_R0		0

#define MODE_SVC 0x13
#define I_BIT	 0x80

/*
 * use bad_save_user_regs for abort/prefetch/undef/swi ...
 * use irq_save_user_regs / irq_restore_user_regs for IRQ/FIQ handling
 */

	.macro	bad_save_user_regs
	@ carve out a frame on current user stack
	sub	sp, sp, #S_FRAME_SIZE
	stmia	sp, {r0 - r12}	@ Save user registers (now in svc mode) r0-r12

	ldr	r2, _armboot_start
	sub	r2, r2, #(CONFIG_STACKSIZE+CFG_MALLOC_LEN)
	sub	r2, r2, #(CFG_GBL_DATA_SIZE+8)  @ set base 2 words into abort stack
	@ get values for "aborted" pc and cpsr (into parm regs)
	ldmia	r2, {r2 - r3}
	add	r0, sp, #S_FRAME_SIZE		@ grab pointer to old stack
	add	r5, sp, #S_SP
	mov	r1, lr
	stmia	r5, {r0 - r3}	@ save sp_SVC, lr_SVC, pc, cpsr
	mov	r0, sp		@ save current stack into r0 (param register)
	.endm

	.macro	irq_save_user_regs
	sub	sp, sp, #S_FRAME_SIZE
	stmia	sp, {r0 - r12}			@ Calling r0-r12
	@ !!!! R8 NEEDS to be saved !!!! a reserved stack spot would be good.
	add	r8, sp, #S_PC
	stmdb	r8, {sp, lr}^		@ Calling SP, LR
	str	lr, [r8, #0]		@ Save calling PC
	mrs	r6, spsr
	str	r6, [r8, #4]		@ Save CPSR
	str	r0, [r8, #8]		@ Save OLD_R0
	mov	r0, sp
	.endm

	.macro	irq_restore_user_regs
	ldmia	sp, {r0 - lr}^			@ Calling r0 - lr
	mov	r0, r0
	ldr	lr, [sp, #S_PC]			@ Get PC
	add	sp, sp, #S_FRAME_SIZE
	subs	pc, lr, #4		@ return & move spsr_svc into cpsr
	.endm

	.macro get_bad_stack
	ldr	r13, _armboot_start		@ setup our mode stack
	sub	r13, r13, #(CONFIG_STACKSIZE+CFG_MALLOC_LEN)
	sub	r13, r13, #(CFG_GBL_DATA_SIZE+8) @ reserved a couple spots in abort stack

	str	lr, [r13]	@ save caller lr in position 0 of saved stack
	mrs	lr, spsr	@ get the spsr
	str	lr, [r13, #4]	@ save spsr in position 1 of saved stack
	mov	r13, #MODE_SVC	@ prepare SVC-Mode
	@ msr	spsr_c, r13
	msr	spsr, r13	@ switch modes, make sure moves will execute
	mov	lr, pc		@ capture return pc
	movs	pc, lr		@ jump to next instruction & switch modes.
	.endm

	.macro get_irq_stack			@ setup IRQ stack
	ldr	sp, IRQ_STACK_START
	.endm

	.macro get_fiq_stack			@ setup FIQ stack
	ldr	sp, FIQ_STACK_START
	.endm

/*
 * exception handlers
 */
	.align  5
undefined_instruction:
	get_bad_stack
	bad_save_user_regs
	bl	do_undefined_instruction

	.align	5
software_interrupt:
	get_bad_stack
	bad_save_user_regs
	bl	do_software_interrupt

	.align	5
prefetch_abort:
	get_bad_stack
	bad_save_user_regs
	bl	do_prefetch_abort

	.align	5
data_abort:
	get_bad_stack
	bad_save_user_regs
	bl	do_data_abort

	.align	5
not_used:
	get_bad_stack
	bad_save_user_regs
	bl	do_not_used

#ifdef CONFIG_USE_IRQ

	.align	5
irq:
	get_irq_stack
	irq_save_user_regs
	bl 	do_irq
	irq_restore_user_regs

	.align	5
fiq:
	get_fiq_stack
	/* someone ought to write a more effiction fiq_save_user_regs */
	irq_save_user_regs
	bl 	do_fiq
	irq_restore_user_regs

#else

	.align	5
irq:
	get_bad_stack
	bad_save_user_regs
	bl	do_irq

	.align	5
fiq:
	get_bad_stack
	bad_save_user_regs
	bl	do_fiq
#endif
#endif
