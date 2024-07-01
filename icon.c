/*
 *    icon.c
 *    Routine for setting a window's icon
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *    Loads a bitmap from a file, then
 *    sets that bitmap as the window's icon.
 */

void LoadIcon (
	Display  *display,
	Window    window,
	char     *filename,
	char     *iconname
)
{
	Pixmap    icon;
	unsigned int icon_width, icon_height;

	icon = LoadBitmap (display, window, filename, &icon_width, &icon_height);

	if (icon != (Pixmap) None) {
		SetWindowIcon (display, window, icon, iconname);
	}
}


/*
 *    Tells the window manager about
 *    our icon. See window.c for more
 *    on the WM Hints.
 */

int SetWindowIcon (
	Display   *display,
	Window     window,
	Pixmap     icon,
	char      *iconname
)
{
	XWMHints  *wmhints;

	/* Get old hint values, because we want to add to what is there */

	if ((wmhints = XGetWMHints (display, window)) == (XWMHints *) NULL) {
		wmhints = (XWMHints *) malloc (sizeof (XWMHints));

		if (wmhints == (XWMHints *) NULL) {
			return (False);
		}

		wmhints->flags = 0;
	}

	wmhints->flags |= IconPixmapHint;
	wmhints->icon_pixmap = icon;

	XSetWMHints (display, window, wmhints);

	XFree (wmhints);

	/*
	 *  Use older R3 routine to set icon
	 *  name for compatibility. Look up
	 *  XSetWMIconName on newer X systems.
	 */

	XSetIconName (display, window, iconname);

	return (True);
}  /*  SetWindowName  */

/* end of file icon.c */
