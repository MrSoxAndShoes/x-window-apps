/*
 *    pixmap.c
 *    Routine to update a window from a pixmap.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *    This routine assumes that the window and the bitmap
 *    share the same size, or close to the same size.
 */

void UpdateWindowFromBitmap (
	Display        *display,
	Window          window,
	GC              gc,
	Pixmap          bitmap,
	XExposeEvent   *event,
	int             max_width,
	int             max_height
)
{
	CopyPlane (
		display, bitmap, window, gc,
		event->x,     event->y,
		event->width, event->height,
		max_width,    max_height);
}  /*  UpdateWindowFromBitmap  */


void CopyPlane (
	Display   *display,
	Drawable   src_draw,
	Drawable   dest_draw,
	GC         gc,
	int        x,
	int        y,
	int        width,
	int        height,
	int        max_width,
	int        max_height
)
{
	/* make sure we update a valid area */
	if (
		((width  + x) <= max_width)  &&
		((height + y) <= max_height) &&
		(x < max_width && y <= max_height)
	)
	{
	 XCopyPlane (
	  	display, src_draw, dest_draw, gc,
	  	x, y, width, height,
	  	x, y, 0x01);
	}
}  /*  CopyPlane  */

/*  end of file pixmap.c  */
