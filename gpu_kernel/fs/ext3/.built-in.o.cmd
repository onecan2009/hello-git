cmd_fs/ext3/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o fs/ext3/built-in.o fs/ext3/ext3.o ; scripts/mod/modpost fs/ext3/built-in.o
