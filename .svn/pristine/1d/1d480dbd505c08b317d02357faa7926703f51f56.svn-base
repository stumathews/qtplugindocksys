#include "generic.h"
#include <QtPlugin>
#include <QObject>

#include <iostream>
using namespace std;

void Generic::loadMe(){
	setPluginName( "Generic" );
}
bool Generic::recieveDockItemPlugin( QObject* foreignPlugin ){
	cout << "generic doesn't recieve dockItem plugins..." << endl;
}

Q_EXPORT_PLUGIN2( generic, Generic )

