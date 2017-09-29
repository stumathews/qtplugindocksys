#ifndef DOCK_ITEM_FEATURES_H
#define DOCK_ITEM_FEATURES_H
#include <QObject>
#include "pluginFeatures.h"

class DockItemFeatures
{
	public:
	virtual ~DockItemFeatures(){}	
	virtual const char* getFitsIntoWho();
	virtual void setFitsIntoWho( const char* fitsIntoWho );
	virtual void setDockableObject( QObject* dockableObject );
	virtual QObject* getDockableObject();
	QObject* dockableObject;	
	virtual void loadMeAsForeignPlugin() = 0;
	const char* fitsIntoWho;
};
Q_DECLARE_INTERFACE( DockItemFeatures, "DockItem Features Interace" )

#endif
