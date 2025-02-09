/**
 * @file draw.c
 * @brief This file contains the implementation of drawing functions.
 *
 * This file includes the header file "draw.h" which contains the declarations
 * of the drawing functions. The function initDrawing() is defined in this file.
 */

#include <SDL2/SDL.h>

#include "SSPDW.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FOV 50.0  // Als double für genauere Berechnungen

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("DBG: Could not init SDL! SDL_Error: %s\n", SDL_GetError());
    } else {
        printf("DBG: SDL init\n");
    }
}

SDL_Window* createSDLWindow(const char *title) {
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("DBG: Could not create Window! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    } else {
        printf("DBG: Fenster erstellt\n");
    }
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("DBG: Renderer konnte nicht erstellt werden! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    } else {
        printf("DBG: Renderer erstellt\n");
    }
    return renderer;
}

void cleanupDrawing() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    printf("DBG: SDL terminated\n");
}

void initDrawing(const char* title) {
    printf("DBG: Initializing drawing\n");
    initSDL();
    printf("DBG: SDL initialized\n");
    window = createSDLWindow(title);
    renderer = createRenderer(window);
    printf("DBG: SDL variables initialized\n");
    clearScreen();
    printf("DBG: Drawing fully initialized\n");
}


void renderPx(unsigned int color, unsigned char alpha, int x, int y) {
    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) {
        printf("DBG: Pixel out of bounds (%d, %d)\n", x, y);
        return;
    }

    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = color & 0xFF;

    SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
    SDL_RenderDrawPoint(renderer, x, y);
}

void renderPresent() {
    SDL_RenderPresent(renderer);
}

void sdlDelay(int ms) {
    SDL_Delay(ms);
}

void clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

int listenForQuit()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return 1;
        }
    }

    return 0;
}
