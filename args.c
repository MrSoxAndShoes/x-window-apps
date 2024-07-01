/*
 *    args.c
 *    Utility routine for searching
 *    command-line parameters.
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
 *   Searches the command-line parameters for a
 *   a match with the search string look_for.
 *   If found, then returns the next command-line
 *   parameter, or the current command-line parameter,
 *   if there are no more parameters.
 *   Returns NULL if nothing is found.
 */

char *FindParameter (int argc, char *argv[], char *look_for)
{
	int  count, length;

	length = strlen (look_for);
	count  = 1; /* skip argv[0] */

	while (count < argc) {
		if (strncmp (look_for, argv[count], length) == 0) {
			count++;

			return (count < argc) ? argv[count] : argv[count-1];
		}

		count++;
	}

	return ((char *) NULL);
}  /*  FindParameter  */

/* end of file args.c */
