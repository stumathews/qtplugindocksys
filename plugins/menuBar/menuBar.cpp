#include "menuBar.h"
#include <QtPlugin>
#include <QObject>
#include "mainWindowDockableInterface.h"
#include "pluginFeatures.h"
#include <QMenuBar>
#include <iostream>

using namespace std;

void MenuBar::constructObjects(){
	menuBar = new QMenuBar();
}

void MenuBar::loadMe(){
	constructObjects();
	setPluginName( "MenuBar" );
}
bool MenuBar::recieveDockItemPlugin( QObject* foreignPlugin ){
	cout << "MenuBar is not accepting any plugins as of yet..." << endl;
	return true;
}

void MenuBar::loadMeAsForeignPlugin(){
	menuBar->addAction( "menuBarPluginItem1" );
	menuBar->addAction( "defaultPluginItem2" );
	qobject_cast<MainWindowDockableInterface*>(getDockableObject())->updateTheMenuBar( menuBar );
}

Q_EXPORT_PLUGIN2( menuBar, MenuBar )

