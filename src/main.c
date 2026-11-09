#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>

#include "platform/x11_window.h"

int main(void)
{
    Display *display = XOpenDisplay(NULL);
    Window window = createWindow(display);

    XStoreName(display, window, "My Browser");
    XSelectInput(display, window, 
        KeyPressMask |
        KeyReleaseMask |
        ButtonPressMask |
        ButtonReleaseMask |
        PointerMotionMask
    );
    XMapWindow(display, window);

    XEvent event;
    while (1) {
        XNextEvent(display, &event);

        if (event.type == DestroyNotify)
            break;
        
        switch(event.type)
        {
            case KeyPress:
                printf("key pressed\n");
                break;

            case DestroyNotify:
                exit(EXIT_SUCCESS);
            
            case MotionNotify:
                printf("mouse position (%d, %d)\n", event.xmotion.x, event.xmotion.y);
                break;
        }
    }

    XCloseDisplay(display);
    return EXIT_SUCCESS;
}

