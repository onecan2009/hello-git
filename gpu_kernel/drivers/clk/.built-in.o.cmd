cmd_drivers/clk/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o drivers/clk/built-in.o drivers/clk/clk-devres.o drivers/clk/clkdev.o drivers/clk/clk.o drivers/clk/clk-divider.o drivers/clk/clk-fixed-factor.o drivers/clk/clk-fixed-rate.o drivers/clk/clk-gate.o drivers/clk/clk-mux.o drivers/clk/clk-composite.o drivers/clk/rockchip/built-in.o ; scripts/mod/modpost drivers/clk/built-in.o