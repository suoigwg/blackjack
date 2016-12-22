#ifndef PLAYER_H
#define PLAYER_H

#include <cards.h>

class Player
{
    std::string name;
    std::vector<Cards::Card> cards;
    bool betOnCards;
public:
    Player();
    Player(std::string name)
        :name(name){}

    void addCard(Cards::Card card);
    void emptyCards();
    std::vector<Cards::Card>getCards();
    unsigned char getCardsPoints();
    std::string getName();
    bool isBetOnCards();
    void setBetOnCards(bool betOnCards);
};

#endif // PLAYER_H
