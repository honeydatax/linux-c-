
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
#include <wiringPi.h>


 


time_t rawtime;
struct termios oldt,newt;
struct tm *timeinfo;
struct timeval start, ends;
FILE *fp;

int main()
{
char ttimes[20];
char toprints[]="0|0|0|0\r\0";
int s[8];
int iii=0;
int xxx=1;
int cc=0;
int tt=0;
int ttt=0;

char a=0;
long b=0;
long c=0;
long counter=0;
s[0]=0;
s[1]=0;
s[2]=0;
s[3]=0;
s[4]=0;
s[5]=0;
s[6]=0;
s[7]=0;
tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);

if (wiringPiSetup () == -1) return 1 ;
 
  pinMode (0, INPUT) ;         // aka BCM_GPIO pin 17
  pinMode (1, INPUT) ;         // aka BCM_GPIO pin 17 
  pinMode (2, INPUT) ;         // aka BCM_GPIO pin 17
  pinMode (3, INPUT) ;         // aka BCM_GPIO pin 17

printf ("\nosc2: out file ../saida.txt press esc to exit\n");
b=0;
printf ("\033c");
printf ("\e[0;30;47m");
for(iii=0;iii<98;iii++){
printf ("                    ");
}

printf ("\e[1;1f\\oscilator: press esc to exit");

fp=fopen("../saida.txt","w+");
do{
gettimeofday(&start,NULL);
b=start.tv_sec;
if (b>c){
gettimeofday(&ends,NULL);
c=ends.tv_sec;
time(&rawtime);
timeinfo=localtime(&rawtime);
fprintf (fp,"%i\n",counter);
fprintf (fp,"%s",ctime(&rawtime));
counter=0;
a=getc(stdin);
}

if (digitalRead (0)==1){
toprints[0]='1';
s[0]=0;
}
else 
{
toprints[0]='0';
s[0]=1;
}
if (digitalRead (1)==1){
toprints[2]='1';
s[1]=0;
}
else 
{toprints[2]='0';
s[1]=1;
}
if (digitalRead (2)==1){ 
toprints[4]='1';
s[2]=0;
}
else {
toprints[4]='0';
s[2]=1;
}

if (digitalRead (3)==1)
{toprints[6]='1';
s[3]=0;
}
else {
toprints[6]='0';
s[3]=1;
}



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
tt=2+iii*3+(s[iii]);
ttt=41+s[iii]*3;
printf("\e[%i;%if\e[0;30;%im ",tt,xxx,ttt);
}

fprintf (fp,"%s\n",toprints);
counter++;
xxx++;
if (xxx>77) xxx=1;
usleep(11000);
}
while( a != 0x1B); 
fclose(fp);
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
printf ("\033c");
return 0;
}
















