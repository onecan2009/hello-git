cmd_drivers/pinctrl/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o drivers/pinctrl/built-in.o drivers/pinctrl/core.o drivers/pinctrl/pinctrl-utils.o drivers/pinctrl/pinmux.o drivers/pinctrl/pinconf.o drivers/pinctrl/devicetree.o drivers/pinctrl/pinconf-generic.o drivers/pinctrl/pinctrl-rockchip.o ; scripts/mod/modpost drivers/pinctrl/built-in.o