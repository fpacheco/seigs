#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include <QToolBar>


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  // Maximize
  setWindowState(Qt::WindowMaximized);
  // Create
  createActions();
  createMenus();
  createToolBars();
  createStatusBar();
  ///@todo Eliminated?
  readSettings();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::createActions()
{
  //QString myIconPath=MiihApplication::themePath();
  //qDebug()<< "myIconPath=" << myIconPath;
  QString myIconPath="/homes/rpacheco";

  mActionNew = new QAction(QIcon(myIconPath+"/mActionFileNew.png"), tr("&New database"), this);
  mActionNew->setShortcut(tr("Ctrl+N"));
  mActionNew->setStatusTip(tr("Create a new MIIH database"));
  connect(mActionNew, SIGNAL(triggered()), this, SLOT(newDatabaseFile()));

  mActionOpen = new QAction(QIcon(myIconPath+"/mActionFileOpen.png"), tr("&Open..."), this);
  mActionOpen->setShortcut(tr("Ctrl+O"));
  mActionOpen->setStatusTip(tr("Open ASCII sesimic file"));
  //connect(mActionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
  connect(mActionOpen, &QAction::triggered, this, &MainWindow::openFile);

  mActionSave = new QAction(QIcon(myIconPath+"/mActionFileSave.png"), tr("&Save"),this);
  mActionSave->setShortcut(tr("Ctrl+S"));
  mActionSave->setStatusTip(tr("Save the document to disk"));
  //connect(mActionSave, &QAction::triggered, this, &MainWindow::save);

  mActionSaveAs = new QAction(QIcon(myIconPath+"/mActionFileSaveAs.png"),tr("Save &As..."), this);
  mActionSaveAs->setStatusTip(tr("Save the actual MIIH under a new name"));
  connect(mActionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));

  mActionClose = new QAction(QIcon(myIconPath+"/mActionClose.png"),tr("C&lose"), this);
  mActionClose->setStatusTip(tr("Close ASCII sesimic file"));
  connect(mActionClose, &QAction::triggered, this, &MainWindow::closeFile);

  mActionExit = new QAction(tr("E&xit"), this);
  mActionExit->setShortcut(tr("Ctrl+Q"));
  mActionExit->setStatusTip(tr("Exit the application"));
  connect(mActionExit, SIGNAL(triggered()), this, SLOT(close()));

  mActionCut = new QAction(QIcon(myIconPath+"/mActionEditCut.png"), tr("Cu&t"), this);
  mActionCut->setShortcut(tr("Ctrl+X"));
  mActionCut->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
  //connect(mActionCut, SIGNAL(triggered()), mTextEdit, SLOT(cut()));

  mActionCopy = new QAction(QIcon(myIconPath+"/mActionEditCopy.png"), tr("&Copy"),this);
  mActionCopy->setShortcut(tr("Ctrl+C"));
  mActionCopy->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
  //connect(mActionCopy, SIGNAL(triggered()), mTextEdit, SLOT(copy()));

  mActionPaste = new QAction(QIcon(myIconPath+"/mActionEditPaste.png"), tr("&Paste"),this);
  mActionPaste->setShortcut(tr("Ctrl+V"));
  mActionPaste->setStatusTip(tr("Paste the clipboard's contents into the"
                                "current selection"));
  //connect(mActionPaste, SIGNAL(triggered()), mTextEdit, SLOT(paste()));

  mActionShowPluginManager = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"), tr("Plu&gins"),this);
  mActionShowPluginManager->setShortcut(tr("Ctrl+G"));
  mActionShowPluginManager->setStatusTip(tr("View the Plugin Manager interface"));
  connect(mActionShowPluginManager, SIGNAL(triggered()), this,SLOT(showPluginManager()));

  mActionAbout = new QAction(tr("&About"), this);
  mActionAbout->setStatusTip(tr("Show the application's About box"));
  connect(mActionAbout, SIGNAL(triggered()), this, SLOT(about()));

  mActionAboutQt = new QAction(tr("About &Qt"), this);
  mActionAboutQt->setStatusTip(tr("Show the Qt library's About box"));
  connect(mActionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  // Database basic actions
  mActionDBPointCreate = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Create point"), this);
  mActionDBPointCreate->setStatusTip(tr("Create new points in the current database"));
  connect(mActionDBPointCreate, SIGNAL(triggered()), this, SLOT(dbPointCreate()));

  mActionDBPointEdit = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Edit point"), this);
  mActionDBPointEdit->setStatusTip(tr("Edit points in the current database"));
  connect(mActionDBPointEdit, SIGNAL(triggered()), this, SLOT(dbPointEdit()));

  mActionDBPointDelete = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Delete point"), this);
  mActionDBPointDelete->setStatusTip(tr("Delete new points in the current database"));
  connect(mActionDBPointDelete, SIGNAL(triggered()), this, SLOT(dbPointDelete()));

  mActionDBGroupCreate = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Create group"), this);
  mActionDBGroupCreate->setStatusTip(tr("Create new groups in the current database"));
  connect(mActionDBGroupCreate, SIGNAL(triggered()), this, SLOT(dbGroupCreate()));

  mActionDBGroupEdit = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Edit group"), this);
  mActionDBGroupEdit->setStatusTip(tr("Edit groups in the current database"));
  connect(mActionDBGroupEdit, SIGNAL(triggered()), this, SLOT(dbGroupEdit()));

  mActionDBGroupDelete = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Delete group"), this);
  mActionDBGroupDelete->setStatusTip(tr("Delete groups in the current database"));
  connect(mActionDBGroupDelete, SIGNAL(triggered()), this, SLOT(dbGroupDelete()));

  mActionDBProjectCreate = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Create group"), this);
  mActionDBProjectCreate->setStatusTip(tr("Create new groups in the current database"));
  connect(mActionDBProjectCreate, SIGNAL(triggered()), this, SLOT(dbProjectCreate()));

  mActionDBProjectEdit = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Edit grou"), this);
  mActionDBProjectEdit->setStatusTip(tr("Edit groups in the current database"));
  connect(mActionDBProjectEdit, SIGNAL(triggered()), this, SLOT(dbProjectEdit()));

  mActionDBProjectDelete = new QAction(QIcon(myIconPath+"/mActionShowPluginManager.png"),tr("Delete group"), this);
  mActionDBProjectDelete->setStatusTip(tr("Delete groups in the current database"));
  connect(mActionDBProjectDelete, SIGNAL(triggered()), this, SLOT(dbProjectDelete()));



  mActionCut->setEnabled(false);
  mActionCopy->setEnabled(false);
  //connect(mTextEdit, SIGNAL(copyAvailable(bool)),mActionCut, SLOT(setEnabled(bool)));
  //connect(mTextEdit, SIGNAL(copyAvailable(bool)),mActionCopy, SLOT(setEnabled(bool)));

}

void MainWindow::createMenus()
{
  mFileMenu = menuBar()->addMenu(tr("&File"));
  //mFileMenu->addAction(mActionNew);
  mFileMenu->addAction(mActionOpen);
  mFileMenu->addAction(mActionSave);
  mFileMenu->addAction(mActionSaveAs);
  mFileMenu->addAction(mActionClose);
  mFileMenu->addSeparator();
  mFileMenu->addAction(mActionExit);

  mEditMenu = menuBar()->addMenu(tr("&Edit"));
  mEditMenu->addAction(mActionCut);
  mEditMenu->addAction(mActionCopy);
  mEditMenu->addAction(mActionPaste);

  /*
  qDebug() << "Creating database menus ... ";
  qDebug() << "Points ... ";
  mDatabaseMenu = menuBar()->addMenu(tr("&Database"));
  mDatabaseMenuPoints = mDatabaseMenu->addMenu(tr("Po&ints"));
  mDatabaseMenuPoints->addAction(mActionDBPointCreate);
  mDatabaseMenuPoints->addAction(mActionDBPointEdit);
  mDatabaseMenuPoints->addAction(mActionDBPointDelete);

  qDebug() << "Groups ... ";
  mDatabaseMenuGroups = mDatabaseMenu->addMenu(tr("&Groups"));
  mDatabaseMenuGroups->addAction(mActionDBGroupCreate);
  mDatabaseMenuGroups->addAction(mActionDBGroupEdit);
  mDatabaseMenuGroups->addAction(mActionDBGroupDelete);

  qDebug() << "Projects ... ";
  mDatabaseMenuProjects = mDatabaseMenu->addMenu(tr("P&rojects"));
  mDatabaseMenuProjects->addAction(mActionDBProjectCreate);
  mDatabaseMenuProjects->addAction(mActionDBProjectEdit);
  mDatabaseMenuProjects->addAction(mActionDBProjectDelete);

  mPluginMenu = menuBar()->addMenu(tr("&Plugins"));
  mPluginMenu->addAction(mActionShowPluginManager);
#ifdef HAVE_PYTHON
  //mPluginMenu->addAction(mActionShowPythonDialog);
#endif
  mPluginMenu->addSeparator();
  */

  menuBar()->addSeparator();

  mHelpMenu = menuBar()->addMenu(tr("&Help"));
  mHelpMenu->addAction(mActionAbout);
  mHelpMenu->addAction(mActionAboutQt);
}

void MainWindow::createToolBars()
{
  mFileToolBar = addToolBar(tr("File"));
  //mFileToolBar->addAction(mActionNew);
  mFileToolBar->addAction(mActionOpen);
  mFileToolBar->addAction(mActionSave);
  mFileToolBar->addSeparator();
  mFileToolBar->addAction(mActionClose);

  mEditToolBar = addToolBar(tr("Edit"));
  mEditToolBar->addAction(mActionCut);
  mEditToolBar->addAction(mActionCopy);
  mEditToolBar->addAction(mActionPaste);

  // mPluginToolBar = addToolBar(tr("Plugins"));
}

void MainWindow::createStatusBar()
{
  statusBar()->showMessage(tr("Ready"));
}

void MainWindow::readSettings()
{
  QSettings settings("Trolltech", "Application Example");
  QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
  QSize size = settings.value("size", QSize(400, 400)).toSize();
  resize(size);
  move(pos);
}

void MainWindow::writeSettings()
{
  QSettings settings("Trolltech", "Application Example");
  settings.setValue("pos", pos());
  settings.setValue("size", size());
}

void MainWindow::openFile()
{
  QString filePath = QFileDialog::getOpenFileName(this);//,tr("Open MIIH database"),QDir::currentPath(),tr("Miih files (*.miih);;All files (*.*)"));
  ///@todo If database is open
  if (!filePath.isEmpty()) {
    mSline = new SeisLine(filePath);

    emit dataLoaded(filePath);

    /*
    loadDB(fileName);
    mConnected = true;
    ///@todo
    setupPointsTree();
    //setupGroupsTree();
    //setupProjectsTree();
    */
  }
}

void MainWindow::closeFile()
{
  emit dataUnloaded();
}
