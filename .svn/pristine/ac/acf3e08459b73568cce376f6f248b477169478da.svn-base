#include "MainWindow.h"
#include <QMessageBox>
#include <iostream>
#include <QSqlQuery>
#include <QAbstractItemModel>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
// Tempararily implemented
#include <QSplitter>
#include <QListView>
#include <QAbstractItemModel>

MainWindow::MainWindow()
{
	
	constructObjects();
	
	updateButton = new QPushButton( "Update" );
	connect( updateButton, SIGNAL( clicked() ), this, SLOT( updateJob() ) );
	editViewButton = new QPushButton( "View/Edit" );
	connect( editViewButton, SIGNAL( clicked() ), this, SLOT( editEntry() ) );

//	setModel( model );
//	setView( view );
	createActions();
//	createMenus();
//	createToolBars();
//	createStatusBar();
	createFormLayout();

}

void MainWindow::bookIn(){
}
void MainWindow::bookOut(){

}
void MainWindow::viewEntry(){

}
void MainWindow::editEntry(){
	viewEntry();
	
}
void MainWindow::searchForEntry(){
	QMessageBox::information(this,"nota bene","This has not been implemented yet\n"
			" because the functionality is already available.\n"
			"This merely is a place holder for that functionality to be\n"
			" implemented in a diffirent way.");
}
void MainWindow::updateJob(){
}
void MainWindow::reserved(){
}

void MainWindow::about(){
}
void MainWindow::createActions(){
	actBookIn = new QAction( QIcon(":/actions/images/bookin.png"), tr("Book In"),this);
		actBookIn->setShortcut( tr("CTRL+I") );
		actBookIn->setStatusTip( tr("Book in a new entry") );
		connect( actBookIn, SIGNAL( triggered()), this, SLOT( bookIn()));
	actBookOut = new QAction( QIcon(":/actions/images/bookout.png"),tr("Book Out"), this );
		actBookOut->setShortcut( tr("CTRL+O") );
		actBookOut->setStatusTip( tr("Book out an entry" ) );
		connect( actBookOut, SIGNAL( triggered() ), this, SLOT( bookOut() ) );
	actViewEntry = new QAction( QIcon( ":/actions/images/view.png" ), tr("View Entry"), this );
		actViewEntry->setShortcut( tr("CTRL+V") );
		actViewEntry->setStatusTip( tr("View an existing entry") );
		connect( actViewEntry, SIGNAL( triggered() ), this, SLOT( viewEntry() ) );
	actEditEntry = new QAction( QIcon( ":/actions/images/edit" ),tr("Edit Entry"), this );
		actEditEntry->setShortcut( tr("CTRL+E") );
		actEditEntry->setStatusTip( tr("Edit an existing entry") );
		connect( actEditEntry, SIGNAL( triggered() ), this, SLOT( editEntry() ) );
	actSearchForEntry = new QAction( QIcon( ":/actions/images/search.png" ),tr("Search For Entry"), this );
		actSearchForEntry->setShortcut( tr("CTRL+S") );
		actSearchForEntry->setStatusTip( tr("Search for an existing entry") );
		connect( actSearchForEntry, SIGNAL( triggered() ), this, SLOT( searchForEntry()) );
	actAboutQt = new QAction( QIcon( ":/actions/images/help.png" ),tr("About Qt Toolkit"), this );
		actAboutQt->setShortcut( tr("CTRL+A") );
		actAboutQt->setStatusTip( tr("About this wonderful toolkit"));
		connect( actAboutQt, SIGNAL( triggered() ), qApp, SLOT( aboutQt() ) );
	actAbout = new QAction( QIcon( ":/actions/images/help.png" ),tr("About"), this );
		actAbout->setShortcut( tr("CTRL+A") );
		actAbout->setStatusTip( tr("About this wonderful toolkit"));
		connect( actAbout, SIGNAL( triggered() ), this, SLOT( about() ) );
	actExitApp = new QAction( QIcon( ":/actions/images/exit.png" ),tr("Exit application" ), this );
		actExitApp->setShortcut( tr("CTRL+X") );
		actExitApp->setStatusTip( tr("Exit application") );
		connect( actExitApp, SIGNAL( triggered() ), qApp, SLOT( quit() ) );
	actReserved = new QAction( QIcon( ":/actions/images/reserved.png" ),tr("Reserved Action"), this );
		actReserved->setShortcut( tr("CTRL+?") );
		actReserved->setStatusTip( tr("This is a reserved action" ) );
		connect( actReserved, SIGNAL( triggered() ), this, SLOT( reserved() ) );
	actUpdateJob = new QAction( QIcon( ":/actions/images/update.png" ),tr("Update Job"), this );
		actUpdateJob->setShortcut( tr("CTRL+?") );
		actUpdateJob->setStatusTip( tr("This is a reserved action" ) );
		connect( actUpdateJob, SIGNAL( triggered() ), this, SLOT( updateJob() ) );
}
void MainWindow::createMenus(){
	fileMenu = menuBar()->addMenu( tr("&File") );
	fileMenu->addAction( actReserved );
	fileMenu->addSeparator();	
	fileMenu->addAction( actExitApp );

	editMenu = menuBar()->addMenu( tr("&Edit") );
	editMenu->addAction( actViewEntry );
	editMenu->addAction( actEditEntry );
	editMenu->addSeparator();
	editMenu->addAction( actSearchForEntry );

	bookMenu = menuBar()->addMenu( tr("&Book") );
	bookMenu->addAction( actBookIn );
	bookMenu->addAction( actBookOut );
	bookMenu->addSeparator();
	bookMenu->addAction( actReserved );

	aboutMenu = menuBar()->addMenu( tr("&About") );
	aboutMenu->addAction( actAboutQt );
	aboutMenu->addAction( actAbout );
	aboutMenu->addSeparator();
	aboutMenu->addAction( actReserved );
	
}
void MainWindow::createToolBars(){
	
	fileToolBar = addToolBar( tr("File ToolBar") );
	fileToolBar->setMovable( false );
	fileToolBar->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
	fileToolBar->addAction( actReserved );
	fileToolBar->addAction( actExitApp );

	editToolBar = addToolBar( tr("Edit ToolBar") );
	editToolBar->setMovable( false );
	editToolBar->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
	editToolBar->addAction( actViewEntry );
	editToolBar->addAction( actEditEntry );
	editToolBar->addAction( actSearchForEntry );

	bookToolBar = addToolBar( tr("Book ToolBar" ) );
	bookToolBar->setMovable( false );
	bookToolBar->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
	bookToolBar->addAction( actBookIn );
	bookToolBar->addAction( actUpdateJob );
	bookToolBar->addAction( actBookOut );
}
void MainWindow::createStatusBar(){
	statusBar()->showMessage( tr("services@ready") );
	statusBar()->setSizeGripEnabled( true );
}


void MainWindow::createFormLayout( ){
	// This lets you change the contents of the view, on the fly
	

		buttonLayout->addStretch( 1 );
		buttonLayout->addWidget( editViewButton );
		buttonLayout->addWidget( updateButton );
	
	QLabel* picTemp = new QLabel();
		picTemp->setPixmap( QPixmap( ":/actions/images/transparentLogo.png"));
	splitter->addWidget( picTemp );
	layout->addLayout( imageLayout );
	group->setLayout( layout );
	setCentralWidget( group );
}

void MainWindow::constructObjects(){
	buttonLayout = new QHBoxLayout();
	listView = new QListView();
	layout = new QVBoxLayout();
	group = new QGroupBox();
	splitter = new QSplitter();
	imageLayout = new QHBoxLayout();
	
}
MainWindow::~MainWindow(){}
