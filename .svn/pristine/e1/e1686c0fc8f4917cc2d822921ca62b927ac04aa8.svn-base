#include "pluginManager.h"
#include "dockableFeatures.h"
#include "dockItemFeatures.h"
#include "pluginFeatures.h"
#include <cstring>
#include <QPluginLoader>
#include <QByteArray>
#include <QDir>
#include <QStringList>
#include <QObject>
#include <iostream>
using namespace std;

/*
 *  Plugin Manager Keeps track of each plugin.
 *  A plugin is either a 'Dockable Plugin' or a 'DockItem Plugin'.
 *  It is in this context that this plugin manager 'manages' 'plugins'
 * 
 *  This is a plugin Manager for the top level accumulation and managment of plugins.
 *  Plugins are loaded by finding them in a plugin Directory and loading them sequentially.
 *  Once they arem loaded the dockable plugins are initialised and then passed sequentially the aviable dockItem
 *  plugins and then its up to the Dockable plugins to accept or reject them.
 *  Once the dockable Plugins load a dockItem plugin, it must use its internal pluginManager to manage it's own
 *  children dockItem plugins.
 * */

PluginManager::PluginManager( const char* pluginsDirectory){
	constructObjects();
	numPlugins = 0;
	setPluginsDir( pluginsDirectory ); // internal const char* variable updated.
	initializePluginManager();
	initializePluginsDir();
	browsePluginsDir();
}
PluginManager::PluginManager(){
	constructObjects();
	setNumPlugins(0);
	setPluginsDir( "./pluginsPlace" ); // default location set
	initializePluginManager();
	initializePluginsDir();
	// ... the action begins with this next function...browse and load plugins...	
	browsePluginsDir();
}
void PluginManager::initializePluginManager(){
}
void PluginManager::browsePluginsDir(){
	pluginsDir->setPath( QString( getPluginsDir().toAscii().data() ) );
	*(allPlugins) = pluginsDir->entryList( QDir::Files, QDir::Unsorted ).filter( QString(".so" ) );
	setNumPlugins( allPlugins->count() );	
	cout << "Found " << getNumPlugins() << " plugin(s)" <<endl;
	if( getNumPlugins() > 0 )
		cout << "Loading these plugins..." << endl << endl;
	// Start Plugin Loader, Fetch and instantiate all plugins...
	for( int i = 0 ; i < getNumPlugins() ; i++ )
		loadPlugin( QString( getPluginsDir() + QString("/") + allPlugins->at(i) ).toAscii().data() );

	// Load/Start all Dockable Plugins -> initialize them ( they are already instantiated by now )...
	for( int i = 0 ; i < storeForAllDockablePlugins->count() ; i++ )
		qobject_cast<PluginFeatures*>(storeForAllDockablePlugins->at(i))->loadMe();
	
	// Now for all Dockable Plugins, pass them each dockItem plugin and let them verify if they can handle them.
	// DockablePlugins will take in any DockItemPlugin, but will only accept plugins made for it ( ie cast it to a specific interface )
	
	for( int i = 0; i < storeForAllDockablePlugins->count() ; i++ ){
		for( int j = 0; j < storeForAllDockItemPlugins->count() ; j++){
		// #1) Give each dockItem to each dockable object -> dockable object will check and cast appropriatly.
		// result is bool -> true acceppted, false rejected ( not used yet )
		 qobject_cast<DockableFeatures*>(storeForAllDockablePlugins->at(i))->recieveDockItemPlugin( storeForAllDockItemPlugins->at(j));
		 // TODO : Even though it finds the right dockable-dockItem combination it still 
		 //        tries the other combinations out(slow-unnecessary)...fix later
		 
		}
	}
	cout << storeForAllDockablePlugins->count() << " DockableFeatures Plugin(s)" << endl;
	cout << storeForAllDockItemPlugins->count() << " DockItemsFeatures Plugin(s)" << endl;
	// That's it ! Now its over to the dockable plugins and the dockItem plugins...
}


void PluginManager::setPluginsDir( const char* dir ){
	pluginsDir->setPath( QString( dir ) );
}
QString PluginManager::getPluginsDir(){
	return pluginsDir->canonicalPath();
}
void PluginManager::setNumPlugins( int num){
	this->numPlugins = num;
}
int PluginManager::getNumPlugins(){
	return this->numPlugins;
}
void PluginManager::constructObjects(){
	pluginsDir = new QDir(); // browsing the current direcory so far.
	allPlugins = new QStringList();
	pluginLoader = new QPluginLoader();
	storeForAllDockablePlugins = new QList<QObject*>;
	storeForAllDockItemPlugins = new QList<QObject*>;
	storeForAllPlugins = new QList<QObject*>;
}
void PluginManager::initializePluginsDir(){
	// set the plugin directory as QDir
	pluginsDir->setPath( getPluginsDir().toAscii().data()); // see deferences
	// check if it is a valid location
	if( pluginsDir->exists() == false )
		cout << "Plugin directory '" << getPluginsDir().toAscii().data() << "' doesn't exist" << endl;
	// return only files when we query for all the contents of directory.
	pluginsDir->setFilter( QDir::Files );
}


void PluginManager::loadPlugin( const char* fileName ){
	
	pluginLoader->setFileName( QString( fileName ) );
	pluginLoader->load();  // instantiate object plugin
	QObject* plugin = pluginLoader->instance(); // metamorphoses from static serialized file into dynamic object.Beautiful

		
	// Check if it has been loaded( requirements are QT-dev build number versions of lib etc..)
	// It debug release of application, should debug version of plugin...
	
	// Load all plugins that we find, put them into two catagories -> dockable and dockItem.	
	if( pluginLoader->isLoaded() == false ){
		cout << fileName << " could not be loaded." << endl;
	}else{
		storeForAllPlugins->append( plugin );
		if( qobject_cast<DockableFeatures*>(plugin) ){
			storeForAllDockablePlugins->append( plugin ); // Keep dockable plugins, if thats what it is
		}
		if( qobject_cast<DockItemFeatures*>(plugin) ){
			storeForAllDockItemPlugins->append( plugin ); // keep DockItem plugins, if thats what it is
		}
	}

	// leaving this function, we should have a nice fat collection of plugins stored in
	// 1) storeForAllDockablePlugins
	// 2) storeForAllDockItemPlugins
	// Now we need to load/start the dockable plugins...
}
