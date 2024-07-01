/*
 *        fontht.c
 *        Determine height of text in a given font.
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

int FontHeight (XFontStruct *font_struct)
{
	int height;

	height = font_struct->ascent + font_struct->descent;

	return (height);
}    /* FontHeight */

/* end of file fontht.c */
