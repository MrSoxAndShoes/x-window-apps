/*
 *        gc.c
 *        Routine for creating a graphics
 *        context.
 *
 *        Written for X Window Applications
 *        Programming, 2nd Edition
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *    Creates a graphics context with the given
 *    foreground and background pixel values
 *    (colors).
 */

GC CreateGC (
	Display   *display,
	Drawable   drawable,
	ulong      forecolor,
	ulong      backcolor
)
{
	XGCValues  xgcvalues;
	GC         gc;

	xgcvalues.foreground = forecolor;
	xgcvalues.background = backcolor;

	gc = XCreateGC (
		display, drawable,
		(GCForeground | GCBackground),
		&xgcvalues);

	return (gc);
}    /* CreateGC */

/* end of file gc.c */
