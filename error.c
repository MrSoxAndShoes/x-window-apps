/*
 *    error.c
 *
 *    X Window error-handling functions.
 *
 *    Written for X Window Applications
 *    Programming, 2nd Edition
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "xwin.h"

/*
 *    Global static table of X Protocol Code Ids
 */
static char *ErrorCodes[] = {
	"",                       /* 0 */
	"CreateWindow",           /* 1 */
	"ChangeWindowAttributes",
	"GetWindowAttributes",
	"DestroyWindow",	
	"DestroySubwindows",
	"ChangeSaveSet",
	"ReparentWindow",
	"MapWindow",
	"MapSubwindows",
	"UnmapWindow",            /* 10 */
	"UnmapSubwindows",
	"ConfigureWindow",
	"CirculateWindow",
	"GetGeometry",
	"QueryTree",
	"InternAtom",
	"GetAtomName",
	"ChangeProperty",
	"DeleteProperty",
	"GetProperty",
	"ListProperties",
	"SetSelectionOwner",
	"GetSelectionOwner",
	"ConvertSelection",
	"SendEvent",
	"GrabPointer",
	"UngrabPointer",
	"GrabButton",
	"UngrabButton",
	"ChangeActivePointerGrab",
	"GrabKeyboard",
	"UngrabKeyboard",
	"GrabKey",
	"UngrabKey",
	"AllowEvents",
	"GrabServer",
	"UngrabServer",
	"QueryPointer",
	"GetMotionEvents",
	"TranslateCoords",
	"WarpPointer",
	"SetInputFocus",
	"GetInputFocus",
	"QueryKeymap",
	"OpenFont",
	"CloseFont",
	"QueryFont",
	"QueryTextExtents",
	"ListFonts",
	"ListFontsWithInfo",
	"SetFontPath",
	"GetFontPath",
	"CreatePixmap",
	"FreePixmap",
	"CreateGC",
	"ChangeGC",
	"CopyGC",
	"SetDashes",
	"SetClipRectangles",
	"FreeGC",
	"ClearArea",
	"CopyArea",
	"CopyPlane",
	"PolyPoint",
	"PolyLine",
	"PolySegment",
	"PolyRectangle",
	"PolyArc",
	"FillPoly",
	"PolyFillRectangle",
	"PolyFillArc",
	"PutImage",
	"GetImage",
	"PolyText8",
	"PolyText16",
	"ImageText8",
	"ImageText16",
	"CreateColormap",
	"FreeColormap",
	"CopyColormapAndFree",
	"InstallColormap",
	"UninstallColormap",
	"ListInstalledColormaps",
	"AllocColor",
	"AllocNamedColor",
	"AllocColorCells",
	"AllocColorPlanes",
	"FreeColors",
	"StoreColors",
	"StoreNamedColor",
	"QueryColors",
	"LookupColor",
	"CreateCursor",
	"CreateGlyphCursor",
	"FreeCursor",
	"RecolorCursor",
	"QueryBestSize",
	"QueryExtension",
	"ListExtensions",
	"ChangeKeyboardMapping",
	"GetKeyboardMapping",
	"ChangeKeyboardControl",
	"GetKeyboardControl",
	"Bell",
	"ChangePointerControl",
	"GetPointerControl",
	"SetScreenSaver",
	"GetScreenSaver",
	"ChangeHosts",
	"ListHosts",
	"SetAccessControl",
	"SetCloseDownMode",
	"KillClient",
	"RotateProperties",
	"ForceScreenSaver",
	"SetPointerMapping",
	"GetPointerMapping",
	"SetModifierMapping",
	"GetModifierMapping"
};

int ErrorHandler (Display *display, XErrorEvent *event)
{
	/* 6/30/2024 EA: Buffer overflow candidate */
	int	 length = 120;
	char string[130];

	XGetErrorText(display, event->error_code, string, length);

	(void) fprintf(stderr,
		"\n\nX Error:\n\t%s\n", string);

	(void) fprintf(stderr,
		"\tSerial number of request: %ld\n",
		event->serial);

	(void) fprintf(stderr,
		"\tOp Code: %d.%d %s\n\tError Code: %d\n",
		event->request_code,
		event->minor_code,
		ErrorCodes[event->request_code],
		event->error_code);

	(void) fprintf(stderr,
		"\tResource ID of failed request: %ld\n\ton display %s.\n",
		event->resourceid,
		DisplayString(display));

	/* 6/30/2024 EA: Make compiler happy for now. */
	return 0;
	
}	/* ErrorHandler */

/*
 *	FatalErrorHandler() takes care of
 *	fatal X errors, like a broken
 *	connection to the X server.
 *	If this routine does not exit,
 *	and returns, the XLib will exit
 *	anyway. Thus, in this function
 *	you need to save all important
 *	data and get ready for a fatal
 *	termination. Note: Do not call
 *	Xlib routines from a fatal X
 *	error handler.
 *
 *	This function is registered
 *	with X by use of the
 *	XSetIOErrorHandler() Xlib function.
 */

int FatalErrorHandler (Display *display)
{
	(void) fprintf(stderr,
		"X Error: Fatal IO error on display %s.\n",
		DisplayString(display));

	(void) fprintf(stderr,
		"Bailing out near line one.\n");

	/* Put any clean -up code here. */

	/* Terminate the program */
	exit(1);
}	/* FatalErrorHandler */

/*
 *	Sets up our Xlib error handlers.
 */

void SetErrorHandlers ()
{
	/*
	 * Set up the normal error
	 * handler, for things like
	 * bad window IDs, etc.
	 */
	XSetErrorHandler (ErrorHandler);

	/*
	 * Set up the fatal error handler
	 * for a broken connection with
	 * the X server, and other nasties.
	 */
	XSetIOErrorHandler (FatalErrorHandler);
	
}	/* SetErrorHandlers */

/*
 *	ErrorHandler() handles non-fatal X errors.
 *	This routine basically just prints out
 *	the error message and returns. Thus, we
 *	can probaly expect many, many errors to be
 *	generated, since nothing stops the erroneous
 *	condition. This function mainly exists so
 *	that the program does not terminate on a minor
 *	error. No one seems to like unexpected program
 *	termination, at least in a production environment.
 *
 */

/* end of file error.c */
