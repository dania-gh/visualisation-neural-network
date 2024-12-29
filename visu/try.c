#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
int width = 1000;
int height = 1000 ;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2_gfx Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    

    int r = 40;
    
    for (int i = 200; i <= 800; i += 200)
    {
        for (int j = 200; j <= 800; j += 200) {
        lineRGBA(renderer, 350, i, 650, j, i, 100, 200, 255);
    }
    }
    for (int i = 200; i <= 800; i += 200) {
    
    lineRGBA(renderer, 100, height / 2 - 100, 350, i, 204, 0, 0, 255); 
    lineRGBA(renderer, 100, height / 2 + 100, 350, i, 255, 128, 0, 255);
    lineRGBA(renderer, 650, i, 900, height / 2, 0,128,255, 255); 

    
    filledCircleRGBA(renderer, 350, i, r, i, 100, 200, 255); 
    filledCircleRGBA(renderer, 650, i, r, 100, 200, i, 255);
    }


    filledCircleRGBA(renderer, 100, height/2-100, r, 204, 0, 0, 255);
    filledCircleRGBA(renderer, 100, height/2+100, r, 255, 128, 0, 255);
    filledCircleRGBA(renderer, 900, height/2, r, 0,128,255, 255);

    SDL_RenderPresent(renderer);

    //SDL_Delay(5000);

    SDL_Event e; /*pour garder la fenetre ouverte */
    int quit = 0;
     while (!quit) { 
        while (SDL_PollEvent(&e) != 0) { 
            if (e.type == SDL_QUIT) {   
                quit = 1;  
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
