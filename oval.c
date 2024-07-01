/*
 *        oval.c
 *        Routines for drawing and
 *        filling ovals under X.
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
 *    Start circles at 0/64 degrees and
 *    go all the way around (360 degrees
 *    in 1/64 degree increments).
 */

#define START_CIRCLE   (0)
#define FULL_CIRCLE    (23040)   /* (360*64) */


void DrawOval (
	Display   *display,
	Drawable   drawable,
	GC         gc,
	int        x,
	int        y,
	int        width,
	int        height
)
{
	/* never draw an "arc" with width | height < 1 !!! */
	if (width  < 1)  width  = 1;
	if (height < 1)  height = 1;

	XDrawArc (
		display, drawable, gc,
		x, y, width, height, START_CIRCLE, FULL_CIRCLE);

}    /* DrawOval */

void FillOval (
	Display   *display,
	Drawable   drawable,
	GC         gc,
	int        x,
	int        y,
	int        width,
	int        height
)
{
	/* never draw an "arc" with width | height < 1 !!! */
	if (width  < 1)  width  = 1;
	if (height < 1)  height = 1;

	XFillArc (
		display, drawable, gc,
		x, y, width, height, START_CIRCLE, FULL_CIRCLE);

}    /* FillOval */

/* end of file oval.c */
