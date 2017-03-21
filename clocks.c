
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
char toprints[250];
int z=0;

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
printf ("press esc to exit clock\n");
b=0;
do{
gettimeofday(&start,NULL);
b=start.tv_sec;
if (b>c){
gettimeofday(&ends,NULL);
c=ends.tv_sec;
time(&rawtime);
timeinfo=localtime(&rawtime);
sprintf (toprints,"%s",ctime(&rawtime));
for(z=0;z<240;z++){
if(toprints[z]=='\n')
{toprints[z]='\r';
z=250;
}
}
printf ("%s",toprints);
counter=0;
a=fgetc(stdin);
}
counter++;
}while(a!=0x1B); 
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
printf ("\n");
return 0;
}








