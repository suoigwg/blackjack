#ifndef BET_H
#define BET_H

#include "blackjackconsole.h"

class bet
{

public:
    bet();
    void setfund(int fund);
    int getfund();
    void setstake(int stake);
    int getstake();
    void addten();
    void addfifty();
    void addtwentyfive();
    void adddouble();
    void betresult(int win);
    void clear();
private:
    int fund;
    int stake;
};

#endif // BET_H
