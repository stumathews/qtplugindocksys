
abs_dir = /home/stuart/projects/Services@Workshop
program_dir = $$abs_dir/pluginDockSystem/program
plugin_dir = $$abs_dir/pluginDockSystem/plugins
menuBar_dir = $$plugin_dir/menuBar
interface_dir = $$plugin_dir/pluginInterfaces
templates_dir = $$program_dir/templates

TEMPLATE = lib
TARGET += menuBar
CONFIG += plugin
INCLUDEPATH += . \
	       $$templates_dir/DockableFeatures \
	       $$templates_dir/DockItemFeatures \
	       $$templates_dir/PluginFeatures \
	       $$interface_dir/mainWindowDockableInterface \
	       $$interface_dir/mainWindowDockItemInterface \
	       $$interface_dir/
	       
DESTDIR = $$abs_dir/pluginDockSystem/program/pluginsPlace/
HEADERS += $$menuBar_dir/menuBar.h \
	   $$templates_dir/DockableFeatures/dockableFeatures.h \
	   $$templates_dir/DockItemFeatures/dockItemFeatures.h \
	   $$templates_dir/PluginFeatures/pluginFeatures.h \
	   $$interface_dir/mainWindowDockableInterface/mainWindowDockableInterface.h \
	   $$interface_dir/mainWindowDockItemInterface/mainWindowDockItemInterface.h 
	   
SOURCES += $$templates_dir/PluginFeatures/pluginFeatures.cpp \
	   $$menuBar_dir/menuBar.cpp \
	   $$templates_dir/DockItemFeatures/dockItemFeatures.cpp
	   
	   

contains( TEMPLATE, lib ){
	CONFIG( debug, debug|release ){
		unix:TARGET = $$member( TARGET, 0 )_debug
		else:TARGET = $$member( TARGET, 0 )_d
	}
}
