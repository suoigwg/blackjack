#include "bet.h"

bet::bet()
{
    fund=1500;
    stake=0;
}

int bet::getfund()
{
    return fund;
}

void bet::setfund(int fund)
{
    this->fund=fund;
}

int bet::getstake()
{
    return stake;
}

void bet::setstake(int stake)
{
    this->stake=stake;
}

void bet::clear()
{
    setstake(0);
}

void bet::addten()
{
    setstake(getstake()+10);
    setfund(getfund()-10);
}

void bet::addtwentyfive()
{
    setstake(getstake()+25);
    setfund(getfund()-25);
}

void bet::addfifty()
{
    setstake(getstake()+50);
    setfund(getfund()-50);
}

void bet::adddouble()
{
    setfund(getfund()-getstake());
    setstake(getstake()*2);
}

void bet::betresult(int win)
{
    switch (win) {
    case 0:
        clear();
        break;
    case 1:
        setfund(getfund()+getstake()*2);
        clear();
        break;
    case 2:
        setfund(getfund()+getstake());
        clear();
        break;
    default:
        break;
    }
}
