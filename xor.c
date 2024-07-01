/*
 *    xor.c
 *    Routine for creating Graphics
 *    Context, or gc to be used for
 *    XOR-mode drawing.
 *
 *    Written for X Window Applications
 *    Programming, 2nd Edition
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *  Creates a graphics context with the given
 *  foreground and background pixel values
 *  (colors).
 */

GC CreateXorGC (
	Display        *display,
	Drawable        drawable,
	unsigned long   forecolor,
	unsigned long   backcolor
)
{
	XGCValues   xgcvalues;
	GC          gc;

	xgcvalues.foreground = forecolor ^ backcolor;
	xgcvalues.background = 0;
	xgcvalues.function   = GXxor;

	gc = XCreateGC (
		display, drawable,
		(GCForeground | GCBackground | GCFunction),
		&xgcvalues);

	return (gc);

}  /*  CreateXorGC  */

/* end of file xor.c */
