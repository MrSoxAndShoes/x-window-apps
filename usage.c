/*
 *    usage.c
 *    Routines to display a usage message to the
 *    user on stdout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"


/*
 *    Checks if the user passed a "-help"
 *    command-line parameter. If so, it
 *    prints out a help message and
 *    returns True. If not, it returns
 *    False.
 */

int CheckForHelp (int argc, char *argv[], char *extra_message)
{
	char   *ptr;

	ptr = FindParameter (argc, argv, "-help");

	if (ptr != (char *) NULL) {
		PrintUsageMessage (extra_message);
		return (True);
	}

	return (False);

}  /*  CheckForHelp  */


void PrintUsageMessage (char *extra_message)
{
	fputs ("\nThe allowable command line options are:\n", stderr);

	fputs ("\t-display  <displayName>\n", stderr);
	fputs ("\t\tConnect to X server <displayName>\n", stderr);

	fputs ("\t-geometry <geometrySpec>\n", stderr);
	fputs ("\t\tSpecify window location and size\n", stderr);

	fputs ("\t-font <fontName>\n", stderr);
	fputs ("\t\tLoad up font <fontName>\n", stderr);

	fputs ("\t-title <windowTitle>\n", stderr);
	fputs ("\t\tUse name for the window title\n", stderr);

	fputs ("\t-name <windowTitle>\n", stderr);
	fputs ("\t\tSame as -title\n", stderr);

	fputs ("\t-iconic\n", stderr);
	fputs ("\t\tStart with the window in iconic state\n", stderr);

	fputs (extra_message, stderr);

	fputs ("\n\n", stderr);

}  /*  PrintUsageMessage  */

/* end of file usage.c */
