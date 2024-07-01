/*
 *    bitmap.c
 *    Routines to load and save bitmap
 *    files.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

Pixmap LoadBitmap (
	Display       *display,
	Window         window,
	char          *filename,
	unsigned int  *width,  /* RETURNED size */
	unsigned int  *height
)
{
	int     x_hotspot, y_hotspot;
	int     status;
	Pixmap  pixmap;

	status = XReadBitmapFile (
		display, window, filename,
		width, height, &pixmap, &x_hotspot, &y_hotspot);

	if (status != BitmapSuccess) {
		pixmap = (Pixmap) None;
	}

	return (pixmap);
}  /*  LoadBitmap  */


int SaveBitmap (
	Display  *display,
	char     *filename,
	Pixmap    bitmap,
	int       width,
	int       height
)
{
	int  status;

	status = XWriteBitmapFile (
		display, filename, bitmap,
		width, height, -1, -1);  /* no hot spot */

	return (status);
}  /*  SaveBitmap  */

/* end of file bitmap.c */
