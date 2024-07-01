/*
 *        key.c
 *        Routine to decode a KeyPress event.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

int DecodeKeyPress (
	XKeyEvent *event,
	KeySym    *keysym,
	char      *string
)
{
	XComposeStatus  composestatus;
	int             length;

	*keysym   = 0x0;
	string[0] = '\0';

	if ((event->type != KeyPress) && (event->type != KeyRelease)) {
		return (False);
	}

	/*  Convert Event to a string  */

	length = XLookupString (event, string, 1, keysym, &composestatus);

	if (length > 0) {
		string[1] = '\0';  /*  terminate  */
	}
	else {
		string[0] = '\0';
	}

	return (IsMetaQ (event, string));
}  /* DecodeKeyPress */


/*
 *    Checks to see if:
 *      a) the event is a key event;
 *      b) the Meta-1 ro Meta-2 key is pressed down
 */

int IsMetaKey (XEvent *event)
{
	if ((event->type == KeyPress) || (event->type == KeyRelease)) {
		if ((event->xkey.state & Mod1Mask) || (event->xkey.state & Mod2Mask)) {
			return (True);
		}
	}

	return (False);
}  /*  IsMetaKey  */


/*
 *    Returns True if the key event is
 *    for a Meta (or Alt) Q.
 */

int IsMetaQ (XKeyEvent *event, char *string)
{
	int  status = False;

	if (IsMetaKey ((XEvent *) event) == True) {
		if ((string[0] == 'Q') || (string[0] == 'q')) {
			status = True;
		}
	}

	return (status);
}  /*  IsMetaQ  */

/* end of file key.c */
