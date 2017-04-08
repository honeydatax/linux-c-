
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
char *ab="cons0";
char *abc="cons1";

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
mkfifo (ab,0777);
mkfifo (abc,0777);
chmod (ab,0777);
chmod (abc,0777);

pid_t pid=fork();
if (pid==0) main2();
else{
f1=open(ab,O_WRONLY|O_NONBLOCK);

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
f2=open(abc,O_RDONLY|O_NONBLOCK);

do{
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

for(iii=0;iii<4;iii++){
read(f2,buf,1);
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
usleep(11000);
}while(a!=0x1B); 
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
printf ("\033c");
buf[0]=1;
write(f1,buf,1);
wait();
close(f1);
close(f2);
unlink(ab);
unlink(abc);
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
f1=open(ab,O_RDONLY|O_NONBLOCK);
f2=open(abc,O_WRONLY|O_NONBLOCK);

do{
buf[0]='0';
if (ccc==1) buf[0]='1' ;
write(f2,buf,1);
read(f1,buf,1);
ccc++;
if (ccc>1)ccc=0;
usleep(11000);
}while(buf[0]!=1); 
close(f1);
close(f2);
return 0;
}















