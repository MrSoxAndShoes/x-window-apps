#
#	Makefile for X Window Applications 
#	Programming, 2nd Edition 
#
#	December 29, 1993
#
#	To compile all the example sources,
#	follow STEPS 1 to 4 below to customize this
#	Makefile for your system.  Then, type 
#
#		make all
#
#	and away you go.
#
#--------------------------------------------------------
#
#	STEP 1: CC is the C compiler command you need to 
#	invoke, plus whatever flags are necessary. Some 
#	samples are below.
#
#	If you are using X11 Release 4 or higher (or the 
#	equivalent thereof), define the symbol X11R4.
#
#	Some common defines for the C compiler:
#	cc		Standard Unix C compiler
#	gcc		GNU C compiler (standard cc on DG Aviions)
#	-O		Optimize
#	-g		Include debugging information (usually 
#			precludes optimizing)
#	sysv		Unix System V or equivalent.
#	SYSV		Unix System V or equivalent.
#	SVR4_0		Unix System V Release 4
#	LAI_TCP		Lachman TCP definition for 386 UNIX
#	i386		386-based processor (Intel byte ordering)
#	X_WCHAR		May be needed for Release 5 pre-ANSI C systems.
#
#	Generic X11 R4/R5			cc -g -DX11R4
#	Generic X11 R3				cc -g
#
#	HP-UX 7.0, HP 9000			cc -g
#	HP-UX 7.0, HP 9000 (ANSI)	cc -g -Ae
#	SCO OpenDesktop 1.0, 1.1	cc -g -DLAI_TCP -Di386 -DSYSV
#	Esix System V Release 4		cc -g -DX11R4 -DSYSV -DSVR4_0 -Di386 
#	Aviion DG-UX 4.3			cc -g -DX11R4
#
#	Put the flags necessary for your system below:
# CFLAGS = -DX11R4 -DX_WCHAR -I/usr/include/X11R4
# CFLAGS = -DX_WCHAR -I/nfs/kitsapa/usr/include/X11R5
# CFLAGS = -DX11R4 -I/nfs/kitsapa/usr/include/X11R5
CFLAGS = -Wall -MMD -g
#
#--------------------------------------------------------
#
#	STEP 2: LIBS are the libraries needed to link 
#	an X program. You may need to specify where
#	the linker should look for the X 
#	libraries, using the -L option.
#
#	If your X Window libraries are in a non-standard
#	place, like /usr/opt/X11, use something like the
#	following:	-L/usr/opt/X11/lib -lX11
#
#	Generic X11		-lX11
#
#	SCO Open Desktop	-lX11 -ltlisock -lsocket -lnsl_s
#	Esix System V R4	-lX11 -lsocket -lnsl -lns
#	Interactive UNIX 2.2	-lX11 -linet
#
#	Put the library flags below:
# X11LIBS = -L /usr/lib/X11R5 -lX11 
X11LIBS = -lX11
#
#--------------------------------------------------------
#
#	STEP 3: Toolkit Libraries
#	ATHENA_LIBS are the libraries needed to compile 
#	an Athena widget (Xaw) program. 
#
#	-lXaw		Athena widget library, libXaw.a
#	-lXmu		X Misc. Utilities library, libXmu.a
#	-lXt		Xt Intrinsics library, libXt.a
#	-lXext		X extension library, libXext.a
#	-lX11		good 'ol X library, libX11.a
#
#	X11R4/R5
#	-lXaw -lXmu -lXt -lXext -lX11
#	X11R3
#	-lXaw -lXt -lX11
#
ATHENA_LIBS =	-lXaw -lXmu -lXt -lXext -lX11
#
#	MOTIF_LIBS are the libraries needed to compile 
#	a Motif widget (Xm) program. 
#
#	-lXm		Motif widget library, libXm.a
#
MOTIF_LIBS =	-lXm -lXt -lX11
#
#	Your system may not have both the Motif and Athena
#	libraries. TOOLKIT_APPS specify which toolkit
#	programs to build: motif and/or athena
#
#	TOOLKIT_APPS =	motif
#	TOOLKIT_APPS =	athena
#	TOOLKIT_APPS =	athena motif
#
TOOLKIT_APPS =	athena motif
#
#--------------------------------------------------------
#
#	STEP 4: Release 5 Application. If you have X11 R5
#	or higher, set R5_APPS to chap4cms. 
#
#	Otherwise, comment out the R5_APPS definition.
#
#	Pre-R5:
#		R5_APPS =
#	R5:
#		R5_APPS =	chap4cms
#
R5_APPS =chap4cms
#
#
#	Add a macro for the bin destination
#
BIN=./bin
LIB=./lib
OBJ=./obj
#
#
#       Define relationship between .c and .o
#
.c.o:
	$(CC) $(CFLAGS) -c $<
#
#--------------------------------------------------------
#
#	Compile all the sample programs with make all.
#

all: \
	$(LIB)/xwin \
	$(BIN)/chap1 $(BIN)/chap2 $(BIN)/chap3 $(BIN)/chap4 \
	$(BIN)/chap5 $(BIN)/chap6 $(BIN)/chap7 $(BIN)/chap8 \
	$(BIN)/chap9 $(BIN)/chap10 $(BIN)/chap11 $(BIN)/chap12
	$(BIN)/chap13   \
	$(BIN)/drawapp  \
	$(TOOLKIT_APPS) \
	$(R5_APPS)

#
#	Build the 'xwin' library
#
xwin: \
	append.o args.o bitmap.o       \
	classhnt.o color.o colormap.o           \
	connect.o display.o drawstr.o           \
    error.o fontname.o fontht.o gc.o   \
    geometry.o icon.o key.o loadfont.o \
    oval.o pixmap.o sizehint.o              \
    startupx.o topwind.o usage.o            \
    visual.o window.o wmhints.o             \
    wmname.o xor.o
	ar r $(LIB)/xwin.lib $?

#
#	Chapter 1 Building a First X Program
#
chap1: chap1.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 2 Creating Windows
#
chap2: chap2.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 3 Drawing With X
#
chap3: chap3.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 4 Color
#
chap4: chap4.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 4 Release 5's Device-Independent Color
#
chap4cms: chap4cms.o colorcms.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 5 Text and Fonts
#
chap5: chap5.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 6 Events
#
chap6: chap6.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 7 Keyboard and Mouse Events
#
chap7: chap7.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 8 Cursors
#
chap8: chap8.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 9 Bitmaps and Icons: Off-Screen 
#	Drawing with Pixmaps
#
chap9: chap9.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 10 Rubber-Band Lines and Shapes
#
chap10: chap10.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 11 Common Command-Line Parameters
#
chap11: chap11.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 12 Sending More Information to the
#	Window Manager.
#
chap12: chap12.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 13 Handling X Errors
#
chap13: chap13.o
	cc $(CFLAGS) -o $(BIN)/$@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Chapter 14 Building a Small Toolkit
#
toolkit.o:	toolkit.c 
		$(CC) -c toolkit.c

pushb.o:	pushb.c 
		$(CC) -c pushb.c

entry.o:	entry.c 
		$(CC) -c entry.c

label.o:	label.c 
		$(CC) -c label.c

#
#	Chapter 15 Pop-up Dialogs and Transient Windows
#
dialog.o:	dialog.c
		$(CC) -c dialog.c

query.o:	query.c 
		$(CC) -c query.c

tranwind.o:	tranwind.c 
		$(CC) -c tranwind.c


#
#	Chapter 17 Editing Pixmaps
#
da_undo.o:	da_undo.c drawapp.h
		$(CC) -c da_undo.c

#
#	Chapter 18 The Drawapp Application Source Code
#
da_file.o:	da_file.c drawapp.h
	$(CC) -c da_file.c


drawapp.o:	drawapp.c drawapp.h
		$(CC) -c drawapp.c

da_draw.o:	da_draw.c drawapp.h
		$(CC) -c da_draw.c

da_edit.o:	da_edit.c drawapp.h
		$(CC) -c da_edit.c

da_meta.o:	da_meta.c drawapp.h
		$(CC) -c da_meta.c

da_pix.o:	da_pix.c 
		$(CC) -c da_pix.c

drawapp:	toolkit.o pushb.o entry.o label.o dialog.o \
		drawapp.o da_edit.o da_file.o da_draw.o da_pix.o \
		tranwind.o da_undo.o fontht.o query.o da_meta.o \
		args.o display.o geometry.o usage.o color.o error.o \
		colormap.o bitmap.o icon.o pixmap.o \
		fontname.o gc.o key.o loadfont.o startupx.o \
		oval.o topwind.o visual.o xor.o \
		classhnt.o connect.o sizehint.o window.o \
		wmhints.o wmname.o
		$(CC) -o drawapp toolkit.o pushb.o entry.o label.o \
		dialog.o drawapp.o da_edit.o da_file.o da_draw.o \
		da_pix.o tranwind.o da_undo.o fontht.o query.o \
		args.o display.o geometry.o usage.o color.o error.o \
		colormap.o bitmap.o icon.o pixmap.o da_meta.o \
		fontname.o gc.o key.o loadfont.o startupx.o \
		oval.o topwind.o visual.o xor.o \
		classhnt.o connect.o sizehint.o window.o \
		wmhints.o wmname.o $(LIBS)

#
#	Chapter 20 Introducing X Toolkits
#
athena:	athena.c
	$(CC) -o athena athena.c $(ATHENA_LIBS)

motif:	motif.c
	$(CC) -o motif motif.c $(MOTIF_LIBS)

#
#	See if I can do RGB
#
rgb: rgb.o
	cc $(CFLAGS) -o $@ $? $(LIB)/xwin.lib $(X11LIBS)

#
#	Provide a means to clean up files
#
clean:
	@rm -f core *.d *.o *~ *\#
#
#	end of file
#


