#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include <QObject>
#include <QMainWindow>
#include <QChart>
#include <QChartView>
//
#include "seisline.h"
#include "chartviewwindow.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = Q_NULLPTR);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

  void createActions();
  void createMenus();
  void createToolBars();
  void createStatusBar();

  void createDockPoints();
  void createDockGroups();
  void createDockProjects();

  void readSettings();
  void writeSettings();

public slots:
  void openFile();
  void closeFile();
  void plotChannels();
  void plotShots();

signals:
  void dataLoaded(QString filePath);
  void dataUnloaded();

// Private variables
private:
  QMenu *mFileMenu;
  QMenu *mEditMenu;
  //! Database menu
  QMenu * mDatabaseMenu;
  QMenu * mDatabaseMenuPoints;
  QMenu * mDatabaseMenuGroups;
  QMenu * mDatabaseMenuProjects;

  //QMenu *mPluginsMenu;
  QMenu *mHelpMenu;
  //! Popup menu
  QMenu * mPopupMenu;
  //! Top level plugin menu
  QMenu *mPluginMenu;

  /// Toolbars
  QToolBar *mFileToolBar;
  QToolBar *mEditToolBar;
  QToolBar *mChartToolBar;

  /// Plugins
  // QToolBar *mPluginToolBar;

  /// Docks
  QDockWidget *mDockPoints;
  QDockWidget *mDockGroups;
  QDockWidget *mDockProjects;
  /// Trees
  //QTreeView *mGroupsTree;
  //QTreeView *mProjectsTree;

  ///Actions
  QAction *mActionNew;
  QAction *mActionOpen;
  QAction *mActionSave;
  QAction *mActionSaveAs;
  QAction *mActionClose;
  QAction *mActionExit;
  QAction *mActionCut;
  QAction *mActionCopy;
  QAction *mActionPaste;
  QAction *mActionShowPluginManager;
  QAction *mActionAbout;
  QAction *mActionAboutQt;

  // Plot actions
  QAction *mActionChartChannels;
  QAction *mActionChartShots;

  //Database basic actions
  QAction *mActionDBPointCreate;
  QAction *mActionDBPointEdit;
  QAction *mActionDBPointDelete;

  QAction *mActionDBGroupCreate;
  QAction *mActionDBGroupEdit;
  QAction *mActionDBGroupDelete;

  QAction *mActionDBProjectCreate;
  QAction *mActionDBProjectEdit;
  QAction *mActionDBProjectDelete;

  // The data
  SeisLine *mSline;
  ChartViewWindow *mCVWindow;
};

#endif // MAINWINDOW_H
