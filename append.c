/*
 *        append.c
 *        Routine to cnvert a Key/Button
 *        state to a string, used by chapter 6.
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
 *    Appends a message based on the current state of
 *    the shift keys, etc.
 */

void AppendKeyStateMessage (unsigned int state)
{
	/* 6/30/2024 EA: Buffer overflow candidate */
	char string[400];

	(void) strcpy (string, "    ");     /* initialize */

	if (state & Button1Mask)
		(void) strcat (string, "Button1 ");

	if (state & Button2Mask)
		(void) strcat (string, "Button2 ");

	if (state & Button3Mask)
		(void) strcat (string, "Button3 ");

	if (state & Button4Mask)
		(void) strcat (string, "Button4 ");

	if (state & Button5Mask)
		(void) strcat (string, "Button5 ");

	if (state & ShiftMask)
		(void) strcat (string, "Shift ");

	if (state & LockMask)
		(void) strcat (string, "Lock ");

	if (state & ControlMask)
		(void) strcat (string, "Control ");

	if (state & Mod1Mask)
		(void) strcat (string, "Mod1 ");

	if (state & Mod2Mask)
		(void) strcat (string, "Mod2 ");

	if (state & Mod3Mask)
		(void) strcat (string, "Mod3 ");

	if (state & Mod4Mask)
		(void) strcat (string, "Mod4 ");

	if (state & Mod5Mask)
		(void) strcat (string, "Mod5 ");

	/*
	 *  Only append message if we've
	 *  added any information.
	 */

	if (strlen (string) > 4) {
		(void) puts (string);
	}

}  /* AppendKeyStateMessage */


/* end of file append.c */
