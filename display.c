/*
 *    display.c
 *    Routines to open a connection to an X Server,
 *    based on a display name in the command-line
 *    parameters, e.g., "-display display_name"
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
 *    display name. If a "-display" option is
 *    found, then the command-line parameter
 *    following the "-display" is copied to
 *    display_name. This routine assumes that
 *    the display name will follow the "-display"
 *    option. Note that we are really only
 *    looking for "-disp" to allow users to
 *    type in a shorthand for "-display".
 */

int FindDisplayName (int argc, char *argv[], char *display_name)
{
	char  *ptr;

	ptr = FindParameter (argc, argv, "-disp");

	if (ptr != (char *) NULL) {
		(void) strcpy (display_name, ptr);
		return (True);
	}
	else {
		display_name[0] = '\0';
		return (False);
	}
}  /*  FindDisplayName  */


/*
 *   Sets up a connection to an X Server (called a
 *   Display), and then gets the default screen
 *   number and root window ID on that display.
 *   The display may be named in the command-line
 *   parameters, argv, with the "-display" option.
 *   If so, this routine expects a display name to
 *   follow the "-display".
 */

Display *OpenDisplay (int argc, char *argv[], int *screen, Window *rootwindow)
{
	/* 6/30/2024 EA: Buffer overflow candidate */
	char     display_name[200];
	Display *display;

	/*
	 *  Find display name. Will put a NULL in
	 *  display_name if not found.
	 */

	(void) FindDisplayName (argc, argv, display_name);

	/*
	 *  Connect to X Server. Note that
	 *  ConnectToServer ill call exit
	 *  on errors.
	 */

	display = ConnectToServer (display_name, screen, rootwindow);

	return (display);

}  /*  OpenDisplay  */

/* end of file display.c */
