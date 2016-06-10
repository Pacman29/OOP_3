#############################################################################
# Makefile for building: OOP_3
# Generated by qmake (3.0) (Qt 5.5.0)
# Project:  OOP_3.pro
# Template: app
# Command: J:/QT/5.5/mingw492_32/bin/qmake.exe -spec win32-g++ CONFIG+=debug -o Makefile OOP_3.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = J:/QT/5.5/mingw492_32/bin/qmake.exe
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = cp -f
INSTALL_PROGRAM = cp -f
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: OOP_3.pro J:/QT/5.5/mingw492_32/mkspecs/win32-g++/qmake.conf J:/QT/5.5/mingw492_32/mkspecs/features/spec_pre.prf \
		J:/QT/5.5/mingw492_32/mkspecs/qdevice.pri \
		J:/QT/5.5/mingw492_32/mkspecs/features/device_config.prf \
		J:/QT/5.5/mingw492_32/mkspecs/qconfig.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_clucene_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_core.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_core_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_designer.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_designer_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_gui.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_gui_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_help.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_help_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_location.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_location_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_network.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_network_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_platformsupport_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qml.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qml_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quick.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quick_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_script.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_script_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sql.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sql_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_svg.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_svg_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_uiplugin.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xml.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xml_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		J:/QT/5.5/mingw492_32/mkspecs/features/qt_functions.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/qt_config.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/win32/qt_config.prf \
		J:/QT/5.5/mingw492_32/mkspecs/win32-g++/qmake.conf \
		J:/QT/5.5/mingw492_32/mkspecs/features/spec_post.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/exclusive_builds.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/default_pre.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/win32/default_pre.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/resolve_config.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/exclusive_builds_post.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/default_post.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/c++11.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/win32/rtti.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/precompile_header.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/warn_on.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/qt.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/resources.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/moc.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/win32/opengl.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/uic.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/win32/windows.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/testcase_targets.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/exceptions.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/yacc.prf \
		J:/QT/5.5/mingw492_32/mkspecs/features/lex.prf \
		OOP_3.pro \
		J:/QT/5.5/mingw492_32/lib/qtmaind.prl \
		J:/QT/5.5/mingw492_32/lib/Qt5Widgets.prl \
		J:/QT/5.5/mingw492_32/lib/Qt5Gui.prl \
		J:/QT/5.5/mingw492_32/lib/Qt5Core.prl
	$(QMAKE) -spec win32-g++ CONFIG+=debug -o Makefile OOP_3.pro
J:/QT/5.5/mingw492_32/mkspecs/features/spec_pre.prf:
J:/QT/5.5/mingw492_32/mkspecs/qdevice.pri:
J:/QT/5.5/mingw492_32/mkspecs/features/device_config.prf:
J:/QT/5.5/mingw492_32/mkspecs/qconfig.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dcore_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dinput_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquick_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3dquickrenderer_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_3drenderer_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axbase_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_axserver_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_clucene_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_concurrent_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_core.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_core_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_dbus_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_declarative_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_designer.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_designer_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_enginio_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_gui.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_gui_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_help.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_help_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_location.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_location_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimedia_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_network.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_network_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_nfc_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_opengl_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_platformsupport_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_positioning_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_printsupport_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qml.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qml_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qmltest_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quick.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quick_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_script.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_script_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_scripttools_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sensors_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_serialport_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sql.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_sql_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_svg.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_svg_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_testlib_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_uiplugin.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_uitools_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webchannel_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkit_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_websockets_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_widgets_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_winextras_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xml.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xml_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
J:/QT/5.5/mingw492_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
J:/QT/5.5/mingw492_32/mkspecs/features/qt_functions.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/qt_config.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/win32/qt_config.prf:
J:/QT/5.5/mingw492_32/mkspecs/win32-g++/qmake.conf:
J:/QT/5.5/mingw492_32/mkspecs/features/spec_post.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/exclusive_builds.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/default_pre.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/win32/default_pre.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/resolve_config.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/exclusive_builds_post.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/default_post.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/c++11.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/win32/rtti.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/precompile_header.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/warn_on.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/qt.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/resources.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/moc.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/win32/opengl.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/uic.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/win32/windows.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/testcase_targets.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/exceptions.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/yacc.prf:
J:/QT/5.5/mingw492_32/mkspecs/features/lex.prf:
OOP_3.pro:
J:/QT/5.5/mingw492_32/lib/qtmaind.prl:
J:/QT/5.5/mingw492_32/lib/Qt5Widgets.prl:
J:/QT/5.5/mingw492_32/lib/Qt5Gui.prl:
J:/QT/5.5/mingw492_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-g++ CONFIG+=debug -o Makefile OOP_3.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile