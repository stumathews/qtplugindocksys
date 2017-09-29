#ifndef TOOLBAR_DEFAULT_BUTTON_H
#define TOOLBAR_DEFAULT_BUTTON_H

#include <QObject>
#include "dockItemFeatures.h"
#include "pluginFeatures.h"
#include "toolBarDockableInterface.h"
#include "toolBarDockItemInterface.h"

class ToolBarDefaultButtonPlugin : public QObject,
				   public ToolBarDockItemInterface,
				   public PluginFeatures,
				   public DockItemFeatures
{
	Q_OBJECT
	Q_INTERFACES ( DockItemFeatures PluginFeatures )
	public:
		~ToolBarDefaultButtonPlugin(){}

		virtual void loadMe();
		virtual void loadMeAsForeignPlugin();

};



#endif
