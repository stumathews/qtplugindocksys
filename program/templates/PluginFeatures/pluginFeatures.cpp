#include "pluginFeatures.h"

void PluginFeatures::setPluginName( const char* pluginName ){
	this->pluginName = pluginName;
}
const char* PluginFeatures::getPluginName(){
	return this->pluginName;
}
