######################################################################
# Automatically generated by qmake (2.00a) Mon Aug 14 07:26:23 2006
######################################################################

TEMPLATE = lib
QT += sql
TARGET += mainWindowPlugin
INCLUDEPATH += . \
		../../program/templates/DockableFeatures \
		../../program/templates/PluginFeatures \
		../../program/templates/DockItemFeatures \
		../pluginInterfaces/mainWindowDockableInterface \
		../pluginInterfaces/mainWindowDockItemInterface
CONFIG += plugin
DESTDIR = ../../program/pluginsPlace/
# Input
HEADERS += mainWindowDockablePlugin.h MainWindow.h \
	../../program/templates/DockableFeatures/dockableFeatures.h \
	../../program/templates/PluginFeatures/pluginFeatures.h \ 
	../pluginInterfaces/mainWindowDockItemInterface/mainWindowDockItemInterface.h
SOURCES += mainWindowDockablePlugin.cpp  \
	MainWindow.cpp \
	../../program/templates/PluginFeatures/pluginFeatures.cpp 

contains( TEMPLATE, lib ){
	CONFIG( debug, debug|release ){
	unix:TARGET = $$member(TARGET, 0)_debug
	else:TARGET = $$member(TARGET, 0)_d
	}
}
