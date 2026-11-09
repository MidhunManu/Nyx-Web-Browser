#include <X11/Xlib.h>
#include <stdlib.h>
#include "platform/x11_window.h"

int main(void)
{
    Display *display = XOpenDisplay(NULL);
    Window window = createWindow(display);

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

