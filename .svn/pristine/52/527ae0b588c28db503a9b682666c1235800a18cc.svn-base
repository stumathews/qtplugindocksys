#ifndef MAIN_WINDOW_DOCK_ITEM_INTERFACE_H
#define MAIN_WINDOW_DOCK_ITEM_INTERFACE_H
#include <QObject>

/*
 * MainWindowDockItemInterface is the interface that all dockItem plugins must inherit (use) in order to be accepted
 * by MainWindowDockablePlugin .
 * MainWindowDockablePlugin will test this by verifying that the dockItem can cast to this object.
 * */

class MainWindowDockItemInterface
{
	public:
		virtual ~MainWindowDockItemInterface(){}
};
Q_DECLARE_INTERFACE( MainWindowDockItemInterface, "MainWindowDockItem" )

#endif
