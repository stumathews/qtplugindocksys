
abs_dir = /home/stuart/projects/Services@Workshop
program_dir = $$abs_dir/pluginDockSystem/program
plugin_dir = $$abs_dir/pluginDockSystem/plugins
generic_dir = $$plugin_dir/generic
interface_dir = $$plugin_dir/pluginInterfaces
templates_dir = $$program_dir/templates

TEMPLATE = lib
TARGET += generic
CONFIG += plugin
INCLUDEPATH += . \
	       $$templates_dir/DockableFeatures \
	       $$templates_dir/PluginFeatures \
	       $$interface_dir/
	       
DESTDIR = $$abs_dir/pluginDockSystem/program/pluginsPlace/
HEADERS += $$generic_dir/menuBar.h \
	   $$templates_dir/DockableFeatures/dockableFeatures.h \
	   $$templates_dir/PluginFeatures/pluginFeatures.h
	   
SOURCES += $$templates_dir/PluginFeatures/pluginFeatures.cpp \
	   $$generic_dir/menuBar.cpp
	   

contains( TEMPLATE, lib ){
	CONFIG( debug, debug|release ){
		unix:TARGET = $$member( TARGET, 0 )_debug
		else:TARGET = $$member( TARGET, 0 )_d
	}
}
