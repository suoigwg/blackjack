#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

namespace Cards {

    enum Card{
        no_card=0x00,
        clubs_ace=0x01,clubs_two=0x02,clubs_three=0x03,clubs_four=0x04,clubs_five=0x05,clubs_six=0x06,clubs_seven=0x07,clubs_eight=0x08,clubs_nine=0x09,clubs_ten=0x0A,clubs_jack=0x0B,clubs_queen=0x0C,clubs_king=0x0D,
        diamonds_ace=0x11,diamonds_two=0x12,diamonds_three=0x13,diamonds_four=0x14,diamonds_five=0x15,diamonds_six=0x16,diamonds_seven=0x17,diamonds_eight=0x18,diamonds_nine=0x19,diamonds_ten=0x1A,diamonds_jack=0x1B,diamonds_queen=0x1C,diamonds_king=0x1D,
        hearts_ace=0x21,hearts_two=0x22,hearts_three=0x23,hearts_four=0x24,hearts_five=0x25,hearts_six=0x26,hearts_seven=0x27,hearts_eight=0x28,hearts_nine=0x29,hearts_ten=0x2A,hearts_jack=0x2B,hearts_queen=0x2C,hearts_king=0x2D,
        spades_ace=0x31,spades_two=0x32,spades_three=0x33,spades_four=0x34,spades_five=0x35,spades_six=0x36,spades_seven=0x37,spades_eight=0x38,spades_nine=0x39,spades_ten=0x3A,spades_jack=0x3B,spades_queen=0x3C,spades_king=0x3D
    };



    inline std::string getCardName(Card card)
    {
        std::string name;
        switch(card){
            case clubs_ace:
                name="ace of clubs";
                break;
            case clubs_two:
                name="two of clubs";
                break;
            case clubs_three:
                name="three of clubs";
                break;
            case clubs_four:
                name="four of clubs";
                break;
            case clubs_five:
                name="five of clubs";
                break;
            case clubs_six:
                name="six of clubs";
                break;
            case clubs_seven:
                name="seven of clubs";
                break;
            case clubs_eight:
                name="eight of clubs";
                break;
            case clubs_nine:
                name="nine of clubs";
                break;
            case clubs_ten:
                name="ten of clubs";
                break;
            case clubs_jack:
                name="jack of clubs";
                break;
            case clubs_queen:
                name="queen of clubs";
                break;
            case clubs_king:
                name="king of clubs";
                break;
            case diamonds_ace:
                name="ace of diamonds";
                break;
            case diamonds_two:
                name="two of diamonds";
                break;
            case diamonds_three:
                name="three of diamonds";
                break;
            case diamonds_four:
                name="four of diamonds";
                break;
            case diamonds_five:
                name="five of diamonds";
                break;
            case diamonds_six:
                name="six of diamonds";
                break;
            case diamonds_seven:
                name="seven of diamonds";
                break;
            case diamonds_eight:
                name="eight of diamonds";
                break;
            case diamonds_nine:
                name="nine of diamonds";
                break;
            case diamonds_ten:
                name="ten of diamonds";
                break;
            case diamonds_jack:
                name="jack of diamonds";
                break;
            case diamonds_queen:
                name="queen of diamonds";
                break;
            case diamonds_king:
                name="king of diamonds";
                break;
            case hearts_ace:
                name="ace of hearts";
                break;
            case hearts_two:
                name="two of hearts";
                break;
            case hearts_three:
                name="three of hearts";
                break;
            case hearts_four:
                name="four of hearts";
                break;
            case hearts_five:
                name="five of hearts";
                break;
            case hearts_six:
                name="six of hearts";
                break;
            case hearts_seven:
                name="seven of hearts";
                break;
            case hearts_eight:
                name="eight of hearts";
                break;
            case hearts_nine:
                name="nine of hearts";
                break;
            case hearts_ten:
                name="ten of hearts";
                break;
            case hearts_jack:
                name="jack of hearts";
                break;
            case hearts_queen:
                name="queen of hearts";
                break;
            case hearts_king:
                name="king of hearts";
                break;
            case spades_ace:
                name="ace of spades";
                break;
            case spades_two:
                name="two of spades";
                break;
            case spades_three:
                name="three of spades";
                break;
            case spades_four:
                name="four of spades";
                break;
            case spades_five:
                name="five of spades";
                break;
            case spades_six:
                name="six of spades";
                break;
            case spades_seven:
                name="seven of spades";
                break;
            case spades_eight:
                name="eight of spades";
                break;
            case spades_nine:
                name="nine of spades";
                break;
            case spades_ten:
                name="ten of spades";
                break;
            case spades_jack:
                name="jack of spades";
                break;
            case spades_queen:
                name="queen of spades";
                break;
            case spades_king:
                name="king of spades";
                break;
            default:
                break;
        }
        return name;
    }
    inline unsigned char getCardValue(Card card)
    {
        unsigned char unmaskCard = 0x0f & card;
        return unmaskCard > 10 ? 10:unmaskCard;
    }
}

#endif // CARDS_H
