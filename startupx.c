/*
 *    startupx.c
 *    Convenience routine to start up
 *    connect to X server.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

Display *StartupX (
	int            argc,
	char          *argv[],
	int           *screen,
	Window        *rootwindow,
	unsigned long *black,
	unsigned long *white,
	char          *message
)
{
	Display   *display;

	/*  Check to see if user asked for "-help" option.  */
	if (CheckForHelp (argc, argv, message) == True) {
		exit (0);
	}

	/*  Attempt to open up connection to X Server  */
	display = OpenDisplay (argc, argv, screen, rootwindow);

	/*  Set up error handlers  */
	SetErrorHandlers ();

	/*  Set up "colors" we'll use  */
	*black = BlackPixel (display, *screen);
	*white = WhitePixel (display, *screen);

	return (display);

}  /*  StartupX  */

/*  end of file startupx.c  */
