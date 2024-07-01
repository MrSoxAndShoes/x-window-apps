/*
 *        colormap.c
 *        Colormap function.
 *
 *        Written for X Window Applications
 *        Programming, 2nd Edition
 *
 *        Modified by Erik W. Anderson, May 17, 1993
 *
 *        Only creates the colormap; the calling program
 *        must associate (via XSetWindowColormap) each
 *        window created with the colormap.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *    SetUpColormap creates an X colormap using
 *    the given screen and visual. Uses the default
 *    colormap, if possible, to avoid technicolor
 *    effects on the screen as the mouse is moved.
 */

int SetUpColormap (
	Display  *display,
	int       screen,
	Window    window,
	Visual   *visual,
	Colormap *colormap
)
{
	int status = False;

	if (visual == DefaultVisual (display, screen)) {
		*colormap = DefaultColormap (display, screen);
		status   = True;
	}
	else {
		/*
		 *    Create a colormap using the
		 *    visual found in SetUpVisual.
		 */

		*colormap = XCreateColormap (display, window, visual, AllocNone);

		/* Check for failure */

		if (*colormap != None) {
			/*
			 *    Use this in calling program!
			 *    XSetWindowColormap (display, window, *colormap);
			 *
			 */
			status = True;
		}
		else {
			/* At least have a colormap anyway. */

			*colormap = DefaultColormap (display, screen);
		}
	}

	return (status);

}    /* SetUpColormap */

/* end of file colormap.c */
