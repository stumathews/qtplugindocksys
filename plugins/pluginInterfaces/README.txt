

1. Interface that Dockable plugin Uses -> API
2. Interface that the DockItem must inherit to be a DockItem to that Dockable plugin. -> is check against in dockable plugin.

HOWTO implement of dockItem Plugin :

	1. Inherit the right interface -> the REQUIRED interface that the Dockable plugin specifies
		AND :
		a) QObject.
		b) DockItemFeatures
		c) PluginFeatures
	2. Include the header file of the interface of API routines that the Dockable plugin uses.
	2.1 Include <QObject>
	3. Specify the interfaces that are used in class declaration Q_INTERFACES( ... )
	4. Specify the Q_OBJECT macro in class declaration.

	5. Overide and implment all functions that are required( abstract functions... )
	6. Should call doMyMainWork() in loadMeAsForeignPlugin() function.


Making a Dockable Plugin :

	Make you plugin class inherits these classes  :
		1) QObject 
		2) DockableFeatures
		3) PluginFeatures
	Now you need to create a interface to your plugin class.
	To do this you need to make a class that declares pure virtual functions.
	These are the routines that your plugin class will overide.
	This is done so that the DockItem can 'use' this interface.

	Now apart from the above classes you inherited, inherit your interface as well in your plugin class.
	Now you will need to overide and implment all those pure virtual functions in your classes cpp.
	You'll see that you wont be able use your plugin class until you implment these 'abstract'/virtual functions.

	At this stage you have a class declaration that inherits 4 classes.
	Now create your corresponding .cpp file and implement those virtual functions.(to start off leave them blank)

	That's it -> your plugin class can now be instantiated, and passed around the plugin system.
	Oh, one other thing... include the macros :
		Q_OBJECT
		Q_INTERFACES( ... )
	in your class declaration( class.h file ).
	
	EG : 
		class NewDockablePlugin : public QObject,
					  public DockableFeatures,
					  public PluginFeatures,
					  public YourDefinedInterfaceAPI
		{
			Q_OBJECT
			Q_INTERFACES( DockableFeatures PluginFeatures YourDefinedInterfaceAPI )
		
			public:
				NewDockablePlugin(){}
			// the overidded/implment functions from 'YourDefiendInterfaceAPI' will come here
			// and any other internal functions you use for your 'NewDockablePlugin' goes in here.
		}
		
	See mainWindow plugin for example on what i mean.


Making a DockItem plugin for a Dockable Plugin :

	Make your plugin class inherit these classes :
		1) QObject
		2) DockItemFeatures
		3) PluginFeatures
	Now you need to create a common DockItem Compatibility Interface...just a empty class..heh.
	Inherit that empty class.Tell you why now, now.
	Okay now implment all the pure virtual functions you inherited from those classes above.(can leave them blank for now )

	That's it -> your dockItem plugin now will be able to 'Fit' into any dockable plugin that likes your empty class you
	inherited remember? Dockable plugins look for specific classes that dockItem plugins inherit inorder to know if
	that dockItem plugin is make for it.
	Oh! one other thing... include the macros( in .h ):
		Q_OBJECT
		Q_INTERFACE( ... )

	EG :
		class NewDockItemPlugin : public QObject,
					  public DockItemFeatures,
					  public PluginFeatures,
					  plugin YourEmptyClass
		{
			Q_OBJECT
			Q_INTERFACE( DockItemFeatures PluginFeatures YourEmptyClass )
			public:
				NewDockItemPlugin(){}
			// the overidded/implment functions from inherited classes will come here
			// and any other internal functions you use for your 'NewDockItemPlugin' goes in here.
		
		}
					

To see what we expect in those blank virtual functions, see the example in plugins/mainWindow.
