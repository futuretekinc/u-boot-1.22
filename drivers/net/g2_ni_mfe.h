/***********************************************************************/
/* This file contains unpublished documentation and software           */
/* proprietary to Cortina Systems Incorporated. Any use or disclosure, */
/* in whole or in part, of the information in this file without a      */
/* written consent of an officer of Cortina Systems Incorporated is    */
/* strictly prohibited.                                                */
/* Copyright (c) 2010 by Cortina Systems Incorporated.                 */
/***********************************************************************/
/*
 *
 * g2_ni_mfe.h
 *
 * $Id: g2_ni_mfe.h,v 1.4 2012/11/30 06:00:32 alee Exp $
 */
#ifndef __G2_NI_MFE_H
#define __G2_NI_MFE_H

#include <asm/types.h>
#include <config.h>
#include <registers.h>

#define G2_DBG 0

#ifdef CS_BIG_ENDIAN
#define CRCPOLY_BE 						0x04c11db7
#else /* CS_LITTLE_ENDIAN */
#define CRCPOLY_LE 						0xedb88320
#endif

#define CS_SWAP32(x) (((x & 0xFF000000) >> 24)    \
                          | ((x  & 0xFF0000) >> 8)   \
                          | ((x  & 0xFF00) << 8)     \
                          | ((x  & 0xFF)<< 24))

/* XRAM BASE ADDRESS */
#define NI_XRAM_BASE 					0xF0400000
#define GET_NI_XRAM_BASE() 				(NI_XRAM_BASE)

#ifdef	CONFIG_CS75XX_PHY_ADDR_GMAC0
#define GE_PORT0_PHY_ADDR			CONFIG_CS75XX_PHY_ADDR_GMAC0
#endif

#ifdef	CONFIG_CS75XX_PHY_ADDR_GMAC1
#define GE_PORT1_PHY_ADDR			CONFIG_CS75XX_PHY_ADDR_GMAC1
#endif

#ifdef	CONFIG_CS75XX_PHY_ADDR_GMAC2
#define GE_PORT2_PHY_ADDR			CONFIG_CS75XX_PHY_ADDR_GMAC2
#endif

#define PHY_ID_RTL8201				0x001cc810
#define PHY_ID_RTL8211				0x001cc910
#define PHY_ID_QCA8337				0x004dd035
#define PHY_ID_MASK					0xFFFFFFF0

/*
 * MFE registers and configuraitons
 */
#define RESET_NI 					0x1

#define INTF_RST_GE0 					(1)
#define INTF_RST_GE1 					(1 << 1)
#define INTF_RST_GE2 					(1 << 2)

#define INTF_CFG_GE0_MASK				0x00000037
#define INTF_CFG_GE1_MASK				0x00003700
#define INTF_CFG_GE2_MASK				0x00370000

#define GE0_MAC_INTF_MII				(1)
#define GE0_MAC_INTF_RGMII_1000				(2)
#define GE0_MAC_INTF_RGMII_100				(3)
#define GE0_MAC_INTF_RMII				(5)
#define GE0_RMII_CLKSRC_OUTPUT				(1 << 5)
#define GE1_MAC_INTF_MII				(1 << 8)
#define GE1_MAC_INTF_RGMII_1000				(2 << 8)
#define GE1_MAC_INTF_RGMII_100				(3 << 8)
#define GE1_MAC_INTF_RMII				(5 << 8)
#define GE1_RMII_CLKSRC_OUTPUT				(1 << 13)
#define GE2_MAC_INTF_MII				(1 << 16)
#define GE2_MAC_INTF_RGMII_1000				(2 << 16)
#define GE2_MAC_INTF_RGMII_100				(3 << 16)
#define GE2_MAC_INTF_RMII				(5 << 16)
#define GE2_RMII_CLKSRC_OUTPUT				(1 << 21)

#define GE0_TO_CPU 					0
#define GE1_TO_CPU 					0x01
#define GE2_TO_CPU 					0x02

#if 1
#if (CONFIG_UBOOT_CPU_TO_GMAC == 0)
#define PORT_TO_CPU_MSG					"GMAC0"
#define GE_PORT_PHY_ADDR				GE_PORT0_PHY_ADDR

#define INTF_RST_GE 					INTF_RST_GE0

#define INTF_CFG_GE_MASK				INTF_CFG_GE0_MASK

#define GE_MAC_INTF_MII					GE0_MAC_INTF_MII
#define GE_MAC_INTF_RGMII_1000				GE0_MAC_INTF_RGMII_1000
#define GE_MAC_INTF_RGMII_100				GE0_MAC_INTF_RGMII_100
#define GE_MAC_INTF_RMII				GE0_MAC_INTF_RMII
#define GE_RMII_CLKSRC_OUTPUT				GE0_RMII_CLKSRC_OUTPUT

#define GE_TO_CPU 					GE0_TO_CPU
#elif (CONFIG_UBOOT_CPU_TO_GMAC == 1)
#define PORT_TO_CPU_MSG					"GMAC1"
#define GE_PORT_PHY_ADDR				GE_PORT1_PHY_ADDR

#define INTF_RST_GE 					INTF_RST_GE1

#define INTF_CFG_GE_MASK				INTF_CFG_GE1_MASK

#define GE_MAC_INTF_MII					GE1_MAC_INTF_MII
#define GE_MAC_INTF_RGMII_1000				GE1_MAC_INTF_RGMII_1000
#define GE_MAC_INTF_RGMII_100				GE1_MAC_INTF_RGMII_100
#define GE_MAC_INTF_RMII				GE1_MAC_INTF_RMII
#define GE_RMII_CLKSRC_OUTPUT				GE1_RMII_CLKSRC_OUTPUT

#define GE_TO_CPU 					GE1_TO_CPU
#elif (CONFIG_UBOOT_CPU_TO_GMAC == 2)
#define PORT_TO_CPU_MSG					"GMAC2"
#define GE_PORT_PHY_ADDR				GE_PORT2_PHY_ADDR

#define INTF_RST_GE 					INTF_RST_GE2

#define INTF_CFG_GE_MASK				INTF_CFG_GE2_MASK

#define GE_MAC_INTF_MII					GE2_MAC_INTF_MII
#define GE_MAC_INTF_RGMII_1000				GE2_MAC_INTF_RGMII_1000
#define GE_MAC_INTF_RGMII_100				GE2_MAC_INTF_RGMII_100
#define GE_MAC_INTF_RMII				GE2_MAC_INTF_RMII
#define GE_RMII_CLKSRC_OUTPUT				GE2_RMII_CLKSRC_OUTPUT

#define GE_TO_CPU 					GE2_TO_CPU
#else
#define PORT_TO_CPU_MSG					"GMAC1"
#define GE_PORT_PHY_ADDR				GE_PORT1_PHY_ADDR

#define INTF_RST_GE 					INTF_RST_GE1

#define INTF_CFG_GE_MASK				INTF_CFG_GE1_MASK

#define GE_MAC_INTF_MII					GE1_MAC_INTF_MII
#define GE_MAC_INTF_RGMII_1000				GE1_MAC_INTF_RGMII_1000
#define GE_MAC_INTF_RGMII_100				GE1_MAC_INTF_RGMII_100
#define GE_MAC_INTF_RMII				GE1_MAC_INTF_RMII
#define GE_RMII_CLKSRC_OUTPUT				GE1_RMII_CLKSRC_OUTPUT

#define GE_TO_CPU 					GE1_TO_CPU
#endif
#endif

#define INTF_CFG_MFE 					0x00424242 /*2'b010 - 1xGE, RGMII mode*/

/*Defines the various configuration bits for Ethernet MACs.*/
/* 5 instances: base + ([0..4] * 8)  4 - MFE port */
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG0_0 + \
					(CONFIG_UBOOT_CPU_TO_GMAC * 12))
#if 0
#if CONFIG_UBOOT_CPU_TO_GMAC == 0
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG0_0)
#elif CONFIG_UBOOT_CPU_TO_GMAC == 1
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG0_0 + (1 * 12))
#elif CONFIG_UBOOT_CPU_TO_GMAC == 2
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG0_0 + (2 * 12))
#else
#define NI_TOP_NI_ETH_MAC_CONFIG0_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG0_0 + (1 * 12))
#endif
#endif

#define NI_TOP_NI_RTH_MAC_10M			1
#define NI_TOP_NI_RTH_MAC_100M			0
#define NI_TOP_NI_RTH_MAC_HALF			1
#define NI_TOP_NI_RTH_MAC_FULL			0

#define NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG2_0 + \
					(CONFIG_UBOOT_CPU_TO_GMAC * 12))
#if 0
#if CONFIG_UBOOT_CPU_TO_GMAC == 0
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG2_0)
#elif CONFIG_UBOOT_CPU_TO_GMAC == 1
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG2_0 + (1 * 12))
#elif CONFIG_UBOOT_CPU_TO_GMAC == 2
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG2_0 + (2 * 12))
#else
#define NI_TOP_NI_ETH_MAC_CONFIG2_0_MFE (NI_TOP_NI_ETH_MAC_CONFIG2_0 + (1 * 12))
#endif
#endif

/* Defines the base and top address in CPU XRAM for packets to cpu instance 0 */
#define RX_TOP_ADDR  					0x03FF	/* 0x400 * 8-byte = 8K-byte */
#define RX_BASE_ADDR 					0x0000
#define RX_MAX_ADDR_LOC 				0x07FF

/* Defines the base and top address in CPU XRAM for packets from cpu instance 0.*/
#define TX_TOP_ADDR  					0x04FF	/* 0x100 * 8-byte = 2K-byte */
#define TX_BASE_ADDR 					0x0400

#define RX_0_CPU_PKT_DIS 				(1 << 0)
#define TX_0_CPU_PKT_DIS 				(1 << 9)

#define PHY_POLL_TIMES					0x200

#define cs_uint32 	unsigned int


struct g2_ni_priv {
	unsigned int 	rx_xram_base_adr;
	unsigned int 	rx_xram_end_adr;
	unsigned short  rx_xram_start;
	unsigned short  rx_xram_end;
	unsigned int 	tx_xram_base_adr;
	unsigned int 	tx_xram_end_adr;
	unsigned short  tx_xram_start;
	unsigned short  tx_xram_end;
};


typedef volatile union {
  struct {
#ifdef CS_BIG_ENDIAN
    cs_uint32 ownership            :  1 ; /* bits 31:31 */
    cs_uint32 hdr_a		           :  1 ; /* bits 30:30 */
    cs_uint32 error_flag           :  1 ; /* bits 29:29 */
    cs_uint32 invalid_pkt_len      :  1 ; /* bits 28:28 */
    cs_uint32 reserved             : 12 ; /* bits 27:16 */
    cs_uint32 bytes_valid          :  4 ; /* bits 15:12 */
    cs_uint32 reserved1            :  1 ; /* bits 11:11 */
    cs_uint32 next_link		       : 11 ; /* bits 10: 0 */
#else /* CS_LITTLE_ENDIAN */
    cs_uint32 next_link		       : 11 ; /* bits 10: 0 */
    cs_uint32 reserved1            :  1 ; /* bits 11:11 */
    cs_uint32 bytes_valid          :  4 ; /* bits 15:12 */
    cs_uint32 reserved             : 12 ; /* bits 27:16 */
    cs_uint32 invalid_pkt_len      :  1 ; /* bits 28:28 */
    cs_uint32 error_flag           :  1 ; /* bits 29:29 */
    cs_uint32 hdr_a		           :  1 ; /* bits 30:30 */
    cs_uint32 ownership            :  1 ; /* bits 31:31 */
#endif
  } bf ;
  cs_uint32     wrd ;
} NI_HEADER_X_T;

/************************************************************************/
/* If not include registers.h, we have to define CONFIG_NO_REGISTERS_H. */
/************************************************************************/
#ifdef CONFIG_NO_REGISTERS_H

#define GLOBAL_BLOCK_RESET			0xf0000004
#define GLOBAL_IO_DRIVE_STRENGTH		0xf00000b4
#define NI_TOP_NI_INTF_RST_CONFIG 		0xf0010000
#define NI_TOP_NI_ETH_INT_CONFIG1 		0xf0010004
#define NI_TOP_NI_ETH_MGMT_PT_CONFIG 	0xf001000c
#define NI_TOP_NI_ETH_MAC_CONFIG0_0 	0xf0010010
#define NI_TOP_NI_ETH_MAC_CONFIG2_0 	0xf0010018
#define NI_TOP_NI_MAC_ADDR0				0xf0010040
#define NI_TOP_NI_MAC_ADDR1				0xf0010044
#define NI_TOP_NI_CPUXRAM_ADRCFG_RX_0 	0xf00101ac
#define NI_TOP_NI_CPUXRAM_ADRCFG_TX_0 	0xf00101d0
#define NI_TOP_NI_CPUXRAM_CFG 			0xf00101d8
#define NI_TOP_NI_CPUXRAM_CPU_CFG_RX_0 	0xf0010204
#define NI_TOP_NI_CPUXRAM_CPU_STA_RX_0 	0xf0010208
#define	NI_TOP_NI_CPUXRAM_CPU_CFG_TX_0 	0xf00102e4
#define NI_TOP_NI_CPUXRAM_CPU_STAT_TX_0 0xf00102e8

#define PER_MDIO_CFG 					0xf00700a0
#define PER_MDIO_ADDR 					0xf00700a4
#define PER_MDIO_WRDATA 				0xf00700a8
#define PER_MDIO_RDDATA 				0xf00700ac
#define PER_MDIO_CTRL 					0xf00700b0

typedef volatile union {
  struct {
#ifdef CS_BIG_ENDIAN
    cs_uint32 mac_tx_rst           :  1 ; /* bits 31:31 */
    cs_uint32 mac_rx_rst           :  1 ; /* bits 30:30 */
    cs_uint32 send_pg_data         :  1 ; /* bits 29:29 */
    cs_uint32 pass_thru_hdre       :  1 ; /* bits 28:28 */
    cs_uint32 tx_fifo_reset        :  1 ; /* bits 27:27 */
    cs_uint32 tx_auto_xon          :  1 ; /* bits 26:26 */
    cs_uint32 txfifo_thrshld       :  9 ; /* bits 25:17 */
    cs_uint32 txfifo_mode          :  1 ; /* bits 16:16 */
    cs_uint32 lpbk_mode            :  2 ; /* bits 15:14 */
    cs_uint32 tx_drain             :  1 ; /* bits 13:13 */
    cs_uint32 tx_flow_disable      :  1 ; /* bits 12:12 */
    cs_uint32 tx_ipg_sel           :  3 ; /* bits 11:9 */
    cs_uint32 rx_flow_disable      :  1 ; /* bits 8:8 */
    cs_uint32 link_active_mask     :  1 ; /* bits 7:7 */
    cs_uint32 link_stat_mask       :  1 ; /* bits 6:6 */
    cs_uint32 link_status          :  1 ; /* bits 5:5 */
    cs_uint32 crs_polarity         :  1 ; /* bits 4:4 */
    cs_uint32 tx_en                :  1 ; /* bits 3:3 */
    cs_uint32 rx_en                :  1 ; /* bits 2:2 */
    cs_uint32 duplex               :  1 ; /* bits 1:1 */
    cs_uint32 speed                :  1 ; /* bits 0:0 */
#else /* CS_LITTLE_ENDIAN */
    cs_uint32 speed                :  1 ; /* bits 0:0 */
    cs_uint32 duplex               :  1 ; /* bits 1:1 */
    cs_uint32 rx_en                :  1 ; /* bits 2:2 */
    cs_uint32 tx_en                :  1 ; /* bits 3:3 */
    cs_uint32 crs_polarity         :  1 ; /* bits 4:4 */
    cs_uint32 link_status          :  1 ; /* bits 5:5 */
    cs_uint32 link_stat_mask       :  1 ; /* bits 6:6 */
    cs_uint32 link_active_mask     :  1 ; /* bits 7:7 */
    cs_uint32 rx_flow_disable      :  1 ; /* bits 8:8 */
    cs_uint32 tx_ipg_sel           :  3 ; /* bits 11:9 */
    cs_uint32 tx_flow_disable      :  1 ; /* bits 12:12 */
    cs_uint32 tx_drain             :  1 ; /* bits 13:13 */
    cs_uint32 lpbk_mode            :  2 ; /* bits 15:14 */
    cs_uint32 txfifo_mode          :  1 ; /* bits 16:16 */
    cs_uint32 txfifo_thrshld       :  9 ; /* bits 25:17 */
    cs_uint32 tx_auto_xon          :  1 ; /* bits 26:26 */
    cs_uint32 tx_fifo_reset        :  1 ; /* bits 27:27 */
    cs_uint32 pass_thru_hdre       :  1 ; /* bits 28:28 */
    cs_uint32 send_pg_data         :  1 ; /* bits 29:29 */
    cs_uint32 mac_rx_rst           :  1 ; /* bits 30:30 */
    cs_uint32 mac_tx_rst           :  1 ; /* bits 31:31 */
#endif
  } bf ;
  cs_uint32     wrd ;
} NI_TOP_NI_ETH_MAC_CONFIG0_0_t;


typedef volatile union {
  struct {
#ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd3               : 16 ;
    cs_uint32 mdio_rd_wr           :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 mdio_offset          :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mdio_addr            :  5 ; /* bits 4:0 */
#else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdio_addr            :  5 ; /* bits 4:0 */
    cs_uint32 rsrvd1               :  3 ;
    cs_uint32 mdio_offset          :  5 ; /* bits 12:8 */
    cs_uint32 rsrvd2               :  2 ;
    cs_uint32 mdio_rd_wr           :  1 ; /* bits 15:15 */
    cs_uint32 rsrvd3               : 16 ;
#endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_ADDR_t;

#define     mdio_rd_wr_WR                                 0x0
#define     mdio_rd_wr_RD                                 0x1
#define     mdio_addr_NORM                                0x0
#define     mdio_addr_CONLY                               0x1

typedef volatile union {
  struct {
#ifdef CS_BIG_ENDIAN
    cs_uint32 rsrvd2               : 24 ;
    cs_uint32 mdiostart            :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 mdiodone             :  1 ; /* bits 0:0 */
#else /* CS_LITTLE_ENDIAN */
    cs_uint32 mdiodone             :  1 ; /* bits 0:0 */
    cs_uint32 rsrvd1               :  6 ;
    cs_uint32 mdiostart            :  1 ; /* bits 7:7 */
    cs_uint32 rsrvd2               : 24 ;
#endif
  } bf ;
  cs_uint32     wrd ;
} PER_MDIO_CTRL_t;
#endif

#endif /* __G2_NI_MFE_H */
