#!/bin/bash

# stupid little static script to make distribution easier...:w

PLUGINSDIR=/home/stuart/projects/Services@Workshop/pluginDockSystem/plugins/
PROGRAMDIR=/home/stuart/projects/Services@Workshop/pluginDockSystem/program/
# Various Make Directories...

# Plugins :

MAINWINDOW=$PLUGINSDIR/mainWindow
TOOLBAR=$PLUGINSDIR/toolBarPlugin
DEFAULTTOOLBARBUTTON=$TOOLBAR/defaultToolBarButtonPlugin
MENUBAR=$PLUGINSDIR/menuBar
STATUSBAR=$PLUGINSDIR/statusBar




echo "Making program..."
cd $PROGRAMDIR
make clean
qmake -project
qmake
make
echo "Making plugins..."
echo "PLUGIN: mainWindow"
cd $MAINWINDOW
make clean
qmake
make
echo "PLUGIN: toolbar"
cd $TOOLBAR
make clean
qmake
make
echo "PLUGIN: toolbar default button..."
cd $DEFAULTTOOLBARBUTTON
make clean
qmake
make
echo "PLUGIN: menubar "
cd $MENUBAR
make clean
qmake
make
echo "PLUGIN: statusBar "
cd $STATUSBAR
make clean
qmake
make

