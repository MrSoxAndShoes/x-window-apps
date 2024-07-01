/*
 *    fontname.c
 *    Routines to check for a user-requested
 *    name and load that font.
 *
 *    Written for X Windows Applications
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
 *    font name. If a "-font" or "-fn" option is
 *    found, then the command-line parameter
 *    following the "-font" is copied to
 *    font_name. Then, the actual font is
 *    loaded. Returns a pointer to the font
 *    structure, or NULL on errors.
 */

XFontStruct *LoadFontName (
	Display    *display,
	int         argc,
	char       *argv[],
	char       *font_name,
	char       *fallback_font
)
{
	char           *ptr;
	XFontStruct    *font_struct;

	ptr = FindParameter (argc, argv, "-font");

	if (ptr != (char *) NULL) {
		(void) strcpy (font_name, ptr);
	}
	else {
		ptr = FindParameter (argc, argv, "-fn");

		if (ptr != (char *) NULL) {
			(void) strcpy (font_name, ptr);
		}
	}

	font_struct = LoadFont (display, font_name, fallback_font);

	return (font_struct);
}  /*  LoadFontName  */

/* end of file fontname.c */
