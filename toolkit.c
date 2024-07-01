/*
 *    toolkit.c
 *    Source code for a mini X toolkit.
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

#define MAX_NAME_LEN (80)

/*
 *    Structure for our ToolWindow type.
 *    We are essentially building a very
 *    tiny X toolkit here.
 */

typdef struct _ToolWindow {
	Display       *display;
	Window         parent;
	Window         window;
	GC             gc;                /*  usually shared  */
	XFontStruct   *font;
	int            width, height;
	int            state;             /*  used for toggling  */
	int            group;             /*  used for toggling  */
	int            id;
	char           name[MAX_NAME_LEN + 1];
	void           (*drawfunc)  ();
	void           (*userfunc)  ();
	void           (*eventfunc) ();
} ToolWindow;

/*
 *    Maximum number of global toolkit windows.
 */
#define MAX_TOOL_WINDOWS  (40)

/*
 *    Global toolkit windows
 */
static ToolWindow        TWArray[MAX_TOOL_WINDOWS + 1];
static int               tool_max_id = 0;

/*
 *    Creates a window and fills in a
 *    ToolWindow structure. Returns an
 *    ID on success, -1 otherwise.
 */

int CreateToolWindow (
	Display       *display;
	Window         parent;
	int            x,
	int            y,
	int            width,
	int            height;
	unsigned long  bordercolor,
	unsigned long  backcolor;
	ulong          event_mask;
	Visual        *visual
)
{
	int  id;

	/*  check for a free slot  */
	if (tool_max_id >= MAX_TOOL_WINDOWS) {
		return (-1);
	}

	/*  open a window  */
	id = tool_max_id;

	TWArray[id].window = OpenWindow (
		display, parent,
		x, y, width, height,
		bordercolor, backcolor,
		event_mask, visual);

	/*  Fill in ToolWindow structure  */
	if (TWArray[id].window != (Window) None) {
		TWArray[id].display    =  display;
		TWArray[id].parent     =  parent;
		TWArray[id].width      =  width;
		TWArray[id].height     =  height;
		TWArray[id].state      =  False;  /*  not on  */
		TWArray[id].group      =  0;
		TWArray[id].drawfunc   =  NullDrawFunc;
		TWArray[id].userfunc   =  NullUserFunc;
		TWArray[id].eventfunc  =  NullEventFunc;

		TWArray[id].name[0]    = '\0';

		tool_max_id++;

		return (id);
	}

	/*  Don't map window  */
	return (id);

}  /*  CreateToolWindow  */


Display *ToolGetDisplay (int id)
{
	if ((id >= 0) && (id < tool_max_id)) {
		return (TWArray[id].display);
	}
	else {
		return (TWArray[0].display);
	}
}


Window ToolgetWindow (int id)
{
	if ((id >= 0) && (id < tool_max_id)) {
		return (TWArray[id].window);
	}
	else {
		return (TWArray[0].window);
	}
}


void ToolSetBackground (int id, unsigned long color)
{
	if ((id >= 0) && (id < tool_max_id)) {
		XSetBackground (TWArray[id].display, TWArray[id].gc, color);
	}
}


void ToolSetForeground (int id, unsigned long color)
{
	if ((id >= 0) && (id < tool_max_id)) {
		XSetForeground (TWArray[id].display, TWArray[id].gc, color);
	}
}


void ToolSetGC (int id, GC gc)
{
	if ((id >= 0) && (id < tool_max_id)) {
		TWArray[id].gc = gc;
	}
}

/*
 *    MUST call ToolSetGC () first!
 */

void ToolSetFont (int id, XFontStruct *font_struct)
{
	if ((id >= 0) && (id < tool_max_id)) {
		TWArray[id].font = font_struct;

		XSetFont (TWArray[id].display,
			TWArray[id].gc,
			TWArray[id].font->fid);
	}
}


int ToolGetGroup (int id)
{
	if ((id >= 0) && (id < tool_max_id)) {
		return (TWArray[id].group);
	}

	return (-1);
}


void ToolSetGroup (int id, int group)
{
	if ((id >= 0) && (id < tool_max_id)) {
		TWArray[id].group = group;
	}
}


int ToolGetState (int id)
{
	if ((id >= 0) && (id < tool_max_id)) {
		return (TWArray[id].state);
	}

	return (-1);
}


void ToolSetState (int id, int state)
{
	if ((id >= 0) && (id < tool_max_id)) {
		TWArray[id].state = state;
	}
}


int ToolGetName (int id, char *name)
{
	if ((id >= 0) && (id < tool_max_id)) {
		(void) strcpy (name, TWArray[id].name);
	}
	else {
		name[0] = '\0';
	}
}


void ToolSetName (int id, char *name)
{
	if ((id >= 0) && (id < tool_max_id) && (strlen (name) < MAX_NAME_LEN)) {
		(void) strcpy (TWArray[id].name, name);
	}
}
