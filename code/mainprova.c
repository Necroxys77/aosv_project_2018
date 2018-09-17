#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/ioctl.h>

#define MAGIC 'a'
#define case_1 _IO(MAGIC, 0)
#define case_2 _IO(MAGIC, 1)

int fd;

void hello(void){
    int a;
    a = 0;
    printf("ip correctly modified!\n");
    ioctl(fd, case_2, 0);
}

int main(int argc, char const *argv[])
{
    fd = open("/dev/DeviceName", O_RDWR);
    if (fd < 0){
        perror("Failed to open the device...");
        return errno;
    }
    ioctl(fd, case_1, hello);
    printf("OOOOK\n");
    return 0;
}
