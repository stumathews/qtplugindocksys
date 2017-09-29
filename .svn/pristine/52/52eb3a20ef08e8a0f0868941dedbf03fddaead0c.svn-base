#include "statusBar.h"
#include <QtPlugin>
#include <QObject>
#include <QStatusBar>
#include <QLabel>
#include "mainWindowDockableInterface.h"

#include <iostream>
using namespace std;

void StatusBar::constructObjects(){
	statusBar = new QStatusBar();
}
void StatusBar::loadMe(){
	constructObjects();
	setPluginName( "StatusBar" );
}
bool StatusBar::recieveDockItemPlugin( QObject* foreignPlugin ){
	cout << "Status Bar doesn't recieve dockItem plugins..." << endl;
	return true;
}
void StatusBar::loadMeAsForeignPlugin(){
	statusBar->setSizeGripEnabled( true );
	statusBar->showMessage( "StatusBar Plugin" );
	statusBar->addPermanentWidget( new QLabel( "StatusBar Plugin" ) );
	qobject_cast<MainWindowDockableInterface*>(getDockableObject())->updateTheStatusBar( statusBar );
	
}

Q_EXPORT_PLUGIN2( statusBar, StatusBar )

