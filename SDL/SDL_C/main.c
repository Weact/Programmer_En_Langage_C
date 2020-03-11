#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "../../personalLIB/WeactLIB.h"

int main(int argc, char*argv[])
{
    printf("Hello world!\n");
    s(1);

    SDL_Window *pWindow=NULL;
    SDL_Renderer *pRenderer=NULL;
    SDL_Texture *pTexture=NULL;


    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        //Créer le pinteur sur la reference de la fenetre Win32
        pWindow = SDL_CreateWindow("SDL_APPLICATION",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

        //Si la fenetre créée
        if(pWindow != NULL)
        {
            pRenderer=SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }
    }


    SDL_SetRenderDrawColor(pRenderer, 0,255,0,255);
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);

    SDL_Delay(2000);

    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}
