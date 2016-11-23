#
# Makefile for the rockchip device drivers.
#
obj-$(CONFIG_NET_VENDOR_ROCKCHIP) += eth_mac.o
obj-$(CONFIG_RK_VMAC_ETH) += vmac/
#obj-$(CONFIG_RK_GMAC_ETH) += gmac/
#obj-$(CONFIG_RK_GMAC_ETH) += pungo/
#obj-$(CONFIG_RK_GMAC_ETH) += genyang_pungo/

MODULE_NAME := linuxpungodriver
GMACDIR := gmac
PUNGODIR := pungo/PungoDriver

EXTRA_CFLAGS += -I$(src)/pungo/SDK/Include/ -D__LINUX_PUNGGOL_CROSS__
#$(warning  $(src)/gmac) #drivers/net/ethernet/rockchip
#$(warning  $(CURDIR)) #/home/rk3288-sdk/firefly-rk3288-kernel

GMACDRIVER :=$(GMACDIR)/stmmac_platform.o \
							$(GMACDIR)/stmmac_main.o $(GMACDIR)/stmmac_ethtool.o $(GMACDIR)/stmmac_mdio.o $(GMACDIR)/ring_mode.o \
							$(GMACDIR)/chain_mode.o $(GMACDIR)/dwmac_lib.o $(GMACDIR)/dwmac1000_core.o $(GMACDIR)/dwmac1000_dma.o \
							$(GMACDIR)/dwmac100_core.o $(GMACDIR)/dwmac100_dma.o $(GMACDIR)/enh_desc.o $(GMACDIR)/norm_desc.o \
							$(GMACDIR)/mmc_core.o $(GMACDIR)/stmmac_hwtstamp.o $(GMACDIR)/stmmac_ptp.o 

PUNGODRIVER := $(PUNGODIR)/DriverEntry.o $(PUNGODIR)/DeviceEntry.o $(PUNGODIR)/Adapter.o \
								$(PUNGODIR)/Timer.o $(PUNGODIR)/MemoryMap.o $(PUNGODIR)/Kernel.o

obj-$(CONFIG_RK_GMAC_ETH) += $(MODULE_NAME).o

$(MODULE_NAME)-objs := $(GMACDRIVER) $(PUNGODRIVER)


