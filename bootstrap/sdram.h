#ifndef __SDRAM_H__
#define __SDRAM_H__
#include "config.h"

#define SAMSUNG_PHY_DLL_LOW_FREQUENCY 4000
#define SDRAM_BASE	(DDR_BASE_ADDR + 0x800000)

#define TYPE_DDR3	0
#define TYPE_LPDDR2	1

#define DEFAULT_DDR_FREQ	(800)

#ifndef CONFIG_CORTINA_FPGA
#define DDR3_MEM
#endif


#define DEFAULT_LOOP_CNT	100

#define RET_OK		0
#define RET_ERR		-1

//#define BUILD_FOR_SIMULATION

int reset_ddrc(void);

unsigned int get_bitmask_len(unsigned int a);
unsigned int sdram_uidiv(unsigned int dividend, unsigned int divisor);
int Denali_SDRAMDriver_initialize(void);
int denali_sdram_cntl_config(int mem_type);
int denali_sdram_init_done(void);
int denali_sdram_phy_config(int mem_type);
int initialize_lpddr2_s2(void);
int sdram_pattern_write(void);
int denali_sdram_train_rd_strobe(void);
int  cpu_read_check_sdram_mem(unsigned int addr);
int set_denali_16bit_mode(void);
unsigned int  cpu_read_sdram_mem_32bit(unsigned int addr);
int denali_sdram_train_rd_latency(void);
int denali_sdram_train_gateo(void);
int denali_sdram_train_wr_data(void);
unsigned int denali_sdram_size(void);
int denali_sdramdriver_set_default_conf(void);
int write_sdram_mem(unsigned int addr, unsigned long long *wr_data, int count) ;

int restart_dll_lock(void);
int force_zq_pmos_nmos(unsigned char impp, unsigned char impn);
int restart_zq_calibration(void);

int set_ddr_freq(unsigned int freq);
int g2_ddr_freq(int argc, char **argv);
int g2_eye_loop(int argc, char **argv);
int g2_reg_wr(int argc, char **argv);
int g2_ddr_reg_init(int argc, char **argv);
int g2_ddr_start(void);
int g2_ddr_start_and_train(void);
int g2_wr_ddr_pat(void);
int g2_tr_rd(int argc, char **argv);
int g2_tr_lat(int argc, char **argv);
int g2_tr_gat(int argc, char **argv);
int g2_tr_wr(int argc, char **argv);
int g2_ddr_size(int argc, char **argv);
int g2_ddr_rst(int argc, char **argv);
int g2_long_test1(int argc, char **argv);
int g2_long_term(int argc, char **argv);

int g2_start_zq(int argc, char **argv);
int g2_force_zq(int argc, char **argv);
int g2_start_dll(int argc, char **argv);
int g2_dbg_on(int argc, char **argv);
int g2_ddr_set_default_conf(int argc, char **argv);
int g2_start_init(int argc, char **argv);
int g2_scan_range(unsigned char *left, unsigned char *right, unsigned char *left_right);

typedef struct {
   unsigned int addr;
   unsigned int reg_v;
   unsigned int *pglobal;
} reg_save_t;

/* These are used by cpu_read_check_sdram_mem() to show different message */
#define SHOW_TYPE_DEF		0
#define SHOW_TYPE_TR_RD		1
#define SHOW_TYPE_TR_LAT	2
#define SHOW_TYPE_TR_GAT	3
#define SHOW_TYPE_TR_WR		4


#endif
