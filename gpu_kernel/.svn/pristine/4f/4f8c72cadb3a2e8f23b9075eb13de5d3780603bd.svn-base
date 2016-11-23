
#Kbuild语法的语句，指明模块源码中各个文件的依赖关系，以及生成的目标模块名
#$(warning  $(src))#/home/board/kernel1.3/KernelDriver
#$(src) 是一个相对路径，它就是Makefile/Kbuild 文件所在的路径。同样$(obj) 就是编译目标保存的路径，默认就是源代码所在路径
EXTRA_CFLAGS += -I$(src)/../SDK/Include/ -D__LINUX_PUNGGOL_CROSS__
MODULE_NAME := linuxpungodriver

obj-$(CONFIG_RK_GMAC_ETH) += $(MODULE_NAME).o

OBJDRIVER := DriverEntry.o DeviceEntry.o Adapter.o Timer.o MemoryMap.o Kernel.o

$(MODULE_NAME)-objs :=  $(OBJDRIVER)

