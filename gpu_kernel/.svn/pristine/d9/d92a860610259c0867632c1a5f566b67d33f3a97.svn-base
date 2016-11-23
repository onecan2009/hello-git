#!/bin/bash

#echo "config kernel"
#make firefly-rk3288-linux_defconfig

echo "build kernel"
make firefly-rk3288_gufudao.img
#make -j8 firefly-rk3288.img

mkbootimg --kernel arch/arm/boot/zImage --ramdisk initrd.img -o boot.img

rm /mnt/hgfs/shared-rk3288/lark-img/boot.img -rf
rm /mnt/hgfs/shared-rk3288/lark-img/resource.img -rf

#echo "copy boot.img and resource.img to shared-rk3288"
#cp boot.img /mnt/hgfs/shared-rk3288/lark-img/
#cp resource.img /mnt/hgfs/shared-rk3288/lark-img/

