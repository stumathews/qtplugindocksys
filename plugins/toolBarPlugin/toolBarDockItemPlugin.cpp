
#include "toolBarDockItemPlugin.h"
#include <QtPlugin>
#include <iostream>
#include <QToolBar>
#include <QString>
#include "mainWindowDockableInterface.h"
#include "toolBarDockItemInterface.h"



using namespace std;


void ToolBarDockItemPlugin::loadMe(){
	constructObjects();
	setPluginName( "ToolBarDockItemPlugin" );
	setFitsIntoWho( "MainWindow" );
}
void ToolBarDockItemPlugin::constructObjects(){
	
}
// loadMeAsForeignPlugin() now should be run in an instantiated ToolBarDockItemPlugin object, becuase now it should
// be able to work on the getDockableObject() object, which was passed to it before loadMeAsForeignPlugin() was called.
// So in conclusion -> accessing getDockableObject() should work and manipulate it successfully.

void ToolBarDockItemPlugin::loadMeAsForeignPlugin(){
	cout << getPluginName() << " : " <<"Im being loaded as a foreign plugin." << endl;
	// access dockable object.	
	cout << getPluginName() << " : " <<	"DockableObject => " << qobject_cast<PluginFeatures*>(getDockableObject())->getPluginName() << endl;	
	// Do Stuff with the dockable object :
	// FIXME : can't access dockable objects interface (like member functions) in compiling *FIXED*
	
	// this reports undeclared "addToolBar"

	if( qobject_cast<MainWindowDockableInterface*>(getDockableObject()) ){ // the dockable object adheres to the interface, not us!
		
		doMyMainWork();
	}
	
}
bool ToolBarDockItemPlugin::recieveDockItemPlugin( QObject* dockItem ){
	if ( qobject_cast<ToolBarDockItemInterface*>(dockItem)  )
	{
		cout << "ToolBarDockItemPlugin Detected. "<< endl;
		qobject_cast<DockItemFeatures*>(dockItem)->setDockableObject( this );
		qobject_cast<DockItemFeatures*>(dockItem)->loadMeAsForeignPlugin();
		return true;
	}
return false;
}

void ToolBarDockItemPlugin::addWidgetToToolBar( QWidget* theWidget ){
	if( !theToolBar ){
		cout << "Toolbar object not avialable - improper calling routine order for plugin." << endl;
	}
	theToolBar->addWidget( theWidget );
}
// Where the real work is done...
// 
// ToolBarDockItemPlugin::doMyMainWork() : 
// =======================================
// 
//  This is a ToolBarDockItemPlugin -> it serves two purposes:
//  1) It _is_ the ToolBar for the application.
//  2) It can load other plugins as widgets into itself (as a toolbar )
// 
void ToolBarDockItemPlugin::doMyMainWork(){
	cout << getPluginName() << " Doing my main work now..." << endl;
	// see how we call the interface functions, but ourselves not being apart of it.
	theToolBar = qobject_cast<MainWindowDockableInterface*>(getDockableObject())->addToolBarByName( new QString("stuart") );
	// Add a initial Toolbar to the mainWindow, keep it for future reference -> for plugins to append themselves to.
	
	// Add a couple of buttons as defaults
	
	
}
Q_EXPORT_PLUGIN2( toolBarDockItemPlugin, ToolBarDockItemPlugin )
