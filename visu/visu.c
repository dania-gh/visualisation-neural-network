#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
int width = 1800;
int height = 950 ;

void neuralNetwork(SDL_Renderer* renderer,int r,int time,int a){
    Uint32 startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+time)
    {
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        

        for (int i = 100; i <= 880; i += 80)
        {
        for (int j = 100; j <= 880; j += 80) {
        lineRGBA(renderer, 600, i, 900, j, i, 100, 200, a); //line between fist and second layers
        lineRGBA(renderer, 900, i, 1200, j, 100, 200, i, a);//line between second and third layers
        }
        }
        for (int i = 100; i <= 880; i += 80) {
        for(int j = 200 ; j<=800;j+=80)
        {
            lineRGBA(renderer, 300, j, 600, i, 204, 0, 0, a);//lines between input and fist layer
        }



        lineRGBA(renderer, 1200, i, 1500, height / 2, 0,128,255, a); //line between last layers and output

        filledCircleRGBA(renderer, 600, i, r, 30, 30, 30, 255); //first layer background
        filledCircleRGBA(renderer, 900, i, r, 30, 30, 30, 255);//second layer background
        filledCircleRGBA(renderer, 1200, i, r, 30, 30, 30, 255);//third layer background


        filledCircleRGBA(renderer, 600, i, r, i, 100, 200, a); //first layer
        filledCircleRGBA(renderer, 900, i, r, 100, 200, i, a);//second layer
        filledCircleRGBA(renderer, 1200, i, r, 100,i, 200, a);//third layer
        }
        for(int i = 200 ; i<=800;i+=80 ){ //input node
            filledCircleRGBA(renderer, 300, i, r, 30, 30, 30, 255);
            filledCircleRGBA(renderer, 300,i, r, 204, 0, 0, a);
        }


        //output node
        filledCircleRGBA(renderer, 1500, height/2, r, 30, 30, 30, 255);
        filledCircleRGBA(renderer, 1500, height/2, r, 0,128,255, a);




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
SDL_Color textColor = {255, 255, 255, 255};//set color of text
SDL_Texture* textTexture;
SDL_Surface* textSurface;

int r =25;



    neuralNetwork(renderer, r,1000,255);
    neuralNetwork(renderer, r,1000,150);

    

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
        textSurface = TTF_RenderText_Solid(font, finalStr, textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect textRect = {290, i-10, 30, 30};//{x,y,w,h}
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        j++;
        }
        SDL_RenderPresent(renderer);
        
    }

    neuralNetwork(renderer, r,1000,150);

    startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+1500)//to print y for 2000ms
    {   

        filledCircleRGBA(renderer, 1500, height/2, r+10, 0,128,255, 255);// drow y node bigger

        //display Y test
        textSurface = TTF_RenderText_Solid(font, "Y", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect textRect = {1500-10, height/2-10, 30, 30};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_RenderPresent(renderer);
    }

    neuralNetwork(renderer, r,1000,150);

    startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+5000)//segmoid zoomed
    {   
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);

        lineRGBA(renderer, 600,300, 1400,500,100, 200, 100, 255);//input 1 line
        lineRGBA(renderer, 600,700, 1400,500, 100, 200, 100, 255);// input 2 line

        filledCircleRGBA(renderer, 600,300, r*4, 204, 0, 0, 255);//input 1
        filledCircleRGBA(renderer, 600,700, r*4, 204, 0, 0, 255);// input 2
        filledCircleRGBA(renderer, 1400,500, r*7, 200, 100, 200, 255);// 3th node

        textSurface = TTF_RenderText_Solid(font, "Forword propagation", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect textRect = {20, 20, 300, 100};//{x,y,w,h}
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        if (SDL_GetTicks() > startTime1+1000){
            textSurface = TTF_RenderText_Solid(font, "X1", textColor);//write x1 in node 1
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_FreeSurface(textSurface);
            SDL_Rect textRect1 = {600-20,300-20, 70, 40};
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect1);
            

            textSurface = TTF_RenderText_Solid(font, "X2", textColor);//write x2 in node 2
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_FreeSurface(textSurface);
            SDL_Rect textRect2 = {600-20,700-20, 70, 40};
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect2);
        }
        
        if (SDL_GetTicks() > startTime1+2000){
            textSurface = TTF_RenderText_Solid(font, "w1", textColor);//write w1 in line 1
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_FreeSurface(textSurface);
            SDL_Rect textRect4 = {1000,350, 70, 40};
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect4);

            textSurface = TTF_RenderText_Solid(font, "w2", textColor);//write w2 in line 2
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_FreeSurface(textSurface);
            SDL_Rect textRect3 = {1000,600, 70, 40};
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect3);
        }
        
        if (SDL_GetTicks() > startTime1+3000){
        textSurface = TTF_RenderText_Solid(font, "x1*w1 + x2*w2 + bias", textColor);//write x1*w1 + x2*w2 + bias
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        textRect.x = 1260;
        textRect.y = 470;
        textRect.w = 300;
        textRect.h = 60;
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        }
        

        SDL_RenderPresent(renderer);
    }


      

    /*startTime1 = SDL_GetTicks();
    while(SDL_GetTicks() < startTime1+1500)//to make hidden layer node bigger
    { 
        for (int i = 100; i <= 880; i += 80) {
        
        filledCircleRGBA(renderer, 600, i, r+10, i, 100, 200, 255); //first layer
        filledCircleRGBA(renderer, 900, i, r+10, 100, 200, i, 255);//second layer
        filledCircleRGBA(renderer, 1200, i, r+10, 100,i, 200, 255);//third layer

        
        }
        SDL_RenderPresent(renderer);
    }*/

    //neuralNetwork(renderer, r,1000,255);

   


int alpha1, alpha2,alpha3,alpha4,alpha5;

Uint32 startTime = SDL_GetTicks();
Uint32 duration = 1000;


SDL_Event e;
int quit = 0;
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


if(SDL_GetTicks() - startTime < duration + 3000){
    textSurface = TTF_RenderText_Solid(font, "Forword propagation", textColor);
}else {
    textSurface = TTF_RenderText_Solid(font, "Back propagation", textColor);
}
textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
SDL_FreeSurface(textSurface);
SDL_Rect textRect = {20, 20, 300, 100};//{x,y,w,h}
SDL_RenderCopy(renderer, textTexture, NULL, &textRect);


SDL_RenderPresent(renderer);

//SDL_Delay(5000);


}
SDL_DestroyTexture(textTexture);
TTF_CloseFont(font);
TTF_Quit();
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 0;
}