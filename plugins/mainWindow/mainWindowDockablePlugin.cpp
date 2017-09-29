#include "mainWindowDockablePlugin.h"
#include <QtPlugin>
#include <QObject>
#include <iostream>
#include <cstring>
#include "MainWindow.h"
#include "mainWindowDockableInterface.h"
#include "mainWindowDockItemInterface.h"
#include "dockItemFeatures.h"
#include "pluginFeatures.h"
#include <QMainWindow>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
using namespace std;

// implement interface functions ( override )

// Remember we are a mainWindow dockablePLugin, so this means we need to encapsulate the functinoality behind mainWindows
// in QT4 and then provide a interface for DockItem plugins to Use :-)

void MainWindowDockablePlugin::loadMe(){
	constructObjects();
	setPluginName( "MainWindow" );
	mainWindow->show();
}

void MainWindowDockablePlugin::constructObjects(){
	// Here is the mainWindow Object that we manipulate through a bunch of routines ( which turn out to be the interface to the DockItem plugins that will dock into this dockable plugin )
	mainWindow = new QMainWindow(); // notice Q
}
void MainWindowDockablePlugin::test(){ // Historical test()
	cout << "Remote Call ..." << endl;
	// this is called remotely, from dockItem Object plugin
	cout << "Call succeded...static -> didn't touch dockable objects members." << endl;
}

// reciveDockItemPlugin() : recived a DockItemPlugin Object as a QObject( we recived the address of it ).
// -----------------------
// What to do with it :
// 1) UseObject's address to call object as plugin -> get its name.
// 2) Pass THIS dockable Object, to the DockItemPLugin -> thats the address
// 3) Call a method in the DockItem Object.( loadMeAsForeignPlugin )
// NB this function is called from pluginManager.( top level loading one )

bool MainWindowDockablePlugin::recieveDockItemPlugin( QObject* foreignPlugin ){

	// start testing the foreign Plugin...:
	
	// If this is a DockItem Plugin, query it -> then see if its an actaul mainWindowDockableInterface compatible
	// plugin, if so then yay load it, else kick it outta here!
	//
	// At this point, mainWindowDockableInterface plugins are the only ones this dockable plugin accepts.
	// Test Scheme :
	// 1) Is the foreignObnject a plugin...yes goto 2)
	// 2) Is the foreignObject a dockItem plugin..yes goto 3)
	// 3) Is the dockItem Plugin a mainWindowDockableInterface plugin...yes goto ACCEPT, else REJECT
	
	if( ( qobject_cast<PluginFeatures*>(foreignPlugin) && qobject_cast<DockItemFeatures*>(foreignPlugin) ) )
	{
		qobject_cast<DockItemFeatures*>(foreignPlugin)->setDockableObject( this );
		// at this point we have two objects, dockable(this) and dockItem(instantiated)
		// Take the item and call its loadMeAsForeignPlugin function...
		// The idea now is that loadMeAsForeignPlugin can 'operate' on the object we passed earlier, namly
		// the DockableObject ( setDockableObject(this)
		
		// Cast further : if foreignPlugin is a MainWindowDockItem...
		// Assuming that this is so...
		if( qobject_cast<MainWindowDockItemInterface*>(foreignPlugin) ){
			cout << "MainWindowDockablePlugin Detected." << endl;
			cout << "+ Giving " << getPluginName() << ", dockableObject to DockItemPlugin..." << endl;
			qobject_cast<DockItemFeatures*>(foreignPlugin)->setDockableObject( this );
			cout << "+ Calling dockItem's loadMeAsForeignPlugin().." << endl;
			// at this point we have two objects, dockable(this) and dockItem(instantiated)
			// Take the item and call its loadMeAsForeignPlugin function...
			// The idea now is that loadMeAsForeignPlugin can 'operate' on the object we passed earlier, namly
			// the DockableObject ( setDockableObject(this)
			// TODO:
			// --> Now we need to store the plugin, and later load all our plugins sequentally.
			qobject_cast<DockItemFeatures*>(foreignPlugin)->loadMeAsForeignPlugin();
			// That's it! , its up to the DockItem Plugin to operate independantly...:0>
		return true;
		}
	}
	return false;
}

void MainWindowDockablePlugin::loadMeAsForeignPlugin(){
	cout << "MainWindowDockablePlugin : loadMeAsForeignPlugin()" << endl;
}
void MainWindowDockablePlugin::closeWindow(){
	cout << "Closing Window..." << endl;
	mainWindow->close();
}
QToolBar* MainWindowDockablePlugin::addToolBarByName(QString* title){
	return mainWindow->addToolBar( *title );
}
void MainWindowDockablePlugin::addToolBar( QToolBar* toolBar ){
		mainWindow->addToolBar( toolBar );
}


// MISC

QMainWindow* MainWindowDockablePlugin::getMainWindowObject(){
	return mainWindow;
}
// MenuBar Functionality

QMenuBar* MainWindowDockablePlugin::getTheMenuBar(){
	return mainWindow->menuBar();
}

void MainWindowDockablePlugin::updateTheMenuBar( QMenuBar* theMenuBar ){
	mainWindow->setMenuBar( theMenuBar );
}
// StatusBar Functionality

QStatusBar* MainWindowDockablePlugin::getTheStatusBar(){
	return mainWindow->statusBar();
}
void MainWindowDockablePlugin::updateTheStatusBar( QStatusBar* theStatusBar ){
	mainWindow->setStatusBar( theStatusBar );
}
Q_EXPORT_PLUGIN2( mainWindowDockablePlugin, MainWindowDockablePlugin )
