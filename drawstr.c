/*
 *        drawstr.c
 *        Draw string utility functions.
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
 *    Draws a text string using XDrawImageString.
 */

void DrawString (
	Display  *display,
	Window    window,
	GC        gc,
	int       x,
	int       y,
	char     *string
)
{
	XDrawImageString (
		display, window, gc,
		x, y, string, strlen (string));
}  /* DrawString */


/*
 *    Draws a text string with justification
 */

void DrawStringJustify (
	Display      *display,
	Window        window,
	GC            gc,
	XFontStruct  *font,
	int           x,
	int           y,
	char         *string,
	int           justification
)
{
	int height, width;

	/*  Get the height and width of the text string  */
	height = font->ascent + font->descent;
	width  = XTextWidth (font, string, strlen (string));

	switch (justification) {
		case UL :                   y += height     ; break;
		case UC : x -= width >> 1;  y += height     ; break;
		case UR : x -= width     ;  y += height     ; break;
		case CL :                   y += height >> 1; break;
		case CC : x -= width >> 1;  y += height >> 1; break;
		case CR : x -= width     ;  y += height >> 1; break;
		case LC : x -= width >> 1;                  ; break;
		case LR : x -= width     ;                  ; break;
	}

	XDrawImageString (
		display, window, gc,
		x, y, string, strlen (string));
}  /* DrawStringJustify */


/* end of file drawstr.c */
