#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H


/*
 * A plugin manager can do many things, this one specifically does :
 * 1) Load plugins from directories, therefore -> not in Type pluginManager class
 * 
 * Other plugins managers wont do that.
 *
 * */

#include "dockablePluginManager.h"

class QPluginLoader;
class QDir;
class QString;
class PluginFeatures;
class DockableFeatures;
class DockItemFeatures;
class QObject;

class PluginManager : public DockablePluginManager {

	public:
		PluginManager();
		PluginManager( const char* pluginDir );
		~PluginManager(){}
		void setPluginsDir( const char* dir );
		QString getPluginsDir();
		int getNumPlugins();
		void loadPlugin( const char* dir );
	
	private:

		// Member Functions
		void constructObjects();  // Very Important -> instantiate all objects used ( make them usable )
		void setNumPlugins(int num);
		void initializePluginManager();
		void initializePluginsDir();
		void browsePluginsDir();
		
		// Data Members
		QList<QObject*>* storeForAllPlugins;
		QList<QObject*>* storeForAllDockablePlugins;
		QList<QObject*>* storeForAllDockItemPlugins;
		int numPlugins;
		QStringList* allPlugins;
		QDir* pluginsDir;
		QPluginLoader* pluginLoader;
	
};

#endif
