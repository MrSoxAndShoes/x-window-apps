/*
 *    geometry.c
 *    Routines to find and parse the geomtery string.
 *    Geometry strings are used to specify the
 *    size and location of a window, from the
 *    command-line.
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
 *    Searches the command-line parameters for a
 *    window geometry option. If the "-geometry"
 *    option is found, then the command-line
 *    parameter following the "-geometry" is
 *    copied to a string. This string is then
 *    parsed to pull out an x,y location and
 *    a width, height size, if these are
 *    part of the geometry string.
 *    Note that we are really only looking
 *    for "-geom" to allow users to type
 *    in a shorthand fpr "-geometry".
 */

int FindGeometry (int argc, char *argv[], char *geometry)
{
	char *ptr = FindParameter (argc, argv, "-geom");

	if (ptr != (char *) NULL) {
		(void) strcpy (geometry, ptr);
		return (True);
	}
	else {
		geometry[0] = '\0';
		return (False);
	}
}  /*  FindGeometry  */


void ParseGeometry (
	char  *geometry,
	int    max_width,  /*  screen size  */
	int    max_height,
	int   *x,
	int   *y,
	int   *width,
	int   *height
)
{
	int status, x1, y1;
	unsigned int width1, height1;

	status = XParseGeometry (geometry, &x1, &y1, &width1, &height1);

	if (status & XValue)      { *x = x1;}

	if (status & YValue)      { *y = y1;}

	if (status & WidthValue)  { *width = width1;}

	if (status & HeightValue) { *height = height1;}

	if (status & XNegative)   { *x = max_width - *width + *x;}

	if (status & YNegative)   { *y = max_height - *height + *y;}
}  /*  ParseGeometry  */


void CheckGeometry (
	int    argc,
	char  *argv[],
	int    max_width,  /*  screen size  */
	int    max_height,
	int   *x,
	int   *y,
	int   *width,
	int   *height
)
{
	char geometry[200];

	if (FindGeometry (argc, argv, geometry) == True) {
		ParseGeometry (geometry, max_width, max_height, x, y, width, height);
	}
}  /*  CheckGeometry  */

/*  end of file geometry.c  */
