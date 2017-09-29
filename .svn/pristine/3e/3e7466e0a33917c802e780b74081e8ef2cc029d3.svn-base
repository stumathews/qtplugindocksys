#ifndef MAINWINDOW_H
#define MAINWINDOW_H
	
#include <QtGui> 
#include <QItemSelectionModel>
#include <QSqlRecord>
class QTableView;
class QSqlTableModel;
class AboutBox;
class StatusDialog;
class FilterPabel;
class QVBoxLayout;
class QHBoxLayout;
class QSplitter;
class QListView;
class QGroupBox;
class TestPlatform;
class QSqlRelationalTableModel;

class MainWindow : public QMainWindow{
	Q_OBJECT
	public:
		/*Constructors*/
		MainWindow();
		~MainWindow();
		void createToolBars();
		
	private slots:
		void bookIn(); 
		void bookOut();
		void viewEntry();
		void editEntry();
				 
		void searchForEntry();
		void updateJob();
		void about();
		void reserved();
	private:
		void createActions();
		void createMenus();
		void createStatusBar();
		void createFormLayout();
		void constructObjects();
		
		QLabel* topHeader;
		
		QGroupBox* mainWindowContent;
		QVBoxLayout* mainPage;
		QHBoxLayout* buttonPanel;

		QPushButton* editViewButton;
		QPushButton* updateButton;
		
		QMenu* fileMenu;
		QMenu* editMenu;
		QMenu* bookMenu;
		QMenu* aboutMenu;
		QToolBar* fileToolBar;
		QToolBar* editToolBar;
		QToolBar* bookToolBar;
		QAction* actBookIn;
		QAction* actBookOut;
		QAction* actViewEntry;
		QAction* actEditEntry;
		QAction* actSearchForEntry;
		QAction* actAboutQt;
		QAction* actAbout;
		QAction* actExitApp;
		QAction* actReserved;
		QAction* actUpdateJob;

		QVBoxLayout* layout;
		QHBoxLayout* buttonLayout;
		QHBoxLayout* imageLayout;
		QSplitter* splitter;
		QListView* listView;
		QGroupBox* group;
		
		
};

#endif
