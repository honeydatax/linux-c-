
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



 


time_t rawtime;
struct termios oldt,newt;
struct tm *timeinfo;
struct timeval start, ends;
FILE *fp;

int main()
{
char ttimes[20];
char toprints[]="0|0|0|0\r\0";
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
tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);


b=0;
printf ("\033c");
printf ("\e[0;30;47m");
for(iii=0;iii<98;iii++){
printf ("                    ");
}

printf ("\e[1;1f\\simulator: press esc to exit");

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
tt=2+iii*3+(s);
ttt=44-s*3;
printf("\e[%i;%if\e[0;30;%im ",tt,xxx,ttt);
}
sleep(1);
xxx++;
s++;
if (xxx>77) xxx=0;
if (s>1) s=0;
}while(a!=0x1B); 
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
printf ("\033c");
return 0;
}
















