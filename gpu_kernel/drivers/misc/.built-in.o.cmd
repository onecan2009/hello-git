cmd_drivers/misc/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o drivers/misc/built-in.o drivers/misc/uid_stat.o drivers/misc/eeprom/built-in.o drivers/misc/cb710/built-in.o drivers/misc/ti-st/built-in.o drivers/misc/lis3lv02d/built-in.o drivers/misc/carma/built-in.o drivers/misc/inv_mpu/built-in.o drivers/misc/sram.o drivers/misc/atx8_unsetup.o drivers/misc/5v_en.o drivers/misc/hsic_hub_reset.o ; scripts/mod/modpost drivers/misc/built-in.o