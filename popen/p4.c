#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    char buf[20];
    read(0,buf,20);
    write(1,"printing from p4\n",sizeof("printing from p4\n"));
    write(1,buf,sizeof(buf));

    return 0;
}
