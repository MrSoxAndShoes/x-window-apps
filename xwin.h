/*
 *     xwin.h - a header file for the functions developed
 *              for X Windows Applications, 2nd Edition
 *
 *     NOTE: The following headers should be included:
 *
 *     X11/Xlib.h
 */

#ifndef __XWIN_H__
#define __XWIN_H__

/* definitions for string justification */

#define   LL   0
#define   UL   1
#define   UC   2
#define   UR   3
#define   CL   4
#define   CC   5
#define   CR   6
#define   LC   7
#define   LR   8

/* functions declared */

Display *ConnectToServer(       /* connect.c               */
	char      *display_name,    /* name of display         */
	int       *screen,          /* RETURN: default screen  */
	Window    *rootwindow);     /* RETURN: root window     */

Window OpenWindow(               /* window.c                */
	Display        *display,     /* X server connection     */
	Window          parent,      /* parent window           */
	int             x,           /* location                */
	int             y,
	int             width,       /* size                    */
	int             height,
	unsigned long   bordercolor, /* border color            */
	unsigned long   backcolor,   /* background color        */
	unsigned long   event_mask,  /* Just Expose will do     */
	Visual         *visual);     /* normally CopyFromParent */

void SetStandardHints(          /* window.c                */
	Display   *display,         /* X server connection     */
	Window     window,          /* window to setup         */
	char      *app_name,        /* application name        */
	char      *wind_name,       /* window name             */
	int        x,               /* location & size         */
	int        y,
	int        width,
	int        height); 

void SetSizeHints(              /* sizehint.c                 */ 
	Display   *display,         /* X server connection        */
	Window     window,          /* hints apply to this window */
	int        x,               /* position and size          */
	int        y,
	int        width,
	int        height); 

void FillSizeHints(             /* sizehint.c                 */
	int x, int y,               /* position and size          */
	int width, int height,
	XSizeHints *sizehints);     /* RETURN                     */

void SetWMHints(                /* wmhints.c                  */
	Display *display,           /* X server connection        */
	Window   window,            /* hints apply to this window */
	int      initial_state);    /* startup state for window   */

void SetClassHints(             /* classhnt.c                 */
	Display  *display,          /* X server connection        */
	Window    window,           /* window being classified    */
	char     *res_name,         /* name of application        */
	char     *res_class);       /* class type of application  */

void SetWindowName(             /* wmname.c                   */
	Display  *display,          /* X server connection        */
	Window    window,           /* window being named         */
	char     *name);            /* name of window             */

GC CreateGC(                    /* gc.c                       */
	Display       *display,     /* X server connection        */
	Drawable       drawable,    /* drawable object            */
	unsigned long  forecolor,   /* pixel color                */
	unsigned long  backcolor);  /* pixel color                */

void DrawOval(                  /* oval.c                     */
	Display   *display,         /* X server connection        */
	Drawable   drawable,        /* drawable object            */
	GC         gc,              /* graphic context            */
	int        x,               /* size and  location         */
	int        y,
	int        width,
	int        height); 

void FillOval(                  /* oval.c                     */
	Display   *display,         /* X server connection        */
	Drawable   drawable,        /* drawable object            */
	GC         gc,              /* graphic context            */
	int        x,               /* size and  location         */
	int        y,
	int        width,
	int        height); 

int SetUpVisual(                /* visual.c                    */
	Display  *display,          /* X server connection         */
	int       screen,
	Visual  **visual,           /* RETRUN: ptr to visual found */
	int      *depth);           /* RETURN: depth of visual     */

int SetUpColormap(              /* colormap.c                  */
	Display  *display,          /* X server connection         */
	int       screen,
	Window    window,           /* window to set colormap      */
	Visual   *visual,           /* visual information          */
	Colormap *colormap);        /*                             */

unsigned long AllocNamedColor(       /* color.c                     */
	Display       *display,          /* X server connection         */
	Colormap       colormap,
	char          *colorname,
	unsigned long  default_color); 

XFontStruct *LoadFont(               /* loadfont.c                  */
	Display  *display,               /* X server connection         */
	char     *font_name,             /* font to try for             */
	char     *fallback_font_name);   /* backup font                 */ 

int FontHeight(                      /* fontht.c                    */
	XFontStruct  *font_struct);      /* pointer to font structure   */

void AppendKeyStateMessage(          /* append.c                    */
	unsigned int state);             /* value of modifier flag      */

void DrawString(                     /* drawstr.c                   */
	Display   *display,              /* X server connection         */
	Window     window,               /* window to draw on           */
	GC         gc,                   /* graphics context            */
	int        x,                    /* location to draw string     */
	int        y,
	char      *string);              /* string to draw              */

void DrawStringJustify(              /* drawstr.c                   */
	Display      *display,           /* X server connection         */
	Window        window,            /* window to draw on           */
	GC            gc,                /* graphics context            */
	XFontStruct  *font,              /* font pointer to structure   */
	int           x,                 /* location to draw string     */
	int           y,
	char         *string,            /* string to draw              */
	int           justification);    /* for string strat location   */

int DecodeKeyPress(                  /* key.c                       */
	XKeyEvent *event,                /* event packet received       */
	KeySym    *keysym,               /* key symbol                  */ 
	char      *string);              /* string for key string       */

int IsMetaKey(                       /* key.c                       */
	XEvent *event);                  /* event packet received       */

int IsMetaQ(                         /* key.c                       */
	XKeyEvent  *event,               /* event packet received       */
	char       *string);             /* string returned for KeySym  */

void UpdateWindowFromBitmap(       /* pixmap.c                    */
	Display        *display,       /* X server connection         */
	Window          window,        /* window to update            */
	GC              gc,            /* graphics context            */
	Pixmap          bitmap,        /* image to use                */
	XExposeEvent   *event,         /* area to update              */
	int             max_width,     /* size of pixmap              */
	int             max_height); 

void CopyPlane(                   /* pixmap.c                    */
	Display   *display,            /* X server connection         */
	Drawable   src_draw,           /* drawable source             */
	Drawable   dest_draw,          /* drawable destination        */
	GC         gc,                 /* graphics context            */
	int        x,                  /* location of update area     */
	int        y,
	int        width,              /* size of update area height  */
	int        height,
	int        max_width,          /* size of pixmap              */
	int        max_height); 

Pixmap LoadBitmap(                 /* bitmap.c                    */
	Display       *display,        /* X server connection         */
	Window         window,
	char          *filename,       /* read bitmap from ...        */
	unsigned int  *width,          /* RETURNED bitmap size        */
	unsigned int  *height);

int SaveBitmap(                    /* bitmap.c                    */
	Display  *display,             /* X server connection         */
	char     *filename,            /* save bitmap as ...          */
	Pixmap    bitmap,              /* image to save               */
	int       width,               /* size of bitmap              */
	int       height);

void LoadIcon(                     /* icon.c                      */
	Display  *display,             /* X server connection         */
	Window    window,              /* window to set icon for      */
	char     *filename,            /* file name for icon image    */
	char     *iconname);           /* name of icon                */

int SetWindowIcon(                 /* icon.c                      */
	Display   *display,            /* X server connection         */
	Window     window,             /* window to set icon for      */
	Pixmap     icon,               /* icon bitmap image           */
	char      *iconname);          /* name of icon                */

GC CreateXorGC(                    /* xor.c                       */
	Display       *display,        /* X server connection         */
	Drawable       drawable,       /* drawable GC will apply for  */
	unsigned long  forecolor,      /* foreground of drawable      */
	unsigned long  backcolor);     /* background of drawable      */

char *FindParameter(               /* args.c                      */
	int   argc,
	char *argv[],                  /* command-line parameters     */
	char *look_for);               /* parameter to search for     */

int FindDisplayName(               /* display.c                   */
	int   argc,
	char *argv[],                  /* command-line parameters     */
	char *display_name);           /* RETURN: display name        */

Display *OpenDisplay(              /* display.c                   */
	int     argc,
	char   *argv[],                /* command-line parameters     */
	int    *screen,                /* RETURN: default screen #    */
	Window *rootscreen);           /* RETURN: root window ID      */

int FindGeometry(                  /* geometry.c                  */
	int   argc,
	char *argv[],                  /* command-line parameters     */
	char *geometry);               /* RETURN: geometry string     */

void ParseGeometry(                /* geometry.c                  */
	char  *geometry,               /* geometry string             */
	int    max_width,
	int    max_height,             /* screen size                 */
	int   *x,
	int   *y,                      /* RETURN: window location     */
	int   *width,
	int   *height);                /* RETURN: window size         */

void CheckGeometry(                /* geometry.c                  */
	int    argc,
	char  *argv[],                 /* command-line parameters     */
	int    max_width,
	int    max_height,             /* screen size                 */
	int   *x,
	int   *y,                      /* RETURN: window location     */
	int   *width,
	int   *height);                /* RETURN: window size         */

XFontStruct *LoadFontName(         /* fontname.c                  */
	Display  *display,             /* X server connection         */
	int       argc,
	char     *argv[],              /* command-line parameters     */
	char     *font_name,           /* RETURN: default font name   */
	char     *fallback_font); 

int CheckForHelp(                  /* usage.c                     */
	int     argc,
	char   *argv[],                /* command-line parameters     */
	char   *extra_message);        /* extra help message          */

void PrintUsageMessage(            /* usage.c                     */
	char  *extra_message);         /* extra help message          */

Window TopWindow(                  /* topwind.c                   */
	Display       *display,        /* X server connection         */
	Window         parent,         /* parent window               */
	int            argc,
	char          *argv[],         /* command-line parameters     */
	int           *x,
	int           *y,              /* default location            */
	int           *width,
	int           *height,         /* default size                */
	unsigned long  bordercolor,
	unsigned long  backcolor,
	unsigned long  event_mask,
	Visual        *visual);        /* often CopyFromParent        */

int FindInitialState(              /* topwind.c                   */
	int   argc,
	char *argv[]);                 /* command-line parameters     */

void FindWindowName(               /* topwind.c                   */
	Display *display,              /* X server connection         */
	Window   window,               /* window to name              */
	int      argc,
	char    *argv[]);              /* command-line parameters     */

void SetErrorHandlers();           /* error.c                     */

Display *StartupX(                 /* startupx.c                  */
	int            argc,
	char          *argv[],         /* command-line parameters     */
	int           *screen,         /* RETURN: screen number       */
	Window        *rootwindow,     /* RETURN: root window         */
	unsigned long *black,          /* RETURN: black color         */
	unsigned long *white,          /* RETURN: white color         */
	char          *message);       /* extra help message          */

#endif
