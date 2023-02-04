#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{

printf("pid : %d\n" , getpid());
char *args[] ={"./hello","2",NULL};
execv(args[0],args);
return 0;

}
