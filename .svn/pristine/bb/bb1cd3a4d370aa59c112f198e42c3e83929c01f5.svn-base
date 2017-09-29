#ifndef MAIN_WINDOW_DOCKABLE_PLUGIN_H
#define MAIN_WINDOW_DOCKABLE_PLUGIN_H
#include <QObject>

// THIS IS THE INTERFACE FOR MainWindowDockItemPlugin.
#include "dockableFeatures.h"
#include "pluginFeatures.h"
#include "mainWindowDockableInterface.h"

//class MainWindow;
class QMainWindow;
class QObject;
class QToolBar;
class QString;
class QMenuBar;
class QStatusBar;


class MainWindowDockablePlugin : public QObject,
				 public DockableFeatures, // DOCKABLE PLUGIN
				 public PluginFeatures,
				 public MainWindowDockableInterface // DOCKABLE INTERFACE API
{
	Q_OBJECT
	Q_INTERFACES( DockableFeatures PluginFeatures MainWindowDockableInterface )
	public:

		~MainWindowDockablePlugin(){}
	// Overide virtual functions from interfaces...
	virtual void loadMe(); // All Dockable plugins are LoadMe'ed from pluginManager first before dockItem plugins, duh.
	private:
	// Member Functions.
		void constructObjects();
		void loadMeAsForeignPlugin();
		virtual bool recieveDockItemPlugin( QObject* foreignPlugin );
		void addToolBar( QToolBar* toolBar );
		void test();	
	// Data Members	
		QMainWindow* mainWindow;
		// Define the Interface here -> interface structure is MainWindowDockableInterface :
		// This means, that MainWindowDockableInterface defines what functions exist, we inherit from it and it
		// is a abstract class declaring functions -> here we overide those functions and define them...with me?
		
		// Misc Window Features
		virtual void closeWindow(); // Close the main Window
		virtual QMainWindow* getMainWindowObject();
		// ToolBar Functionality
		virtual QToolBar* addToolBarByName( QString* title ); // add Tool Bar To Main Window ( nice name :) )
		// Menu Functionality
		virtual QMenuBar* getTheMenuBar();
		virtual void updateTheMenuBar( QMenuBar* theMenuBar );
		// StatusBar Functioality
		virtual QStatusBar* getTheStatusBar();
		virtual void updateTheStatusBar( QStatusBar* theStatusBar );
		// Window Features/functionality
		// Popup menu functionality

};
#endif


// THIS IS INCOMPLETE
