#ifndef MAPVIEW_H
#define MAPVIEW_H
#include <QWidget>
#include <QGraphicsScene>
#include <QLayout>
namespace Ui {
class MapView;
}

class MapView : public QWidget
{
    Q_OBJECT

public:
    explicit MapView(QWidget *parent = 0);
    ~MapView();

private:
    Ui::MapView *ui;
    QAction* borderAction;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QVBoxLayout* layout;
    void setSceneBackground(QGraphicsScene* scene,QGraphicsView* view);
    void setToolBar();
    void closeEvent(QCloseEvent* event);
    void paintEvent(QPaintEvent* event);

};

#endif // MAPVIEW_H
