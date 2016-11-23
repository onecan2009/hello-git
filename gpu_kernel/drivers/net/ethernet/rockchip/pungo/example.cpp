#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#define __LINUX_PUNGGOL_CROSS__
#include "SDK/Include/Pungo/Kernel/IoControlCode.h"
#include "SDK/Include/Pungo/Kernel/SharedMemory.h"



int main(int argc, char* argv[])
{
	unsigned  long i = 0;
	unsigned long phymem_size, phymem_addr;
	KernelSharedMemory_t *map_addr;

	int fd = open("/dev/LPungo1.3", O_RDWR);
	if(fd < 0)
	{
		printf("cannot open file /dev/LPungo1.3\n");
		return false;
	}

	/*get the physical address of allocated memory in kernel*/
	if (ioctl(fd, KERNEL_IOCTL_GET_SHARED_MEMORY_ADDR, &phymem_addr) != 0)
	{
		printf("%s(),KERNEL_IOCTL_GET_SHARED_MEMORY_ADDR =%s\n",__FUNCTION__,strerror(errno));
		close(fd);
		return false;
	}
	//read(fd, &phymem_addr, sizeof(phymem_addr));
	printf("phymem_addr=0x%lx \n", phymem_addr);

	/*get the size of allocated memory in kernel*/
	if (ioctl(fd, KERNEL_IOCTL_GET_SHARED_MEMORY_SIZE, &phymem_size) != 0)
	{
		printf("%s(),KERNEL_IOCTL_GET_SHARED_MEMORY_SIZE =%s\n",__FUNCTION__,strerror(errno));
		close(fd);
		return false;
	}
	//read(fd, &phymem_size, sizeof(phymem_size));
	printf("phymem_size=%ld \n", phymem_size);

	int map_fd = open("/dev/mem", O_RDWR|O_SYNC);
	if(map_fd < 0)
	{
		printf("cannot open file /dev/mem/n");
		close(fd);
		return false;
	}

	map_addr = (KernelSharedMemory_t *)mmap(0, phymem_size, PROT_READ|PROT_WRITE, MAP_SHARED, map_fd, phymem_addr);
	if (map_addr == NULL)
	{
		perror("mmap");
		close(fd);
		return 0;
	}
	close(map_fd);
	//strcpy(map_addr, argv[1]);
	printf("m_KernerData = %s\n",map_addr->m_KernerData);
	map_addr->m_Start = 1;//qidong  PDO
	
#if 1	
	while(1)
	{
		printf("hours = %ld, minutes = %ld second = %ld\n",i/3600, i/60, i);
		printf("send packedt count = %lld\n",map_addr->m_sendecat_count);
		printf("receive packedt count = %lld\n",map_addr->m_recvecat_count);
		i++;
		
		sleep(1);

		//printf("map_addr->m_200or400_count = %lld\n",map_addr->m_200or400_count);
		//printf("map_addr->m_400or600_count = %lld\n",map_addr->m_400or600_count);
		//printf("map_addr->m_600or800_count = %lld\n",map_addr->m_600or800_count);
		//printf("map_addr->m_800or1000_count = %lld\n",map_addr->m_800or1000_count);
	}
#endif
	munmap(map_addr, phymem_size);
	
	close(fd);
	
	printf("close source\n");
	return true;
}
