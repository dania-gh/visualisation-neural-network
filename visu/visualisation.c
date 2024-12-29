#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <math.h> // Pour sin()

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

    // Paramètres du réseau
    int num_layers = 5;                              // Nombre total de couches
    int neurons_per_layer[] = {1, 5, 2, 2, 2};       // Nombre de neurones par couche
    int layer_positions[] = {200, 300, 400, 500, 600}; // Positions Y des couches
    int r = 40;                                      // Rayon des neurones
    Uint32 duration_per_layer = 1000;                // Durée d'activation par couche (en ms)
    Uint32 startTime = SDL_GetTicks();               // Temps de départ de l'animation
    SDL_Event e;
    int quit = 0;

    int direction = 1; // Direction de l'animation : 1 = avancer, -1 = reculer
    int activeLayer = 0; // Couche active initiale

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        Uint32 elapsedTime = SDL_GetTicks() - startTime; // Temps écoulé depuis le début
        if (elapsedTime >= duration_per_layer) {
            startTime = SDL_GetTicks(); // Réinitialise le temps de départ

            // Change la couche active en fonction de la direction
            activeLayer += direction;
            if (activeLayer == num_layers - 1 || activeLayer == 0) {
                direction *= -1; // Inverse la direction à chaque extrémité
            }
        }

        float layerProgress = (float)(elapsedTime % duration_per_layer) / duration_per_layer; // Progression dans l'animation

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); // Efface l'écran avec une couleur sombre
        SDL_RenderClear(renderer);

        for (int layer = 0; layer < num_layers; layer++) {
            int num_neurons = neurons_per_layer[layer];
            int x_spacing = (width - 200) / (num_neurons + 1); // Espacement des neurones dans chaque couche

            // Détermine l'alpha (transparence) pour chaque couche
            int alpha = 70; // Par défaut, faible transparence
            if (layer == activeLayer) {
                alpha = 70 + (int)(185 * fabs(sin(M_PI * layerProgress))); // Transition fluide (sinus)
            }

            // Dessine les neurones
            for (int neuron = 0; neuron < num_neurons; neuron++) {
                int x_pos = 100 + (neuron + 1) * x_spacing;
                int y_pos = layer_positions[layer];

                // Couleur par couche
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

                // Dessine les connexions entre les couches
                if (layer > 0) {
                    int prev_num_neurons = neurons_per_layer[layer - 1];
                    int x_spacing_prev = (width - 200) / (prev_num_neurons + 1);

                    for (int prev_neuron = 0; prev_neuron < prev_num_neurons; prev_neuron++) {
                        int prev_x_pos = 100 + (prev_neuron + 1) * x_spacing_prev;
                        int prev_y_pos = layer_positions[layer - 1];

                        // Utilise la couleur du cercle actuel pour la ligne
                        lineRGBA(renderer, prev_x_pos, prev_y_pos, x_pos, y_pos, r_color, g_color, b_color, alpha);
                    }
                }
            }
        }

        SDL_RenderPresent(renderer); // Rafraîchit l'écran
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

