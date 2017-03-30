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
char a;
char f;
SDL_Surface *s;
SDL_Surface *i;
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO==-1)){
printf("error:%s",SDL_GetError());
exit(-1);
}



atexit(SDL_Quit);

s=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
if (s==NULL){
printf ("video mode size error:",SDL_GetError());
}

i=SDL_LoadBMP("128.bmp");
if (i->format->palette && s->format->palette){
SDL_SetColors(s,i->format->palette->colors,0,
i->format->palette->ncolors);
}

if (SDL_BlitSurface(i,NULL,s,NULL)<0){
printf ("surface error:",SDL_GetError());
}

SDL_UpdateRect(s,0,0,i->w,i->h);

a=fgetc(stdin);

SDL_FreeSurface(i);

return (0);
}













