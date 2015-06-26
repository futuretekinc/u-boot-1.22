#include "serial_cs752x.h"
#include "utils.h"
#include "common.h"
#include "sdram.h"
#include "config.h"

SDRAM_DENALI_CTL_000_t denali_cntl_00;
SDRAM_DENALI_CTL_000_t denali_cntl_001;
SDRAM_DENALI_CTL_010_t denali_cntl_01;
SDRAM_DENALI_CTL_011_t denali_cntl_011;
SDRAM_DENALI_CTL_020_t denali_cntl_02;
SDRAM_DENALI_CTL_021_t denali_cntl_021;
SDRAM_DENALI_CTL_030_t denali_cntl_03;
SDRAM_DENALI_CTL_031_t denali_cntl_031;
SDRAM_DENALI_CTL_040_t denali_cntl_04;
SDRAM_DENALI_CTL_041_t denali_cntl_041;
SDRAM_DENALI_CTL_050_t denali_cntl_05;
SDRAM_DENALI_CTL_051_t denali_cntl_051;
SDRAM_DENALI_CTL_060_t denali_cntl_06;
SDRAM_DENALI_CTL_061_t denali_cntl_061;
SDRAM_DENALI_CTL_070_t denali_cntl_07;
SDRAM_DENALI_CTL_071_t denali_cntl_071;
SDRAM_DENALI_CTL_080_t denali_cntl_08;
SDRAM_DENALI_CTL_081_t denali_cntl_081;
SDRAM_DENALI_CTL_090_t denali_cntl_09;
SDRAM_DENALI_CTL_091_t denali_cntl_091;
SDRAM_DENALI_CTL_100_t denali_cntl_10;
SDRAM_DENALI_CTL_101_t denali_cntl_101;
SDRAM_DENALI_CTL_110_t denali_cntl_11;
SDRAM_DENALI_CTL_110_t denali_cntl_111;
SDRAM_DENALI_CTL_120_t denali_cntl_12;
SDRAM_DENALI_CTL_120_t denali_cntl_121;
SDRAM_DENALI_CTL_130_t denali_cntl_13;
SDRAM_DENALI_CTL_131_t denali_cntl_131;
SDRAM_DENALI_CTL_140_t denali_cntl_14;
SDRAM_DENALI_CTL_141_t denali_cntl_141;
SDRAM_DENALI_CTL_150_t denali_cntl_15;
SDRAM_DENALI_CTL_151_t denali_cntl_151;
SDRAM_DENALI_CTL_160_t denali_cntl_16;
SDRAM_DENALI_CTL_161_t denali_cntl_161;
SDRAM_DENALI_CTL_170_t denali_cntl_17;
SDRAM_DENALI_CTL_171_t denali_cntl_171;
SDRAM_DENALI_CTL_180_t denali_cntl_18;
SDRAM_DENALI_CTL_181_t denali_cntl_181;
SDRAM_DENALI_CTL_190_t denali_cntl_19;
SDRAM_DENALI_CTL_191_t denali_cntl_191;
SDRAM_DENALI_CTL_200_t denali_cntl_20;
SDRAM_DENALI_CTL_201_t denali_cntl_201;
SDRAM_DENALI_CTL_210_t denali_cntl_21;
SDRAM_DENALI_CTL_211_t denali_cntl_211;
SDRAM_DENALI_CTL_220_t denali_cntl_22;
SDRAM_DENALI_CTL_221_t denali_cntl_221;
SDRAM_DENALI_CTL_230_t denali_cntl_23;
SDRAM_DENALI_CTL_231_t denali_cntl_231;
SDRAM_DENALI_CTL_240_t denali_cntl_24;
SDRAM_DENALI_CTL_241_t denali_cntl_241;
SDRAM_DENALI_CTL_250_t denali_cntl_25;
SDRAM_DENALI_CTL_251_t denali_cntl_251;
SDRAM_DENALI_CTL_260_t denali_cntl_26;
SDRAM_DENALI_CTL_261_t denali_cntl_261;
SDRAM_DENALI_CTL_270_t denali_cntl_27;
SDRAM_DENALI_CTL_271_t denali_cntl_271;
SDRAM_DENALI_CTL_280_t denali_cntl_28;
SDRAM_DENALI_CTL_281_t denali_cntl_281;
SDRAM_DENALI_CTL_290_t denali_cntl_29;
SDRAM_DENALI_CTL_291_t denali_cntl_291;
SDRAM_DENALI_CTL_300_t denali_cntl_30;
SDRAM_DENALI_CTL_301_t denali_cntl_301;
SDRAM_DENALI_CTL_310_t denali_cntl_31;
SDRAM_DENALI_CTL_311_t denali_cntl_311;
SDRAM_DENALI_CTL_320_t denali_cntl_32;
SDRAM_DENALI_CTL_321_t denali_cntl_321;
SDRAM_DENALI_CTL_330_t denali_cntl_33;
SDRAM_DENALI_CTL_331_t denali_cntl_331;
SDRAM_DENALI_CTL_340_t denali_cntl_34;
SDRAM_DENALI_CTL_341_t denali_cntl_341;
SDRAM_DENALI_CTL_350_t denali_cntl_35;
SDRAM_DENALI_CTL_351_t denali_cntl_351;
SDRAM_DENALI_CTL_360_t denali_cntl_36;
SDRAM_DENALI_CTL_361_t denali_cntl_361;
SDRAM_DENALI_CTL_370_t denali_cntl_37;
SDRAM_DENALI_CTL_371_t denali_cntl_371;
SDRAM_DENALI_CTL_380_t denali_cntl_38;
SDRAM_DENALI_CTL_381_t denali_cntl_381;
SDRAM_DENALI_CTL_390_t denali_cntl_39;
SDRAM_DENALI_CTL_391_t denali_cntl_391;
SDRAM_DENALI_CTL_400_t denali_cntl_40;
SDRAM_DENALI_CTL_401_t denali_cntl_401;
SDRAM_DENALI_CTL_410_t denali_cntl_41;
SDRAM_DENALI_CTL_411_t denali_cntl_411;
SDRAM_DENALI_CTL_420_t denali_cntl_42;
SDRAM_DENALI_CTL_421_t denali_cntl_421;
SDRAM_DENALI_CTL_430_t denali_cntl_43;
SDRAM_DENALI_CTL_431_t denali_cntl_431;
SDRAM_DENALI_CTL_440_t denali_cntl_44;
SDRAM_DENALI_CTL_441_t denali_cntl_441;
SDRAM_DENALI_CTL_450_t denali_cntl_45;
SDRAM_DENALI_CTL_451_t denali_cntl_451;
SDRAM_DENALI_CTL_460_t denali_cntl_46;
SDRAM_DENALI_CTL_461_t denali_cntl_461;
SDRAM_DENALI_CTL_470_t denali_cntl_47;
SDRAM_DENALI_CTL_471_t denali_cntl_471;
SDRAM_DENALI_CTL_480_t denali_cntl_48;
SDRAM_DENALI_CTL_481_t denali_cntl_481;
SDRAM_DENALI_CTL_490_t denali_cntl_49;
SDRAM_DENALI_CTL_491_t denali_cntl_491;
SDRAM_DENALI_CTL_500_t denali_cntl_50;
SDRAM_DENALI_CTL_501_t denali_cntl_501;
SDRAM_DENALI_CTL_510_t denali_cntl_51;
SDRAM_DENALI_CTL_511_t denali_cntl_511;
SDRAM_DENALI_CTL_520_t denali_cntl_52;
SDRAM_DENALI_CTL_521_t denali_cntl_521;
SDRAM_DENALI_CTL_530_t denali_cntl_53;
SDRAM_DENALI_CTL_531_t denali_cntl_531;
SDRAM_DENALI_CTL_540_t denali_cntl_54;
SDRAM_DENALI_CTL_541_t denali_cntl_541;
SDRAM_DENALI_CTL_550_t denali_cntl_55;
SDRAM_DENALI_CTL_551_t denali_cntl_551;
SDRAM_DENALI_CTL_560_t denali_cntl_56;
SDRAM_DENALI_CTL_561_t denali_cntl_561;
SDRAM_DENALI_CTL_570_t denali_cntl_57;
SDRAM_DENALI_CTL_571_t denali_cntl_571;
SDRAM_DENALI_CTL_580_t denali_cntl_58;
SDRAM_DENALI_CTL_581_t denali_cntl_581;
SDRAM_DENALI_CTL_590_t denali_cntl_59;
SDRAM_DENALI_CTL_591_t denali_cntl_591;

SDRAM_PHY_CTL_64_0_t sphy_cntl_64;
SDRAM_PHY_CTL_64_1_t sphy_cntl_641;
SDRAM_PHY_CTL_65_0_t sphy_cntl_65;
SDRAM_PHY_CTL_65_1_t sphy_cntl_651;
SDRAM_PHY_CTL_66_0_t sphy_cntl_66;
SDRAM_PHY_CTL_66_1_t sphy_cntl_661;
SDRAM_PHY_CTL_67_0_t sphy_cntl_67;
SDRAM_PHY_CTL_67_1_t sphy_cntl_671;
SDRAM_PHY_CTL_68_0_t sphy_cntl_68;
SDRAM_PHY_CTL_68_1_t sphy_cntl_681;
SDRAM_PHY_CTL_69_0_t sphy_cntl_69;
SDRAM_PHY_CTL_69_1_t sphy_cntl_691;
SDRAM_PHY_CTL_70_0_t sphy_cntl_70;
SDRAM_PHY_CTL_70_1_t sphy_cntl_701;
SDRAM_PHY_CTL_71_0_t sphy_cntl_71;
SDRAM_PHY_CTL_71_1_t sphy_cntl_711;
SDRAM_PHY_CTL_72_0_t sphy_cntl_72;
SDRAM_PHY_CTL_72_1_t sphy_cntl_721;
SDRAM_PHY_CTL_74_t sphy_cntl_74;
SDRAM_PHY_CTL_75_t sphy_cntl_75;
SDRAM_PHY_CTL_76_0_t sphy_cntl_76;
SDRAM_PHY_CTL_76_1_t sphy_cntl_761;
SDRAM_PHY_CTL_77_0_t sphy_cntl_77;
SDRAM_PHY_CTL_77_1_t sphy_cntl_771;
SDRAM_PHY_CTL_78_0_t sphy_cntl_78;
SDRAM_PHY_CTL_78_1_t sphy_cntl_781;
SDRAM_PHY_CTL_79_0_t sphy_cntl_79;
SDRAM_PHY_CTL_79_1_t sphy_cntl_791;
SDRAM_PHY_CTL_80_t sphy_cntl_80;
SDRAM_PHY_CTL_81_t sphy_cntl_81;
SDRAM_PHY_CTL_82_t sphy_cntl_82;
SDRAM_PHY_CTL_83_t sphy_cntl_83;
SDRAM_PHY_CTL_84_t sphy_cntl_84;
SDRAM_PHY_CTL_85_t sphy_cntl_85;
SDRAM_PHY_CTL_86_t sphy_cntl_86;
SDRAM_PHY_CTL_87_t sphy_cntl_87;
SDRAM_PHY_CTL_88_t sphy_cntl_88;
SDRAM_PHY_CTL_89_t sphy_cntl_89;
SDRAM_PHY_CTL_90_t sphy_cntl_90;
SDRAM_PHY_CTL_91_t sphy_cntl_91;
SDRAM_PHY_CTL_92_t sphy_cntl_92;
SDRAM_PHY_CTL_93_t sphy_cntl_93;
SDRAM_PHY_CTL_94_t sphy_cntl_94;
SDRAM_PHY_CTL_95_t sphy_cntl_95;
SDRAM_PHY_CTL_96_t sphy_cntl_96;
SDRAM_PHY_CTL_97_0_t sphy_cntl_97;
SDRAM_PHY_CTL_97_1_t sphy_cntl_971;
SDRAM_PHY_CTL_98_t sphy_cntl_98;
SDRAM_PHY_CTL_100_0_t sphy_cntl_100;
SDRAM_PHY_CTL_100_1_t sphy_cntl_1001;
SDRAM_PHY_CTL_100_0_t sphy_cntl_101;
SDRAM_PHY_CTL_100_1_t sphy_cntl_1011;
SDRAM_PHY_CTL_100_0_t sphy_cntl_102;
SDRAM_PHY_CTL_100_1_t sphy_cntl_1021;
SDRAM_PHY_CTL_100_0_t sphy_cntl_103;
SDRAM_PHY_CTL_100_1_t sphy_cntl_1031;

unsigned char show_dbg_message;
unsigned char failed_byte_lane[4];
unsigned char show_type;
unsigned int loop_check_cnt;
unsigned char display_all = 0;
unsigned int ddr_freq = 0;
unsigned char detected_16bit_mode = 0 ;

//unsigned long long offset_scan[2]; /* total 64 bit result 0: fail, 1: pass*/
unsigned char offset_scan[128];

unsigned int get_bitmask_len(unsigned int a)
{
	int i;

	for (i = 31; i >=0; i--) {
		if (a & (0x1 << i))
			return (unsigned int)i;
	}
	return 0;
}

unsigned int sdram_uidiv(unsigned int dividend, unsigned int divisor)
{
	unsigned int quotient, remainder;
	unsigned int dividend_len, divisor_len;
	int i, diff_len;

	if (dividend < divisor)
		return 0;
	if ((dividend == 0) || (divisor == 0))
		return 0;
	dividend_len = get_bitmask_len(dividend);
	divisor_len = get_bitmask_len(divisor);

	quotient = 0;
	remainder = dividend;
	diff_len = dividend_len - divisor_len;
	for (i = diff_len; i >= 0; i--) {
		if (remainder > (divisor << i)) {
			quotient |= 0x01;
			remainder -= divisor << i;
		}
		quotient = quotient << 1;
	}
	quotient = quotient >> 1;

	if (remainder >= (divisor >> 1))
		quotient += 1;

	return quotient;
}

int denali_sdramdriver_set_default_conf(void)
{
	/* set frequency to 800Mhz */
	if (ddr_freq == 0)
		ddr_freq = DEFAULT_DDR_FREQ;
	set_ddr_freq(ddr_freq);

	/* Init DRAM Controller */
	denali_sdram_cntl_config(TYPE_DDR3);
	/* Init DDR PHY */
	denali_sdram_phy_config(TYPE_DDR3);

	serial_puts("Initiate Denali SDRAM Controller initialization\n");

	return RET_OK;
}

int g2_ddr_start_and_train(void)
{
	/*  Now wait for initialization to complete */
	g2_ddr_start();

	initialize_lpddr2_s2();

	sdram_pattern_write();
	denali_sdram_train_rd_strobe();
	denali_sdram_train_rd_latency();
	denali_sdram_train_gateo();
	denali_sdram_train_wr_data();

	/* following two task can't go earlier than training sequence */
	set_denali_16bit_mode();

	denali_sdram_size();
	/* FIXME, check dram size match board configuration */

	serial_puts("Denali SDRAM Controller initialization Done\n");

	return RET_OK;
}

int denali_sdramdriver_initialize(void)
{
	denali_sdramdriver_set_default_conf();
	g2_ddr_start_and_train();
	return RET_OK;
}

int denali_sdram_cntl_config(int mem_type)
{
	serial_puts("Started Denali SDRAM Controller Configuration...\n");

	/*Configure CNTL_00 */
	denali_cntl_00.wrd = 0;
#ifdef LPDDR2_MEM
	denali_cntl_00.bf.dram_class0 = 5;
#else
#ifdef DDR3_MEM
	denali_cntl_00.bf.dram_class0 = 6;
#else
	denali_cntl_00.bf.dram_class0 = 4;
#endif
#endif

	IO_WRITE(SDRAM_DENALI_CTL_000, denali_cntl_00.wrd);

	/*Configure CNTL_01 */
	denali_cntl_01.wrd = 0;
	denali_cntl_011.wrd = 0;
	denali_cntl_01.bf.TINIT0 = 0x50;	/*  LPDDR2=h28; value doesn't matter for GG */
	/*    software must set following "trst_pwron" to correct value=32'h13880:200us!! 0x10 is just for speed up simulation!! */
	denali_cntl_01.bf.TRST_PWRON0 = 0x13880 & 0xFF;	/*  only DDR3 matter */
	denali_cntl_011.bf.TRST_PWRON1 = 0x13880 >> 8;	/*  only DDR3 matter */
#ifdef BUILD_FOR_SIMULATION
	denali_cntl_01.bf.TRST_PWRON0 = 0x10 & 0xFF;	/*  only DDR3 matter */
	denali_cntl_011.bf.TRST_PWRON1 = 0x10 >> 8;	/*  only DDR3 matter */
#endif
	IO_WRITE(SDRAM_DENALI_CTL_010, denali_cntl_01.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_011, denali_cntl_011.wrd);

	/*Configure CNTL_02 */
	denali_cntl_02.wrd = 0;
	/*    software must set following "cke_inactive" to correct value=32'h30D40:500us!! 0x10 is just for speed up simulation!! */
	denali_cntl_02.bf.CKE_INACTIVE0 = 0x30D40;	/*  only DDR3 matter */
#ifdef BUILD_FOR_SIMULATION
	denali_cntl_02.bf.CKE_INACTIVE0 = 0x10;	/*  only DDR3 matter */
#endif
	IO_WRITE(SDRAM_DENALI_CTL_020, denali_cntl_02.wrd);

	/*Configure CNTL_021 */
	denali_cntl_021.wrd = 0;
	denali_cntl_021.bf.INITAREF1 = 0x2;	/*  only DDR2 matter */

#ifdef LPDDR2_MEM
	/*    CL=6/CWL=3 ~2.5ns */
	denali_cntl_021.bf.CASLAT_LIN1 = 0xc;
	denali_cntl_021.bf.WRLAT1 = 0x3;
#else
#ifdef DDR3_MEM
	if (ddr_freq > 850) {
		/*    CL=7/CWL=6 1.875ns/2.5ns */
		denali_cntl_021.bf.CASLAT_LIN1 = 0x10;
		denali_cntl_021.bf.WRLAT1 = 0x6;
	} else {
		/*    CL=6/CWL=5 2.5ns/3.3ns */
		denali_cntl_021.bf.CASLAT_LIN1 = 0xc;
		denali_cntl_021.bf.WRLAT1 = 0x5;
	}
#else
	/*    CL=5 2.5ns/8ns */
	denali_cntl_021.bf.CASLAT_LIN1 = 0xa;
	denali_cntl_021.bf.WRLAT1 = 0x4;
#endif
#endif
	IO_WRITE(SDRAM_DENALI_CTL_021, denali_cntl_021.wrd);

	/*Configure CNTL_03 */
	denali_cntl_03.wrd = 0;
	denali_cntl_031.wrd = 0;

	denali_cntl_03.bf.TRRD0 = 0x4;
	denali_cntl_03.bf.TBST_INT_INTERVAL0 = 0x4;

#ifdef LPDDR2_MEM
	denali_cntl_031.bf.TRP1 = 0x8;	/*  18ns */
	denali_cntl_03.bf.TCCD0 = 0x4;
	denali_cntl_03.bf.TRC0 = 0x1a;	/*  42+21ns */
	denali_cntl_031.bf.TRAS_MIN1 = 0x11;	/*  42ns */
	denali_cntl_031.bf.TWTR1 = 0x3;
	denali_cntl_031.bf.TRTP1 = 0x3;
#else
#ifdef DDR3_MEM
	if (ddr_freq > 850) {
		denali_cntl_03.bf.TRRD0 = 0x5;
		denali_cntl_031.bf.TRP1 = 0x8;	/*  Denali minimum; DDR3=DDR2=5 */
		denali_cntl_03.bf.TRC0 = 0x1b;	/*  49.125ns */
		denali_cntl_031.bf.TRAS_MIN1 = 0x13;	/*  36ns */
	} else {
		denali_cntl_031.bf.TRP1 = 0x6;	/*  Denali minimum; DDR3=DDR2=5 */
		denali_cntl_03.bf.TRC0 = 0x15;	/*  52.5ns */
		denali_cntl_031.bf.TRAS_MIN1 = 0xf;	/*  37.5ns */
	}
	denali_cntl_03.bf.TCCD0 = 0x4;
	denali_cntl_031.bf.TWTR1 = 0x4;
	denali_cntl_031.bf.TRTP1 = 0x4;
#else
	denali_cntl_031.bf.TRP1 = 0x6;	/*  Denali minimum; DDR3=DDR2=5 */
	denali_cntl_03.bf.TCCD0 = 0x2;
	denali_cntl_03.bf.TRC0 = 0x18;	/*  60ns */
	denali_cntl_031.bf.TRAS_MIN1 = 0x12;	/*  45ns */
	denali_cntl_031.bf.TWTR1 = 0x3;
	denali_cntl_031.bf.TRTP1 = 0x3;
#endif
#endif
	IO_WRITE(SDRAM_DENALI_CTL_030, denali_cntl_03.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_031, denali_cntl_031.wrd);

	/*Configure CNTL_04 */
	denali_cntl_04.wrd = 0;
	denali_cntl_041.wrd = 0;

	denali_cntl_041.bf.WRITEINTERP1 = 0x0;
	denali_cntl_041.bf.TCKE1 = 0x3;	/*  LPDDR2=DDR3=DDR2=3 */
	denali_cntl_041.bf.TCKESR1 = 0x6;	/*  LPDDR2=6/DDR3=1/DDR2=? */
	denali_cntl_041.bf.AP1 = 0x0;
#ifdef LPDDR2_MEM
	denali_cntl_04.bf.TMRD0 = 0x5;
	denali_cntl_04.bf.TMOD0 = 0x5;
#else
#ifdef DDR3_MEM
	denali_cntl_04.bf.TMRD0 = 0x4;
	denali_cntl_04.bf.TMOD0 = 0xc;
#else
	denali_cntl_04.bf.TMRD0 = 0x2;
	denali_cntl_04.bf.TMOD0 = 0x5;	/*  12ns */
#endif
#endif
	IO_WRITE(SDRAM_DENALI_CTL_040, denali_cntl_04.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_041, denali_cntl_041.wrd);

	/*Configure CNTL_05 */
	denali_cntl_05.wrd = 0;
	denali_cntl_051.wrd = 0;

	denali_cntl_05.bf.CONCURRENTAP0 = 0x1;
	denali_cntl_05.bf.TRAS_LOCKOUT0 = 0x1;
	denali_cntl_05.bf.TWR_INT0 = 0x6;	/*  15ns */
	denali_cntl_051.bf.TDLL1 = 0xc8;	/*  200Tck;only DDR2 matters */
	denali_cntl_051.bf.NO_CMD_INIT1 = 0x1;	/*  only DDR2 matters */
#ifdef LPDDR2_MEM
	denali_cntl_05.bf.TRCD_INT0 = 0x8;	/*  18ns */
	denali_cntl_051.bf.TDAL1 = 0xe;	/*  tWR+tRP */
#else
	if (ddr_freq > 850) {
		denali_cntl_05.bf.TWR_INT0 = 0x8;	/*  15ns */
		denali_cntl_05.bf.TRCD_INT0 = 0x8;	/*  15ns */
		denali_cntl_051.bf.TDAL1 = 0x10;	/*  tWR+tRP */
	} else {
		denali_cntl_05.bf.TRCD_INT0 = 0x6;	/*  15ns */
		denali_cntl_051.bf.TDAL1 = 0xb;	/*  tWR+tRP */
	}
#endif
	IO_WRITE(SDRAM_DENALI_CTL_050, denali_cntl_05.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_051, denali_cntl_051.wrd);

	/*Configure CNTL_06 */
	denali_cntl_06.wrd = 0;
	denali_cntl_061.wrd = 0;

	denali_cntl_06.bf.BSTLEN0 = 0x3;
	denali_cntl_06.bf.TFAW0 = 0x14;	/*  LPDDR2=DDR3=50ns/DDR2=45ns */
	denali_cntl_06.bf.TCPD0 = 0xa0;	/*  400ns; only DDR2 matters */
#ifdef LPDDR2_MEM
	denali_cntl_061.bf.TRP_AB1 = 0x9;	/*  21ns */
#else
	if (ddr_freq > 850) {
		denali_cntl_06.bf.TFAW0 = 0x19;	/*  LPDDR2=DDR3=50ns/DDR2=45ns */
		denali_cntl_061.bf.TRP_AB1 = 0x8;	/*  =tRP */
	} else {
		denali_cntl_061.bf.TRP_AB1 = 0x6;	/*  =tRP */
	}
#endif
	IO_WRITE(SDRAM_DENALI_CTL_060, denali_cntl_06.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_061, denali_cntl_061.wrd);

	/*Configure CNTL_07 */
	denali_cntl_07.wrd = 0;
	denali_cntl_071.wrd = 0;

	denali_cntl_07.bf.TREF_ENABLE0 = 0x1;
	/*denali_sdram_size() will decide following two */
	denali_cntl_07.bf.TRFC0 = sdram_uidiv(131 * ddr_freq, 800) + 1;	/*  largest value=10'h84 */
	denali_cntl_07.bf.TREF0 = (sdram_uidiv(39 * ddr_freq, 10) + 1) & 0xFF;	/*  DDR2/DDR3 7.8us+1=14'hc31 */
	denali_cntl_071.bf.TREF1 = ((sdram_uidiv(39 * ddr_freq, 10) + 1) >> 8) & 0xFF;
	if (ddr_freq > 850)
		denali_cntl_071.bf.TPDEX1 = 0x4;
	else
		denali_cntl_071.bf.TPDEX1 = 0x3;
	IO_WRITE(SDRAM_DENALI_CTL_070, denali_cntl_07.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_071, denali_cntl_071.wrd);

	/*Configure CNTL_08 */
	denali_cntl_08.wrd = 0;
	denali_cntl_081.wrd = 0;

	denali_cntl_08.bf.TXPDLL0 = 0xa;	/*  only DDR3 matters */
#ifdef LPDDR2_MEM
	denali_cntl_08.bf.TXSR0 = 0x58;	/*  210+10ns */
	denali_cntl_081.bf.TXSNR1 = 0x58;
#else
#ifdef DDR3_MEM
	denali_cntl_08.bf.TXSR0 = 0x200;	/*  =tDLLK */
	if (ddr_freq > 850) {
		denali_cntl_08.bf.TXPDLL0 = 0xc;	/*  24ns */
		denali_cntl_081.bf.TXSNR1 = 0x9b;	/* 300 + 10ns */
	} else {
		denali_cntl_081.bf.TXSNR1 = 0x7c;	/* 300 + 10ns */
	}
#else
	denali_cntl_08.bf.TXSR0 = 0xc8;	/*  200-6 */
	denali_cntl_081.bf.TXSNR1 = 0x88;	/*  327.5+10ns */
#endif
#endif
	IO_WRITE(SDRAM_DENALI_CTL_080, denali_cntl_08.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_081, denali_cntl_081.wrd);

	/*Configure CNTL_09 */
	denali_cntl_09.wrd = 0;
	denali_cntl_091.wrd = 0;

	denali_cntl_09.bf.ENABLE_QUICK_SREFRESH0 = 0x1;
#ifdef LPDDR2_MEM
	denali_cntl_091.bf.MR1_DATA_01 = 0x83;	/*  tWR=6 */
#else
#ifdef DDR3_MEM
	if (ddr_freq > 850) {
		denali_cntl_09.bf.MR0_DATA_00 = 0x0840 & 0xFF;	/*  WR=8/CL=8 */
		denali_cntl_091.bf.MR0_DATA_01 = 0x0840 >> 8;	/*  WR=8/CL=8 */
	} else {
		denali_cntl_09.bf.MR0_DATA_00 = 0x0420 & 0xFF;	/*  WR=6/CL=6 */
		denali_cntl_091.bf.MR0_DATA_01 = 0x0420 >> 8;	/*  WR=6/CL=6 */
	}

//	denali_cntl_091.bf.MR1_DATA_01 = 0x0040;
//	denali_cntl_091.bf.MR1_DATA_01 = 0x0004;
	denali_cntl_091.bf.MR1_DATA_01 = 0x0000;	/* no termination */
#else
	denali_cntl_09.bf.MR0_DATA_00 = 0x1a53 & 0xFF;	/*  tWR=6/CL=5 */
	denali_cntl_091.bf.MR0_DATA_01 = 0x1a53 >> 8;	/*  WL=5/CL=6 */
	denali_cntl_091.bf.MR1_DATA_01 = 0x0044;
#endif
#endif
	IO_WRITE(SDRAM_DENALI_CTL_090, denali_cntl_09.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_091, denali_cntl_091.wrd);

	/*Configure CNTL_10 */
	denali_cntl_10.wrd = 0;
	denali_cntl_101.wrd = 0;

	denali_cntl_101.bf.ADDR_SPACE1 = 0x1e;	/*  1G byte */
#ifdef LPDDR2_MEM
	denali_cntl_10.bf.MR2_DATA_00 = 0x0004;	/*  CL=6/CWL=3 */
	denali_cntl_10.bf.MR3_DATA_00 = 0x0002;
#else
#ifdef DDR3_MEM
	if (ddr_freq > 850) {
		denali_cntl_10.bf.MR2_DATA_00 = 0x0008;
	} else {
//		denali_cntl_10.bf.MR2_DATA_00 = 0x0400;
		denali_cntl_10.bf.MR2_DATA_00 = 0x0000;
	}
	denali_cntl_10.bf.MR3_DATA_00 = 0x0000;
#else
	denali_cntl_10.bf.MR2_DATA_00 = 0x0000;
	denali_cntl_10.bf.MR3_DATA_00 = 0x0000;
#endif
#endif
	IO_WRITE(SDRAM_DENALI_CTL_100, denali_cntl_10.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_101, denali_cntl_101.wrd);

	/*Configure CNTL_11 */
	denali_cntl_11.wrd = 0;
	denali_cntl_11.bf.BIST_ADDR_CHECK0 = 0x0;
	IO_WRITE(SDRAM_DENALI_CTL_110, denali_cntl_11.wrd);

	/*Configure CNTL_12 */
	denali_cntl_12.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_120, denali_cntl_12.wrd);

	/*Configure CNTL_13 */
	denali_cntl_13.wrd = 0;
	denali_cntl_131.wrd = 0;
	denali_cntl_131.bf.REFRESH_PER_ZQ1 = 0x80;
#ifdef LPDDR2_MEM
	denali_cntl_13.bf.ZQINIT0 = 0x190;	/*  1us */
	denali_cntl_13.bf.ZQCL0 = 0x90;	/*  360ns */
	denali_cntl_131.bf.ZQCS1 = 0x24;	/*  90ns */
#else
	denali_cntl_13.bf.ZQINIT0 = 0x200;	/*  512tCK */
	denali_cntl_13.bf.ZQCL0 = 0x100;	/*  256tCK */
	denali_cntl_131.bf.ZQCS1 = 0x40;	/*  64tCK */
#endif
	IO_WRITE(SDRAM_DENALI_CTL_130, denali_cntl_13.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_131, denali_cntl_131.wrd);

	/*Configure CNTL_14 */
	denali_cntl_14.wrd = 0;
	denali_cntl_141.wrd = 0;
	denali_cntl_14.bf.ZQ_ON_SREF_EXIT0 = 0x2;
	denali_cntl_14.bf.EIGHT_BANK_MODE0 = 0x1;
	/*denali_sdram_size() will decide following two */
	denali_cntl_14.bf.ADDR_PINS0 = 0x0;
	denali_cntl_141.bf.COLUMN_SIZE1 = 0x1;
	denali_cntl_141.bf.APREBIT1 = 0xa;

	denali_cntl_141.bf.AGE_COUNT1 = 0x7;
	denali_cntl_141.bf.COMMAND_AGE_COUNT1 = 0x7;
	IO_WRITE(SDRAM_DENALI_CTL_140, denali_cntl_14.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_141, denali_cntl_141.wrd);

	/*Configure CNTL_15 */
	denali_cntl_15.wrd = 0;
	denali_cntl_151.wrd = 0;
	denali_cntl_15.bf.ADDR_CMP_EN0 = 0x1;
	denali_cntl_15.bf.BANK_SPLIT_EN0 = 0x1;
	denali_cntl_15.bf.PLACEMENT_EN0 = 0x1;
	denali_cntl_15.bf.PRIORITY_EN0 = 0x1;
	denali_cntl_151.bf.RW_SAME_EN1 = 0x1;
	denali_cntl_151.bf.SWAP_EN1 = 0x1;
	denali_cntl_151.bf.SWAP_PORT_RW_SAME_EN1 = 0x0;
	denali_cntl_151.bf.BURST_ON_FLY_BIT1 = 0xc;
	IO_WRITE(SDRAM_DENALI_CTL_150, denali_cntl_15.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_151, denali_cntl_151.wrd);

	/*Configure CNTL_16 */
	denali_cntl_16.wrd = 0;
	denali_cntl_161.wrd = 0;
	denali_cntl_161.bf.RESYNC_DLL_PER_AREF_EN1 = 0x1;
	IO_WRITE(SDRAM_DENALI_CTL_160, denali_cntl_16.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_161, denali_cntl_161.wrd);

	/*Configure CNTL_17 */
	IO_WRITE(SDRAM_DENALI_CTL_170, 0);
	IO_WRITE(SDRAM_DENALI_CTL_171, 0);

	/*Configure CNTL_18 */
	IO_WRITE(SDRAM_DENALI_CTL_180, 0);
	IO_WRITE(SDRAM_DENALI_CTL_181, 0);

	/*Configure CNTL_19 */
	IO_WRITE(SDRAM_DENALI_CTL_190, 0);
	IO_WRITE(SDRAM_DENALI_CTL_191, 0);

	/*Configure CNTL_20 */
	IO_WRITE(SDRAM_DENALI_CTL_200, 0);
	IO_WRITE(SDRAM_DENALI_CTL_201, 0);

	/*Configure CNTL_21 */
	IO_WRITE(SDRAM_DENALI_CTL_210, 0);
	IO_WRITE(SDRAM_DENALI_CTL_211, 0);

	/*Configure CNTL_22 */
	IO_WRITE(SDRAM_DENALI_CTL_220, 0);
	IO_WRITE(SDRAM_DENALI_CTL_221, 0);

	/*Configure CNTL_23 */
	IO_WRITE(SDRAM_DENALI_CTL_230, 0);
	IO_WRITE(SDRAM_DENALI_CTL_231, 0);

	/*Configure CNTL_24 */
	denali_cntl_24.wrd = 0;
	denali_cntl_241.wrd = 0;
	denali_cntl_241.bf.R2W_SAMECS_DLY1 = 0x4;
	/* Add 3 clocks. Be conservative here according to experience. */
	IO_WRITE(SDRAM_DENALI_CTL_240, denali_cntl_24.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_241, denali_cntl_241.wrd);

	/*Configure CNTL_25 */
	denali_cntl_25.wrd = 0;
	denali_cntl_251.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_250, denali_cntl_25.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_251, denali_cntl_251.wrd);

	/*Configure CNTL_26 */
	denali_cntl_26.wrd = 0;
	denali_cntl_261.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_260, denali_cntl_26.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_261, denali_cntl_261.wrd);

	/*Configure CNTL_27 */
	denali_cntl_27.wrd = 0;
	denali_cntl_271.wrd = 0;
	denali_cntl_27.bf.WLDQSEN0 = 0x19;
	denali_cntl_27.bf.WLMRD0 = 0x28;
	IO_WRITE(SDRAM_DENALI_CTL_270, denali_cntl_27.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_271, denali_cntl_271.wrd);

	/*Configure CNTL_28 */
	denali_cntl_28.wrd = 0;
	denali_cntl_281.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_280, denali_cntl_28.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_281, denali_cntl_281.wrd);

	/*Configure CNTL_29 */
	denali_cntl_29.wrd = 0;
	denali_cntl_291.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_290, denali_cntl_29.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_291, denali_cntl_291.wrd);

	/*Configure CNTL_30 */
	denali_cntl_30.wrd = 0;
	denali_cntl_301.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_300, denali_cntl_30.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_301, denali_cntl_301.wrd);

	/*Configure CNTL_31 */
	denali_cntl_31.wrd = 0;
	denali_cntl_311.wrd = 0;
	denali_cntl_31.bf.RDLVL_DELAY_00 = 0x1c1c;
	IO_WRITE(SDRAM_DENALI_CTL_310, denali_cntl_31.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_311, denali_cntl_311.wrd);

	/*Configure CNTL_32 */
	denali_cntl_32.wrd = 0;
	denali_cntl_321.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_320, denali_cntl_32.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_321, denali_cntl_321.wrd);

	/*Configure CNTL_33 */
	denali_cntl_33.wrd = 0;
	denali_cntl_331.wrd = 0;
	denali_cntl_33.bf.RDLVL_DELAY_10 = 0x1c1c;
	IO_WRITE(SDRAM_DENALI_CTL_330, denali_cntl_33.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_331, denali_cntl_331.wrd);

	/*Configure CNTL_34 */
	denali_cntl_34.wrd = 0;
	denali_cntl_341.wrd = 0;
	denali_cntl_341.bf.RDLVL_DELAY_21 = 0x1c1c;
	IO_WRITE(SDRAM_DENALI_CTL_340, denali_cntl_34.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_341, denali_cntl_341.wrd);

	/*Configure CNTL_35 */
	denali_cntl_35.wrd = 0;
	denali_cntl_351.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_350, denali_cntl_35.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_351, denali_cntl_351.wrd);

	/*Configure CNTL_36 */
	denali_cntl_36.wrd = 0;
	denali_cntl_361.wrd = 0;
	denali_cntl_36.bf.RDLVL_DELAY_30 = 0x1c1c & 0xFF;
	denali_cntl_361.bf.RDLVL_DELAY_31 = 0x1c1c >> 8;
	IO_WRITE(SDRAM_DENALI_CTL_360, denali_cntl_36.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_361, denali_cntl_361.wrd);

	/*Configure CNTL_37 */
	denali_cntl_37.wrd = 0;
	denali_cntl_371.wrd = 0;
	denali_cntl_37.bf.AXI0_EN_SIZE_LT_WIDTH_INSTR0 = 0xffff;	// Bug# 26000
	denali_cntl_371.bf.AXI1_EN_SIZE_LT_WIDTH_INSTR1 = 0xffff;
	denali_cntl_37.bf.AXI0_R_PRIORITY0 = 0x1;	// 2012/01/06: optimization, was 0x2
	denali_cntl_37.bf.AXI0_W_PRIORITY0 = 0x1;	// 2012/01/06: optimization, was 0x2
	denali_cntl_371.bf.AXI1_R_PRIORITY1 = 0x2;
	IO_WRITE(SDRAM_DENALI_CTL_370, denali_cntl_37.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_371, denali_cntl_371.wrd);

	/*Configure CNTL_38 */
	denali_cntl_38.wrd = 0;
	denali_cntl_381.wrd = 0;
	denali_cntl_38.bf.AXI1_W_PRIORITY0 = 0x2;
	denali_cntl_38.bf.AXI2_EN_SIZE_LT_WIDTH_INSTR0 = 0xffff;
	denali_cntl_381.bf.AXI2_R_PRIORITY1 = 0x2;
	denali_cntl_381.bf.AXI2_W_PRIORITY1 = 0x2;
	IO_WRITE(SDRAM_DENALI_CTL_380, denali_cntl_38.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_381, denali_cntl_381.wrd);

	/*Configure CNTL_39 */
	denali_cntl_39.wrd = 0;
	denali_cntl_391.wrd = 0;
	denali_cntl_39.bf.AXI3_EN_SIZE_LT_WIDTH_INSTR0 = 0x0000;
#ifdef QM_DDR_PORT_BW_75_PERCENT
	denali_cntl_391.bf.ARB_CMD_Q_THRESHOLD1 = 0x1;
#else
	denali_cntl_391.bf.ARB_CMD_Q_THRESHOLD1 = 0x6;	// 2012/01/06: optimization, was 0x3
#endif
#ifdef QM_DDR_PORT_BW_75_PERCENT
	denali_cntl_391.bf.AXI0_BDW1 = 0x8;
	denali_cntl_39.bf.AXI3_R_PRIORITY0 = 0x0;
	denali_cntl_39.bf.AXI3_W_PRIORITY0 = 0x1;
#else
	denali_cntl_391.bf.AXI0_BDW1 = 0x32;
	denali_cntl_39.bf.AXI3_R_PRIORITY0 = 0x0;
	denali_cntl_39.bf.AXI3_W_PRIORITY0 = 0x1;
#endif
	denali_cntl_391.bf.AXI0_BDW_OVFLOW1 = 0x1;
	IO_WRITE(SDRAM_DENALI_CTL_390, denali_cntl_39.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_391, denali_cntl_391.wrd);

	/*Configure CNTL_40 */
	denali_cntl_40.wrd = 0;
	denali_cntl_401.wrd = 0;

#ifdef QM_DDR_PORT_BW_75_PERCENT
	denali_cntl_40.bf.AXI1_BDW0 = 0x8;
#else
	denali_cntl_40.bf.AXI1_BDW0 = 0x32;
#endif
	denali_cntl_40.bf.AXI1_BDW_OVFLOW0 = 0x1;
#ifdef QM_DDR_PORT_BW_75_PERCENT
	denali_cntl_401.bf.AXI2_BDW1 = 0x8;
#else
	denali_cntl_401.bf.AXI2_BDW1 = 0x32;
#endif
	denali_cntl_401.bf.AXI2_BDW_OVFLOW1 = 0x1;
#ifdef QM_DDR_PORT_BW_75_PERCENT
	denali_cntl_401.bf.AXI3_BDW1 = 0x4c;
#else
	denali_cntl_401.bf.AXI3_BDW1 = 0x32;
#endif
	IO_WRITE(SDRAM_DENALI_CTL_400, denali_cntl_40.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_401, denali_cntl_401.wrd);

	/*Configure CNTL_41 */
	denali_cntl_41.wrd = 0;
	denali_cntl_411.wrd = 0;
	denali_cntl_41.bf.AXI3_BDW_OVFLOW0 = 0x1;
	IO_WRITE(SDRAM_DENALI_CTL_410, denali_cntl_41.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_411, denali_cntl_411.wrd);

	/*Configure CNTL_42 */
	denali_cntl_42.wrd = 0;
	denali_cntl_421.wrd = 0;
	denali_cntl_42.bf.TDFI_PHY_RDLAT0 = 0x4;
	denali_cntl_421.bf.TDFI_CTRLUPD_MAX1 = 0xc2d;
	IO_WRITE(SDRAM_DENALI_CTL_420, denali_cntl_42.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_421, denali_cntl_421.wrd);

	/*Configure CNTL_43 */
	denali_cntl_43.wrd = 0;
	denali_cntl_431.wrd = 0;
	denali_cntl_43.bf.TDFI_PHYUPD_TYPE00 = 0x200;
	denali_cntl_43.bf.TDFI_PHYUPD_TYPE10 = 0x200;
	denali_cntl_431.bf.TDFI_PHYUPD_TYPE21 = 0x200;
	denali_cntl_431.bf.TDFI_PHYUPD_TYPE31 = 0x200;
	IO_WRITE(SDRAM_DENALI_CTL_430, denali_cntl_43.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_431, denali_cntl_431.wrd);

	/*Configure CNTL_44 */
	denali_cntl_44.wrd = 0;
	denali_cntl_441.wrd = 0;
	/*    LPDDR2 rdlat_adj=b; DDR3 rdlat_adj=a; DDR3 rdlat_adj=9; */
	/*    LPDDR2 wrlat_adj=3; DDR3 wrlat_adj=5; DDR2 wrlat_adj=4; */
	/*    denali_sdram_train() will decide what rdlat_adj is */
	denali_cntl_44.bf.RDLAT_ADJ0 = 0x14;
	/* FIXME */
	/*denali_cntl_44.bf.WRLAT_ADJ = tb.denali_sdram_cntl.denali_cntl_02.wr_lat; */
	denali_cntl_44.bf.TDFI_PHYUPD_RESP0 = 0xc2d;
	denali_cntl_44.bf.WRLAT_ADJ0 = denali_cntl_021.bf.WRLAT1;

	denali_cntl_44.bf.TDFI_PHYUPD_RESP0 = 0xc2d;
	denali_cntl_441.bf.DFI_WRLVL_MAX_DELAY1 = 0x8000;
	denali_cntl_441.bf.TDFI_WRLVL_EN1 = 0x3;
	denali_cntl_441.bf.TDFI_WRLVL_DLL1 = 0x3;
	IO_WRITE(SDRAM_DENALI_CTL_440, denali_cntl_44.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_441, denali_cntl_441.wrd);

	/*Configure CNTL_45 */
	denali_cntl_45.wrd = 0;
	denali_cntl_451.wrd = 0;
	denali_cntl_45.bf.TDFI_WRLVL_LOAD0 = 0x7;
	denali_cntl_45.bf.TDFI_WRLVL_RESPLAT0 = 0x4;
	denali_cntl_45.bf.TDFI_WRLVL_WW0 = 0xa;
	denali_cntl_451.bf.TDFI_WRLVL_RESP1 = 0xc2d;
	IO_WRITE(SDRAM_DENALI_CTL_450, denali_cntl_45.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_451, denali_cntl_451.wrd);

	/*Configure CNTL_46 */
	denali_cntl_46.wrd = 0;
	denali_cntl_461.wrd = 0;
	denali_cntl_461.bf.RDLVL_MAX_DELAY1 = 0xffff;
	denali_cntl_461.bf.RDLVL_GATE_MAX_DELAY1 = 0x0010;
	IO_WRITE(SDRAM_DENALI_CTL_460, denali_cntl_46.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_461, denali_cntl_461.wrd);

	/*Configure CNTL_47 */
	denali_cntl_47.wrd = 0;
	denali_cntl_471.wrd = 0;
	denali_cntl_47.bf.TDFI_RDLVL_EN0 = 0x3;
	denali_cntl_47.bf.TDFI_RDLVL_DLL0 = 0x3;
	denali_cntl_47.bf.TDFI_RDLVL_LOAD0 = 0x7;
	denali_cntl_47.bf.TDFI_RDLVL_RESPLAT0 = 0x11;
	denali_cntl_471.bf.TDFI_RDLVL_RR1 = 0xf;
	IO_WRITE(SDRAM_DENALI_CTL_470, denali_cntl_47.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_471, denali_cntl_471.wrd);

	/*Configure CNTL_48 */
	denali_cntl_48.wrd = 0;
	denali_cntl_481.wrd = 0;
	denali_cntl_48.bf.TDFI_RDLVL_RESP0 = 0xc2d;
	IO_WRITE(SDRAM_DENALI_CTL_480, denali_cntl_48.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_481, denali_cntl_481.wrd);

	/*Configure CNTL_49 */
	denali_cntl_49.wrd = 0;
	denali_cntl_491.wrd = 0;
	IO_WRITE(SDRAM_DENALI_CTL_490, denali_cntl_49.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_491, denali_cntl_491.wrd);

	/*Configure CNTL_50 */
	denali_cntl_50.wrd = 0;
	denali_cntl_501.wrd = 0;
	denali_cntl_50.bf.TDFI_RDLVL_MAX0 = 0xc2d;
	denali_cntl_501.bf.RDLVL_DQ_ZERO_COUNT1 = 0x4;
	denali_cntl_501.bf.RDLVL_GATE_DQ_ZERO_COUNT1 = 0x2;
	IO_WRITE(SDRAM_DENALI_CTL_500, denali_cntl_50.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_501, denali_cntl_501.wrd);

	/*Configure CNTL_51 */
	denali_cntl_51.wrd = 0;
	denali_cntl_511.wrd = 0;
	denali_cntl_511.bf.ODT_ALT_EN1 = 0x1;
	IO_WRITE(SDRAM_DENALI_CTL_510, denali_cntl_51.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_511, denali_cntl_511.wrd);

	/*Configure CNTL_52 */
	denali_cntl_52.wrd = 0;
	denali_cntl_521.wrd = 0;
	denali_cntl_52.bf.TRAS_MAX0 = 0x6d60;
	IO_WRITE(SDRAM_DENALI_CTL_520, denali_cntl_52.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_521, denali_cntl_521.wrd);

	/*Configure CNTL_53 */
	IO_WRITE(SDRAM_DENALI_CTL_530, 0);
	IO_WRITE(SDRAM_DENALI_CTL_531, 0);

	/*Configure CNTL_54 */
	denali_cntl_54.wrd = 0;
	denali_cntl_541.wrd = 0;
	denali_cntl_54.bf.TDFI_CTRLUPD_INTERVAL0 = 0x3ce1;
	IO_WRITE(SDRAM_DENALI_CTL_540, denali_cntl_54.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_541, denali_cntl_541.wrd);

#ifdef LPDDR2_MEM
	/*wr_data[7]  = 64'h00_00_90_00_00_80_00_00; */
	/*    software must use following line because above line is just for speed up simulation!! */
	/*    wr_data[7]  = 64'h00_01_90_01_38_80_00_00;  //Configure CNTL_55, tINIT3=200us, tINIT4=1us */
	IO_WRITE(SDRAM_DENALI_CTL_550, 0x38800000);
	IO_WRITE(SDRAM_DENALI_CTL_551, 0x00019001);

	/*wr_data[8]  = 64'h00_00_00_02_00_00_01_a0; */
	/*    software must use following line because above line is just for speed up simulation!! */
	/*    wr_data[8]  = 64'h00_00_00_02_00_00_0f_a0;  //Configure CNTL_56, tMRR=2, tINIT5=10us */
	IO_WRITE(SDRAM_DENALI_CTL_560, 0x00000fa0);
	IO_WRITE(SDRAM_DENALI_CTL_561, 0x00000002);

	/*wr_data[9]  = 64'h00_ff_00_00_00_00_00_00;  //Configure CNTL_57 */
	IO_WRITE(SDRAM_DENALI_CTL_570, 0x00000000);
	IO_WRITE(SDRAM_DENALI_CTL_571, 0x00ff0000);

	/*wr_data[10] = 64'h03_00_01_00_00_14_00_00;  //Configure CNTL_58, S4 device, tDQSCK_MAX=3 */
	IO_WRITE(SDRAM_DENALI_CTL_580, 0x00140000);
	IO_WRITE(SDRAM_DENALI_CTL_581, 0x03000100);

	/*wr_data[11] = 64'h00_00_01_02_00_00_00_01;  //Configure CNTL_59 */
	IO_WRITE(SDRAM_DENALI_CTL_590, 0x00000001);
	IO_WRITE(SDRAM_DENALI_CTL_591, 0x00000102);
#endif

	serial_puts("DONE Denali SDRAM Controller Configuration...\n");

	return RET_OK;
}

int denali_sdram_phy_config(int mem_type)
{

	serial_puts("Started SDRAM PHY Configuration...\n");

	/*Configure CNTL_64 */
#ifdef LPDDR2_MEM
	IO_WRITE(SDRAM_PHY_CTL_64_1, 0x00001001);
#else
	IO_WRITE(SDRAM_PHY_CTL_64_1, 0x00011010);
#endif
	IO_WRITE(SDRAM_PHY_CTL_64_0, 0x00000000);

	/*Configure CNTL_65 */
#ifdef LPDDR2_MEM
	IO_WRITE(SDRAM_PHY_CTL_65_1, 0x00000001);
#else
	IO_WRITE(SDRAM_PHY_CTL_65_1, 0x00000000);
#endif
	IO_WRITE(SDRAM_PHY_CTL_65_0, 0x00000e38);

	/*Configure CNTL_66 */
	if ((2000000 / SAMSUNG_PHY_DLL_LOW_FREQUENCY) > ddr_freq)
		IO_WRITE(SDRAM_PHY_CTL_66_0, 0x10108100);
	else
		IO_WRITE(SDRAM_PHY_CTL_66_0, 0x10108000);

	IO_WRITE(SDRAM_PHY_CTL_66_1, 0x00000020);

	/*Configure CNTL_67 */
	/*denali_sdram_size() will decide following */
#ifdef LPDDR2_MEM
	IO_WRITE(SDRAM_PHY_CTL_67_0, 0x00000500);
	IO_WRITE(SDRAM_PHY_CTL_67_1, 0x0000000f);
#else
	IO_WRITE(SDRAM_PHY_CTL_67_0, 0x00000600);
	IO_WRITE(SDRAM_PHY_CTL_67_1, 0x00000000);
#endif

	/*Configure CNTL_68 */
	IO_WRITE(SDRAM_PHY_CTL_68_0, 0x00000000);
	IO_WRITE(SDRAM_PHY_CTL_68_1, 0x00000000);

	/*Configure CNTL_69 */
	IO_WRITE(SDRAM_PHY_CTL_69_0, 0x00000000);
	IO_WRITE(SDRAM_PHY_CTL_69_1, 0x00000000);

	/*Configure CNTL_70 */
#ifdef LPDDR2_MEM
	IO_WRITE(SDRAM_PHY_CTL_70_0, 0x05052100);
	IO_WRITE(SDRAM_PHY_CTL_70_1, 0x00003000);
#else
	if (ddr_freq > 850)
		IO_WRITE(SDRAM_PHY_CTL_70_0, 0x03243100);	// no termination
	else
		IO_WRITE(SDRAM_PHY_CTL_70_0, 0x04243100);	// no termination
	IO_WRITE(SDRAM_PHY_CTL_70_1, 0x00003000);
#endif

	serial_puts("DONE SDRAM PHY Configuration...\n");

	return RET_OK;
}

int denali_sdram_init_done()
{
	int init_done = 0;
	int time_out = 0;
	int time_out_period = 500;	// supposed to be 400000 / ddr_freq

	serial_puts("Waiting for SDRAM initialization to complete\n");

	while (init_done == 0) {
		init_done = (IO_READ(SDRAM_DENALI_CTL_161) >> (45 - 32)) & 1;

		time_out++;

		/*if(time_out == (500)) { */
		if (time_out == time_out_period) {
			/*if(time_out >= 10000) { */
			serial_puts
			    ("Timed out while waiting for sdram init done to get set\n");
			return RET_ERR;
		}
	}			/*end of while init_done */

	serial_puts("SDRAM initialization DONE.............\n");

	return RET_OK;
}

int initialize_lpddr2_s2(void)
{
	unsigned char lpddr2_type, lpddr2_io_width, lpddr2_density;

	/*-------------------------------------------------------------------------*/
	/*    Read back configuration of LPDDR2 for setting S2 devices */
	/*-------------------------------------------------------------------------*/
	denali_cntl_00.wrd = IO_READ(SDRAM_DENALI_CTL_000);
	if (denali_cntl_00.bf.dram_class0 == 0x5) {
		/*    read CNTL_57 */
		denali_cntl_571.wrd = IO_READ(SDRAM_DENALI_CTL_571);
		lpddr2_type = denali_cntl_571.wrd >> (56 - 32) & 0x3;	/*[57:56]; */
		lpddr2_density = denali_cntl_571.wrd >> (58 - 32) & 0xF;	/*[61:58]; */
		lpddr2_io_width = denali_cntl_571.wrd >> (62 - 32) & 0x3;	/*[63:62]; */

		if ((lpddr2_type == 0x2) || (lpddr2_type == 0x3)) {
			serial_puts("ERROR: No LPDDR2 SDRAM type detected\n");
			return 1;
		}

		if (lpddr2_type == 0x01) {	/*  S2 devices */
			IO_WRITE(SDRAM_DENALI_CTL_580, 0x00140000);
			IO_WRITE(SDRAM_DENALI_CTL_581, 0x03000000);

			if ((lpddr2_density == 0x4) || (lpddr2_density == 0x5)) {	/*  1Gb or 2Gb */
				/*    read CNTL_14 */
				denali_cntl_14.wrd =
				    IO_READ(SDRAM_DENALI_CTL_140);
				denali_cntl_14.bf.EIGHT_BANK_MODE0 = 0x0;

				/*    write CNTL_14 with valid bank setting */
				IO_WRITE(SDRAM_DENALI_CTL_140,
					 denali_cntl_14.wrd);
			}

		}
	}

	return RET_OK;
}				/*end of task initialize_lpddr2_s2 */

int sdram_pattern_write(void)
{
	unsigned long long wr_data[8];
	unsigned int i;
	unsigned long long *paddr = (unsigned long long *)SDRAM_BASE;

	wr_data[0] = 0xFCFDFEF703020108ULL;
	wr_data[1] = 0xF8F9FAFB07060504ULL;
	wr_data[2] = 0xECEDEEEF13121110ULL;
	wr_data[3] = 0xE8E9EAEB17161514ULL;
	wr_data[4] = 0xDCDDDEDF23222120ULL;
	wr_data[5] = 0xD8D9DADB27262524ULL;
	wr_data[6] = 0xCCCDCECF33323130ULL;
	wr_data[7] = 0xC8C9CACB37363534ULL;

	/*  burst write SDRAM address 0 with fix pattern */
	/*  software can use 32 bits write but still need to fulfill 64 bytes */

	/*  write eight 64bits data into SDRAM */
	for (i = 0; i < 8; i++)
		paddr[i] = wr_data[i];


	return RET_OK;
}

int g2_scan_range(unsigned char *left_hand_margin, unsigned char *right_hand_margin, unsigned char *left_right)
{
	char final_left, final_right, tmp_left, tmp_right;
	short max_rng, tmp_rang, i;

	final_left = 0x3f;
	final_right = 0x40;

	/* Review: Scan for max valid range */
	max_rng = 0;
	for (i = 0x7F; i >= 0; i--){
		tmp_rang = 0;
		/* down seek for first pass */
		while ((i >= 0) && (offset_scan[i] == 0))
			i--;

		if (i < 0)
			break;
		tmp_right = i;
		/* Count valid range */
		while ((i >= 0) && (offset_scan[i] == 1)){
			tmp_rang++;
			tmp_left = i;
			i--;
		}
		/* Update if find larger ranger */
		if (tmp_rang > max_rng){
			max_rng = tmp_rang;
			final_left = tmp_left;
			final_right = tmp_right;
		}
	}

	*right_hand_margin = final_right;
	*left_hand_margin = final_left;

	if ((final_left + final_right) / 2 < 64 )
		*left_right = 1;
	else
		*left_right = 0;

	return 0;
}

int denali_sdram_train_rd_strobe(void)
{
	unsigned char offset_reg, curr_offset, left_right;
	unsigned char right_hand_margin = 0, left_hand_margin = 0;
	int byte_lane, offset_bit;
	unsigned int data_l, tmp, sphy_data0_reg;

	serial_puts("Performing train RD strobe\n");
	/*-------------------------------------------------------------------------*/
	/*    First step: Put read strobe to center per byte lane */
	/*-------------------------------------------------------------------------*/
	/*    read CNTL_16 */
	denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);

	/*    read CNTL_68 */
//	sphy_cntl_68.wrd = IO_READ(SDRAM_PHY_CTL_68_0);
//	sphy_cntl_681.wrd = IO_READ(SDRAM_PHY_CTL_68_1);

	sphy_data0_reg = 0;

	/*    read leveling */
	for (byte_lane = 0; byte_lane < 4; byte_lane++) {
		if ((detected_16bit_mode == 1) && (byte_lane >= 2))
			break;
		serial_puts("byte lane#");
		serial_put_decimal((unsigned int)byte_lane);
		serial_puts(":\n");
		for (left_right = 0; left_right < 2; left_right++) {
			offset_reg = left_right << 6;
			if (display_all != 1) {
				for (offset_bit = 5; offset_bit >= 0; offset_bit--) {
					offset_reg |= 1 << offset_bit;
					/*  write PHY_68 to offset read strobe */
//					sphy_data0_reg &= ~(0x7f << (byte_lane*8));
					data_l = sphy_data0_reg | (offset_reg << (byte_lane * 8));
					IO_WRITE(SDRAM_PHY_CTL_68_0, data_l);

#if 0
					serial_puts("CTL_68 : ");
					serial_put_hex(data_l);
					serial_puts("\n");
#endif

					/*  write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
					data_l = denali_cntl_16.wrd | 1 << 24;
					IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

					/*  read SDRAM and check against patterns */
					cpu_read_check_sdram_mem(SDRAM_BASE);	/*  at 64M */

					if (failed_byte_lane[byte_lane])
						offset_reg &= ~(1 << offset_bit);
				}	/*  end of offset_bit */
			} else {
				if (left_right == 0)
					serial_puts("\tright:\n");
				else
					serial_puts("\tleft:\n");
				for (offset_bit = 0; offset_bit < (1 << 6); offset_bit++) {
					curr_offset = (left_right << 6) + offset_bit;
//					sphy_data0_reg &= ~(0x7f << (byte_lane*8));
					data_l = sphy_data0_reg | (curr_offset << (byte_lane * 8));
					IO_WRITE(SDRAM_PHY_CTL_68_0, data_l);
					/*  write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
					data_l = denali_cntl_16.wrd | (1 << 24);
					IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

					/*  read SDRAM and check against patterns */
					cpu_read_check_sdram_mem(SDRAM_BASE);	/*  at 64M */

					if ((offset_bit & 0x1f) == 0x00)
						serial_puts("\t");
					if (failed_byte_lane[byte_lane]) {
						serial_puts("X");
						if (left_right == 0)
							offset_scan[offset_bit + 64] = 0;
						else
							offset_scan[63 - offset_bit] = 0;
					} else {
						if (offset_reg == (curr_offset - 1))
							offset_reg = curr_offset;
						serial_puts("O");
						if (left_right == 0)
							offset_scan[offset_bit + 64] = 1;
						else
							offset_scan[63 - offset_bit] = 1;
					}
					if ((offset_bit & 0x07) == 0x07)
						serial_puts(" ");
					if ((offset_bit & 0x1f) == 0x1f)
						serial_puts("\n");
				}
			}
			if (left_right == 0)
				right_hand_margin = offset_reg & 0x3F;
			else
				left_hand_margin = offset_reg & 0x3F;

		}		/*  end of left_right */

		if (display_all == 1)
			g2_scan_range(&left_hand_margin, &right_hand_margin, &left_right);

		serial_puts("\tRight hand margin is ");
		serial_put_decimal(right_hand_margin);
		serial_puts("\n");

		serial_puts("\tLeft hand margin is ");
		serial_put_decimal(left_hand_margin);
		serial_puts("\n");

		if (display_all == 1) {
//			sphy_data0_reg &= ~(0x7f << (byte_lane*8));
			tmp = (left_hand_margin + right_hand_margin) / 2;
			if (tmp < 64)
				sphy_data0_reg |= ((64 - tmp) | 0x40) << (byte_lane * 8);
			else
				sphy_data0_reg |= (tmp - 64) << (byte_lane * 8);
		} else {
			if (right_hand_margin >= left_hand_margin) {
				sphy_data0_reg |= ((unsigned int)
						(right_hand_margin -
						 left_hand_margin) >> 1) <<
					(byte_lane * 8);
			} else {
				sphy_data0_reg |= ((unsigned int)
						(left_hand_margin -
						 right_hand_margin) >> 1 | 0x40)
					<< (byte_lane * 8);
			}
		}

		if ((left_hand_margin == 0) && (right_hand_margin == 0)
		    && (byte_lane >= 2)) {
			detected_16bit_mode = 1;
		}
	}			/*  end of byte_lane */

	/*    write CNTL_68 -> Set to middle in between left and right margins */
	IO_WRITE(SDRAM_PHY_CTL_68_0, sphy_data0_reg);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_PHY_CTL_68_0);
	serial_puts("  VAL: ");
	serial_put_hex(sphy_data0_reg);
	serial_puts("\n\n");

	/*  write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
	data_l = denali_cntl_16.wrd | 1 << 24;
	IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

	return RET_OK;
}

int cpu_read_check_sdram_mem(unsigned int addr)
{
	unsigned char alternate_addr = 0;
	unsigned int sdram_address;
	unsigned int cpu_readback0, cpu_readback1;
	unsigned long long to_compare0, to_compare1;
	unsigned long long wr_pattern[8];
	unsigned int burst_seq;
	unsigned short i = 0, fail_st[4] = { 0, 0, 0, 0 };

	wr_pattern[0] = 0xFCFDFEF703020108ULL;
	wr_pattern[1] = 0xF8F9FAFB07060504ULL;
	wr_pattern[2] = 0xECEDEEEF13121110ULL;
	wr_pattern[3] = 0xE8E9EAEB17161514ULL;
	wr_pattern[4] = 0xDCDDDEDF23222120ULL;
	wr_pattern[5] = 0xD8D9DADB27262524ULL;
	wr_pattern[6] = 0xCCCDCECF33323130ULL;
	wr_pattern[7] = 0xC8C9CACB37363534ULL;

	if (loop_check_cnt == 0)
		loop_check_cnt = DEFAULT_LOOP_CNT;

check_again:
	memset(failed_byte_lane, 0, sizeof(failed_byte_lane));
	/*  simulation only read check once through those 8 32 bits data */
	/*  software should perform multiple read check and report pass/fail ratio */

	for (burst_seq = 0; burst_seq < 4; burst_seq++) {
		alternate_addr = ~alternate_addr;

		/*  single read (mimic cpu 32 bit read) SDRAM sdram_address to check fix pattern */
		if (alternate_addr)
			sdram_address = addr + burst_seq * 8 + 4;
		else
			sdram_address = addr + burst_seq * 8;

		cpu_readback0 = cpu_read_sdram_mem_32bit(sdram_address);

		/*  single read (mimic cpu 32 bit read) SDRAM sdram_address to check fix pattern */
		if (alternate_addr)
			sdram_address = addr + burst_seq * 8 + 32;
		else
			sdram_address = addr + burst_seq * 8 + 32 + 4;

		cpu_readback1 = cpu_read_sdram_mem_32bit(sdram_address);

		to_compare0 = wr_pattern[burst_seq];
		to_compare1 = wr_pattern[burst_seq + 4];
		/*  software needs to be able to tell which byte lane always fails here */
		if (alternate_addr) {
			if ((cpu_readback0 & 0xFF) !=
			    ((to_compare0 >> 32) & 0xFF))
				failed_byte_lane[0] = 1;
			if (((cpu_readback0 >> 8) & 0xFF) !=
			    ((to_compare0 >> 40) & 0xFF))
				failed_byte_lane[1] = 1;
			if (((cpu_readback0 >> 16) & 0xFF) !=
			    ((to_compare0 >> 48) & 0xFF))
				failed_byte_lane[2] = 1;
			if (((cpu_readback0 >> 24) & 0xFF) !=
			    ((to_compare0 >> 56) & 0xFF))
				failed_byte_lane[3] = 1;

			if ((cpu_readback1 & 0xFF) != (to_compare1 & 0xFF))
				failed_byte_lane[0] = 1;
			if (((cpu_readback1 >> 8) & 0xFF) !=
			    ((to_compare1 >> 8) & 0xFF))
				failed_byte_lane[1] = 1;
			if (((cpu_readback1 >> 16) & 0xFF) !=
			    ((to_compare1 >> 16) & 0xFF))
				failed_byte_lane[2] = 1;
			if (((cpu_readback1 >> 24) & 0xFF) !=
			    ((to_compare1 >> 24) & 0xFF))
				failed_byte_lane[3] = 1;
		} else {
			if ((cpu_readback0 & 0xFF) != (to_compare0 & 0xFF))
				failed_byte_lane[0] = 1;
			if (((cpu_readback0 >> 8) & 0xFF) !=
			    ((to_compare0 >> 8) & 0xFF))
				failed_byte_lane[1] = 1;
			if (((cpu_readback0 >> 16) & 0xFF) !=
			    ((to_compare0 >> 16) & 0xFF))
				failed_byte_lane[2] = 1;
			if (((cpu_readback0 >> 24) & 0xFF) !=
			    ((to_compare0 >> 24) & 0xFF))
				failed_byte_lane[3] = 1;

			if ((cpu_readback1 & 0xFF) !=
			    ((to_compare1 >> 32) & 0xFF))
				failed_byte_lane[0] = 1;
			if (((cpu_readback1 >> 8) & 0xFF) !=
			    ((to_compare1 >> 40) & 0xFF))
				failed_byte_lane[1] = 1;
			if (((cpu_readback1 >> 16) & 0xFF) !=
			    ((to_compare1 >> 48) & 0xFF))
				failed_byte_lane[2] = 1;
			if (((cpu_readback1 >> 24) & 0xFF) !=
			    ((to_compare1 >> 56) & 0xFF))
				failed_byte_lane[3] = 1;
		}
	}

	if (failed_byte_lane[0])
		fail_st[0]++;
	if (failed_byte_lane[1])
		fail_st[1]++;
	if (failed_byte_lane[2])
		fail_st[2]++;
	if (failed_byte_lane[3])
		fail_st[3]++;

	if (++i < loop_check_cnt)	/* Next loop */
		goto check_again;

	/* set failed_byte_lane if any fail */
	if (fail_st[0] != 0)
		failed_byte_lane[0] = 1;
	if (fail_st[1] != 0)
		failed_byte_lane[1] = 1;
	if (fail_st[2] != 0)
		failed_byte_lane[2] = 1;
	if (fail_st[3] != 0)
		failed_byte_lane[3] = 1;

#if 0
	if (display_all != 1) {
		serial_puts("PASS/FAIL: Byte0= ");
		serial_put_decimal(i - fail_st[0]);
		serial_puts("/");
		serial_put_decimal(fail_st[0]);

		serial_puts(" Byte1= ");
		serial_put_decimal(i - fail_st[1]);
		serial_puts("/");
		serial_put_decimal(fail_st[1]);

		denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);
		if (detected_16bit_mode == 0){	/* 16 bit mode */
			serial_puts(" Byte2= ");
			serial_put_decimal(i - fail_st[2]);
			serial_puts("/");
			serial_put_decimal(fail_st[2]);

			serial_puts(" Byte3= ");
			serial_put_decimal(i - fail_st[3]);
			serial_puts("/");
			serial_put_decimal(fail_st[3]);
		}
		serial_puts("\n");
	}
#endif

	return RET_OK;
}				/*end of task cpu_read_check_sdram_mem */

int set_denali_16bit_mode(void)
{
	if (detected_16bit_mode == 1 ){
	//if (denali_cntl_16.bf.REDUC0) {	/*  16 bit mode */
		/* read CNTL_16 */
		denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);
		denali_cntl_16.bf.REDUC0 = 1;

		/* write CNTL_16 to set 16 bit mode */
		IO_WRITE(SDRAM_DENALI_CTL_160, denali_cntl_16.wrd);

		/* read CNTL_67 */
		sphy_cntl_671.wrd = IO_READ(SDRAM_PHY_CTL_67_1);

		/* write CNTL_67 to disable upper 16 bits IO */
		sphy_cntl_671.bf.ctrl_PD = 0xC;
		IO_WRITE(SDRAM_PHY_CTL_67_1, sphy_cntl_671.wrd);
	}

	return RET_OK;
}				/*end of task set_denali_16bit_mode */

unsigned int cpu_read_sdram_mem_32bit(unsigned int addr)
{
	unsigned int ret_v;
	unsigned int *paddr = (unsigned int *)addr;

	ret_v = *paddr;

	if (show_dbg_message == 1) {
		serial_puts("Started SDRAM transaction of read burst 1\n");
		serial_puts("SDRAM ADDR = ");
		serial_put_hex(addr);
		serial_puts("\n");
		serial_puts("cpu_read_out32bit = ");
		serial_put_hex(ret_v);
		serial_puts("\n");
	}

	return ret_v;
}				/*end of task cpu_read_sdram_mem_32bit */

int restart_dll_lock(void)
{
	unsigned char ctrl_locked = 0;
	int time_out = 0;
	unsigned int time_stamp;
	int time_out_period = 500;	// supposed to be 400000 / ddr_freq

	/* read CNTL_66 */
	sphy_cntl_66.wrd = IO_READ(SDRAM_PHY_CTL_66_0);
	sphy_cntl_661.wrd = IO_READ(SDRAM_PHY_CTL_66_1);

	/* write CNTL_66 to force dll value before off it */
	/* bit[39:32] are assigned from bit[61:54] */
	sphy_cntl_661.bf.ctrl_FORCE = (sphy_cntl_661.wrd & 0x3FC00000) >> 22;
	IO_WRITE(SDRAM_PHY_CTL_66_1, sphy_cntl_661.wrd);

	/* read CNTL_65 */
	sphy_cntl_651.wrd = IO_READ(SDRAM_PHY_CTL_65_1);

	/* write CNTL_66 to on dll and off start */
	//sphy_cntl_661.bf.ctrl_FORCE = (sphy_cntl_661.wrd & 0x3FC00000) >> 22;
	sphy_cntl_66.bf.ctrl_DLL_ON = 1;
	sphy_cntl_66.bf.ctrl_START = 0;
	/* IO_WRITE(SDRAM_PHY_CTL_66_1, sphy_cntl_661.wrd); */
	IO_WRITE(SDRAM_PHY_CTL_66_0, sphy_cntl_66.wrd);

	/* write CNTL_65 to enable dll_start/dll_on overrite; start is 0 now */
	sphy_cntl_651.wrd |= 0xC0000000;
	IO_WRITE(SDRAM_PHY_CTL_65_1, sphy_cntl_651.wrd);

	/* write CNTL_66 to off dll */
	//sphy_cntl_661.bf.ctrl_FORCE = (sphy_cntl_661.wrd & 0x3FC00000) >> 22;
	sphy_cntl_66.bf.ctrl_DLL_ON = 0;
	sphy_cntl_66.bf.ctrl_START = 0;
	IO_WRITE(SDRAM_PHY_CTL_66_0, sphy_cntl_66.wrd);

	/*  Important! Software should wait at leat 1 us here */
	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;

	/* write CNTL_66 to on dll */
	//sphy_cntl_661.bf.ctrl_FORCE = (sphy_cntl_661.wrd & 0x3FC00000) >> 22;
	sphy_cntl_66.bf.ctrl_DLL_ON = 1;
	sphy_cntl_66.bf.ctrl_START = 0;
	IO_WRITE(SDRAM_PHY_CTL_66_0, sphy_cntl_66.wrd);

	/* Important! Software should wait at leat 1 us here */
	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;

	/* write CNTL_66 to start dll */
	//sphy_cntl_661.bf.ctrl_FORCE = (sphy_cntl_661.wrd & 0x3FC00000) >> 22;
	sphy_cntl_66.bf.ctrl_DLL_ON = 1;
	sphy_cntl_66.bf.ctrl_START = 1;
	IO_WRITE(SDRAM_PHY_CTL_66_0, sphy_cntl_66.wrd);

	/* write CNTL_65 to disable dll_start/dll_on overrite */
	sphy_cntl_651.wrd &= ~0xC0000000;
	IO_WRITE(SDRAM_PHY_CTL_65_1, sphy_cntl_651.wrd);

	while (ctrl_locked == 0) {
		sphy_cntl_661.wrd = IO_READ(SDRAM_PHY_CTL_66_1);
		ctrl_locked = sphy_cntl_661.bf.ctrl_LOCKED;

		time_out++;
		if (time_out == time_out_period) {
			serial_puts
			    ("Timed out while waiting for DLL locking\n");
			return RET_ERR;
		}
	}

	return RET_OK;
}

int force_zq_pmos_nmos(unsigned char impp, unsigned char impn)
{
	unsigned int time_stamp;

	/* read CNTL_70 */
	sphy_cntl_70.wrd = IO_READ(SDRAM_PHY_CTL_70_0);
	sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);

	sphy_cntl_70.bf.ctrl_ZQ_FORCE_IMPP = impp;
	sphy_cntl_70.bf.ctrl_ZQ_FORCE_IMPN = impn;
	sphy_cntl_70.bf.ctrl_ZQ_FORCE = 1;

	/* HW bug at read back ctrl_za_div[46:44] */
	sphy_cntl_701.bf.ctrl_ZQ_DIV = 3;

	/* write CNTL_70 to force impp/impn; harware bug at read back
	 * ctrl_zq_div, [46:44] */
	/* wr_data[0] = {20'h3, sphy_cntl_70_rd_data[43:20], impp, impn, */
	/* sphy_cntl_70_rd_data[11:8], 4'h1, sphy_cntl_70_rd_data[3:0]}; */
	IO_WRITE(SDRAM_PHY_CTL_70_0, sphy_cntl_70.wrd);

	/* Important! Software should wait at leat 1 us here */
	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;	/* Wait 1ms */

	/* write CNTL_70 to release forcing */
	sphy_cntl_70.bf.ctrl_ZQ_FORCE = 0;
	IO_WRITE(SDRAM_PHY_CTL_70_0, sphy_cntl_70.wrd);

	return RET_OK;
}

int restart_zq_calibration(void)
{
	unsigned int time_stamp;
	unsigned char ctrl_zq_end = 1;
	unsigned char ctrl_zq_error = 0;
	unsigned int time_out = 0;
	int time_out_period = 500;	// supposed to be 400000 / ddr_freq

	/* read CNTL_16 */
	denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);
	denali_cntl_161.wrd = IO_READ(SDRAM_DENALI_CTL_161);

	/* write CNTL_16 to stop ctrl_resync */
	denali_cntl_161.bf.RESYNC_DLL_PER_AREF_EN1 = 0;
	IO_WRITE(SDRAM_DENALI_CTL_161, denali_cntl_161.wrd);

	/* read CNTL_65 */
	sphy_cntl_651.wrd = IO_READ(SDRAM_PHY_CTL_65_1);

	/*  write CNTL_65 to enable zq_start override */
	sphy_cntl_651.bf.override_en_ZQ_START = 1;
	IO_WRITE(SDRAM_PHY_CTL_65_1, sphy_cntl_651.wrd);

	/* read CNTL_70 */
	sphy_cntl_70.wrd = IO_READ(SDRAM_PHY_CTL_70_0);

	/* write CNTL_70 to start ZQ calibration; harware bug at read back
	 * ctrl_zq_div, [46:44] */
	sphy_cntl_70.bf.ctrl_ZQ_START = 1;
	IO_WRITE(SDRAM_PHY_CTL_70_0, sphy_cntl_70.wrd);

	while (ctrl_zq_end == 1) {
		sphy_cntl_70.wrd = IO_READ(SDRAM_PHY_CTL_70_0);
		sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
		ctrl_zq_end = sphy_cntl_70.bf.ctrl_ZQ_END;
		ctrl_zq_error = sphy_cntl_701.bf.ctrl_ZQ_ERROR;

		time_out++;
		if (time_out == time_out_period) {
			serial_puts
			    ("Timed out while waiting for ZQ calibration\n");
			return RET_ERR;
		}
		if (ctrl_zq_error) {
			serial_puts
			    ("Hardware error found in ZQ calibration. Try force it\n");
			return RET_ERR;
		}
	}

	/* Important! Software should wait at leat 2 us here */
	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;	/* Wait 1ms */
	ctrl_zq_end = 0;

	time_out = 0;
	while (ctrl_zq_end == 0) {
		sphy_cntl_70.wrd = IO_READ(SDRAM_PHY_CTL_70_0);
		sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
		ctrl_zq_end = sphy_cntl_70.bf.ctrl_ZQ_END;
		ctrl_zq_error = sphy_cntl_701.bf.ctrl_ZQ_ERROR;

		time_out++;
		if (time_out == time_out_period) {
			serial_puts
			    ("Timed out while waiting for ZQ calibration\n");
			return RET_ERR;
		}
		if (ctrl_zq_error) {
			serial_puts
			    ("Hardware error found in ZQ calibration. Try force it\n");
			return RET_ERR;
		}
	}

	/*  write CNTL_16 to enable ctrl_resync with refresh */
	denali_cntl_161.bf.RESYNC_DLL_PER_AREF_EN1 = 1;
	IO_WRITE(SDRAM_DENALI_CTL_161, denali_cntl_161.wrd);

	/*  write CNTL_16 to trigger ctrl_resync */
	denali_cntl_16.bf.RESYNC_DLL0 = 1;
	IO_WRITE(SDRAM_DENALI_CTL_160, denali_cntl_16.wrd);

	/*  a dumy read for waiting ctrl_resync */
//	IO_READ(SDRAM_DENALI_CTL_160);

	/*  write CNTL_65 to disable zq_start override mode */
	sphy_cntl_651.bf.override_en_ZQ_START = 0;
	IO_WRITE(SDRAM_PHY_CTL_65_1, sphy_cntl_651.wrd);

#if 0	/* Removed base on 0623 simulation version*/
	/*  a dumy read in case hardware goes another ZQ */
	IO_READ(SDRAM_PHY_CTL_70_0);
	IO_READ(SDRAM_PHY_CTL_70_1);

	time_out = 0;
	while (ctrl_zq_end == 0) {
		sphy_cntl_70.wrd = IO_READ(SDRAM_PHY_CTL_70_0);
		sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
		ctrl_zq_end = sphy_cntl_70.bf.ctrl_ZQ_END;
		ctrl_zq_error = sphy_cntl_701.bf.ctrl_ZQ_ERROR;

		time_out++;
		if (time_out == time_out_period) {
			serial_puts
			    ("Timed out while waiting for ZQ calibration\n");
			return RET_ERR;
		}
		if (ctrl_zq_error) {
			serial_puts
			    ("Hardware error found in ZQ calibration. Try force it\n");
			return RET_ERR;
		}
	}
	/*  Important! Software should wait at leat 2 us here */
	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;	/* Wait 1ms */
#endif

	return RET_OK;
}

int denali_sdram_train_rd_latency(void)
{
	unsigned int data_l;
	unsigned char left_hand_margin;

	serial_puts("Performing train RD latency\n");
	/*-------------------------------------------------------------------------*/
	/*    Second step: compensate read dealy path */
	/*-------------------------------------------------------------------------*/
	/*    read CNTL_16 */
	denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);

	/*    read CNTL_44 */
	denali_cntl_44.wrd = IO_READ(SDRAM_DENALI_CTL_440);

	/*  Tune rdlat_adj for real world delay: IO + BOARD + SDRAM */
	left_hand_margin = 0;
	denali_cntl_44.bf.RDLAT_ADJ0 = 0x4;
	while (denali_cntl_44.bf.RDLAT_ADJ0 < 20) {
		/*  write CNTL_44 to change rdlat_adj */
		IO_WRITE(SDRAM_DENALI_CTL_440, denali_cntl_44.wrd);

		/*  read SDRAM and check against patterns */
		cpu_read_check_sdram_mem(SDRAM_BASE);	/*  at 64M */

		if (!(failed_byte_lane[0] || failed_byte_lane[1])
		    && left_hand_margin == 0)
			left_hand_margin = denali_cntl_44.bf.RDLAT_ADJ0;
		/*  write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
		data_l = denali_cntl_16.wrd | (1 << 24);
		IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

		if (left_hand_margin != 0) {
			if (failed_byte_lane[2] || failed_byte_lane[3])
				detected_16bit_mode = 1;
			break;
		}
		denali_cntl_44.bf.RDLAT_ADJ0++;
	}

	if (left_hand_margin == 0) {
		serial_puts("ERROR: Can't find any slot for read\n");
		return RET_ERR;
	}

#ifndef CONFIG_CORTINA_FPGA
	/* Add one clock to accommodate more skew of drifting at lower speed
	 * (say 333MHz) */
	denali_cntl_44.bf.RDLAT_ADJ0++;
	/* write CNTL_44 to change rdlat_adj */
	IO_WRITE(SDRAM_DENALI_CTL_440, denali_cntl_44.wrd);
#endif

	/* read CNTL_00 */
	denali_cntl_00.wrd = IO_READ(SDRAM_DENALI_CTL_000);

	serial_puts("Read delay adjusted at rdlat_adj=");
	serial_put_decimal(left_hand_margin);
	serial_puts(" dram_class=");
	serial_put_decimal(denali_cntl_00.bf.dram_class0);
	serial_puts("\n");

	data_l = IO_READ(SDRAM_DENALI_CTL_160);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_DENALI_CTL_160);
	serial_puts("  VAL: ");
	serial_put_hex(data_l);
	serial_puts("\n");

	data_l = IO_READ(SDRAM_DENALI_CTL_440);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_DENALI_CTL_440);
	serial_puts("  VAL: ");
	serial_put_hex(data_l);
	serial_puts("\n\n");

	return RET_OK;
}				/*end of task denali_sdram_train_rd_latency */

int denali_sdram_train_gateo(void)
{
	unsigned char offset_reg, failed_byte_lane_all, curr_offset, left_right;
	unsigned char right_hand_margin = 0, left_hand_margin = 0;
	int offset_bit, data_l, tmp;

	serial_puts("Performing train gating\n");
	/*--------------------------------------------------------------------*/
	/* Third step: Check if GATO have enough margin */
	/*--------------------------------------------------------------------*/
	/* read CNTL_16 */
	denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);

	/* read CNTL_67 */
	sphy_cntl_67.wrd = IO_READ(SDRAM_PHY_CTL_67_0);

	/* GATEO leveling */
	for (left_right = 0; left_right < 2; left_right++) {
		offset_reg = left_right << 6;
		if (display_all != 1) {
			for (offset_bit = 5; offset_bit >= 0; offset_bit--) {
				offset_reg |= 1 << offset_bit;
				sphy_cntl_67.wrd &= 0xff80ffff;
				/* write PHY_67 to offset GATEO */
				data_l = sphy_cntl_67.wrd | offset_reg << 16;
				IO_WRITE(SDRAM_PHY_CTL_67_0, data_l);

				/* write CNTL_16 to trigger resync_dll ->
				 * reset FIFO in PHY */
				data_l = denali_cntl_16.wrd | (1 << 24);
				IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

				/*  read SDRAM and check against patterns */
				/*  at 64M */
				cpu_read_check_sdram_mem(SDRAM_BASE);

				failed_byte_lane_all = failed_byte_lane[0] |
					failed_byte_lane[1] |
					failed_byte_lane[2] |
					failed_byte_lane[3];

				if (detected_16bit_mode == 1) {
					/*  16 bit mode */
					if (failed_byte_lane[0] |
							failed_byte_lane[1])
						offset_reg &= ~(1 << offset_bit);
				} else {
					if (failed_byte_lane_all)
						offset_reg &= ~(1 << offset_bit);
				}
			}	/*  end of offset_bit */
		} else {
			if (left_right == 0)
				serial_puts("right:\n");
			else
				serial_puts("left:\n");
			for (offset_bit = 0; offset_bit < (1 << 6); offset_bit++) {
				curr_offset = (left_right << 6) + offset_bit;
				sphy_cntl_67.wrd &= 0xff80ffff;
				data_l = sphy_cntl_67.wrd | (curr_offset << 16);
				IO_WRITE(SDRAM_PHY_CTL_67_0, data_l);

				/*  write CNTL_16 to trigger resync_dll ->
				 *  reset FIFO in PHY */
				data_l = denali_cntl_16.wrd | (1 << 24);
				IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

				/*  read SDRAM and check against patterns */
				/*  at 64M */
				cpu_read_check_sdram_mem(SDRAM_BASE);

				failed_byte_lane_all = failed_byte_lane[0] |
					failed_byte_lane[1];
				if (detected_16bit_mode == 0) {
					failed_byte_lane_all |=
						failed_byte_lane[2] |
						failed_byte_lane[3];
				}

				if ((offset_bit & 0x1f) == 0x00)
					serial_puts("\t");

				if (failed_byte_lane_all) {
					serial_puts("X");
					if (left_right == 0)
						offset_scan[offset_bit + 64] = 0;
					else
						offset_scan[63 - offset_bit] = 0;
				} else {
					if (offset_reg == (curr_offset - 1))
						offset_reg = curr_offset;
					serial_puts("O");
					if (left_right == 0)
						offset_scan[offset_bit + 64] = 1;
					else
						offset_scan[63 - offset_bit] = 1;
				}

				if ((offset_bit & 0x07) == 0x07)
					serial_puts(" ");
				if ((offset_bit & 0x1f) == 0x1f)
					serial_puts("\n");
			}
		}
		if (left_right == 0)
			right_hand_margin = offset_reg & 0x3F;	/*[5:0]; */
		else
			left_hand_margin = offset_reg & 0x3F;	/*[5:0]; */

	}			/*  end of left_right */

	if (display_all == 1)
		g2_scan_range(&left_hand_margin, &right_hand_margin, &left_right);

	serial_puts("Right hand margin is ");
	serial_put_decimal(right_hand_margin);
	serial_puts(" for GATEO\n");

	serial_puts("Left hand margin is ");
	serial_put_decimal(left_hand_margin);
	serial_puts(" for GATEO\n");

	if (display_all == 1){
		tmp = (left_hand_margin + right_hand_margin) / 2;
		if(tmp < 64)
			sphy_cntl_67.wrd |=  ((64 - tmp) | 0x40) << 16;
		else
			sphy_cntl_67.wrd |= (tmp - 64) << 16;
	}
	else{
		if (right_hand_margin >= left_hand_margin) {
			sphy_cntl_67.wrd |=
		    	((right_hand_margin - left_hand_margin) >> 1) << 16;
		} else {
			sphy_cntl_67.wrd |=
		    	(((left_hand_margin -
		       		right_hand_margin) >> 1) | 0x40) << 16;
		}

	}
	/*  write PHY_67 -> Set to middle in between left and right margins */
	IO_WRITE(SDRAM_PHY_CTL_67_0, sphy_cntl_67.wrd);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_PHY_CTL_67_0);
	serial_puts("  VAL: ");
	serial_put_hex(sphy_cntl_67.wrd);
	serial_puts("\n");

	/*  write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
	data_l = denali_cntl_16.wrd | (1 << 24);
	IO_WRITE(SDRAM_DENALI_CTL_160, data_l);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_DENALI_CTL_160);
	serial_puts("  VAL: ");
	serial_put_hex(data_l);
	serial_puts("\n\n");

	return RET_OK;
}				/*end of task denali_sdram_train_gateo */

int denali_sdram_train_wr_data_chk(unsigned long long *wr_data,
	unsigned char burst_seq, unsigned int sdram_address, unsigned char byte_lane )
{
	unsigned int cpu_readback0;
	unsigned long long to_compare0;

	cpu_readback0 = cpu_read_sdram_mem_32bit(sdram_address);

	to_compare0 = wr_data[burst_seq >> 1];
	/*  software needs to be able to tell which byte lane always fails here */
	if (burst_seq & 1) {
		if (((cpu_readback0 >> (byte_lane * 8)) & 0xFF) !=
				((to_compare0 >> (byte_lane * 8 + 32)) & 0xFF))
			failed_byte_lane[byte_lane] |= 1;
	} else {
		if (((cpu_readback0 >> (byte_lane * 8)) & 0xFF) !=
				((to_compare0 >> (byte_lane * 8)) & 0xFF))
			failed_byte_lane[byte_lane] |= 1;
	}
	return RET_OK;
}

int denali_sdram_train_wr_data_offset(int byte_lane, unsigned char offset_bit,
		unsigned int data_h)
{
	unsigned long long wr_data[16], wr_pattern[8];
	unsigned int sdram_address, data_l;
	int burst_seq, i;

	wr_pattern[0] = 0xFCFDFEF703020108ULL;
	wr_pattern[1] = 0xF8F9FAFB07060504ULL;
	wr_pattern[2] = 0xECEDEEEF13121110ULL;
	wr_pattern[3] = 0xE8E9EAEB17161514ULL;
	wr_pattern[4] = 0xDCDDDEDF23222120ULL;
	wr_pattern[5] = 0xD8D9DADB27262524ULL;
	wr_pattern[6] = 0xCCCDCECF33323130ULL;
	wr_pattern[7] = 0xC8C9CACB37363534ULL;

	/*  write PHY_68 to offset write strobe */
	IO_WRITE(SDRAM_PHY_CTL_68_1, data_h);

	/* write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
	data_l = denali_cntl_16.wrd | (1 << 24);
	IO_WRITE(SDRAM_DENALI_CTL_160, data_l);

	failed_byte_lane[byte_lane] = 0;
	/* read back what just wrote */
	/* simulation only read check once through those 8 32 bits data */
	for (i = 0; i < loop_check_cnt; i++) {
		/* write alternate fix pattern to SDRAM address 0 */
		/* software can use 32 bits write */
		if (i & 0x0001) {
			wr_data[0] = ~(wr_pattern[(offset_bit + 0) & 7]);
			wr_data[1] = ~(wr_pattern[(offset_bit + 1) & 7]);
			wr_data[2] = ~(wr_pattern[(offset_bit + 2) & 7]);
			wr_data[3] = ~(wr_pattern[(offset_bit + 3) & 7]);
		} else {
			wr_data[0] = wr_pattern[(offset_bit + 0) & 7];
			wr_data[1] = wr_pattern[(offset_bit + 1) & 7];
			wr_data[2] = wr_pattern[(offset_bit + 2) & 7];
			wr_data[3] = wr_pattern[(offset_bit + 3) & 7];
		}

		/*  write four 64bits data into SDRAM */
		write_sdram_mem(SDRAM_BASE, wr_data, 4);

		for (burst_seq = 0; burst_seq < 8; burst_seq++) {
			/* single read (mimic cpu 32 bit read) SDRAM
			 * sdram_address to check fix pattern */
			sdram_address = SDRAM_BASE + burst_seq * 4;

			denali_sdram_train_wr_data_chk(wr_data, burst_seq,
					sdram_address, byte_lane);
		}	/*  end of burst_seq */
	}	/* end of i */
	return RET_OK;
}

int denali_sdram_train_wr_data()
{
/*-----------------------------------------------------------------------------*/
	unsigned int sphy_data0_reg, tmp;
	unsigned int data_l, data_h;
	unsigned char offset_reg, curr_offset, left_right;
	unsigned char right_hand_margin = 0, left_hand_margin = 0;
	int byte_lane, offset_bit;

	serial_puts("Performing train write data\n");
	/*-------------------------------------------------------------------------*/
	/*    Fourth step: Align DQS with DQ per byte lane */
	/*-------------------------------------------------------------------------*/
	/*    read CNTL_16 */
	denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);

	/*    read CNTL_68 */
	/* don't need to read.. we are resetting it to 0 to start with anyway */
//	sphy_cntl_681.wrd = IO_READ(SDRAM_PHY_CTL_68_1);

	sphy_data0_reg = 0;

	/*    write leveling */
	for (byte_lane = 0; byte_lane < 4; byte_lane++) {
		if ((detected_16bit_mode == 1) && (byte_lane >= 2))
			break;
		serial_puts("byte lane#");
		serial_put_decimal((unsigned int)byte_lane);
		serial_puts(":\n");
		for (left_right = 0; left_right < 2; left_right++) {
			offset_reg = left_right << 6;
			if (display_all != 1) {
				for (offset_bit = 5; offset_bit >= 0; offset_bit--) {
					offset_reg |= 1 << offset_bit;
					/*  write PHY_68 to offset write strobe */
					data_h = sphy_data0_reg |
						(offset_reg << (byte_lane * 8));

					denali_sdram_train_wr_data_offset(
							byte_lane, offset_bit,
							data_h);

					if (failed_byte_lane[byte_lane])
						offset_reg &= ~(1 << offset_bit);
				}	/*  end of offset_bit */
			} else {
				if (left_right == 0)
					serial_puts("\tright:\n");
				else
					serial_puts("\tleft:\n");
				for (offset_bit = 0; offset_bit < (1 << 6); offset_bit++) {
					curr_offset = (left_right << 6) + offset_bit;
					data_h = sphy_data0_reg |
						(curr_offset << (byte_lane * 8));

					denali_sdram_train_wr_data_offset(
							byte_lane, offset_bit,
							data_h);

					if ((offset_bit & 0x1f) == 0x00)
						serial_puts("\t");
					if (failed_byte_lane[byte_lane]) {
						serial_puts("X");
						if (left_right == 0)
							offset_scan[offset_bit + 64] = 0;
						else
							offset_scan[63 - offset_bit] = 0;
					} else {
						if (offset_reg == (curr_offset - 1))
							offset_reg = curr_offset;
						serial_puts("O");
						if (left_right == 0)
							offset_scan[offset_bit + 64] = 1;
						else
							offset_scan[63 - offset_bit] = 1;
					}
					if ((offset_bit & 0x07) == 0x07)
						serial_puts(" ");
					if ((offset_bit & 0x1f) == 0x1f)
						serial_puts("\n");
				}
			}
			if (left_right == 0)
				right_hand_margin = offset_reg & 0x3F;	/*[5:0]; */
			else
				left_hand_margin = offset_reg & 0x3F;	/*[5:0]; */

		}	/*  end of left_right */

		if (display_all == 1)
			g2_scan_range(&left_hand_margin, &right_hand_margin, &left_right);

		serial_puts("Right hand margin is ");
		serial_put_decimal(right_hand_margin);
		serial_puts("\n");

		serial_puts("Left hand margin is ");
		serial_put_decimal(left_hand_margin);
		serial_puts("\n");

		if (display_all == 1) {
			tmp = (left_hand_margin + right_hand_margin) >> 1;
			if (tmp < 64)
				sphy_data0_reg |= ((64 - tmp) | 0x40) << (byte_lane * 8);
			else
				sphy_data0_reg |= (tmp - 64) << (byte_lane * 8);

		} else {
			if (right_hand_margin >= left_hand_margin)
				sphy_data0_reg |= ((unsigned int)
						(right_hand_margin -
						 left_hand_margin) >> 1) <<
					(byte_lane * 8);
			else
				sphy_data0_reg |= ((unsigned int)
						(left_hand_margin -
						 right_hand_margin) >> 1 | 0x40)
					<< (byte_lane * 8);
		}
	}	/*  end of byte_lane */

	/*    write CNTL_68 -> Set to middle in between left and right margins */
	IO_WRITE(SDRAM_PHY_CTL_68_1, sphy_data0_reg);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_PHY_CTL_68_1);
	serial_puts("  VAL: ");
	serial_put_hex(sphy_data0_reg);
	serial_puts("\n");

	/*  write CNTL_16 to trigger resync_dll -> reset FIFO in PHY */
	data_l = denali_cntl_16.wrd | 1 << 24;
	IO_WRITE(SDRAM_DENALI_CTL_160, data_l);
	serial_puts("ADDR: ");
	serial_put_hex(SDRAM_DENALI_CTL_160);
	serial_puts("  VAL: ");
	serial_put_hex(data_l);
	serial_puts("\n");

	/* read the interrupt status from SDRAM_DENALI_CTL_161 */
	data_l = IO_READ(SDRAM_DENALI_CTL_161);
	serial_puts("SDRAM_DENALI_CTL_161: ");
	serial_put_hex(data_l);
	serial_puts("\n\n");

	return RET_OK;

}	/*end of task denali_sdram_train_wr_data */

int write_sdram_mem(unsigned int addr, unsigned long long *wr_data, int count)
{
/*----------------------------------------------------------------------------*/
	unsigned int i, val;
	unsigned long long *paddr = (unsigned long long *)addr;

	if (show_dbg_message == 1){
		serial_puts("Started SDRAM transaction of write burst ");
		serial_put_decimal(8);
		serial_puts("\n");
	}

	for (i = 0; i < count; i++) {
		paddr[i] = wr_data[i];
		if (show_dbg_message == 1){
			val = paddr[i] & 0xFFFFFFFF;
			serial_puts("SDRAM ADDR = ");
			serial_put_hex((unsigned int)paddr + i * 8);
			serial_puts(" and Data = ");
			val = (unsigned int)(paddr[i] >> 32);
			serial_put_hex(val);
			val = (unsigned int)(paddr[i] & 0xFFFFFFFF);
			serial_put_hex_no_0x(val);
			serial_puts("\n");
		}

	}

	return RET_OK;
}				/*end of task write_sdram_mem */

unsigned int denali_sdram_size(void)
{

	unsigned long long wr_data[16], wr_pattern[3];
	unsigned int cpu_readback0, cpu_readback1;
	unsigned int cpu_pattern0, cpu_pattern1, cpu_pattern2;
	unsigned int sdram_address;
	unsigned char lpddr2_type, lpddr2_io_width;
	unsigned char lpddr2_density;
	unsigned int memory_size = 0, tmp;
	unsigned int time_stamp;

	wr_pattern[0] = 0xFCFDFEF703020108ULL;
	wr_pattern[1] = 0xF8F9FAFB07060504ULL;
	wr_pattern[2] = 0xECEDEEEF13121110ULL;
	wr_data[0] = wr_pattern[0];
	wr_data[1] = wr_pattern[1];
	wr_data[2] = wr_pattern[2];
	cpu_pattern0 = 0x03020108;	/*  lower 32bits of wr_pattern[0] */
	cpu_pattern1 = 0x07060504;	/*  lower 32bits of wr_pattern[1] */
	cpu_pattern2 = 0x13121110;	/*  lower 32bits of wr_pattern[2] */

	denali_cntl_00.wrd = IO_READ(SDRAM_DENALI_CTL_000);

	denali_cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);

	denali_cntl_07.wrd = IO_READ(SDRAM_DENALI_CTL_070);
	denali_cntl_071.wrd = IO_READ(SDRAM_DENALI_CTL_071);

	denali_cntl_14.wrd = IO_READ(SDRAM_DENALI_CTL_140);
	denali_cntl_141.wrd = IO_READ(SDRAM_DENALI_CTL_141);

	/*-------------------------------------------------------------------------*/
	/*    First part: DDR3 */
	/*-------------------------------------------------------------------------*/
	if (denali_cntl_00.bf.dram_class0 != 0x5) {	/*  DDR2 and DDR3, not support 512Mb and below */
		/*  write pattern to expected overlapping address */
		if (detected_16bit_mode == 1) {	/*  16 bit mode */
			/*  write one 64bits data into SDRAM */
			sdram_address = SDRAM_BASE + 0x04000000;	/*  A[26]=1; bank1 */
			wr_data[0] = wr_pattern[0];
			write_sdram_mem(sdram_address, wr_data, 1);
			/*  write one 64bits data into SDRAM */
			sdram_address = SDRAM_BASE + 0x05000000;	/*  A[25:24]=01 */
			wr_data[0] = wr_pattern[1];
			write_sdram_mem(sdram_address, wr_data, 1);
			/*  write one 64bits data into SDRAM */
			sdram_address = SDRAM_BASE + 0x06000000;	/*  A[25:24]=10 */
			wr_data[0] = wr_pattern[2];
			write_sdram_mem(sdram_address, wr_data, 1);
		} else {	/*  32 bit mode */
			/*  write one 64bits data into SDRAM */
			sdram_address = SDRAM_BASE + 0x08000000;	/*  A[27]=1; bank1 */
			wr_data[0] = wr_pattern[0];
			write_sdram_mem(sdram_address, wr_data, 1);
			/*  write one 64bits data into SDRAM */
			sdram_address = SDRAM_BASE + 0x0A000000;	/*  A[26:25]=01 */
			wr_data[0] = wr_pattern[1];
			write_sdram_mem(sdram_address, wr_data, 1);
			/*  write one 64bits data into SDRAM */
			sdram_address = SDRAM_BASE + 0x0C000000;	/*  A[26:25]=10 */
			wr_data[0] = wr_pattern[2];
			write_sdram_mem(sdram_address, wr_data, 1);
		}

		/*  Important! Make sure write finished before read it back. */
		/*repeat(50) @(negedge i_arml2port1.clk); */
		/* Important! Software should wait at leat 1 us here */
		time_stamp = get_timer(0);
		while (get_timer(time_stamp) <= 0) ;

		if (detected_16bit_mode == 1) {	/*  16 bit mode */
			/*  read back A[25:24]=00 to check fix pattern */
			sdram_address = SDRAM_BASE + 0x04000000;
			cpu_readback0 = cpu_read_sdram_mem_32bit(sdram_address);

			/*  read back A[25:24]=01 to check fix pattern */
			sdram_address = SDRAM_BASE + 0x05000000;
			cpu_readback1 = cpu_read_sdram_mem_32bit(sdram_address);

			if (cpu_readback0 == cpu_pattern2) {
				if (cpu_readback1 == cpu_pattern1)
					memory_size = 256;
				else
					memory_size = 128;

			}
			if (cpu_readback0 == cpu_pattern0)
				memory_size = 512;

		} else {	/*  32 bit mode */
			/*  read back A[26:25]=00 to check fix pattern */
			sdram_address = SDRAM_BASE + 0x08000000;
			cpu_readback0 = cpu_read_sdram_mem_32bit(sdram_address);

			/*  read back A[26:25]=01 to check fix pattern */
			sdram_address = SDRAM_BASE + 0x0A000000;
			cpu_readback1 = cpu_read_sdram_mem_32bit(sdram_address);

			if (cpu_readback0 == cpu_pattern2) {
				if (cpu_readback1 == cpu_pattern1)
					memory_size = 256 * 2;
				else
					memory_size = 128 * 2;

			}
			if (cpu_readback0 == cpu_pattern0)
				memory_size = 512 * 2;

		}

		if (detected_16bit_mode == 1) {	/*  16 bit mode */
			if (memory_size == 128) {
				denali_cntl_14.bf.ADDR_PINS0 = 0x2;
				if (denali_cntl_00.bf.dram_class0 == 0x6) 	/*  DDR3 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(11 * ddr_freq, 200) + 1;	/*  110ns+1=10'h2d */
				else 	/*  DDR2 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(8 * ddr_freq, 125) + 1;	/*  128ns=10'h34 */

			}
			if (memory_size == 256) {
				denali_cntl_14.bf.ADDR_PINS0 = 0x1;
				if (denali_cntl_00.bf.dram_class0 == 0x6) 	/*  DDR3 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(2 * ddr_freq, 25) + 1;	/*  160ns+1=10'h41 */
				else 	/*  DDR2 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(39 * ddr_freq, 400) + 1;	/*  195ns+1=10'h4f */

			}
			if (memory_size == 512) {
				denali_cntl_14.bf.ADDR_PINS0 = 0x0;
				if (denali_cntl_00.bf.dram_class0 == 0x6) 	/*  DDR3 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(3 * ddr_freq, 20) + 1;	/*  300ns+1=10'h79 */
				else 	/*  DDR2 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(131 * ddr_freq, 800) + 1;	/*  327.5ns=10'h84 */

			}
			if (memory_size == 1024) {
				serial_puts
				    ("ERROR: We don't support DDR2/DDR3 8Gb\n");
				return RET_ERR;
			}
		} else {	/*  32 bit mode */
			if (memory_size == 128) {
				serial_puts
				    ("ERROR: We only support DDR2/DDR3 1Gb and larger\n");
				return RET_ERR;
			}
			if (memory_size == 256) {
				denali_cntl_14.bf.ADDR_PINS0 = 0x2;
				if (denali_cntl_00.bf.dram_class0 == 0x6) 	/*  DDR3 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(11 * ddr_freq, 200) + 1;	/*  110ns+1=10'h2d */
				else 	/*  DDR2 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(8 * ddr_freq, 125) + 1;	/*  128ns=10'h34 */

			}
			if (memory_size == 512) {
				denali_cntl_14.bf.ADDR_PINS0 = 0x1;
				if (denali_cntl_00.bf.dram_class0 == 0x6) 	/*  DDR3 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(2 * ddr_freq, 25) + 1;	/*  160ns+1=10'h41 */
				else 	/*  DDR2 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(39 * ddr_freq, 400) + 1;	/*  195ns+1=10'h4f */

			}
			if (memory_size == 1024) {
				denali_cntl_14.bf.ADDR_PINS0 = 0x0;
				if (denali_cntl_00.bf.dram_class0 == 0x6) 	/*  DDR3 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(3 * ddr_freq, 20) + 1;	/*  300ns+1=10'h79 */
				else 	/*  DDR2 */
					denali_cntl_07.bf.TRFC0 = sdram_uidiv(131 * ddr_freq, 800) + 1;	/*  327.5ns=10'h84 */

			}
		}
	}

	/*-------------------------------------------------------------------------*/
	/*    Second part: LPDDR2 			*/
	/*-------------------------------------------------------------------------*/
	if (denali_cntl_00.bf.dram_class0 == 0x5) {	/*  LPDDR2, not support x8 device */
		/*    read CNTL_57 */
		denali_cntl_571.wrd = IO_READ(SDRAM_DENALI_CTL_571);
		lpddr2_type = denali_cntl_571.wrd >> (56 - 32) & 0x3;	/*[57:56]; */
		lpddr2_density = denali_cntl_571.wrd >> (58 - 32) & 0xF;	/*[61:58]; */
		lpddr2_io_width = denali_cntl_571.wrd >> (62 - 32) & 0x3;	/*[63:62]; */

		if ((lpddr2_type == 0x2) || (lpddr2_type == 0x3)) {
			serial_puts("ERROR: No LPDDR2 SDRAM type detected\n");
			return RET_ERR;
		}
		if ((lpddr2_io_width == 0x2) || (lpddr2_io_width == 0x3)) {
			serial_puts
			    ("ERROR: We only support x16 and x32 LPDDR2 at this moment\n");
			return RET_ERR;
		}

		denali_cntl_07.bf.TRFC0 = sdram_uidiv(13 * ddr_freq, 200) + 1;	/*  130ns+1=10'h35 */

		denali_cntl_07.bf.TREF0 = (sdram_uidiv(39 * ddr_freq, 20) + 1) & 0xFF;	/*  3.9us+1=14'hc31 */
		denali_cntl_071.bf.TREF1 = ((sdram_uidiv(39 * ddr_freq, 20) + 1) >> 8) & 0xFF;

		if (lpddr2_density == 0x4) {	/*  1Gb */
			if (lpddr2_type == 0x1) 	/*  S2 */
				denali_cntl_14.bf.ADDR_PINS0 = 0x1;
			else 	/*  S4 */
				denali_cntl_14.bf.ADDR_PINS0 = 0x2;

			if (lpddr2_io_width == 0x0) 	/*  x32 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x2;
			else 	/*  x16 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x1;
			memory_size= 128;
			denali_cntl_07.bf.TREF0 = (sdram_uidiv(39 * ddr_freq, 10) + 1) & 0xFF;	/*  7.8us+1=14'hc31 */
			denali_cntl_071.bf.TREF1 = ((sdram_uidiv(39 * ddr_freq, 10) + 1) >> 8) & 0xFF;
		} else if (lpddr2_density == 0x5) {	/*  2Gb */
			if (lpddr2_type == 0x1) 	/*  S2 */
				denali_cntl_14.bf.ADDR_PINS0 = 0x0;
			else 	/*  S4 */
				denali_cntl_14.bf.ADDR_PINS0 = 0x1;

			if (lpddr2_io_width == 0x0) 	/*  x32 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x2;
			else 	/*  x16 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x1;
			memory_size = 256;

		} else if (lpddr2_density == 0x6) {	/*  4Gb */
			denali_cntl_14.bf.ADDR_PINS0 = 0x1;
			if (lpddr2_io_width == 0x0) 	/*  x32 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x1;
			else 	/*  x16 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x0;
			
			memory_size = 512;

		} else if (lpddr2_density == 0x7) {	/*  8Gb */
			denali_cntl_14.bf.ADDR_PINS0 = 0x0;
			if (lpddr2_io_width == 0x0) 	/*  x32 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x1;
			else 	/*  x16 device */
				denali_cntl_141.bf.COLUMN_SIZE1 = 0x0;

			memory_size = 1024;
			denali_cntl_07.bf.TRFC0 = sdram_uidiv(21 * ddr_freq, 200) + 1;	/*  210ns+1=10'h55 */
		} else {
			serial_puts
			    ("ERROR: We only support 1Gb, 2Gb, 4Gb and 8Gb at this moment\n");
			return RET_ERR;
		}

	}

	serial_puts("Memory size detected as ");
	serial_put_decimal(memory_size);
	serial_puts(" Mbyte\n");

	/*-------------------------------------------------------------------------*/
	/*    Third part: Program Denali registers 				*/
	/*-------------------------------------------------------------------------*/
	/*    read CNTL_14 */

	/*    write CNTL_14 with valid row/column pins */
	IO_WRITE(SDRAM_DENALI_CTL_140, denali_cntl_14.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_141, denali_cntl_141.wrd);

	/*    read CNTL_07 */

	/*    write CNTL_07 with valid tRFC and tREF */
	IO_WRITE(SDRAM_DENALI_CTL_070, denali_cntl_07.wrd);
	IO_WRITE(SDRAM_DENALI_CTL_071, denali_cntl_071.wrd);

	tmp = IO_READ(GLOBAL_SOFTWARE2);
	tmp |= memory_size << 20;
	IO_WRITE(GLOBAL_SOFTWARE2, tmp);

	return RET_OK;
}				/*end of task denali_sdram_size */

int set_ddr_freq(unsigned int freq)
{
	GLOBAL_BLOCK_RESET_t glb_blk_rst;
	GLOBAL_DDR_PLL_t glb_ddr_pll;
	GLOBAL_ARM_STATE_t glb_arm_stat;
	unsigned short m;
	unsigned char s = 1, p = 6, vsel = 1;
	unsigned int time_stamp;

	if ((freq > 1000) || (freq < 263))
		return RET_ERR;

	if (freq >= 500) {
		m = freq / 2;
		p = 6;
		s = 1;
		if (freq <= 700)
			vsel = 0;
	} else {
		m = (freq << 2) / 3;
		p = 8;
		s = 2;
		if (freq <= 350)
			vsel = 0;
#if 0
		if (freq == 450)
			m = 600;
		if (freq == 413)
			m = 550;
		if (freq == 375)
			m = 500;
		if (freq == 338) {
			m = 450;
			vsel = 0;
		}
		if (freq == 300) {
			m = 400;
			vsel = 0;
		}
		if (freq == 263) {
			m = 350;
			vsel = 0;
		}
#endif
	}

	/* Reset PHY */
	glb_ddr_pll.wrd = IO_READ(GLOBAL_DDR_PLL);
	glb_ddr_pll.bf.ddr_phy_reset = 1;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);

	/* Reset Controller */
	glb_blk_rst.wrd = IO_READ(GLOBAL_BLOCK_RESET);
	glb_blk_rst.bf.reset_sdram = 1;
	IO_WRITE(GLOBAL_BLOCK_RESET, glb_blk_rst.wrd);

	/* Disable */
	glb_ddr_pll.bf.enable = 0;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);
	/* reset = 1 */
	glb_ddr_pll.bf.reset = 1;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);

	/* program m/s/p/v_sel */
	glb_ddr_pll.bf.m = m;
	glb_ddr_pll.bf.s = s;
	glb_ddr_pll.bf.p = p;
	glb_ddr_pll.bf.vsel = vsel;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);

	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;	/* Delay 1ms for precaution. */

	/* reset = 0 */
	glb_ddr_pll.bf.reset = 0;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);

	/* Poll pll3_lock */
	glb_arm_stat.wrd = IO_READ(GLOBAL_ARM_STATE);
	while (glb_arm_stat.bf.pll3_lock == 0)
		glb_arm_stat.wrd = IO_READ(GLOBAL_ARM_STATE);


	/* Enable */
	glb_ddr_pll.bf.enable = 1;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);

	/* Clear PHY reset */
	glb_ddr_pll.bf.ddr_phy_reset = 0;
	IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);

	/* Clear Denali Reset */
	glb_blk_rst.bf.reset_sdram = 0;
	IO_WRITE(GLOBAL_BLOCK_RESET, glb_blk_rst.wrd);

	return RET_OK;
}

int g2_ddr_freq(int argc, char **argv)
{
	int freq;

	if (argc < 2)
		return RET_ERR;

	freq = iros_strtol(argv[1]);
	return set_ddr_freq(freq);

}

int g2_eye_loop(int argc, char **argv)
{
	register unsigned int *addr asm("r4");
	register unsigned int r5 asm("r5");
	register unsigned int r6 asm("r6");
	register unsigned int r7 asm("r7");
	register unsigned int r8 asm("r8");
	int rw, i = 0;
	volatile unsigned int val;
	unsigned char key_id = 0;
	volatile unsigned int pattern[8];

	pattern[0] = 0x03020108;
	pattern[1] = 0xFCFDFEF7;
	pattern[2] = 0x07060504;
	pattern[3] = 0xF8F9FAFB;
	pattern[4] = 0x13121110;
	pattern[5] = 0xECEDEEEF;
	pattern[6] = 0x17161514;
	pattern[7] = 0xE8E9EAEB;

	if (argc < 3)
		return RET_ERR;

	rw = iros_strtol(argv[1]);
	addr = (unsigned int *)iros_strtol(argv[2]);

	if (rw == 1) {		/* Read */
		while (1) {
			val = *addr;

			if ((i++ & 0x7FFF) == 0x0) {
				if (key_id == '-')
					key_id = '|';
				else
					key_id = '-';
				serial_putc(key_id);
				serial_puts("\r");
				if (user_escape() == 1) {	/* ^C or ESC */
					/* User wnat to break */
					return RET_OK;
				}
			}
		}
	} else {		/* Write */
		for (i = 0; i < (argc - 3); i++) {
			pattern[i] = iros_strtol(argv[3 + i]);
		}
//		addr = (unsigned int *)iros_strtol(argv[2]);
		i = 0;
		while (1) {

			r5 = pattern[(i & 1) * 4 + 0];
			r6 = pattern[(i & 1) * 4 + 1];
			r7 = pattern[(i & 1) * 4 + 2];
			r8 = pattern[(i & 1) * 4 + 3];

			asm volatile("stm    %0! ,{%1,%2,%3,%4}"   "\n\t"
				:
				:"r"(addr),"r"(r5),"r"(r6),"r"(r7),"r"(r8)
				: "memory");

			if ((i & 1))
				addr -= 8;

			if ((i & 0x7FFF) == 0x0) {
				if (key_id == '-')
					key_id = '|';
				else
					key_id = '-';
				serial_putc(key_id);
				serial_puts("\r");
				if (user_escape() == 1) {	/* ^C */
					/* User wnat to break */
					return RET_OK;
				}
			}

			i++;

		}

	}

	return RET_OK;

}

int g2_reg_wr(int argc, char **argv)
{
	unsigned int *addr;
	int i;
	volatile unsigned int val;

	if (argc < 3)
		return RET_ERR;

	addr = (unsigned int *)iros_strtol(argv[1]);
	for (i = 0; i < (argc - 2); i++) {
		val = iros_strtol(argv[i + 2]);
		*addr++ = val;
	}
	wmb();

	addr = (unsigned int *)iros_strtol(argv[1]);
	for (i = 0; i < (argc - 2); i++, addr++) {
		val = *addr;
		serial_put_hex((unsigned int)addr);
		serial_puts(": ");
		serial_put_hex(val);
		serial_puts("\n");
	}

	return RET_OK;

}

int g2_ddr_reg_init(int argc, char **argv)
{
	int i;
	unsigned int opt[6] = { 0, 0, 0, 0, 0, 0 };

	/* TODO: Need option */
	for (i = 0; i < (argc - 1); i++)
		opt[i] = iros_strtol(argv[i + 1]);


	/* Init DRAM Controller */
	denali_sdram_cntl_config(TYPE_DDR3);
	/* Init DDR PHY */
	denali_sdram_phy_config(TYPE_DDR3);

	return RET_OK;
}

int g2_ddr_start(void)
{
	unsigned int reg_v;

	/*  read CNTL_00 */
	reg_v = IO_READ(SDRAM_DENALI_CTL_000);
	reg_v |= 0x00000001;
	IO_WRITE(SDRAM_DENALI_CTL_000, reg_v);

	/*  Now wait for initialization to complete */
	denali_sdram_init_done();

	return RET_OK;
}

int g2_wr_ddr_pat(void)
{
	sdram_pattern_write();

	return RET_OK;
}

int g2_tr_rd(int argc, char **argv)
{
	reg_save_t save_reg[2];
	unsigned int *addr, tmp;
	SDRAM_DENALI_CTL_440_t cntl_44;
	SDRAM_PHY_CTL_68_0_t phy_68;


	if (argc >= 2) {
		/* catch any argument string starting with 'a'
		 * or 'A'.  If there is, enable display all.
		 */
		if ((*argv[1] == 'a') || (*argv[1] == 'A')) {
			display_all = 1;
			if (argc == 3)
				loop_check_cnt = iros_strtol(argv[2]);
		} else {
			loop_check_cnt = iros_strtol(argv[1]);
			if ((*argv[2] == 'a') || (*argv[2] == 'A'))
				display_all = 1;
		}
	}

	addr = (unsigned int *)RRAM0_BASE;
	memset(save_reg, 0, sizeof(save_reg));

	/* Save register content */
	phy_68.wrd = IO_READ(SDRAM_PHY_CTL_68_0);
	save_reg[0].addr = SDRAM_PHY_CTL_68_0;
	save_reg[0].reg_v = phy_68.wrd;
	save_reg[0].pglobal = (unsigned int *)&sphy_cntl_68;

	memcpy(addr, save_reg, sizeof(save_reg));	/* Save register content to RRAM0 */

	/* Set denali_cntl_44.bf.RDLAT_ADJ0 = 0x14  */
	cntl_44.wrd = IO_READ(SDRAM_DENALI_CTL_440);
	tmp = cntl_44.wrd;
	cntl_44.bf.RDLAT_ADJ0 = 0x14;
	IO_WRITE(SDRAM_DENALI_CTL_440, cntl_44.wrd);

	show_type = SHOW_TYPE_TR_RD;
	/* train... */
	denali_sdram_train_rd_strobe();

	/* Restore control_44 */
	IO_WRITE(SDRAM_DENALI_CTL_440, tmp);

	loop_check_cnt = DEFAULT_LOOP_CNT;
	show_type = SHOW_TYPE_DEF;
	display_all = 0;

	return RET_OK;
}

int g2_tr_lat(int argc, char **argv)
{
	reg_save_t save_reg[3];
	unsigned int *addr;
	SDRAM_DENALI_CTL_160_t cntl_16;
	SDRAM_DENALI_CTL_440_t cntl_44;

	if (argc == 2)
		loop_check_cnt = iros_strtol(argv[1]);

	addr = (unsigned int *)RRAM0_BASE;
	memset(save_reg, 0, sizeof(save_reg));

	/* Save register content */
	cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);
	save_reg[0].addr = SDRAM_DENALI_CTL_160;
	save_reg[0].reg_v = cntl_16.wrd;
	save_reg[0].pglobal = (unsigned int *)&denali_cntl_16;

	cntl_44.wrd = IO_READ(SDRAM_DENALI_CTL_440);
	save_reg[1].addr = SDRAM_DENALI_CTL_440;
	save_reg[1].reg_v = cntl_44.wrd;
	save_reg[1].pglobal = (unsigned int *)&denali_cntl_44;

	memcpy(addr, save_reg, sizeof(save_reg));	/* Save register content to RRAM0 */

	show_type = SHOW_TYPE_TR_LAT;
	/* train... */
	denali_sdram_train_rd_latency();

	loop_check_cnt = DEFAULT_LOOP_CNT;
	show_type = SHOW_TYPE_DEF;

	return RET_OK;
}

int g2_tr_gat(int argc, char **argv)
{
	reg_save_t save_reg[3];
	unsigned int *addr;
	SDRAM_DENALI_CTL_160_t cntl_16;
	SDRAM_PHY_CTL_67_0_t phy_67;

	if (argc >= 2) {
		/* catch any argument string starting with 'a'
		 * or 'A'.  If there is, enable display all.
		 */
		if ((*argv[1] == 'a') || (*argv[1] == 'A')) {
			display_all = 1;
			if (argc == 3)
				loop_check_cnt = iros_strtol(argv[2]);
		} else {
			loop_check_cnt = iros_strtol(argv[1]);
			if ((*argv[2] == 'a') || (*argv[2] == 'A'))
				display_all = 1;
		}
	}

	addr = (unsigned int *)RRAM0_BASE;
	memset(save_reg, 0, sizeof(save_reg));

	/* Save register content */
	cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);
	save_reg[0].addr = SDRAM_DENALI_CTL_160;
	save_reg[0].reg_v = cntl_16.wrd;
	save_reg[0].pglobal = (unsigned int *)&denali_cntl_16;

	phy_67.wrd = IO_READ(SDRAM_PHY_CTL_67_0);
	save_reg[1].addr = SDRAM_PHY_CTL_67_0;
	save_reg[1].reg_v = phy_67.wrd;
	save_reg[1].pglobal = (unsigned int *)&sphy_cntl_67;

	memcpy(addr, save_reg, sizeof(save_reg));	/* Save register content to RRAM0 */

	show_type = SHOW_TYPE_TR_GAT;
	/* train... */
	denali_sdram_train_gateo();

	loop_check_cnt = DEFAULT_LOOP_CNT;
	show_type = SHOW_TYPE_DEF;
	display_all = 0;

	return RET_OK;
}

int g2_tr_wr(int argc, char **argv)
{
	reg_save_t save_reg[3];
	unsigned int *addr;
	SDRAM_DENALI_CTL_160_t cntl_16;
	SDRAM_PHY_CTL_68_1_t phy_68;

	if (argc >= 2) {
		/* catch any argument string starting with 'a'
		 * or 'A'.  If there is, enable display all.
		 */
		if ((*argv[1] == 'a') || (*argv[1] == 'A')) {
			display_all = 1;
			if (argc == 3)
				loop_check_cnt = iros_strtol(argv[2]);
		} else {
			loop_check_cnt = iros_strtol(argv[1]);
			if ((*argv[2] == 'a') || (*argv[2] == 'A'))
				display_all = 1;
		}
	}

	addr = (unsigned int *)RRAM0_BASE;
	memset(save_reg, 0, sizeof(save_reg));

	/* Save register content */
	cntl_16.wrd = IO_READ(SDRAM_DENALI_CTL_160);
	save_reg[0].addr = SDRAM_DENALI_CTL_160;
	save_reg[0].reg_v = cntl_16.wrd;
	save_reg[0].pglobal = (unsigned int *)&denali_cntl_16;

	phy_68.wrd = IO_READ(SDRAM_PHY_CTL_68_1);
	save_reg[1].addr = SDRAM_PHY_CTL_68_1;
	save_reg[1].reg_v = phy_68.wrd;
	save_reg[1].pglobal = (unsigned int *)&sphy_cntl_68;

	memcpy(addr, save_reg, sizeof(save_reg));	/* Save register content to RRAM0 */

	show_type = SHOW_TYPE_TR_WR;
	/* train... */
	denali_sdram_train_wr_data();

	loop_check_cnt = DEFAULT_LOOP_CNT;
	show_type = SHOW_TYPE_DEF;
	display_all = 0;

	return RET_OK;
}

int g2_ddr_size(int argc, char **argv)
{
	unsigned int reg_v;

	denali_sdram_size();
	serial_puts("addr_pin= ");
	serial_put_decimal(denali_cntl_14.bf.ADDR_PINS0);
	serial_puts("  trfc= ");
	serial_put_decimal(denali_cntl_07.bf.TRFC0);

	reg_v = IO_READ(SDRAM_DENALI_CTL_140);
	serial_puts("\nSDRAM_DENALI_CTL_140= ");
	serial_put_hex(reg_v);

	reg_v = IO_READ(SDRAM_DENALI_CTL_141);
	serial_puts("\nSDRAM_DENALI_CTL_141= ");
	serial_put_hex(reg_v);

	reg_v = IO_READ(SDRAM_DENALI_CTL_070);
	serial_puts("\nSDRAM_DENALI_CTL_070= ");
	serial_put_hex(reg_v);

	return RET_OK;
}

int g2_ddr_rst(int argc, char **argv)
{
	GLOBAL_BLOCK_RESET_t glb_blk_rst;
	GLOBAL_DDR_PLL_t glb_ddr_pll;
	unsigned int time_stamp;
	unsigned char rst_opt = 0x03;	/* Reset Controller & PHY if no arg.. */

	if (argc >= 2)
		rst_opt = iros_strtol(argv[1]);	/*Bit0: reset Controller.  Bit1: reset PHY */

	if (rst_opt & 0x2) {
		/* Reset PHY */
		glb_ddr_pll.wrd = IO_READ(GLOBAL_DDR_PLL);
		glb_ddr_pll.bf.ddr_phy_reset = 1;
		IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);
	}

	if (rst_opt & 0x01) {
		/* Reset Controller */
		glb_blk_rst.wrd = IO_READ(GLOBAL_BLOCK_RESET);
		glb_blk_rst.bf.reset_sdram = 1;
		IO_WRITE(GLOBAL_BLOCK_RESET, glb_blk_rst.wrd);
	}

	time_stamp = get_timer(0);
	while (get_timer(time_stamp) <= 0) ;	/* Delay 1ms for precaution. */

	if (rst_opt & 0x02) {
		/* Clear PHY Reset */
		glb_ddr_pll.bf.ddr_phy_reset = 0;
		IO_WRITE(GLOBAL_DDR_PLL, glb_ddr_pll.wrd);
	}

	if (rst_opt & 0x01) {
		/* Clear Denali Reset */
		glb_blk_rst.bf.reset_sdram = 0;
		IO_WRITE(GLOBAL_BLOCK_RESET, glb_blk_rst.wrd);
	}

	return RET_OK;
}

int print_saved_reg(void)
{
	int i = 0;
	unsigned int reg_v;
	reg_save_t *save_reg = (reg_save_t *) RRAM0_BASE;

	while (save_reg[i].addr != 0) {
		serial_puts("\nADDR :");
		serial_put_hex(save_reg[i].addr);

		/* Display register content before and after training */
		serial_puts("\nVAL  :");
		serial_put_hex(save_reg[i].reg_v);
		serial_puts(" --> ");
		reg_v = IO_READ(save_reg[i].addr);
		serial_put_hex(reg_v);
		serial_puts("\n");

		/* Restore saved content to HW register */
		IO_WRITE(save_reg[i].addr, save_reg[i].reg_v);
		*(volatile unsigned int *)save_reg[i].pglobal =
		    save_reg[i].reg_v;

		i++;
	}

	return i;

}

int g2_long_test1(int argc, char **argv)
{
	int i = 0;
	unsigned char use_16mb = 0;

	if (argc >= 2) {
			if ((*argv[1] == 's') || (*argv[1] == 'S'))
					use_16mb = 1;
	}

	while (1) {
		post_cmd_in_function("g2_wr_ddr_pat");

		post_cmd_in_function("g2_tr_rd");
		print_saved_reg();

		post_cmd_in_function("g2_tr_lat");
		print_saved_reg();

		post_cmd_in_function("g2_tr_gat");
		print_saved_reg();

		post_cmd_in_function("g2_tr_wr");
		print_saved_reg();

		/* FIXME, Change DRAM BASE for ASIC! */
		if (use_16mb == 1)
			post_cmd_in_function("t 9 0x00800000 0x4000000 1");
		else
			post_cmd_in_function("t 9 0x00800000 0x10000000 1");

		if ((i++ & 0xFFF) == 0) {
			if (user_escape() == 1)
				break;
		}

	}

	return RET_OK;
}

int g2_start_zq(int argc, char **argv)
{
	int i = 0;
	int loop = 1, interval = 10000;
	unsigned int time_stamp;

	if (argc > 2)
		interval = iros_strtol(argv[2]) * 1000;	/* Second base */

	if (argc > 1)
		loop = iros_strtol(argv[1]);

	for (i = 0; i < loop; i++) {
		sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
		serial_puts("\nSDRAM_PHY_CTL_70_1: ");
		serial_put_hex(sphy_cntl_701.wrd);
		restart_zq_calibration();
		sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
		serial_puts(" --> ");
		serial_put_hex(sphy_cntl_701.wrd);
		time_stamp = get_timer(0);
		while (get_timer(time_stamp) < (interval)) ;
	}

	return RET_OK;
}

int g2_force_zq(int argc, char **argv)
{
	unsigned char impp, impn;

	if (argc < 3)
		return RET_ERR;

	impp = iros_strtol(argv[1]);
	impn = iros_strtol(argv[2]);

	sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
	serial_puts("\nSDRAM_PHY_CTL_70_1: ");
	serial_put_hex(sphy_cntl_701.wrd);
	force_zq_pmos_nmos(impp, impn);
	sphy_cntl_701.wrd = IO_READ(SDRAM_PHY_CTL_70_1);
	serial_puts(" --> ");
	serial_put_hex(sphy_cntl_701.wrd);

	return RET_OK;
}

int g2_start_dll(int argc, char **argv)
{
	int i = 0;
	SDRAM_PHY_CTL_66_1_t phy_cntl_661;
	int loop = 1, interval = 10000;
	unsigned int time_stamp;

	if (argc > 2)
		interval = iros_strtol(argv[2]) * 1000;

	if (argc > 1)
		loop = iros_strtol(argv[1]);

	for (i = 0; i < loop; i++) {
		phy_cntl_661.wrd = IO_READ(SDRAM_PHY_CTL_66_1);
		serial_puts("\nSDRAM_PHY_CTL_66_1: ");
		serial_put_hex(phy_cntl_661.wrd);
		restart_dll_lock();
		phy_cntl_661.wrd = IO_READ(SDRAM_PHY_CTL_66_1);
		serial_puts(" --> ");
		serial_put_hex(phy_cntl_661.wrd);
		time_stamp = get_timer(0);
		while (get_timer(time_stamp) < (interval)) ;
	}

	return RET_OK;
}

int g2_dbg_on(int argc, char **argv)
{

	if (argc < 2)
		return RET_ERR;

	show_dbg_message = iros_strtol(argv[1]);
	show_dbg_message &= 0x01;

	return RET_OK;
}

int g2_ddr_set_default_conf(int argc, char **argv)
{
	int new_freq;

	ddr_freq = DEFAULT_DDR_FREQ;

	if (argc == 2) {
		new_freq = iros_strtol(argv[1]);
		if ((new_freq > 1000) || (new_freq < 263)) {
			serial_puts("out of range freq\n");
			return RET_ERR;
		}
		ddr_freq = new_freq;
	}

	denali_sdramdriver_set_default_conf();

	return RET_OK;
}

int g2_start_init(int argc, char **argv)
{
	int new_freq;

	ddr_freq = DEFAULT_DDR_FREQ;

	if (argc == 2) {
		new_freq = iros_strtol(argv[1]);
		if ((new_freq > 1000) || (new_freq < 263)) {
			serial_puts("out of range freq\n");
			return RET_ERR;
		}
		ddr_freq = new_freq;
	}

	denali_sdramdriver_initialize();
	return RET_OK;
}
