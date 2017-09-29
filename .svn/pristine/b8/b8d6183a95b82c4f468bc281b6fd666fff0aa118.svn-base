#ifndef MAIN_WINDOW_DOCKABLE_INTERFACE_H
#define MAIN_WINDOW_DOCKABLE_INTERFACE_H
#include <QObject>

/*
 * This is the interface that is between the mainWindow and other plugins that would like to interact with the mainWindow.
 * This interface defined the routines that can be called to manipulate the mainWindow.
 * 
 * This interface is shared by both the dockable plugin and dockItem plugins, reason being is that this way dockItem
 * plugins can be varified as usable if they cast down to this interface and we then know for a fact that all the functions
 * in this interface will be accounted for inthe dock Item plugin.
 *
 * In practice, this means that both the DockItem and Dockable object will define the same functions, where in most cases you'll have this 
 * senario :
 *
 *     A             B
 *
 *  |---------|  |---------|
 *  | action1------action1 |
 *  | action2------action2 |
 *  | action3------action3 |
 *  | action4------action4 |
 *  |---------|  |---------|
 *
 *  A = DockItem Plugin
 *  B = Dockable Plugin.
 *
 *  This means in both instances of each the plugins action1,2,3,4 is defined twice, once in A and once in B.
 *  This essentially provides the above image ( a design goal ).
 *  What this means is, both objects share a common interface.
 *  Also the dockItem essentially just calls or mapps its action1 to dockable object's action1 and itself doesn't do anything 
 *  special -> its only dockable item's action1() that does the real action.
 *
 *  This leads to a redundancy issue, of having to define each action in the interface in the dockItem when in each action it just
 *  calls the corresponding action in the dockable object...
 *  The solution would be to make the dockItem plugin 'know' the interface without being involved in the interface.Problem
 *  with this is that you loose the design goal of the above figure.
 *
 *  The question is which one is more flexible in the long run ?
 *
 * NEW :
 * -----
 *  Implemented A single interface that dockItems 'know' with themselves not being apart of the interface :
 *  [dockable] : INTERFACE <--------- 'dockItem' knows the interface.
 * 
 * */

/*

MainWindow Plugin 
Author : S R C Mathews
Location : South Africa
Date : Throughout aug/sept.
----------------------------

Functionality that mainWindow Plugin Implments :

The main window plugin is a core plugin that applications can use to create a truly plugin-able application.
MainWindow plugin provides the correct dockable functionality that allows features to be added dynamically
by way of dockItem plugins that would call mainWindow functions.

A mainWindow plugin is actually a dockable feature wrapper around a QMainWindow Object in QT4, we essentially
use the QT4 API for QMainWindow and provide another API layer to the plugin implementer to use.
This layer essentially calls QT4 API - but this API we provide is their to provide dockable/dockItem plugin features
that correctly fit into the plugin theory model that this system is based on.

Thus MainWindow plugin essentially will/can do anything that a 'MainWindow' can do in QT4 initially.
But we can do more with it - esspecially making it reusable - in terms of our API which is a interface for plugins.

Main Window is expected to do :

Main Functioality :

	Menu.
	ToolBar.
	StatusBar.
	CentralWidget.
	WindowFeatures.
	Popup Menus.

*/
	
class QString;
class QToolBar;
class QMenuBar;
class QStatusBar;
class QMainWindow;

class MainWindowDockableInterface {  // All MainWidowDockItem plugins must 'know' this interface.

	public:
		virtual ~MainWindowDockableInterface(){}
		
		// Misc Window features
		virtual void closeWindow() = 0;
		virtual QMainWindow* getMainWindowObject() = 0;
		// ToolBar Functionality
		virtual QToolBar* addToolBarByName( QString* title ) = 0;
		// Menu functinality
		virtual QMenuBar* getTheMenuBar() = 0;
		virtual void updateTheMenuBar( QMenuBar* theMenuBar ) = 0;
		// StatusBar functionality
		virtual QStatusBar* getTheStatusBar() = 0; 
		virtual void updateTheStatusBar( QStatusBar* theStatusBar ) = 0;
		// CentralWidget functionality
		
		// Window Features/ functionality
		
		// Popup Menu functionality
};
Q_DECLARE_INTERFACE( MainWindowDockableInterface, "MainWindowDockableInterface" )

#endif
