cmd_scripts/mod/empty.o := /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-gcc -Wp,-MD,scripts/mod/.empty.o.d  -nostdinc -isystem /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/../lib/gcc/arm-eabi/4.6.x-google/include -I/home/rk3288-sdk/gpu_kernel/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/rk3288-sdk/gpu_kernel/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/rk3288-sdk/gpu_kernel/include/uapi -Iinclude/generated/uapi -include /home/rk3288-sdk/gpu_kernel/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -fno-dwarf2-cfi-asm -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -mhard-float -Uarm -mfpu=vfp -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(empty)"  -D"KBUILD_MODNAME=KBUILD_STR(empty)" -c -o scripts/mod/empty.o scripts/mod/empty.c

source_scripts/mod/empty.o := scripts/mod/empty.c

deps_scripts/mod/empty.o := \

scripts/mod/empty.o: $(deps_scripts/mod/empty.o)

$(deps_scripts/mod/empty.o):