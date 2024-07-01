/*
 *        visual.c
 *        Routine for grabbing a PseudoColor visual.
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
 *    SetUpVisual finds a PseudoColor visual
 *    on the given screen. If possible, uses the
 *    default visual, to avoid technicolor effects
 *    on the screen as you move the mouse around.
 */

int SetUpVisual (
	Display  *display,
	int       screen,
	Visual  **visual,
	int      *depth
)
{
	int           number_visuals;
	XVisualInfo  *visual_array;
	XVisualInfo   visual_info_template;
	int           status = False;

	if (DefaultVisual (display, screen)->class == PseudoColor) {
		*visual = DefaultVisual (display, screen);
		*depth  = DefaultDepth  (display, screen);
		status = True;
	}
	else {
		/*
		 *    We are looking for a PseudoColor
		 *    visual on the current screen
		 */

		visual_info_template.class  = PseudoColor;
		visual_info_template.screen = screen;

		visual_array = XGetVisualInfo (
			display, (VisualClassMask | VisualScreenMask),
			&visual_info_template, &number_visuals);

		/* Did we find one? */

		if ((number_visuals > 0) && (visual_array != NULL)) {
			/* Choose the first PseduoColor */
			*visual = visual_array[0].visual;
			*depth  = visual_array[0].depth;

			XFree (visual_array);

			status = True;
		}
		else {
			*visual = CopyFromParent;
			status = False;
		}
	}

	return (status);

}    /* SetUpVisual */

/* end of file visual.c */
