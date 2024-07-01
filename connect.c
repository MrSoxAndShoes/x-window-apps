/*
 *     connect.c
 *     Code to connect to an X server.
 *
 *     Written for X Window Applications
 *     Programming, 2nd Edition
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *     Sets up a connection toan X server (called a
 *     Display), and then gets the default screen
 *     number and root window ID on that display
 *     and screen.
 *
 *     display_name names the X server to connect to.
 *
 *     If the display_name is NULL, then the value of
 *     the DISPLAY environment variable is used.
 *     XOpenDisplay does this automatically.
 */

Display *ConnectToServer (
	char    *display_name,     /* name of display         */
	int     *screen,           /* RETURN: default screen  */
	Window  *rootwindow       /* RETURN: root window     */
)
{
	Display *display;

	/* Connect to X server */
	display = XOpenDisplay (display_name);

	/* Check for errors. We assume a failure to connect is a fatal error. */
	if (display == (Display *) NULL) {
		(void) fprintf (stderr, "Cannot connect to X server [%s]\n",
			XDisplayName (display_name));
		exit (1);
	}

	/* Get the screen number */
	*screen = DefaultScreen (display);

	/* Get the ID of this screen's root window */
	*rootwindow = RootWindow (display, *screen);

	return (display);
}   /* ConnectToServer */

/* end of file connect.c */
