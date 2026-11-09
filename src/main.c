#include <X11/Xlib.h>
#include <stdlib.h>

int main(void)
{
    Display *display = XOpenDisplay(NULL);
    if (!display)
        return EXIT_FAILURE;

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,
        800, 600,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XStoreName(display, window, "My Browser");
    XMapWindow(display, window);

    XEvent event;
    while (1) {
        XNextEvent(display, &event);

        if (event.type == DestroyNotify)
            break;
    }

    XCloseDisplay(display);
    return EXIT_SUCCESS;
}

