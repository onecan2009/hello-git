cmd_drivers/staging/android/ion/built-in.o :=  /home/rk3288-sdk/prebuilts/gcc/linux-x86/arm/arm-eabi-4.6/bin/arm-eabi-ld -EL    -r -o drivers/staging/android/ion/built-in.o drivers/staging/android/ion/ion.o drivers/staging/android/ion/ion_heap.o drivers/staging/android/ion/ion_page_pool.o drivers/staging/android/ion/ion_system_heap.o drivers/staging/android/ion/ion_carveout_heap.o drivers/staging/android/ion/ion_chunk_heap.o drivers/staging/android/ion/ion_cma_heap.o drivers/staging/android/ion/rockchip/built-in.o ; scripts/mod/modpost drivers/staging/android/ion/built-in.o