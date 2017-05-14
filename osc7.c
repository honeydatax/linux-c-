#include <SDL/SDL.h>
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
#include <wiringPi.h>


#define bufs 100 

time_t rawtime;
struct termios oldt,newt;
struct tm *timeinfo;
struct timeval start, ends;
FILE *fp;
int bufa=0;
int bufb=0;
char *ab="/mnt/ramdisk1/cons0";
char *abc="/mnt/ramdisk1/saida.dat";
char *abcd="/mnt/ramdisk1/saida.idx";
char *abcde="/mnt/ramdisk1/saida.cr";

int main2();

int main()
{

SDL_Rect rrr[1];
SDL_Rect rrrr[10];
SDL_Surface *sss;
SDL_Surface *iiii;
SDL_Event event;
int bit0=0;
int bit1=0;
int bit2=0;
int bit3=0;


int v0=0;
int v1=0;
int v2=0;
int v3=0;
int ss=0;
off_t lsek;
int cc0=0;
int cc1=0;
int cc2=0;
int cc3=0;
int f1;
int f2;
int f3;
int f4;
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
buf[0]=0;
f1=open(ab,O_CREAT|O_RDWR);
f2=open(abc,O_CREAT|O_RDWR);
f3=open(abcd,O_CREAT|O_RDWR);
f4=open(abcde,O_CREAT|O_RDWR);
write(f1,buf,1);
write(f4,buf,1);
close(f1);
close(f2);
close(f3);
close(f4);
system ("sudo chmod 700 /mnt/ramdisk1/cons0");
system ("sudo chmod 700 /mnt/ramdisk1/saida.dat");
system ("sudo chmod 700 /mnt/ramdisk1/saida.idx");
system ("sudo chmod 700 /mnt/ramdisk1/saida.cr");
pid_t pid=fork();
if (pid==0) main2();
else{
int fd1;
int fd2;
int ret;
b=0;
rrr[0] = {0 ,0 ,639 ,479 };
rrrr[0] = {0 ,0 ,10,250 };
rrrr[1] = {0 ,0 ,10 ,250 };
rrrr[2] = {0 ,0 ,10,10 };
rrrr[3] = {0 ,0 ,10 ,10 };
rrrr[4] = {0 ,0 ,10 ,10 };
rrrr[5] = {0 ,0 ,10 ,10 };
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
atexit(SDL_Quit);
sss=SDL_SetVideoMode(640,480,8,0);
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_UpdateRects(sss,1,rrr);
SDL_WM_SetCaption("simulador:press esc to exit",NULL);


f2=open(abcde,O_RDWR);
do{
lsek=lseek(f2,(off_t)0,SEEK_SET);
counter=0;
if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
}

read(f2,buf,1);
bit0=0;
bit1=0;
bit2=0;
bit3=0;
rrrr[2].y=50;
rrrr[3].y=100;
rrrr[4].y=150;
rrrr[5].y=200;

if (buf[0]>=8){
bit0=1;
buf[0]=buf[0]-8;
rrrr[2].y=60;
}

if (buf[0]>=4){
bit1=1;
buf[0]=buf[0]-4;
rrrr[3].y=110;
}

if (buf[0]>=2){
bit2=1;
buf[0]=buf[0]-2;
rrrr[4].y=160;
}

if (buf[0]>=1){
bit3=1;
buf[0]=buf[0]-1;
rrrr[5].y=210;
}


xxx=xxx+10;
s++;


if (xxx>620) xxx=50;
if (s>1) s=0;
rrrr[0].x=xxx;
rrrr[1].x=xxx+10;
rrrr[2].x=xxx;
rrrr[3].x=xxx;
rrrr[4].x=xxx;
rrrr[5].x=xxx;
SDL_FillRect(sss,&rrrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_FillRect(sss,&rrrr[1],SDL_MapRGB(sss->format,0,0,0));
if (bit0==0)SDL_FillRect(sss,&rrrr[2],SDL_MapRGB(sss->format,255,0,0));
else SDL_FillRect(sss,&rrrr[2],SDL_MapRGB(sss->format,0,0,255));
if (bit1==0)SDL_FillRect(sss,&rrrr[3],SDL_MapRGB(sss->format,255,0,0));
else SDL_FillRect(sss,&rrrr[3],SDL_MapRGB(sss->format,0,0,255));
if (bit2==0)SDL_FillRect(sss,&rrrr[4],SDL_MapRGB(sss->format,255,0,0));
else SDL_FillRect(sss,&rrrr[4],SDL_MapRGB(sss->format,0,0,255));
if (bit3==0)SDL_FillRect(sss,&rrrr[5],SDL_MapRGB(sss->format,255,0,0));
else SDL_FillRect(sss,&rrrr[5],SDL_MapRGB(sss->format,0,0,255));
SDL_UpdateRects(sss,6,rrrr);
usleep(15000);
}while(a!=27); 
SDL_FreeSurface(sss);
close(f2);
buf[0]=1;
f1=open(ab,O_RDWR);
write(f1,buf,1);
close(f1);
wait();
}
return 0;
}


int main2()
{
char ttimes[25];
char tttimes[25];
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

int triger=0;
int cc0=0;
int cc1=0;
int cc2=0;
int cc3=0;
int v0=0;
int v1=0;
int v2=0;
int v3=0;
int f1;
int f2;
int f3;
int f4;
char t='0';
char buf[1];
char buf1[1];
long counter2=0;
int ccc=0;
int nnnull;
off_t lsek;

if (wiringPiSetup () == -1) return 1 ;
 
  pinMode (0, INPUT) ;         // aka BCM_GPIO pin 17
  pinMode (1, INPUT) ;         // aka BCM_GPIO pin 17 
  pinMode (2, INPUT) ;         // aka BCM_GPIO pin 17
  pinMode (3, INPUT) ;         // aka BCM_GPIO pin 17



f1=open(ab,O_RDWR);
f2=open(abc,O_RDWR);
f3=open(abcd,O_RDWR);
f4=open(abcde,O_RDWR);
lsek=lseek(f2,(off_t)0,SEEK_SET);
do{
gettimeofday(&start,NULL);
b=start.tv_sec;
lsek=lseek(f4,(off_t)0,SEEK_SET);
if (b>c){
lsek=lseek(f1,(off_t)0,SEEK_SET);
if (triger!=0)write(f3,&counter,sizeof(long));
gettimeofday(&ends,NULL);
c=ends.tv_sec;
time(&rawtime);
timeinfo=localtime(&rawtime);
sprintf (tttimes,"%s",ctime(&rawtime));
counter=0;
write(f3,&tttimes,25);
write(f3,&counter2,sizeof(long));
buf1[0]=0;
triger=1;
read(f1,buf1,1);
}

v0=1;
v1=1;
v2=1;
v3=1;
if (digitalRead (0)==1)v0=0;
if (digitalRead (1)==1)v1=0;
if (digitalRead (2)==1)v2=0;
if (digitalRead (3)==1)v3=0;
buf[0]=0;
if (v0==1)buf[0]=buf[0]+1;
if (v1==1)buf[0]=buf[0]+2;
if (v2==1)buf[0]=buf[0]+4;
if (v3==1)buf[0]=buf[0]+8;
write(f2,buf,1);
write(f4,buf,1);
cc0++;
cc1++;
cc2++;
cc3++;
ccc++;
if (cc0>1){
cc0=0;
v0++;
if (v0>1)v0=0;
}
if (cc1>2){
cc1=0;
v1++;
if (v1>1)v1=0;
}
if (cc2>3){
cc2=0;
v2++;
if (v2>1)v2=0;

}
if (cc3>4){
cc3=0;
v3++;
if (v3>1)v3=0;
}

counter++;
counter2++;
if (ccc>1)ccc=0;
}while(buf1[0]!=1); 
write(f3,&counter,sizeof(long));
close(f1);
close(f2);
close(f4);
close(f3);
return 0;
}















