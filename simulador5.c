
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


#define bufs 100 


time_t rawtime;
struct termios oldt,newt;
struct tm *timeinfo;
struct timeval start, ends;
FILE *fp;
int bufa=0;
int bufb=0;
char *ab="/mnt/ramdisk1/cons0";
char *abc="/mnt/ramdisk1/cons1";

int main2();

int main()
{
int f1;
int f2;
char ttimes[20];
char toprints[]="0|0|0|0\r\0";
char buf[1];
int nnull;
int s=0;
char a=0;
long b=0;
long c=0;
int iii=0;
int xxx=0;
int cc=0;
int tt=0;
int ttt=0;
long counter=0;
system ("sudo mkdir /mnt/ramdisk1");
system ("sudo chmod 700 /mnt/ramdisk1/");
system ("sudo mount -t tmpfs -o size=50m tmpfs /mnt/ramdisk1");
buf[0]='0';
f1=open(ab,O_CREAT|O_RDWR);
f2=open(abc,O_CREAT|O_RDWR);
write(f1,buf,1);
write(f2,buf,1);
close(f1);
close(f2);
system ("sudo chmod 700 /mnt/ramdisk1/cons0");
system ("sudo chmod 700 /mnt/ramdisk1/cons1");
pid_t pid=fork();
if (pid==0) main2();
else{

tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);
int fd1;
int fd2;
int ret;
b=0;
printf ("\033c");
printf ("\e[0;30;47m");
for(iii=0;iii<98;iii++){
printf ("                    ");
}

printf ("\e[1;1f\\simulator: press esc to exit");
do{
f2=open(abc,O_RDWR);
counter=0;
a=fgetc(stdin);
printf("\e[2;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[3;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[4;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[5;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[6;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[7;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[8;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[9;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[10;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[11;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[12;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[13;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[14;%if\e[0;30;47m \e[0;30;40m ",xxx);
printf("\e[15;%if\e[0;30;47m \e[0;30;40m ",xxx);

read(f2,buf,1);

for(iii=0;iii<4;iii++){
s=0;
if (buf[0]=='1') s=1;
tt=2+iii*3+(s);
ttt=41+s*3;
printf("\e[%i;%if\e[0;30;%im ",tt,xxx,ttt);
}
xxx++;
s++;
if (xxx>77) xxx=0;
if (s>1) s=0;
close(f2);
usleep(5000);
}while(a!=0x1B); 
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
printf ("\033c");
buf[0]='1';
f1=open(ab,O_RDWR);
write(f1,buf,1);
close(f1);
wait();
}
return 0;
}


int main2()
{
int f1;
int f2;
char t='0';
char buf[1];
long counter=0;
int ccc=0;
int nnnull;

do{
f1=open(ab,O_RDWR);
f2=open(abc,O_RDWR);
buf[0]='0';
if (ccc==1) buf[0]='1' ;
write(f2,buf,1);
buf[1]='0';
read(f1,buf,1);
ccc++;
if (ccc>1)ccc=0;
close(f1);
close(f2);
usleep(5000);
}while(buf[0]!=1); 
return 0;
}















