#ifndef BLACKJACKCONSOLE_H
#define BLACKJACKCONSOLE_H

#include "blackjack.h"

class BlackJackConsole
{
    Player player;
    BlackJack blackjack;
public:
    BlackJackConsole(std::string playerName)
        :player(playerName),blackjack(player){}
    void play(std::string &pm,std::string &dm);
    void hit(std::string &pm,std::string &dm,std::string &gm);
    void stand(std::string &pm,std::string &dm,std::string &gm);
    void setwin(int win);
    void clear();
    int getwin();
private:
    std::string getPlayerCardMessage();
    std::string getDealerCardMessage(bool temp);
    std::string getGameRoundResultMessage();
    int win=-1;
};

#endif // BLACKJACKCONSOLE_H
