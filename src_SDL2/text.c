#include "include.h"
#include "SDL_TTF.h"
#include "SDL.h"

#include "text.h"
#include "graphics.h"
#include "imagen.h"
#include <stdio.h>


TTF_Font *font=0;

void textuaGaitu(void){
	font=TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\ARIAL.TTF", 16, 0);
	if(!font) 
  {
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
}

void textuaIdatzi(int x, int y, char *str)
{
  SDL_Surface* textSurface;
  SDL_Texture *mTexture;
  SDL_Color textColor = { 0XFF, 0XFF, 0XFF };
  //SDL_Color textColor = { 15, 1, 2 };
  SDL_Rect src, dst;
  SDL_Renderer* gRenderer;

  if (font == 0) return;
  gRenderer = getRenderer();
  textSurface = TTF_RenderText_Solid(font, str, textColor);
  mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
  src.x = 0; dst.x = x;
  src.y = 0; dst.y = y;
  src.w = dst.w = textSurface->w;
  src.h = dst.h = textSurface->h;
  SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
  SDL_FreeSurface(textSurface);
  SDL_DestroyTexture(mTexture);
}


void textuaDesgaitu(void)
{
  if (font != 0) TTF_CloseFont(font);
  font = 0;
}

void eskatuIzena(char* izena) {
    SDL_Event event;
    int irten = 1; //false
    *(izena) = 0;

    SDL_StartTextInput();
    //Hasta que el usuario salga
    while (irten == 1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN) //Si una tecla esta pulsada o se ha introducido texto
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && strlen(izena) > 0) *(izena + strlen(izena) -1) = '\0'; //Borrar un caracter del final
                else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RETURN)) irten = 0; //Tecla ENTER
                else if (event.type == SDL_TEXTINPUT)
                {
                    strcat(izena, event.text.text);
                    IZENA_erdianBistaratu(event.text.text);
                }
            }
            if (event.type == SDL_QUIT) irten = 0;
        }
    }
    SDL_StopTextInput();
}

void IZENA_erdianBistaratu(char* c)
{
    int static x = 600, y = 330;
    textuaIdatzi(x, y, c);
    x += 10;
    pantailaBerriztu();
}