#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "player.h"

class BlackJack
{
public:

    enum GameRoundResult{
        PLAYER_BUSTED,
        DEALER_BUSTED,
        PLAYER_WON,
        DEALER_WON,
        DRAW
    };

    enum State{
        GAME_START,
        GAME_END,
        GAME_ROUND_START,
        GAME_ROUND_END,
        PLAYER_TURN,
        DEALER_TURN
    };

    BlackJack(Player player)
        : dealer("Anthony"), player(player), state(GAME_START){}

    void endGame();
    void endGameRound();
    Player getDealer();
    Player getPlayer();
    State getState()
    {
        return state;
    }

    GameRoundResult getWinner()
    {
        unsigned char playerPoints = player.getCardsPoints();
        unsigned char dealerPoints = dealer.getCardsPoints();

        if(playerPoints > 21){
            return GameRoundResult::PLAYER_BUSTED;
        }else if(dealerPoints > 21){
            return GameRoundResult::DEALER_BUSTED;
        }else if(playerPoints > dealerPoints){
            return GameRoundResult::PLAYER_WON;
        }else if(playerPoints < dealerPoints){
            return GameRoundResult::DEALER_WON;
        }else{
            return GameRoundResult::DRAW;
        }
    }
    void playerHitCard();
    void playerStand();
    void startGame();
    void startGameRound();

private:
    State state;
    Player dealer;
    Player player;
    std::vector<Cards::Card> cardDeck;
    unsigned char const DEALER_SOFTPOINTS = 17;

    void dealerHitCard();
    void dealersTurn();
    Cards::Card getNextCardFromDeck();
    bool isDealerWantToHit();
    void setCardDeck();
    void shuffleDeck();
};

#endif // BLACKJACK_H
