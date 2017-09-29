#ifndef MENU_BAR_H
#define MENU_BAR_H

#include <QObject>
#include "dockableFeatures.h"
#include "pluginFeatures.h"
#include "dockItemFeatures.h"
#include "mainWindowDockItemInterface.h"
// #include "statusBarInterfaceAPI.h"

class QMenuBar;
class MenuBar :   public QObject,
		  public DockableFeatures,
		  public DockItemFeatures,
		  public MainWindowDockItemInterface,
		  public PluginFeatures
{
	Q_OBJECT
	Q_INTERFACES( DockableFeatures DockItemFeatures PluginFeatures MainWindowDockItemInterface )
	public:
	~MenuBar(){}
	bool recieveDockItemPlugin( QObject* foreignPlugin );
	void loadMe();
	void loadMeAsForeignPlugin();

	// our stuff
	void constructObjects();
	QMenuBar* menuBar;


};

#endif
