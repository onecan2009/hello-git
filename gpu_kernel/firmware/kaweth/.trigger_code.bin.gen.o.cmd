cmd_firmware/kaweth/trigger_code.bin.gen.o := /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-gcc -Wp,-MD,firmware/kaweth/.trigger_code.bin.gen.o.d  -nostdinc -isystem /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/../lib/gcc/arm-eabi/4.6.x-google/include -I/home/rk3288-sdk/gpu_kernel/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/rk3288-sdk/gpu_kernel/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/rk3288-sdk/gpu_kernel/include/uapi -Iinclude/generated/uapi -include /home/rk3288-sdk/gpu_kernel/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian  -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h          -c -o firmware/kaweth/trigger_code.bin.gen.o firmware/kaweth/trigger_code.bin.gen.S

source_firmware/kaweth/trigger_code.bin.gen.o := firmware/kaweth/trigger_code.bin.gen.S

deps_firmware/kaweth/trigger_code.bin.gen.o := \
  /home/rk3288-sdk/gpu_kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \

firmware/kaweth/trigger_code.bin.gen.o: $(deps_firmware/kaweth/trigger_code.bin.gen.o)

$(deps_firmware/kaweth/trigger_code.bin.gen.o):