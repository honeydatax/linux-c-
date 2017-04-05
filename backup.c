
#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

char *abc="/mnt/ramdisk1/saida.dat";
char *ab="/mnt/ramdisk1/saida.idx";
char *abcd="./saida.txt";


int main()
{
char ttimes[25];
char strs[50];
char strs2[150];
time_t rawtime;
struct tm *timeinfo;
struct timeval start, ends;
time(&rawtime);
timeinfo=localtime(&rawtime);

system ("sudo chmod 777 /mnt/ramdisk1/");
system ("sudo chmod 777 /mnt/ramdisk1/saida.dat");
system ("sudo chmod 777 /mnt/ramdisk1/saida.idx");
sprintf (ttimes,"%s",ctime(&rawtime)); 
ttimes[20]=0;
memset(strs,0,49);
strcat(strs,"./");
strcat(strs,ttimes);
mkdir(strs,0777);
printf ("creat dir:%s",strs);
strcat(strs,"/");
memset(strs2,0,149);
strcat(strs2,"sudo cp /mnt/ramdisk1/saida.dat \"");
strcat(strs2,strs);
strcat(strs2,"\"");
system(strs2);
memset(strs2,0,149);
strcat(strs2,"sudo cp /mnt/ramdisk1/saida.idx \"");
strcat(strs2,strs);
strcat(strs2,"\"");
system(strs2);
return 0;
}

















