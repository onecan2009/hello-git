cmd_drivers/bluetooth/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o drivers/bluetooth/built-in.o drivers/bluetooth/vflash.o drivers/bluetooth/hci_uart.o ; scripts/mod/modpost drivers/bluetooth/built-in.o