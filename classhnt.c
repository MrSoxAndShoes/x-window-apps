/*
 *      classhnt.c
 *      Code for sending class hints to
 *      the window manager.
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
 *    Sets the class hints (the WM_CLASS property)
 *    on the given window. res_name is usually
 *    argv[0] (the program's name) and res_class
 *    usually starts with an upper-case letter.
 */

void SetClassHints (
	Display *display,
	Window   window,
	char    *res_name,
	char    *res_class
)
{
	XClassHint   class_hints;

	class_hints.res_class = res_class;
	class_hints.res_name  = res_name;

	XSetClassHint (display, window, &class_hints);
}    /* SetClassHints */

/* end of file classhnt.c */
