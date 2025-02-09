# Simple SDL2 Pixel Drawer Wrapper

A minimal, straightforward C++ wrapper for [SDL2](https://www.libsdl.org/) that enables you to draw individual pixels onto a window. This wrapper is designed to make pixel-level manipulation easy for those experimenting with graphics, game development, or educational projects.

## Features

- Simple API to set or clear individual pixels.
- Easy initialization and cleanup of SDL.
- Lightweight and minimal wrapper around SDL2.
- Perfect for small prototypes or learning how to manipulate graphics at the pixel level.
- Valid C and C++ Code

## Getting Started

### Prerequisites

- [SDL2](https://www.libsdl.org/) library
- A C/C++ compiler (e.g., gcc, clang++)

### Building

1. Clone the repository:

   ```bash
   git clone https://github.com/AlexanderDotEXE/Simple-SDL2-Pixel-Drawer-Wrapper.git
   ```

2. Build with gcc (recommended):

   ```bash
   gcc -o ./build/sspdw/ SSPDW.c
   ```

### Usage

1. Include the header file in your C++ project:

   ```cpp
   #include "SSPDW.h"
   ```

2. Create an instance, initialize it, and start drawing pixels:

   ```cpp
   #include "SSPDW.h"

   int main(int argc, char const *argv[])
   {
    initDrawing("Hello World");
    
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        if(listenForQuit()) break;

        for (int j = 0; j < SCREEN_HEIGHT; j++)
        {
            renderPx(0x00FF00, 0xFF, i, j);
        }
        renderPresent();
        sdlDelay(10);
    }

    cleanupDrawing();
    return 0;
   }
   ```

3. Compile and run the example:

   ```bash
   g++ -o main main.cpp SSPDW.c -lSDL2
   ./main
   ```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests if you find any bugs or want to add new features.

## License

This project is released under the [MIT License](LICENSE). Feel free to use it as you like, but please give credit where credit is due.

---

**Enjoy drawing pixels with Simple SDL2 Pixel Drawer Wrapper!** If you have questions, feel free to open an issue on the repository.
