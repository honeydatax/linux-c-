
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
char a=0;
long b=0;
long c=0;
long counter=0;
tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);

if (wiringPiSetup () == -1)
    return 1 ;
 
  pinMode (0, INPUT) ;         // aka BCM_GPIO pin 17
  pinMode (1, INPUT) ;         // aka BCM_GPIO pin 17 
  pinMode (2, INPUT) ;         // aka BCM_GPIO pin 17
  pinMode (3, INPUT) ;         // aka BCM_GPIO pin 17

printf ("\nosc2: out file ../saida.txt press esc to exit\n");
b=0;
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
a=fgetc(stdin);
}

if (digitalRead (0)==1) toprints[0]='1';
else toprints[0]='0';
if (digitalRead (1)==1) toprints[2]='1';
else toprints[2]='0';
if (digitalRead (2)==1) toprints[4]='1';
else toprints[4]='0';
if (digitalRead (3)==1)toprints[6]='1';
else toprints[6]='0';

printf ("%s",toprints);
fprintf (fp,"%s\n",toprints);
counter++;
}while(a!=0x1B); 
fclose(fp);
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
return 0;
}

