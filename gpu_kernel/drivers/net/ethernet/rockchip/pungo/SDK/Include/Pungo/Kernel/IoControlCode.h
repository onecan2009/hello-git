//
//

#ifndef _IOCONTROLCODE_H
#define _IOCONTROLCODE_H

#ifndef __LINUX_PUNGGOL_CROSS__

const int KERNEL_IOCTL_GET_SHARED_MEMORY =
	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_READ_DATA);

const int KERNEL_IOCTL_LICENSE_VERIFY =
	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA);
#else

#define KERNEL_IOCTL_GET_SHARED_MEMORY_ADDR	0x01
#define KERNEL_IOCTL_GET_SHARED_MEMORY_SIZE	0x10

#define KERNEL_IOCTL_LICENSE_VERIFY	0x100

#endif

#endif /*_IOCONTROLCODE_H*/