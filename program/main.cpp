/*
 * DockablePluginSystem.
 * ---------------------
 *
 *  System that caters for remote plugins that adhere to specific dependant protocols.
 *
 *  Essentially, the aplpication is a top level Plugin Manager, that finds, loads and manages
 *  plugins.
 *  These plugins are separate, logical and defined portions of code that act independantly.
 *  Communication between plugins at this stage is not yet implemented.
 *
 *  Plugins are separated into two distinct types :
 *  1) Dockable
 *  2) DockItem
 *
 * 1) -- Dockable Plugin --
 *  Dockable Plugins are normally core portions of any application in terms of the fact that they are the corner stones
 *  of that application.This contributes to the fact that an application is a collection of plugins.
 *  Dockable plugins provide a means that allows for external plugins to dock onto them.
 *  External plugins( dockItem ) adhere to a interface into dockable plugin's functinoality.
 *  Thus dockItem plugins control the dockable plugin by using the interface that the dockable plugin provides.
 * 
 * 2) -- DockItem Plugin --
 *  DockItems are also separate logical code components that perform a specific role or operation.The operation
 *  that the DockItem plugin performs is dependant on the Dockable plugin that provides it with an interface ( API )
 *  that it can use to manipulate the Dockable Plugin.
 *  DockItem plugins are made to separate functionality in/and control dockable plugins.
 *    
 * */


#include <QApplication>
#include "pluginManager.h"
#include <iostream>
using namespace std;

int main( int argc, char** argv ){
 
	QApplication app( argc, argv );
	// Our application is a PLUGIN manager - nothing else.
	PluginManager pluginManager; // pluginDirectory set as default "./pluginsPlace/"
	return app.exec();
}
