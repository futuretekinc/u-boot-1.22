setenv model FTM-100S
setenv devid FTM100S14080A0001
setenv stdin serial
setenv stdout serial
setenv stderr serial
setenv ethact eth0
setenv ethaddr 00:40:5c:01:01:01
setenv ethaddr1 00:40:5c:01:01:02
setenv ethaddr2 00:40:5c:01:01:03
setenv ipaddr 192.168.1.200
setenv netmask 255.255.255.0
setenv serverip 192.168.1.102
setenv gatewayip 192.168.1.1
setenv verify n
setenv basicargs console=ttyS0,115200 SB_PHY=PPXS
setenv load_kernel nand read ${kernel_base} ${kernel_loc} ${kernel_len}
setenv bootcmd run load_kernel setmtdparts setbootargs;bootm ${kernel_base}
setenv bootdelay 2
setenv QM_INT_BUFF 256
setenv NI_NAPI_BUDGET 16
setenv QM_ACP_ENABLE 0
setenv NI_RX_NONCACHE 0
setenv model FTM-100s
setenv downloadaddr 0x5000000
setenv nandinfo_loc 0x00000000
setenv nandinfo_len 0x00020000
setenv uboot_loc0 0x00020000
setenv uboot_loc1 0x00200000
setenv uboot_len 0xE0000
setenv env_loc0 0x00100000
setenv env_loc1 0x00300000
setenv env_len 0x100000
setenv sysinfo_loc 0x00400000
setenv sysinfo_len 0x00200000
setenv kernel_base 0x02100000
setenv kernel_loc  0x00600000
setenv kernel_loc0 0x00600000
setenv kernel_name0 kernel
setenv kernel_loc1 0x04300000
setenv kernel_name1 kernel_standby
setenv kernel_len 0x00700000
setenv rootfs_loc0 0x00D00000
setenv rootfs_name0 rootfs
setenv rootfs_loc1 0x04A00000
setenv rootfs_name1 rootfs_standby
setenv rootfs_len 0x03600000
setenv overlay_loc0 0x08000000
setenv overlay_name0 overlay
setenv overlay_loc1 0x0C000000
setenv overlay_name1 overlay_standby
setenv overlay_len 0x04000000
setenv data_loc0 0x10000000
setenv data_name0 data
setenv data_loc1 0x18000000
setenv data_name1 data_standby
setenv data_len   0x08000000
setenv flashfiles ftm-100s/
setenv reflash run rf_kernel rf_rootfs rf_overlay rf_data
setenv rf_info tftpboot ${downloadaddr} ${flashfiles}nand-info.bin; nand erase ${nandinfo_loc} ${nandinfo_len}; nand write ${downloadaddr} ${nandinfo_loc} ${nandinfo_len}
setenv rf_loader tftpboot ${downloadaddr} ${flashfiles}bootloader.bin;nand erase ${uboot_loc0} ${uboot_len};nand write ${downloadaddr} ${uboot_loc0} ${uboot_len};nand erase ${uboot_loc1} ${uboot_len};nand write ${downloadaddr} ${uboot_loc1} ${uboot_len}
setenv rf_env tftpboot ${downloadaddr} ${flashfiles}u-boot-env.bin; nand erase ${env_loc0} ${env_len}; nand write ${downloadaddr} ${env_loc0} ${env_len}; nand erase ${env_loc1} ${env_len}; nand write ${downloadaddr} ${env_loc1} ${env_len}
setenv rf_kernel tftpboot ${downloadaddr} ${flashfiles}uImage;nand erase ${kernel_loc0} ${kernel_len};nand write ${downloadaddr} ${kernel_loc0} ${kernel_len};nand erase ${kernel_loc1} ${kernel_len};nand write ${downloadaddr} ${kernel_loc1} ${kernel_len}
setenv rf_rootfs tftpboot ${downloadaddr} ${flashfiles}rootfs.img;nand erase ${rootfs_loc0} ${rootfs_len};nand write ${downloadaddr} ${rootfs_loc0} ${rootfs_len};nand erase ${rootfs_loc1} ${rootfs_len};nand write  ${downloadaddr} ${rootfs_loc1} ${rootfs_len}
setenv rf_rootfs tftpboot ${downloadaddr} ${flashfiles}rootfs.img;savefs rootfs 0;savefs rootfs 1
setenv rf_overlay nand erase ${overlay_loc0} ${overlay_len};nand erase ${overlay_loc1} ${overlay_len}
setenv rf_data nand erase ${data_loc0} ${data_len};nand erase ${data_loc1} ${data_len}
setenv setbootargs setenv bootargs ${basicargs} ${ramargs} ni_napi_budget=${NI_NAPI_BUDGET} qm_acp_enable=${QM_ACP_ENABLE} ni_rx_noncache=${NI_RX_NONCACHE} qm_int_buff=${QM_INT_BUFF} ethaddr0=${ethaddr} ethaddr1=${ethaddr1} ethaddr2=${ethaddr2} wifiaddr0=${wifiaddr0} mtdparts=cs752x_nand_flash:${mtdparts} model=${model} devid=${devid}
setenv setmtdparts setenv mtdparts 2M@${sysinfo_loc}(sysinfo),512K@${env_loc0}(env),8M@${kernel_loc0}(${kernel_name0}),54M@${rootfs_loc0}(${rootfs_name0}),64M@${overlay_loc0}(${overlay_name0}),128M@${data_loc0}(data),512K@${env_loc1}(env1),8M@${kernel_loc1}(${kernel_name1}),54M@${rootfs_loc1}(${rootfs_name1}),64M@${overlay_loc1}(${overlay_name1}),128M@${data_loc1}(data1)
setenv load_kernel nand read ${kernel_base} ${kernel_loc} ${kernel_len}
setenv b bootm ${kernel_address}
setenv rootfs_address -
