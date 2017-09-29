#include "toolBarDefaultButtonPlugin.h"
#include <QtPlugin>
#include <iostream>
#include "toolBarDockableInterface.h"
#include "toolBarDockItemInterface.h"
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QDial>

using namespace std;

void ToolBarDefaultButtonPlugin::loadMe(){
	setPluginName( "ToolBarButtons" );
}
void ToolBarDefaultButtonPlugin::loadMeAsForeignPlugin(){
	cout << "+ loading as foreign Plugin.." << endl;
	// Do some fancy stuff and add a default button..
	qobject_cast<ToolBarDockableInterface*>(getDockableObject())->addWidgetToToolBar( new QPushButton("qpushbutton") );	
	qobject_cast<ToolBarDockableInterface*>(getDockableObject())->addWidgetToToolBar( new QLabel("qlabel") );	
	qobject_cast<ToolBarDockableInterface*>(getDockableObject())->addWidgetToToolBar( new QSlider() );	
	qobject_cast<ToolBarDockableInterface*>(getDockableObject())->addWidgetToToolBar( new QDial() );	
}

Q_EXPORT_PLUGIN2( toolBarDefaultButtonPlugin, ToolBarDefaultButtonPlugin )

