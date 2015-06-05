#include "TexasHoldEm_easy.h"

const std::string SUIT_STR[4] = {"Hearts", "Clubs", "Spades", "Diamonds"};
const std::string FACE_STR[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(int s, int f)
{
    this->suit = s;
    this->face = f;
}

Card::Card()
{}

int Card::getSuit()
{
    return this->suit;
}

int Card::getFace()
{
    return this->face;
}

std::string Card::toStr()
{
    return (FACE_STR[this->face] + " of " + SUIT_STR[this->suit]);
}
