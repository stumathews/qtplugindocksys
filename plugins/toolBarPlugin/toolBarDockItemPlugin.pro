######################################################################
# Automatically generated by qmake (2.00a) Mon Aug 14 07:26:23 2006
######################################################################

TEMPLATES = ../../program/templates
TEMPLATE = lib
QT += sql
TARGET += toolBarDockItemPlugin 
INCLUDEPATH +=  . \
		../../program/templates/DockableFeatures \
		../../program/templates/DockItemFeatures \
		../../program/templates/PluginFeatures \ 
		../pluginInterfaces/mainWindowDockItemInterface \
		../pluginInterfaces/mainWindowDockableInterface \
		../pluginInterfaces/toolBarDockableInterface \
		../pluginInterfaces/toolBarDockItemInterface
CONFIG += plugin
DESTDIR = ../../program/pluginsPlace/
# Input
HEADERS += toolBarDockItemPlugin.h \ 
          ../../program/templates/DockableFeatures/dockableFeatures.h \
	  ../../program/templates/DockItemFeatures/dockItemFeatures.h \
	  ../../program/templates/PluginFeatures/pluginFeatures.h \
	  ../pluginInterfaces/mainWindowDockItemInterface/mainWindowDockItemInterface.h \
	  ../pluginInterfaces/mainWindowDockableInterface/mainWindowDockableInterface.h \
	  ../pluginInterfaces/toolBarDockableInterface/toolBarDockableInterface.h \
	  ../pluginInterfaces/toolBarDockItemInterface/toolBarDockItemInterface.h
SOURCES += toolBarDockItemPlugin.cpp \
	../../program/templates/PluginFeatures/pluginFeatures.cpp \
	../../program/templates/DockItemFeatures/dockItemFeatures.cpp \

contains( TEMPLATE, lib ){
	CONFIG( debug, debug|release ){
	unix:TARGET = $$member(TARGET, 0)_debug
	else:TARGET = $$member(TARGET, 0)_d
	}
}
