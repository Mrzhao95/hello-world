#include "info.h"
#include "ui_info.h"
#include <QScrollArea>
#include <QGridLayout>
#include <QTextBrowser>
Info::Info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info)
{
      ui->setupUi(this);
      setWindowTitle("InfoShow");
//      QWidget* widget = new QWidget;
//      widget->resize(500,500);
      QGridLayout *layout = new QGridLayout;
      QTextBrowser *textBrowser = new QTextBrowser;
      layout->addWidget(textBrowser);
//     widget->setLayout(layout);

      QScrollArea *scrollArea = new QScrollArea;
      scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
      scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
      scrollArea->setLayout(layout);

      QGridLayout *layout2 = new QGridLayout;
      layout2->addWidget(scrollArea);
      setLayout(layout2);

}

Info::~Info()
{
    delete ui;
}
