/*
 *      sizehint.c
 *      Code for sending the size hints to the
 *      window manager.
 *
 *      Written for X Window Applications
 *      Programming, 2nd Edition
 *
 *      Note: if you have an X11 Release 4-based
 *      system (or higher), you should define the
 *      symbol X11R4, as R4 added some new (preferred)
 *      functions for setting window hints.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *  Calls FillSizeHints to set up 'XSizeHints'
 *  data structure and passes that on to the
 *  window manager
 */

void SetSizeHints (
	Display *display,              /* X server connection        */
	Window   window,               /* hints apply to this window */
	int      x,                    /* position and size          */
	int      y,
	int      width,
	int      height
)
{
	XSizeHints sizehints;

	/* Get hint values */
	FillSizeHints (x, y, width, height, &sizehints);

	/* XSetWMNormalHints is new to X11R4. */
	XSetWMNormalHints (display, window, &sizehints);
	/* Older, R2 - R3 routine.
	XSetNormalHints (display, window, &sizehints);
	*/
}

/*
 *    Fills in an XSizeHints structure. Note that we
 *    lie and say that the user picked the size and
 *    location (USPosition and USSize). We could use
 *    PPosition and PSize, but it's easier to place
 *    your window where you want.
 */

void FillSizeHints (
	int         x,            /* position and size */
	int         y,
	int         width,
	int         height,
	XSizeHints *sizehints     /* RETURN            */
)
{
  /* Set size hints */

	/* Obsolete as of X11R4
	sizehints->x            = x;
	sizehints->y            = y;
	sizehints->height       = height;
	sizehints->width        = width;
	*/

	sizehints->min_height   = height;
	sizehints->min_width    = width;
	sizehints->flags        = USPosition | USSize | PMinSize;

	sizehints->base_width   = width;
	sizehints->base_height  = height;
	sizehints->flags       |= PBaseSize;

}    /* FillSizeHints */

/* end of file sizehint.c */
