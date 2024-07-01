/*
 *        window.c
 *        Code for creating a window
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
 *    All our windows will have a 2 pixel wide border
 *    (which window managers like mwm and twm may override).
 *    You, of course, may want to change this, or pass the
 *    border-width as a parameter.
 */

#define      BORDER_WIDTH      (2)

/*    Define application class    */
#define      APPL_CLASS        "Examples"

Window OpenWindow (
	Display        *display,        /* X server connection     */
	Window          parent,         /* parent window           */
	int             x,              /* location                */
	int             y,
	int             width,          /* size                    */
	int             height,
	unsigned long   bordercolor,    /* border color            */
	unsigned long   backcolor,      /* background color        */
	unsigned long   event_mask,     /* Just Expose will do     */
	Visual         *visual          /* normally CopyFromParent */
)
{
	Window               window;
	XSetWindowAttributes attributes;
	ulong                attr_mask;

	/*
	 *  Set up window attributes before
	 *  creating window. Don't confuse
	 *  CWBackPixel with CWBackingPixel!
	 */

	attributes.event_mask       = event_mask;
	attributes.border_pixel     = bordercolor;
	attributes.background_pixel = backcolor;

	attr_mask = CWEventMask | CWBackPixel | CWBorderPixel;

	/*
	 *  Override-Redirect windows make an end-run
	 *  around a window manager. Try the program
	 *  with the next two lines commented out,
	 *  and also with them compiled in. Normally,
	 *  well-behaved X applications only use
	 *  override-redirect windows for pop-up menus.
	 *  Don't abuse override-redirect windows and
	 *  don't have your application's main window
	 *  use override-redirect.
	 *
	 *  attributes.override_redirect = True;
	 *  attr_mask |= CWOverrideRedirect;
	 */

	/* Create the window */
	window = XCreateWindow (
		display, parent,
		x, y, width, height,
		BORDER_WIDTH,
		CopyFromParent,      /* depth */
		InputOutput,         /* class */
		visual,
		attr_mask,
		&attributes);

	return (window);

}    /* OpenWindow */


/*    Convience wrapper function to call utility
 *    functions and set up the minimum necessary
 *    hints for the window manager. in section 2,
 *    we will expand on this
 */

void SetStandardHints (
	Display   *display,              /* X server connection */
	Window     window,               /* window to setup     */
	char      *app_name,             /* application name    */
	char      *wind_name,            /* window name         */
	int        x,                    /* location & size     */
	int        y,
	int        width,
	int        height	
)
{

	SetSizeHints  (display, window, x, y, width, height);
	SetWindowName (display, window, wind_name);
	SetClassHints (display, window, app_name, APPL_CLASS);
	SetWMHints    (display, window, NormalState);

}    /* SetStandardHints */

/* end of file window.c */
