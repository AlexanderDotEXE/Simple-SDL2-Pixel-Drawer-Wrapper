#ifndef SSPDW_H
#define SSPDW_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include <SDL2/SDL.h>


/**
 * @brief Initializes the drawing environment.
 * 
 * This function sets up all necessary resources and configurations
 * required for drawing operations. It should be called before any
 * drawing functions are used.
 * 
 * @param title The title of the window to be created.
 */
extern void initDrawing(const char* title);

/**
 * @brief Cleans up resources used for drawing.
 *
 * This function should be called to release any resources or perform
 * any necessary cleanup operations related to drawing. It is typically
 * called when the drawing operations are complete and the application
 * is shutting down or no longer needs to render graphics.
 */
extern void cleanupDrawing();

/**
 * @brief Renders a pixel on the screen with the specified color and alpha value at the given coordinates.
 * 
 * @param color The color of the pixel to be rendered, represented as an unsigned integer.
 * @param alpha The alpha value (transparency) of the pixel, represented as an unsigned char.
 * @param x The x-coordinate of the pixel on the screen.
 * @param y The y-coordinate of the pixel on the screen.
 */

extern void renderPx(unsigned int color, unsigned char alpha, int x, int y);
/**
 * @brief Presents the rendered frame to the display.
 *
 * This function is responsible for presenting the final rendered frame
 * to the display. It should be called after all rendering operations
 * for the current frame are complete.
 */
extern void renderPresent();

/**
 * @brief Delays the execution for a specified number of milliseconds.
 * 
 * This function uses SDL's delay functionality to pause the program's execution
 * for the given amount of time.
 * 
 * @param ms The number of milliseconds to delay.
 */
extern void sdlDelay(int ms);

/**
 * @brief Clears the screen.
 * 
 * This function clears the screen by filling it with a black color.
 */
extern void clearScreen();

/**
 * @brief Listens for a quit event.
 * 
 * This function waits for a quit event, such as a specific key press or window close event,
 * and returns an integer value indicating the result of the event.
 * 
 * @return int - The result of the quit event. 1 if the quit event occurred, 0 otherwise.
 */
extern int listenForQuit();
#endif // DRAW_H
