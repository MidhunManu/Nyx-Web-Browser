#include <stdlib.h>
#include "x11_window.h"

Window createWindow(Display *display)
{
    if (!display)
        return EXIT_FAILURE;

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,
        1000, 700,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    return window;
}
