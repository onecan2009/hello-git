cmd_pie/libpie_stage2.o := /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-objcopy  --redefine-syms=pie/pie_rename.syms --rename-section .text=.pie.text pie/libpie_stage1.o pie/libpie_stage2.o