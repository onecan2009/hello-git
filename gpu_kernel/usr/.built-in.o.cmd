cmd_usr/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o usr/built-in.o usr/initramfs_data.o ; scripts/mod/modpost usr/built-in.o
