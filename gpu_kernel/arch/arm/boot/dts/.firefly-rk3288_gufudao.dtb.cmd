cmd_arch/arm/boot/dts/firefly-rk3288_gufudao.dtb := /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-gcc -E -Wp,-MD,arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.d.pre.tmp -nostdinc -I/home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts -I/home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.dts arch/arm/boot/dts/firefly-rk3288_gufudao.dts ; /home/rk3288-sdk/gpu_kernel/scripts/dtc/dtc -O dtb -o arch/arm/boot/dts/firefly-rk3288_gufudao.dtb -b 0 -i arch/arm/boot/dts/  -d arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.d.dtc.tmp arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.dts ; cat arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.d.pre.tmp arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.d.dtc.tmp > arch/arm/boot/dts/.firefly-rk3288_gufudao.dtb.d

source_arch/arm/boot/dts/firefly-rk3288_gufudao.dtb := arch/arm/boot/dts/firefly-rk3288_gufudao.dts

deps_arch/arm/boot/dts/firefly-rk3288_gufudao.dtb := \
  arch/arm/boot/dts/rk3288.dtsi \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/clock/rk_system_status.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/interrupt-controller/arm-gic.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/interrupt-controller/irq.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/rkfb/rk_fb.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/rkmipi/mipi_dsi.h \
    $(wildcard include/config/mipi/dsi/ft.h) \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/suspend/rockchip-pm.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/sensor-dev.h \
  arch/arm/boot/dts/skeleton.dtsi \
  arch/arm/boot/dts/rk3288-pinctrl.dtsi \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/gpio/gpio.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/pinctrl/rockchip.h \
    $(wildcard include/config/to/pull.h) \
    $(wildcard include/config/to/vol.h) \
    $(wildcard include/config/to/drv.h) \
    $(wildcard include/config/to/tri.h) \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/pinctrl/rockchip-rk3288.h \
  arch/arm/boot/dts/rk3288-clocks.dtsi \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/clock/rockchip,rk3288.h \
  /home/rk3288-sdk/gpu_kernel/arch/arm/boot/dts/include/dt-bindings/clock/rockchip.h \
  arch/arm/boot/dts/lcd-box.dtsi \
  arch/arm/boot/dts/act8846.dtsi \
  arch/arm/boot/dts/rk808.dtsi \

arch/arm/boot/dts/firefly-rk3288_gufudao.dtb: $(deps_arch/arm/boot/dts/firefly-rk3288_gufudao.dtb)

$(deps_arch/arm/boot/dts/firefly-rk3288_gufudao.dtb):
