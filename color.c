/*
 *        color.c
 *        Color cell routine for X.
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
 *    Allocates a read-only (sharable) color cell in
 *    the given colormap, using the RGB database to
 *    convert the color name to an RGB value.
 */

ulong AllocNamedColor (
	Display  *display,
	Colormap  colormap,
	char     *colorname,
	ulong     default_color
)
{
	XColor   hardwarecolor, exactcolor;
	ulong    color;
	int      status;

	status = XAllocNamedColor(
		display, colormap,
		colorname,
		&hardwarecolor,
		&exactcolor);

	color = (status != 0) ? hardwarecolor.pixel : default_color;

	return (color);

}    /* AllocNamedColor */

/* end of file color.c */
