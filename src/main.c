#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>

#include "platform/x11_window.h"

int main(void)
{
    Display *display = XOpenDisplay(NULL);
    Window window = createWindow(display);
    Atom wm_delete = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wm_delete, 1);

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
        
        switch(event.type)
        {
            case KeyPress:
                printf("key pressed\n");
                break;

            case ClientMessage:
                if ((Atom)event.xclient.data.l[0] == wm_delete)
                    goto clean_up;
                break;
            
            case MotionNotify:
                printf("mouse position (%d, %d)\n", event.xmotion.x, event.xmotion.y);
                break;
        }
    }

clean_up:
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return EXIT_SUCCESS;
}
