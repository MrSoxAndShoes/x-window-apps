/*
 *        wmhints.c
 *        Code for sending window hints to the window manager.
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
 *    Sets the window manager or "WM" hints.
 *    The initial_state can be one of:
 *         WithdrawnState (0)
 *         NormalState    (1)
 *         IconicState    (3)
 */

void SetWMHints (
	Display *display,         /* X server connection        */
	Window   window ,         /* hints apply to this window */
	int      initial_state    /* startup state for window   */
)
{
  XWMHints   wm_hints;

  /*
   *  The flags field specifies which
   *  parts of the structure are filled in.
   */
  wm_hints.flags = InputHint | StateHint;

  /*
   *  This tells the window manager
   *  whether we want the window to
   *  start out in iconic or normal state.
   */
  wm_hints.initial_state = initial_state;

  /*
   *  This tells the window manager
   *  our application would like to
   *  receive keyboard input, if the
   *  application asks for keyboard
   *  input.
   */
  wm_hints.input = True;

  XSetWMHints (display, window, &wm_hints);

}    /* SetWMHints */

/* end of file wmhints.c */
