cmd_drivers/video/logo/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o drivers/video/logo/built-in.o drivers/video/logo/logo.o drivers/video/logo/logo_linux_clut224.o ; scripts/mod/modpost drivers/video/logo/built-in.o