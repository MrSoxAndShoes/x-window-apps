/*
 *    topwind.c
 *    Convenience routine to create a
 *    opt-level window.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *  Define an application class
 */
#define  APPL_CLASS  "Examples"

Window TopWindow (
	Display        *display,
	Window          parent,
	int             argc,
	char           *argv[],
	int            *x,
	int            *y,
	int            *width,
	int            *height,
	unsigned long   bordercolor,
	unsigned long   backcolor,
	unsigned long   event_mask,
	Visual         *visual
)
{
	Window   window;
	int      screen;

	/*
	 *  Check to see if the user
	 *  asked for a particular
	 *  size for our window
	 */
	screen = DefaultScreen (display);

	CheckGeometry (argc, argv,
		DisplayWidth (display, screen),
		DisplayHeight (display, screen),
		x, y, width, height);

	/*  Create a window on the display  */
	window = OpenWindow (
		display, parent,
		*x, *y, *width, *height,
		bordercolor, backcolor,
		event_mask, visual);

	/*  Provide information to the window manager  */
	SetSizeHints (display, window, *x, *y, *width, *height);
	SetClassHints (display, window, argv[0], APPL_CLASS);

	/*  Set window name  */
	FindWindowName (display, window, argc, argv);

	/*  Determine initial state  */
	SetWMHints (display, window, FindInitialState (argc, argv));

	/*
	 *  Set WM_COMMAND propert, as per the ICCM
	 *  NOTE: argv comes first!
	 */
	XSetCommand (display, window, argv, argc);

	return (window);

}  /*  TopWindow  */


int FindInitialState (int argc, char *argv[])
{
	char  *ptr;

	ptr = FindParameter (argc, argv, "-icon");

	if (ptr != (char *) NULL) {
		return (IconicState);
	}
	else {
		return (NormalState);
	}
}  /*  FindInitialState  */



void FindWindowName (
	Display   *display,
	Window     window,
	int        argc,
	char      *argv[]
)
{
	char *ptr;
	char  window_name[30];

	/*  Default name  */
	(void) strcpy (window_name, argv[0]);

	ptr = FindParameter (argc, argv, "-name");

	if (ptr != (char *) NULL) {
		(void) strcpy (window_name, ptr);
	}
	else {
		ptr = FindParameter (argc, argv, "-title");

		if (ptr != (char *) NULL) {
			(void) strcpy (window_name, ptr);
		}
	 }

	SetWindowName (display, window, window_name);

}  /*  FindWindowName  */

/* end of file topwind.c */
