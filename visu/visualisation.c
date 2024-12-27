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