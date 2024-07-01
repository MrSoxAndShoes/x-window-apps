/*
 *        loadfont.c
 *        Contains utility function LoadFont
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
 *    LoadFont loads in an X font into an XFontStruct
 *    and returns a pointer to that structure. If the
 *    font font_name cannot be loaded, Loadfont
 *    then tries to load in the fallback_font_name font.
 *    If that fails, too, then LoadFont will terminate
 *    your program. We're sure you can come up with
 *    a better error-handling routine.
 */

XFontStruct *LoadFont (
	Display  *display,
	char     *font_name,
	char     *fallback_font_name
)
{
	XFontStruct *font_struct;

	font_struct = XLoadQueryFont (display, font_name);

	if (font_struct == (XFontStruct *) NULL) {

		/* Try to load in fallback font */
		font_struct = XLoadQueryFont (display, fallback_font_name);

		if (font_struct == (XFontStruct *) NULL) {
			(void) fprintf (stderr,
				"Error loading fonts [%s] [%s]\n",
				font_name,
				fallback_font_name);

			XCloseDisplay (display);
			exit (1);
		}
	}

	return (font_struct);
}    /* LoadFont */

/* end of file loadfont.c */
