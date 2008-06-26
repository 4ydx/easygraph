#############################################################################
# Makefile for building: easygraph
# Generated by qmake (2.01a) (Qt 4.4.0) on: Wed Jun 25 20:29:21 2008
# Project:  easygraph.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.4.0/bin/qmake -unix CONFIG+=debug_and_release -o Makefile easygraph.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = /usr/local/Trolltech/Qt-4.4.0/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: easygraph.pro  /usr/local/Trolltech/Qt-4.4.0/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.4.0/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/debug_and_release.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.4.0/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.4.0/lib/libQtCore.prl
	$(QMAKE) -unix CONFIG+=debug_and_release -o Makefile easygraph.pro
/usr/local/Trolltech/Qt-4.4.0/mkspecs/common/g++.conf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/debug.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/debug_and_release.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.4.0/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.4.0/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.4.0/lib/libQtCore.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -unix CONFIG+=debug_and_release -o Makefile easygraph.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
