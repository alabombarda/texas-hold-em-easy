#include "TexasHoldEm_easy.h"

Player::Player(std::vector<Card> h)
{
    this->hand = h;
}

std::vector<Card> Player::getHand()
{
    return this->hand;
}
