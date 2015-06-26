/*
 * (C) Copyright 2002
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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

/*
 * Diagnostics support
 */
#include <common.h>
#include <command.h>
#include <post.h>
#include <nand.h>
#include <net.h>
#include <watchdog.h>

void do_diag_net(void)
{
	printf("Net Test Configuration\n");
	printf("%16s : %lu\n", "Loop Count", NetTestCount);
	printf("%16s : %lu\n", "Packet Size", NetTestPacketSize);

	if (NetLoop(NET_TEST) < 0) 
	{
		printf("\nfailed!\n");
	}
	printf("\nsuccessfully finished!\n");


	if (NetTestSendCount != 0)
	{
		ulong	ulErrorRate = (NetTestSendCount - NetTestRcvdCount) * 10000 / NetTestSendCount;
		printf("Send Packets : %lu\n", NetTestSendCount);
		printf("Rcvd Packets : %lu\n", NetTestRcvdCount);
		printf("  Error Rate : %2lu.%02lu\n", ulErrorRate/100, ulErrorRate%100);
	}

}

ulong	ulStartAddress  = 0x10000000;
ulong	ulEndAddress	= 0x20000000;
ulong	ulLoopCount		= 100;
ulong	pulPattern[] = 
{
	0x5AA55AA5,
	0xAA5555AA,
	0x01101001
};

void do_diag_ram(void)
{
	ulong	i, j;
	ulong	*pAddress;
	ulong	ulValue;
	ulong	ulErrors = 0;
	
	for(i = 0 ;i < ulLoopCount ; i++)
	{
		for(j = 0 ; j < sizeof(pulPattern) / sizeof(ulong) ; j++)
		{
			ulong ulPattern = pulPattern[j];
			if (ctrlc()) 
			{
				puts ("\n Memory test canceled\n");
				return;
			}

			printf("\nPattern %08lx ", ulPattern);
			puts ("writing...");

			ulValue = ulPattern;
			pAddress = (ulong *)ulStartAddress;
			while((ulong)pAddress < ulEndAddress)
			{
				WATCHDOG_RESET();
				*pAddress = ulValue;
				ulValue += 1;
				pAddress ++;
			}

			puts ("Reading...");

			ulValue = ulPattern;
			pAddress = (ulong *)ulStartAddress;
			while((ulong)pAddress < ulEndAddress)
			{
				ulong	ulReadback;

				WATCHDOG_RESET();
				ulReadback = *pAddress;
				if (ulReadback != ulValue) 
				{
					printf ("\nMem error @ 0x%08X: " "found %08lX, expected %08lX\n",
							(uint)pAddress, ulReadback, ulValue);
					ulErrors++;
					if (ctrlc()) 
					{
						puts ("\n Memory test canceled\n");
						return;
					}
				}
				ulValue += 1;
				pAddress++;
			}
		}
	}

	if (ulErrors != 0)
	{
		printf("Memory test failed.\n");	
	}
	else
	{
		printf("Memory test finished successfully.\n");	
	}
}

extern nand_info_t nand_info[CONFIG_SYS_MAX_NAND_DEVICE];
void do_diag_nand(void)
{
	int	i, nBadBlocks = 0;
	nand_info_t *nand;
	ulong off;

	for (i = 0; i < CONFIG_SYS_MAX_NAND_DEVICE; i++) 
	{
		if (nand_info[i].name)
		{
			nand = &nand_info[i];
			struct nand_chip *chip = nand->priv;
			printf("Device %d: ", i);
			if (chip->numchips > 1)
			{
				printf("%dx ", chip->numchips);
			}
			printf("%s, sector size %u KiB\n", nand->name, nand->erasesize >> 10);
			printf("Bad blocks: ");

			for (off = 0; off < nand->size; off += nand->erasesize)
			{
				if (nand_block_isbad(nand, off))
				{
					printf("%08lx ", off);
					nBadBlocks++;
				}
			}

			if (nBadBlocks == 0)
			{
				printf("none.\n");
			}
			else
			{
				printf("\n");
			}
		}
	}
}

int do_diag (cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
	unsigned int i;

	if (argc == 1 || strcmp (argv[1], "run") != 0) 
	{
		/* List test info */
		if (argc == 1) 
		{
			puts ("Available hardware tests:\n");
			puts ("    net - ethernet port loopback test\n");
			puts ("Use 'diag [<test1> [<test2> ...]]'"
					" to get more info.\n");
			puts ("Use 'diag run [<test1> [<test2> ...]]'"
					" to run tests.\n");
		} 
		else 
		{
		}
	} 
	else 
	{
		if (argc == 2)
		{
			do_diag_net();
			do_diag_ram();
			do_diag_nand();
		}
		else
		{
			for(i = 2 ; i < argc ; i++)
			{
				if (strcmp(argv[i], "net") == 0)
				{
					do_diag_net();
				}
				else if (strcmp(argv[i], "ram") == 0)
				{
					do_diag_ram();
				}
				else if (strcmp(argv[i], "nand") == 0)
				{
					do_diag_nand();
				}
			}
		}
	}

	return 0;
}
/***************************************************/

U_BOOT_CMD(
	diag,	CONFIG_SYS_MAXARGS,	0,	do_diag,
	"perform board diagnostics",
	     "    - print list of available tests\n"
	"diag [test1 [test2]]\n"
	"         - print information about specified tests\n"
	"diag run - run all available tests\n"
	"diag run [test1 [test2]]\n"
	"         - run specified tests"
);
