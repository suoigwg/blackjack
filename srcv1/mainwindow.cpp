#include "mainwindow.h"
#include "ui_mainwindow.h"

BlackJackConsole blackJackConsole("Orlyn");
bet b;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    text = new QLabel(this);
    text->setText("Black Jack");
    text->show();

    tdm = new QLabel(this);
    tdm->show();

    tpm = new QLabel(this);
    tpm->show();

    tgm = new QLabel(this);
    tgm->show();

    tfund = new QLabel(this);
    tfund->setText("fund: 1500");
    tfund->show();

    tstake = new QLabel(this);
    tstake->setText("stake: 0");
    tstake->show();

    BHit = new QPushButton(this);
    BHit->setText("Hit");
    connect(BHit,&QPushButton::clicked,this,&MainWindow::Hit);

    BStand = new QPushButton(this);
    BStand->setText("Stand");
    connect(BStand,&QPushButton::clicked,this,&MainWindow::Stand);

    BStart = new QPushButton(this);
    BStart->setText("Start");
    connect(BStart,&QPushButton::clicked,this,&MainWindow::Start);

    Bt = new QPushButton(this);
    Bt->setText("+10");
    connect(Bt,&QPushButton::clicked,this,&MainWindow::ten);

    Btf = new QPushButton(this);
    Btf->setText("+25");
    connect(Btf,&QPushButton::clicked,this,&MainWindow::twentyfive);

    Bft = new QPushButton(this);
    Bft->setText("+50");
    connect(Bft,&QPushButton::clicked,this,&MainWindow::fifty);

    Bdb = new QPushButton(this);
    Bdb->setText("double");
    connect(Bdb,&QPushButton::clicked,this,&MainWindow::Bdouble);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Hit()
{
    blackJackConsole.hit(pm,dm,gm);
    win=blackJackConsole.getwin();
    b.betresult(win);
    fund=b.getfund();
    stake=b.getstake();
    qpm=QString::fromStdString(pm);
    qdm=QString::fromStdString(dm);
    qgm=QString::fromStdString(gm);
    qfund=QString::number(fund);
    qstake=QString::number(stake);
    tpm->setText(qpm);
    tdm->setText(qdm);
    tgm->setText(qgm);
    tfund->setText("fund: " + qfund);
    tstake->setText("stake: " + qstake);
}

void MainWindow::Stand()
{
    blackJackConsole.stand(pm,dm,gm);
    win=blackJackConsole.getwin();
    b.betresult(win);
    fund=b.getfund();
    stake=b.getstake();
    qpm=QString::fromStdString(pm);
    qdm=QString::fromStdString(dm);
    qgm=QString::fromStdString(gm);
    qfund=QString::number(fund);
    qstake=QString::number(stake);
    tpm->setText(qpm);
    tdm->setText(qdm);
    tgm->setText(qgm);
    tfund->setText("fund: " + qfund);
    tstake->setText("stake: " + qstake);
}

void MainWindow::Start()
{
    tgm->setText("");
    gm="";
    blackJackConsole.play(pm,dm);
    b.clear();
    b.addten();
    win=blackJackConsole.getwin();
    fund=b.getfund();
    stake=b.getstake();
    qpm=QString::fromStdString(pm);
    qdm=QString::fromStdString(dm);
    qfund=QString::number(fund);
    qstake=QString::number(stake);
    tpm->setText(qpm);
    tdm->setText(qdm);
    tfund->setText("fund: " + qfund);
    tstake->setText("stake: " + qstake);
}

void MainWindow::ten()
{
    if(win==-1){
        b.addten();
        fund=b.getfund();
        stake=b.getstake();
        qfund=QString::number(fund);
        qstake=QString::number(stake);
        tfund->setText("fund: " + qfund);
        tstake->setText("stake: " + qstake);
    }
}

void MainWindow::twentyfive()
{
    if(win==-1){
        b.addtwentyfive();
        fund=b.getfund();
        stake=b.getstake();
        qfund=QString::number(fund);
        qstake=QString::number(stake);
        tfund->setText("fund: " + qfund);
        tstake->setText("stake: " + qstake);
    }
}

void MainWindow::fifty()
{
    if(win == -1){
        b.addfifty();
        fund=b.getfund();
        stake=b.getstake();
        qfund=QString::number(fund);
        qstake=QString::number(stake);
        tfund->setText("fund: " + qfund);
        tstake->setText("stake: " + qstake);
    }
}

void MainWindow::Bdouble()
{
    if(win==-1){
        b.adddouble();
        fund=b.getfund();
        stake=b.getstake();
        qfund=QString::number(fund);
        qstake=QString::number(stake);
        tfund->setText("fund: " + qfund);
        tstake->setText("stake: " + qstake);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    this->resize(QSize( 700, 350 ));

    int nSpacing = 10;
    int nLeft = 10;
    int nTop = 10;
    int nRight = 10;
    int nBottom = 10;

    text->setGeometry(nLeft,nTop,width()-nLeft-nRight,20);
    tdm->setGeometry(nLeft, nTop+2*nSpacing, width() - nLeft - nRight, 20);
    tpm->setGeometry(nLeft, nTop+4*nSpacing, width() - nLeft - nRight, 20);
    tgm->setGeometry(nLeft, nTop+6*nSpacing, width() - nLeft - nRight, 20);


    BHit->setFixedSize(75,25);
    BStand->setFixedSize(75,25);
    BStart->setFixedSize(75,25);
    Bt->setFixedSize(75,25);
    Btf->setFixedSize(75,25);
    Bft->setFixedSize(75,25);
    Bdb->setFixedSize(75,25);


    BHit->move(width()-BHit->width()-nRight,height() - nBottom - BHit->height());
    BStand->move(width() - BStand->width() - BHit->width() - nSpacing - nRight,height() - nBottom - BStand->height());
    BStart->move(width() - BStart->width() - BStand->width() - BHit->width() - 2 * nSpacing - nRight, height() - nBottom - BStart->height());

    tstake->setGeometry(nLeft,height() - nBottom - Bt->height()*6 - tstake->height() - tfund->height(),width() - nLeft - nRight, 20);
    tfund->setGeometry(nLeft,height() - nBottom - Bt->height()*6 - tfund->height(),width() - nLeft - nRight, 20);
    Bt->move(nLeft, height() - nBottom - Bt->height()*5);
    Btf->move(nLeft + Bt->width() + nSpacing, height() - nBottom - Btf->height()*5);
    Bft->move(nLeft + Bt->width() + Btf->width() + 2 * nSpacing, height() - nBottom - Bft->height()*5);
    Bdb->move(nLeft + Bft->width() + Btf->width() + Bt->width() + 3 * nSpacing,height() - nBottom - Bdb->height()*5);
}


