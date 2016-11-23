#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

 unsigned char	APRDSendBuf[56] = {0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x88,0xa4,0x00,0x00,0x11,0x88,0xa4,							   
																					0x0d,0x10,0x01,0x00,0x00,0x00,0x00,0x09,							   
																					0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,							   
																					0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,							   
																					0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,							   
																					0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,							   
																					0x00,0x00};
																					
int main(int argc, char* argv[])
{
	//unsigned char shutdown_flag = false;
	//char num;
	
	int fd = open("/dev/SDO_DEV", O_RDWR);
	if(fd < 0)
	{
		printf("cannot open file /dev/ups_detect \n");
		return true;
	}
	
	while(1)
	{
		//num = read(fd, &shutdown_flag, sizeof(shutdown_flag));
		//printf("shutdown_flag=%d read byte count=%d\n", shutdown_flag,num);
		//if (shutdown_flag)
		//{
			//num = write(fd, &shutdown_flag, sizeof(shutdown_flag));
			//printf(" write byte count=%d\n",num);
		//}
		
		usleep(10000);
		write(fd, &APRDSendBuf, sizeof(APRDSendBuf));
	}
	
	close(fd);
	printf("close source\n");
	
	return false;
}
