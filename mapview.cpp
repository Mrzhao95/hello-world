#include "mapview.h"
#include "ui_mapview.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPolygon>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QToolBar>
#include <QCloseEvent>
#include <QLayout>

MapView::MapView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapView)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,500,500);
    view = new QGraphicsView();
    layout = new QVBoxLayout;
    layout->addWidget(view);
    setLayout(layout);
    setSceneBackground(scene,view);
    setToolBar();

}

void MapView::closeEvent(QCloseEvent *event){
    event->ignore();
}

MapView::~MapView()
{
    delete ui;
}

void MapView::setToolBar(){
    QToolBar* toolBar = new QToolBar;
    borderAction = new QAction(QIcon(":/icon/border.png"),QString("Add Border"));
    toolBar->setFixedHeight(40);
    toolBar->setIconSize(QSize(40,40));
    ui->comboBox->setFixedWidth(100);
    ui->comboBox->addItem(QString("100%"));
    ui->comboBox->addItem(QString("70%"));
    toolBar->addWidget(ui->comboBox);
    toolBar->addAction(borderAction);
   layout->addWidget(toolBar);
}

void MapView::setSceneBackground(QGraphicsScene* scene,QGraphicsView *view){
    QPolygonF myPolygon1;
    myPolygon1 << QPointF(10,0) << QPointF(10,20);
    QPolygonF myPolygon2;
    myPolygon2 << QPointF(0,10) << QPointF(20,10);
    QPixmap pixmap(20,20);//设置pixmap的大小
    pixmap.fill(Qt::transparent);//透明填充
    QPainter painter(&pixmap);

//  QVector<qreal> dashes;//line style--虚线
//  qreal space = 2;
//  dashes <<2<< space <<2<<space;
    QPen pen(Qt::lightGray,1);
  //pen.setDashPattern(dashes);
    pen.setStyle(Qt::DashLine);
    pen.setWidth(1);

    painter.setPen(pen);
    painter.drawPolyline(myPolygon1);
    painter.drawPolyline(myPolygon2);
    scene->setBackgroundBrush(pixmap);
    view->setScene(scene);

}

void MapView::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(18,18,18,1000);
    painter.drawLine(18,18,1000,18);
    int i;
    for(i=18;i<1000;i+=50){
        painter.drawLine(i+50,18,i+50,15);
        painter.drawText(i+50,15,QString::number(i+32));
    }

    for(i=18;i<1000;i+=50){
        painter.drawLine(18,i+50,15,i+50);
        painter.drawText(0,i+50,QString::number(i+32));
    }

}
