
abs_dir = /home/stuart/projects/Services@Workshop
program_dir = $$abs_dir/pluginDockSystem/program
plugin_dir = $$abs_dir/pluginDockSystem/plugins
statusBar_dir = $$plugin_dir/statusBar
interface_dir = $$plugin_dir/pluginInterfaces
templates_dir = $$program_dir/templates

TEMPLATE = lib
TARGET += statusBar
CONFIG += plugin
INCLUDEPATH += . \
	       $$templates_dir/DockableFeatures \
	       $$templates_dir/DockItemFeatures \
	       $$templates_dir/PluginFeatures \
	       $$interface_dir/mainWindowDockableInterface \ 
	       $$interface_dir/mainWindowDockItemInterface  
	       
DESTDIR = $$abs_dir/pluginDockSystem/program/pluginsPlace/
HEADERS += $$statusBar_dir/statusBar.h \
	   $$templates_dir/DockableFeatures/dockableFeatures.h \
	   $$templates_dir/DockItemFeatures/dockItemFeatures.h \
	   $$templates_dir/PluginFeatures/pluginFeatures.h \
	   $$interface_dir/mainWindowDockableInterface/mainWindowDockableInterface.h \
	   $$interface_dir/mainWindowDockItemInterface/mainWindowDockItemInterface.h 
	   
SOURCES += $$templates_dir/PluginFeatures/pluginFeatures.cpp \
	   $$statusBar_dir/statusBar.cpp \
	   $$templates_dir/DockItemFeatures/dockItemFeatures.cpp
	   

contains( TEMPLATE, lib ){
	CONFIG( debug, debug|release ){
		unix:TARGET = $$member( TARGET, 0 )_debug
		else:TARGET = $$member( TARGET, 0 )_d
	}
}
