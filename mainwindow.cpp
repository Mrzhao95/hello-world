#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapview.h"
#include <QMdiSubWindow>
#include <QList>
#include <QDockWidget>
#include <QListWidget>
#include <QTableWidget>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/icon.ico"));
    setWindowTitle("SunnyTcs_MapEdit");
    toolBarInit();
    createInfoWindow();
    MapView* mapView = new MapView;
    QMdiSubWindow* subWindow = new QMdiSubWindow;
    subWindow->setWidget(mapView);
    ui->mdiArea->addSubWindow(subWindow);
    ui->mdiArea->tileSubWindows();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pointActionOnClicked(){
    pointMenu->popup(QPoint(cursor().pos().x(),cursor().pos().y()));
}

void MainWindow::lineActionOnClicked(){
    lineMenu->popup(QPoint(cursor().pos().x(),cursor().pos().y()));
}

void MainWindow::toolBarInit(){
    lineAction = new QAction(QIcon(":/icon/path.png"),QString("line"));
    rectAction = new QAction(QIcon(":/icon/station.png"),QString("rect"));
    pointAction = new QAction(QIcon(":/icon/point.png"),QString("point"));
    saveAction = new QAction(QIcon(":/icon/save.png"),QString("save"));

    rightAlignAction = new QAction(QIcon(":/icon/right.png"),QString("Right Align"));
    leftAlignAction = new QAction(QIcon(":/icon/left.png"),QString("Left Align"));
    centerAlignAction = new QAction(QIcon(":/icon/center.png"),QString("Center Align"));
    topAlignAction = new QAction(QIcon(":/icon/top.png"),QString("Top Align"));
    bottomAlignAction = new QAction(QIcon(":/icon/bottom.png"),QString("Bottom Align"));
    middleAlignAction = new QAction(QIcon(":/icon/middle.png"),QString("Middle Align"));

    ui->mainToolBar->addAction(saveAction);
    ui->mainToolBar->addAction(rectAction);
    ui->mainToolBar->addAction(pointAction);
    ui->mainToolBar->addAction(lineAction);

    QToolBar* toolBar = new QToolBar;
    toolBar->addAction(rightAlignAction);
    toolBar->addAction(leftAlignAction);
    toolBar->addAction(centerAlignAction);
    toolBar->addAction(topAlignAction);
    toolBar->addAction(bottomAlignAction);
    toolBar->addAction(middleAlignAction);
    addToolBarBreak(Qt::TopToolBarArea);
    addToolBar(toolBar);
    createPointMenu(pointAction);
    createLineMenu(lineAction);
}


void MainWindow::createPointMenu(QAction* action){
    pointMenu = new QMenu();
    QAction *haltPointAction = new QAction(QIcon(":/icon/b.png"),QString("Halt Point"));
    QAction *reportPointAction = new QAction(QIcon(":/icon/p.png"),QString("Report Point"));
    QAction *parkPointAction = new QAction(QIcon(":/icon/r.png"),QString("Park Point"));

    pointMenu->addAction(haltPointAction);
    pointMenu->addAction(reportPointAction);
    pointMenu->addAction(parkPointAction);

    connect(action,SIGNAL(triggered()),this,SLOT(pointActionOnClicked()));
}

void MainWindow::createLineMenu(QAction *action){
    lineMenu = new QMenu();
    QAction* directLineAction = new QAction(QString("Directed Line"));
    QAction* bezierLineAction = new QAction(QString("2-Bezier Line"));
    lineMenu->addAction(directLineAction);
    lineMenu->addAction(bezierLineAction);
    connect(action,SIGNAL(triggered()),this,SLOT(lineActionOnClicked()));

}

void MainWindow::createInfoWindow(){
  QDockWidget *dock = new QDockWidget(tr("Info Show"),this);
  dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
  QListWidget *infoList = new QListWidget(dock);
  infoList->addItems(QStringList()<<"agv1->agv2"<<"agv2->agv3"<<"agv3->agv4");
  dock->setWidget(infoList);
  addDockWidget(Qt::LeftDockWidgetArea,dock);
  ui->menu_V->addAction(dock->toggleViewAction());

  QDockWidget *dock2 = new QDockWidget(tr("Show"),this);
  dock2->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
  createTableWidget(dock2);

  addDockWidget(Qt::LeftDockWidgetArea,dock2);
  ui->menu_V->addAction(dock2->toggleViewAction());

}

void MainWindow::createTableWidget(QDockWidget* dock){
    QTableWidget* table = new QTableWidget(4,2);
    table->setHorizontalHeaderLabels(QStringList()<<"Attribute"<<"Value");
    QTableWidgetItem* item1 = new QTableWidgetItem("Name");
    item1->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem* item2 = new QTableWidgetItem("Action");
    item2->setTextAlignment(Qt::AlignCenter);
    table->setItem(0,0,item1);
    table->setItem(1,0,item2);
    table->verticalHeader()->hide();
    table->setShowGrid(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    dock->setWidget(table);
}
