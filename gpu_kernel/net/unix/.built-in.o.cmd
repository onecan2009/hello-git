cmd_net/unix/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o net/unix/built-in.o net/unix/unix.o ; scripts/mod/modpost net/unix/built-in.o
