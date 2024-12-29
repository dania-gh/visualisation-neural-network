#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

void Circle(SDL_Renderer* renderer, int CX, int CY, int rayon) {
    int x = rayon, y = 0;
    int err = 0;

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, CX + x, CY + y);
        SDL_RenderDrawPoint(renderer, CX + y, CY + x);
        SDL_RenderDrawPoint(renderer, CX - y, CY + x);
        SDL_RenderDrawPoint(renderer, CX - x, CY + y);
        SDL_RenderDrawPoint(renderer, CX - x, CY - y);
        SDL_RenderDrawPoint(renderer, CX - y, CY - x);
        SDL_RenderDrawPoint(renderer, CX + y, CY - x);
        SDL_RenderDrawPoint(renderer, CX + x, CY - y);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void drawLine(SDL_Renderer* renderer, int x, int y, int w, int z) {
    SDL_RenderDrawLine(renderer, x, y, w, z);

}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Neural network",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800,
                                          600,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    
    int rayon = 50;     
    int vertical = 120;  
    

    int x_gauche=100;
    for(int i=0; i<1; i++){
        int y_gauche = 200 + i * vertical;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        Circle(renderer, x_gauche, y_gauche, rayon);
    }

    int x_milieu = 400;
    for (int i=0; i<3; i++)
    {
        int y_milieu = 100 + i * vertical;
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        Circle(renderer, x_milieu, y_milieu, rayon);
    }

    int x_droite = 700;
    for(int i=0; i<2; i++){
        int y_droite = 100 + i * vertical;
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        Circle(renderer, x_droite, y_droite, rayon);

    }
        


    SDL_RenderPresent(renderer);

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
