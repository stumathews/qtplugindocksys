#ifndef TOOLBAR_DOCK_ITEM_INTERFACE_H
#define TOOLBAR_DOCK_ITEM_INTERFACE_H
#include <QObject>

class ToolBarDockItemInterface
{
	public:
	virtual ~ToolBarDockItemInterface(){}

};

Q_DECLARE_INTERFACE( ToolBarDockItemInterface, "ToolBarDockItemInterface" )

#endif
