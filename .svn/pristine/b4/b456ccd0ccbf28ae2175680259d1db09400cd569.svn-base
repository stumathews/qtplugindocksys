#ifndef GENERIC_H
#define GENERIC_H

#include <QObject>
#include "dockableFeatures.h"
#include "pluginFeatures.h"
// #include "statusBarInterfaceAPI.h"


class Generic :   public QObject,
		  public DockableFeatures,
		  public PluginFeatures
{
	Q_OBJECT
	Q_INTERFACES( DockableFeatures PluginFeatures )
	public:
		~Generic(){}
	bool recieveDockItemPlugin( QObject* foreignPlugin );
	void loadMe();

};

#endif
