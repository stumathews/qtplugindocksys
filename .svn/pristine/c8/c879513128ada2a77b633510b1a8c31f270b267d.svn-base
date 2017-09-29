#ifndef TOOLBAR_DOCKABLE_INTERFACE_H
#define TOOLBAR_DOCKABLE_INTERFACE_H

#include <QObject>

// Exportable ToolBar functions
/*
	As A ToolBar What can we do ?

	1. Add Icons and actions to toolbar
	2. Add Widgets
	3. Remove Icons and actions
	4. Remove Widgets
	5. Reload All Widgets - redraw and reload - reinitialise them call pluginin init() functions

*/

class QWidget;
class ToolBarDockableInterface
{
	public:
		virtual ~ToolBarDockableInterface(){}
		// Widget Specific 
		virtual void addWidgetToToolBar( QWidget* theWidget ) = 0;
		
		
};

Q_DECLARE_INTERFACE( ToolBarDockableInterface, "ToolBarDockableInterface" )

#endif
