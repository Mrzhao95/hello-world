#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction* lineAction;
    QAction* rectAction;
    QAction* pointAction;
    QAction* saveAction;
    QAction* rightAlignAction;
    QAction* leftAlignAction;
    QAction* centerAlignAction;
    QAction* topAlignAction;
    QAction* bottomAlignAction;
    QAction* middleAlignAction;

    QMenu* pointMenu;
    QMenu* lineMenu;

    void toolBarInit();
    void createInfoWindow();
    void createPointMenu(QAction* action);
    void createLineMenu(QAction* action);
    void createTableWidget(QDockWidget* dock);

private slots:
    void pointActionOnClicked();
    void lineActionOnClicked();
};

#endif // MAINWINDOW_H
