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

int main(){
SDL_Rect r[3];
char a;
SDL_Surface *s;
SDL_Surface *i;
r[0] = {0 ,0 ,639 ,479 };
r[1] = {0 ,0 ,639,15 };
r[2] = {100 ,150 ,50 ,50 };
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO==-1)){
printf("error:%s",SDL_GetError());
exit(-1);
}



atexit(SDL_Quit);

s=SDL_SetVideoMode(640,480,8,0);
if (s==NULL){
printf ("video mode size error:",SDL_GetError());
}

SDL_FillRect(s,&r[0],SDL_MapRGB(s->format,255,255,255));
SDL_FillRect(s,&r[1],SDL_MapRGB(s->format,128,128,255));
SDL_FillRect(s,&r[2],SDL_MapRGB(s->format,25,0,0));

SDL_UpdateRects(s,3,r);

a=fgetc(stdin);

SDL_FreeSurface(s);

return (0);
}













