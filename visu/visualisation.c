#include <SDL2/SDL.h> 
#include <stdio.h>    

int main(int argc, char* argv[]) {
    
    // Step 1: Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); 
        return -1; 
    }

    // Step 2: Create a window
    SDL_Window* window = SDL_CreateWindow("SDL Window",            
                                        SDL_WINDOWPOS_CENTERED,  
                                        SDL_WINDOWPOS_CENTERED,  
                                        800,                       // Width
                                        600,                       // Height
                                        SDL_WINDOW_SHOWN);        // Show window

    // Check if window creation failed
    if (!window) { 
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); 
        SDL_Quit(); 
        return -1; 
    }

    // Step 3: Event loop
    SDL_Event e; 
    int quit = 0;  

    // Keep the window open until the user closes it
    while (!quit) { 
        while (SDL_PollEvent(&e) != 0) { 
            if (e.type == SDL_QUIT) {   
                quit = 1;  // Set quit to 1 when window close event is detected
            }
        }
    }

    // Step 4: Clean up and quit
    SDL_DestroyWindow(window);  
    SDL_Quit();                  // Quit SDL

    return 0; 
}
