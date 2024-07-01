/*
 *      wmname.c
 *      Code for setting a window name.
 *
 *      Written for X Window Applications
 *      Programming, 2nd Edition
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *    Give the window a name, in case the window
 *    manager provides a title bar (most do). We use
 *    the old, R# method here, to avoid  the complexities
 *    of the XTextProperty structures, which were
 *    introduced in X11 Release 4.
 */

void SetWindowName (Display *display, Window window, char *name)
{
	XStoreName (display, window, name);
}    /* SetWindowName */

/* end of file wmname.c */
