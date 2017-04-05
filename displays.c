
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
long nn=0;
int f1;
int f2;
int f3;
off_t lsek;
long pos=0;
char ccc=0;
long sizes=0;
long counter=0;
char enterl='\n';
char value=0;
char pvalue;
char   bit0=0;
char   bit1=0;
char   bit2=0;
char   bit3=0;
system ("sudo chmod 777 /mnt/ramdisk1/");
system ("sudo chmod 777 /mnt/ramdisk1/saida.dat");
system ("sudo chmod 777 /mnt/ramdisk1/saida.idx");
system ("sudo chmod 777 ./saida.txt");
f1=open(ab,O_RDWR);
f2=open(abc,O_RDWR);
f3=open(abcd,O_CREAT|O_RDWR);
long EOFs=0;
printf("\033c");
printf("%s - \n",ab);

do
{
printf("%lu -\t ",counter);
EOFs=read(f1,ttimes,25);
ttimes[20]=0;
printf("%s -\t ",ttimes);

EOFs=read(f1,&pos,sizeof(long));
EOFs=read(f1,&pos,sizeof(long));
printf("%lu \n",pos);
counter++;
}while(EOFs!=0);
printf("code to display? :");
scanf("%lu",&pos);
printf("\nworking...\n");
pos=pos*33;
lsek=lseek(f1,(off_t)pos,SEEK_SET);
EOFs=read(f1,ttimes,25);
ttimes[20]='\n';
EOFs=read(f1,&pos,sizeof(long));
EOFs=read(f1,&sizes,sizeof(long));
lsek=lseek(f2,(off_t)pos,SEEK_SET);
write(f3,&ttimes,20);
sprintf(ttimes,"%12lu",sizes);
write(f3,&enterl,sizeof(char));
write(f3,&ttimes,12);
write(f3,&enterl,sizeof(char));

do{
EOFs=read(f2,&value,sizeof(char));
bit0='0';
bit1='0';
bit2='0';
bit3='0';
if(value>=8){
value=value-8;
bit0='1';
} 

if(value>=4){
value=value-4;
bit1='1';
} 

if(value>=2){
value=value-2;
bit2='1';
} 

if(value>=1){
value=value-1;
bit3='1';
} 

write(f3,&bit0,sizeof(char));
write(f3,&bit1,sizeof(char));
write(f3,&bit2,sizeof(char));
write(f3,&bit3,sizeof(char));
write(f3,&enterl,sizeof(char));

sizes--;
}while(sizes > 0);
close(f3);
close(f1);
close(f2);
system ("sudo chmod 777 ./saida.txt");
system ("mousepad ./saida.txt");
return 0;
}


















