#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <math.h>

int width = 1000;
int height = 1000;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Neural Network Animation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
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

    int num_layers = 5;
    int neurons_per_layer[] = {1, 5, 2, 2, 2};
    int layer_positions[] = {200, 300, 400, 500, 600};
    int r = 40;
    Uint32 duration_per_layer = 1000;
    Uint32 startTime = SDL_GetTicks();
    SDL_Event e;
    int quit = 0;

    int direction = 1;
    int activeLayer = 0;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if (elapsedTime >= duration_per_layer) {
            startTime = SDL_GetTicks();
            activeLayer += direction;
            if (activeLayer == num_layers - 1 || activeLayer == 0) {
                direction *= -1;
            }
        }

        float layerProgress = (float)(elapsedTime % duration_per_layer) / duration_per_layer;

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        for (int layer = 0; layer < num_layers; layer++) {
            int num_neurons = neurons_per_layer[layer];
            int y_spacing = (height - 200) / (num_neurons + 1);

            int alpha = 70;
            if (layer == activeLayer) {
                alpha = 70 + (int)(185 * fabs(sin(M_PI * layerProgress)));
            }

            for (int neuron = 0; neuron < num_neurons; neuron++) {
                int y_pos = 100 + (neuron + 1) * y_spacing;
                int x_pos = layer_positions[layer];

                int r_color, g_color, b_color;
                if (layer == 0) {
                    r_color = 204; g_color = 0; b_color = 0;
                } else if (layer == 1) {
                    r_color = 255; g_color = 128; b_color = 0;
                } else if (layer == 2) {
                    r_color = 0; g_color = 128; b_color = 255;
                } else if (layer == 3) {
                    r_color = 0; g_color = 255; b_color = 0;
                } else if (layer == 4) {
                    r_color = 255; g_color = 0; b_color = 255;
                }

                filledCircleRGBA(renderer, x_pos, y_pos, r, r_color, g_color, b_color, alpha);

                if (layer > 0) {
                    int prev_num_neurons = neurons_per_layer[layer - 1];
                    int y_spacing_prev = (height - 200) / (prev_num_neurons + 1);

                    for (int prev_neuron = 0; prev_neuron < prev_num_neurons; prev_neuron++) {
                        int prev_x_pos = layer_positions[layer - 1];
                        int prev_y_pos = 100 + (prev_neuron + 1) * y_spacing_prev;

                        lineRGBA(renderer, prev_x_pos, prev_y_pos, x_pos, y_pos, r_color, g_color, b_color, alpha);
                    }
                }
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
