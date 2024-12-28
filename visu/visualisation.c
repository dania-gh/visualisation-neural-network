#include <SDL2/SDL.h> 
#include <stdio.h>   
#include<math.h> 



void Circle(SDL_Renderer* renderer,int CX,int CY,int rayon){
    for(int i=0; i<360; i++){
        double angle = i * M_PI / 180.0;
        int x = CX + rayon * cos(angle);
        int y = CY + rayon * sin(angle);
        SDL_RenderDrawPoint(renderer, x, y);
    }
}



void drawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2){
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    
}



int main(int argc, char* argv[]) {
    

    if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
        return -1; 
    }

    
    SDL_Window* window = SDL_CreateWindow("Neural network",            
                                        SDL_WINDOWPOS_CENTERED,  
                                        SDL_WINDOWPOS_CENTERED,  
                                        800,   /*largeur et hauteur */                    
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

    Circle(renderer,400,300,100);
    drawLine(renderer, 100, 100, 700, 100);

    SDL_RenderPresent(renderer);

    
    SDL_Event e; /*pour garder la fenetre ouverte */
    int quit = 0;  

    /*j'ai utiliser cette boucle pour que la fenetre n'est pas de temps limitee */
    while (!quit) { 
        while (SDL_PollEvent(&e) != 0) { 
            if (e.type == SDL_QUIT) {   
                quit = 1;  
            }
        }
    }

    
    SDL_DestroyWindow(window);  /*detruire la fenetre*/
    SDL_Quit();                  

    return 0; 
}
