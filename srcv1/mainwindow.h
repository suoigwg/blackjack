#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include "bet.h"
#include <QString>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);
public slots:
    void Hit();
    void Stand();
    void Start();
    void ten();
    void twentyfive();
    void fifty();
    void Bdouble();
private:
    Ui::MainWindow *ui;
    QLabel* text;
    QLabel* tpm;
    QLabel* tdm;
    QLabel* tgm;
    QLabel* tfund;
    QLabel* tstake;
    QWidget* window;
    QGridLayout* Glayout;
    QPushButton* BHit;
    QPushButton* BStand;
    QPushButton* BStart;
    QPushButton* Bt;
    QPushButton* Btf;
    QPushButton* Bft;
    QPushButton* Bdb;
    std::string pm;
    std::string dm;
    std::string gm;
    QString qpm;
    QString qdm;
    QString qgm;
    QString qfund;
    QString qstake;
    int fund;
    int stake;
    int win;
};

#endif // MAINWINDOW_H
