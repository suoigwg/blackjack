#include "blackjackconsole.h"


void BlackJackConsole::clear()
{
    setwin(-1);
}

void BlackJackConsole::setwin(int win)
{
    this->win=win;
}

int BlackJackConsole::getwin()
{
    return win;
}

void BlackJackConsole::play(std::string &pm,std::string &dm){

    //showGreetings();
    blackjack.endGame();
    clear();
    blackjack.startGame();
    if(blackjack.getState() != BlackJack::State::GAME_END){
        blackjack.startGameRound();
        pm=getPlayerCardMessage();
        dm=getDealerCardMessage(false);
     }
    std::cout<<pm<<std::endl
            <<dm<<std::endl;
    //showExitMessage();
}
void BlackJackConsole::hit(std::string &pm,std::string &dm,std::string &gm)
{
    if(blackjack.getState() != BlackJack::State::GAME_END && blackjack.getState() != BlackJack::State::GAME_ROUND_END)
    {
        blackjack.playerHitCard();
        pm=getPlayerCardMessage();
        dm=getDealerCardMessage(false);
    }
    if(blackjack.getState() == BlackJack::State::GAME_ROUND_END)
    {
        pm=getPlayerCardMessage();
        dm=getDealerCardMessage(true);
        gm=getGameRoundResultMessage();
        blackjack.endGame();
    }
    std::cout<<pm<<std::endl
            <<dm<<std::endl
           <<gm<<std::endl;
}

void BlackJackConsole::stand(std::string &pm,std::string &dm,std::string &gm)
{
    if(blackjack.getState() != BlackJack::State::GAME_END && blackjack.getState() != BlackJack::State::GAME_ROUND_END)
    {
        blackjack.playerStand();
        pm=getPlayerCardMessage();
        dm=getDealerCardMessage(false);
    }
    if(blackjack.getState() == BlackJack::State::GAME_ROUND_END)
    {
        pm=getPlayerCardMessage();
        dm=getDealerCardMessage(true);
        gm=getGameRoundResultMessage();
        blackjack.endGame();
    }
    std::cout<<pm<<std::endl
            <<dm<<std::endl
           <<gm<<std::endl;
}

std::string BlackJackConsole::getPlayerCardMessage(){
    std::vector<Cards::Card> cards = blackjack.getPlayer().getCards();
    std::string message;
    for(auto const& card: cards){
        message+=getCardName(card)+"="+std::to_string((int)getCardValue(card))+",";
    }
    message="Your card in hand: " + message;
    return message;
}

std::string BlackJackConsole::getDealerCardMessage(bool temp) {
    std::vector<Cards::Card>cards = blackjack.getDealer().getCards();
    std::string message;
    std::string secret="Unknow,";
    for (auto const& card : cards) {
        if (temp)
            message += getCardName(card) + "=" + std::to_string((int)getCardValue(card)) + ",";
        else {
            message += secret;
            temp = true;
        }
    }
    message="Dearler card in hand: " + message;
    return message;

}

std::string BlackJackConsole::getGameRoundResultMessage(){
    std::cout << "-----Game Result-----"<< std::endl;
    std::string winner;
    switch(blackjack.getWinner()){
        case BlackJack::PLAYER_BUSTED:
            winner="Player busted. Dealer Wins";
            setwin(0);
            break;
        case BlackJack::DEALER_BUSTED:
            winner="Dealer busted. Player Wins";
            setwin(1);
            break;
        case BlackJack::PLAYER_WON:
            winner="Player won. Player:"+std::to_string((int)blackjack.getPlayer().getCardsPoints())+" Dealer:"+std::to_string((int)blackjack.getDealer().getCardsPoints());
            setwin(1);
            break;
        case BlackJack::DEALER_WON:
            winner="Dealer won. Dealer:"+std::to_string((int)blackjack.getDealer().getCardsPoints())+" Player:"+ std::to_string((int)blackjack.getPlayer().getCardsPoints());
            setwin(0);
            break;
        case BlackJack::DRAW:
            winner="Draw. Dealer:"+std::to_string((int)blackjack.getDealer().getCardsPoints())+" Player:"+ std::to_string((int)blackjack.getPlayer().getCardsPoints());
            setwin(2);
            break;

        default:
            break;
    }

    return winner;
}

