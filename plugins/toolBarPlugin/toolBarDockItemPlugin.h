#ifndef TOOL_BAR_DOCK_ITEM_PLUGIN_H 
#define TOOL_BAR_DOCK_ITEM_PLUGIN_H 
#include <QObject>
#include "dockableFeatures.h"
#include "dockItemFeatures.h"
#include "pluginFeatures.h"
#include "mainWindowDockItemInterface.h"
#include "toolBarDockableInterface.h"

class QToolBar;
class QString;
class QWidget;

class ToolBarDockItemPlugin : public QObject, // we can use signals
			      public DockableFeatures, // I am a Dockable Object too
			      public DockItemFeatures, // I am a DockItem Object too.
			      public PluginFeatures,   // And I am a plugin too.
			      public MainWindowDockItemInterface, // And I am a MainWindwoDockItemInterface compatible object...
			      public ToolBarDockableInterface
{
	Q_OBJECT
	Q_INTERFACES( DockableFeatures PluginFeatures DockItemFeatures MainWindowDockItemInterface )
	public:
		~ToolBarDockItemPlugin(){}
		void constructObjects();
		// PluginFeatures overrides...
		virtual void loadMe();
		// DockItemFeatures overrides...
		virtual void loadMeAsForeignPlugin();
		// DockableFeatures overrides
		virtual bool recieveDockItemPlugin( QObject* foreignPlugin );
		
		// ToolBar Dockable Interface overrides...
		virtual void addWidgetToToolBar( QWidget* theWidget );
		
		// Our own stuff
		
		void doMyMainWork();
		QToolBar* theToolBar;
};

#endif
