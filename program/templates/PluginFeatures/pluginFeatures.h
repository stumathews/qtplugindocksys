#ifndef PLUGIN_FEATURES_H
#define PLUGIN_FEATURES_H
#include <QObject>

class PluginFeatures 
{
	public:
		virtual ~PluginFeatures(){}
		virtual void loadMe() = 0;

		virtual void setPluginName( const char* pluginName );
		virtual const char* getPluginName();
		const char* pluginName;	
};

Q_DECLARE_INTERFACE( PluginFeatures, "Plugin Interface" )
#endif
