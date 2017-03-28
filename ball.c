#include<graphics.h> 
int main()
{
char a;

   int gd = DETECT,gm,b=0,x= 50,y=50,r=10,xmax=300,ymax=200,min=20,xadd=1,yadd=1;
long c=0;   
initgraph(&gd,&gm,NULL);
setbkcolor(15);
setcolor(2);
setfontcolor(2);

do{
x=x+xadd;
y=y+yadd;
if (x > xmax) xadd=-1;
if (y > ymax) yadd=-1;
if (x < min) xadd=1;
if (y < min) yadd=1;
setcolor(2);
circle(x,y,r);
fillellipse(x,y, 10 , 10);
delay(1);
b=kbhit();
setcolor(15);
fillellipse(x-3,y-3, 16 , 16);


}while(!b);
 
   closegraph();
   return 0;
}














