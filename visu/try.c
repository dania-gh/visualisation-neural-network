
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

    SDL_Window* window = SDL_CreateWindow("Neural Network Visualisation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
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

    int num_layers=3;
    int neurons_per_layer[]={2,3,1};
    int layer_positions[]={200,400,600};
    int r=40;

    int alpha1, alpha2,alpha3,alpha4;
    
    Uint32 startTime = SDL_GetTicks();
    Uint32 duration = 1000;
    SDL_Event e; /*pour garder la fenetre ouverte */
    int quit = 0;
     while (!quit) { 
        while (SDL_PollEvent(&e) != 0) { 
            if (e.type == SDL_QUIT) {   
                quit = 1;  
            }
        }

    Uint32 elapsedTime = SDL_GetTicks() - startTime;
    if (elapsedTime > 8 * duration ) {
        startTime = SDL_GetTicks();
        elapsedTime = 0;
    }

    
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    
    if (SDL_GetTicks() - startTime < duration) {
            
            alpha1 = 255; 
            alpha2 = 70;
            alpha3 = 70;
            alpha4 = 70;
        }
    else if(SDL_GetTicks() - startTime >= duration && SDL_GetTicks() - startTime < duration + 1000){
        alpha1 = 70; 
            alpha2 = 255;
            alpha3 = 70;
            alpha4 = 70;
    }
    else if(SDL_GetTicks() - startTime >= duration+1000 && SDL_GetTicks() - startTime < duration + 3000){
        alpha1 = 70; 
            alpha2 = 70;
            alpha3 = 255;
            if( SDL_GetTicks() - startTime > duration + 2000)
            {
                alpha3 = 70;
                alpha4 = 255;
            }  
    }else if(SDL_GetTicks() - startTime >= duration+3000 && SDL_GetTicks() - startTime < duration + 4000)
    {
        alpha1 = 70; 
            alpha2 = 70;
            alpha3 = 255;
            alpha4=70;
    }else if(SDL_GetTicks() - startTime >= duration+4000 && SDL_GetTicks() - startTime < duration + 5000)
    {
        alpha1 = 70; 
            alpha2 = 255;
            alpha3 = 70;
            alpha4 = 70;
    }
    else if (SDL_GetTicks() - startTime >= duration+5000 && SDL_GetTicks() - startTime < duration + 6000){
        alpha1 = 255; 
            alpha2 = 70;
            alpha3 = 70;
            alpha4 = 70;
    }
    else{
        alpha1 = 70; 
            alpha2 = 70;
            alpha3 = 70;
            alpha4 = 70;
    }

    for (int layer = 0; layer < num_layers; layer++) {
            int num_neurons = neurons_per_layer[layer];
            int x_spacing = (width - 200) / (num_neurons + 1);
    }

    for(int neuron = 0; neuron < num_neurons; neuron++){
        int x_pos=100+(neuron+ 1 )*x_spacing;
        int y_pos=layer_positions[layer];
        int alpha=255;

        if (layer == 0) {
                    filledCircleRGBA(renderer, x_pos, y_pos, r, 204, 0, 0, alpha1); 
                } else if (layer == 1) {
                    filledCircleRGBA(renderer, x_pos, y_pos, r, 255, 128, 0, alpha2);
                } else {
                    filledCircleRGBA(renderer, x_pos, y_pos, r, 0, 128, 255, alpha3); 
                }
            }if (layer == 0) {
                    filledCircleRGBA(renderer, x_pos, y_pos, r, 204, 0, 0, alpha1); 
                } else if (layer == 1) {
                    filledCircleRGBA(renderer, x_pos, y_pos, r, 255, 128, 0, alpha2);
                } else {
                    filledCircleRGBA(renderer, x_pos, y_pos, r, 0, 128, 255, alpha3); 
                }
            }

            if (layer > 0) {
                int prev_num_neurons = neurons_per_layer[layer - 1];
                int x_spacing_prev = (width - 200) / (prev_num_neurons + 1)
                                for (int prev_neuron = 0; prev_neuron < prev_num_neurons; prev_neuron++) {
                    int prev_x_pos = 100 + (prev_neuron + 1) * x_spacing_prev;
                    int prev_y_pos = layer_positions[layer - 1];
                    for (int neuron = 0; neuron < num_neurons; neuron++) {
                        int current_x_pos = 100 + (neuron + 1) * x_spacing;
                        int current_y_pos = layer_positions[layer];

                    
                        if (layer == 1) {
                            lineRGBA(renderer, prev_x_pos, prev_y_pos, current_x_pos, current_y_pos, 255, 128, 0, alpha2); // Couleur de la couche 2
                        } else if (layer == 2) {
                            lineRGBA(renderer, prev_x_pos, prev_y_pos, current_x_pos, current_y_pos, 0, 128, 255, alpha3); // Couleur de la couche 3
                        }
                    }
                }
            }
        }





   