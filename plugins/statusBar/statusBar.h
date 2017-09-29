#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <QObject>
#include "dockableFeatures.h"
#include "dockItemFeatures.h"
#include "pluginFeatures.h"
#include "mainWindowDockItemInterface.h"
#include <QStatusBar>
// #include "statusBarInterfaceAPI.h"

class QStatusBar;

class StatusBar : public QObject,
		  public DockableFeatures,
		  public DockItemFeatures,
		  public PluginFeatures,
		  public MainWindowDockItemInterface // we mainWindow DockItem compatible item
		  // StatusInterfaceAPI
		  
{
	Q_OBJECT
	Q_INTERFACES( DockableFeatures PluginFeatures DockItemFeatures MainWindowDockItemInterface )
	public:
		~StatusBar(){}
	bool recieveDockItemPlugin( QObject* foreignPlugin );
	void loadMe();
	void loadMeAsForeignPlugin();

	// our stuff :
	void constructObjects();
	QStatusBar* statusBar;

};

#endif
