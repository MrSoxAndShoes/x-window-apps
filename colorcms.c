/*
 *     colorcms.c
 *     Device-indepentdent color cell routine for X.
 *
 *     Written for X Window Applications
 *     Programming, 2nd Edition
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xcms.h>

#include "xwin.h"

/*
 *    Allocates a read-only (sharable) color cell in
 *    the given colormap, using the X Color Management
 *    System routines to convert an arbitrary color
 *    name to an RGB value.
 */

unsigned long CmsAllocNamedColor (
	Display        *display,
	Colormap        colormap,
	char           *colorname,
	unsigned long   default_color
)
{   /* CmsAllocNamedColor */
	XcmsColor      hardwarecolor, exactcolor;
	unsigned long  color;
	int            status;

	status = XcmsAllocNamedColor(
		display, colormap,
		colorname, &hardwarecolor, &exactcolor,
		XcmsUndefinedFormat);

	if (status != XcmsFailure) {
		color = hardwarecolor.pixel;
	}
	else {
		printf("XcmsFailure on [%s]\n", colorname);
		color = default_color;
	}

	return color;
}   /* CmsAllocNamedColor */

/* end of file colorcms.c */
