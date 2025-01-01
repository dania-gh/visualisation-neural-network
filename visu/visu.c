#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
int width = 1800;
int height = 950 ;

void neuralNetwork(SDL_Renderer* renderer,int r,int time){
    Uint32 startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+time)
    {
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        

        for (int i = 100; i <= 880; i += 80)
        {
        for (int j = 100; j <= 880; j += 80) {
        lineRGBA(renderer, 600, i, 900, j, i, 100, 200, 255); //line between fist and second layers
        lineRGBA(renderer, 900, i, 1200, j, 100, 200, i, 255);//line between second and third layers
        }
        }
        for (int i = 100; i <= 880; i += 80) {
        for(int j = 200 ; j<=800;j+=80)
        {
            lineRGBA(renderer, 300, j, 600, i, 204, 0, 0, 255);//lines between input and fist layer
        }



        lineRGBA(renderer, 1200, i, 1500, height / 2, 0,128,255, 255); //line between last layers and output

        filledCircleRGBA(renderer, 600, i, r, 30, 30, 30, 255); //first layer background
        filledCircleRGBA(renderer, 900, i, r, 30, 30, 30, 255);//second layer background
        filledCircleRGBA(renderer, 1200, i, r, 30, 30, 30, 255);//third layer background


        filledCircleRGBA(renderer, 600, i, r, i, 100, 200, 255); //first layer
        filledCircleRGBA(renderer, 900, i, r, 100, 200, i, 255);//second layer
        filledCircleRGBA(renderer, 1200, i, r, 100,i, 200, 255);//third layer
        }
        for(int i = 200 ; i<=800;i+=80 ){ //input node
            filledCircleRGBA(renderer, 300, i, r, 30, 30, 30, 255);
            filledCircleRGBA(renderer, 300,i, r, 204, 0, 0, 255);
        }


        //output node
        filledCircleRGBA(renderer, 1500, height/2, r, 30, 30, 30, 255);
        filledCircleRGBA(renderer, 1500, height/2, r, 0,128,255, 255);




        SDL_RenderPresent(renderer);

    }
}


int main(int argc, char* argv[]) {
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
SDL_Quit();
return 1;
}

if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
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

TTF_Font* font = TTF_OpenFont("font1.ttf", 24);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

int r =25;
Uint32 startTime2 = SDL_GetTicks();
SDL_Event e; /*pour garder la fenetre ouverte */
int quit = 0;
while (!quit && SDL_GetTicks()<= startTime2+6000 ) { 
while (SDL_PollEvent(&e) != 0) { 
if (e.type == SDL_QUIT) {   
quit = 1;  
}
}
    
    neuralNetwork(renderer, r,1000);

    SDL_Color textColor = {255, 255, 255, 255};//set color of text
    SDL_Texture* textTexture;

    Uint32 startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+1500)//to print x for 2000ms
    {
        
        int j = 1;
        char str1[] = "x";
        char str2[50];
        
        for(int i = 200 ; i<=800;i+=80 ){ //input node
        filledCircleRGBA(renderer, 300,i, r+10, 204, 0, 0, 255);//drow the x node bigger

        // concatinate 2 string#
        sprintf(str2, "%d", j);
        char finalStr[100]; 
        strcpy(finalStr, str1); 
        strcat(finalStr, str2);

        // display x on node
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, finalStr, textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect textRect = {290, i-10, 30, 30};//{x,y,w,h}
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        j++;
        }
        SDL_RenderPresent(renderer);
        
    }

    neuralNetwork(renderer, r,1000);

    startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+1500)//to print y for 2000ms
    {   

        filledCircleRGBA(renderer, 1500, height/2, r+10, 0,128,255, 255);// drow y node bigger

        //display Y test
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Y", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect textRect = {1500-10, height/2-10, 30, 30};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_RenderPresent(renderer);
    }

    neuralNetwork(renderer, r,1000);


    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
}

int alpha1, alpha2,alpha3,alpha4,alpha5;

Uint32 startTime = SDL_GetTicks();
Uint32 duration = 1000;

quit = 0;
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
alpha1 = 70; 
alpha2 = 70;
alpha3 = 70;
alpha4 = 70;
alpha5 = 70;

if (SDL_GetTicks() - startTime < duration) {
alpha1 = 255; 

}else if(SDL_GetTicks() - startTime >= duration && SDL_GetTicks() - startTime < duration + 1000){
alpha1 = 70; 
alpha2 = 255;

}
else if(SDL_GetTicks() - startTime >= duration+1000 && SDL_GetTicks() - startTime < duration + 2000){

alpha2 = 70;
alpha3 = 255;


}else if(SDL_GetTicks() - startTime >= duration+2000 && SDL_GetTicks() - startTime < duration + 4000)
{

alpha3 = 70;
alpha4 = 255;

if( SDL_GetTicks() - startTime > duration + 3000)
{
alpha4 = 70;
alpha5 = 255;
} 
}else if(SDL_GetTicks() - startTime >= duration+4000 && SDL_GetTicks() - startTime < duration + 5000)
{

alpha4 = 255;
alpha5 = 70;
}
else if (SDL_GetTicks() - startTime >= duration+5000 && SDL_GetTicks() - startTime < duration + 6000){

alpha3 = 255;
alpha4 = 70;

}else if(SDL_GetTicks() - startTime >= duration+6000 && SDL_GetTicks() - startTime < duration + 7000){
    
    alpha2 = 255;
    alpha3 = 70;
    
}
else if(SDL_GetTicks() - startTime >= duration+7000 && SDL_GetTicks() - startTime < duration + 8000){
    alpha1 = 255; 
    alpha2 = 70;
    
}else{
alpha1 = 70; 

}



int r =25;

for (int i = 100; i <= 880; i += 80)
{
for (int j = 100; j <= 880; j += 80) {
lineRGBA(renderer, 600, i, 900, j, i, 100, 200, alpha2); //line between fist and second layers
lineRGBA(renderer, 900, i, 1200, j, 100, 200, i, alpha3);//line between second and third layers
}
}
for (int i = 100; i <= 880; i += 80) {
for(int j = 200 ; j<=800;j+=80)
{
    lineRGBA(renderer, 300, j, 600, i, 204, 0, 0, alpha1);//lines between input and fist layer
}



lineRGBA(renderer, 1200, i, 1500, height / 2, 0,128,255, alpha4); //line between last layers and output

filledCircleRGBA(renderer, 600, i, r, 30, 30, 30, 255); //first layer background
filledCircleRGBA(renderer, 900, i, r, 30, 30, 30, 255);//second layer background
filledCircleRGBA(renderer, 1200, i, r, 30, 30, 30, 255);//third layer background


filledCircleRGBA(renderer, 600, i, r, i, 100, 200, alpha2); //first layer
filledCircleRGBA(renderer, 900, i, r, 100, 200, i, alpha3);//second layer
filledCircleRGBA(renderer, 1200, i, r, 100,i, 200, alpha4);//third layer
}
for(int i = 200 ; i<=800;i+=80 ){ //input node
    filledCircleRGBA(renderer, 300, i, r, 30, 30, 30, 255);
    filledCircleRGBA(renderer, 300,i, r, 204, 0, 0, alpha1);
}


//output node
filledCircleRGBA(renderer, 1500, height/2, r, 30, 30, 30, 255);
filledCircleRGBA(renderer, 1500, height/2, r, 0,128,255, alpha5);





SDL_RenderPresent(renderer);

//SDL_Delay(5000);


}

SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;
}