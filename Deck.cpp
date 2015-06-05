#include "TexasHoldEm_easy.h"

Deck::Deck()
{
    this->shuffle();
}

void Deck::shuffle()
{
    this->inDeck.clear();
    this->discarded.clear();
    this->inDeck.reserve(sizeof(Card)*52);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            this->inDeck.push_back(Card(i, j));
        }
    }

    std::random_shuffle(this->inDeck.begin(), this->inDeck.end());
}

Card Deck::draw()
{
    Card c = this->inDeck.front();
    this->discarded.push_back(c);
    this->inDeck.erase(this->inDeck.begin());

    return c;
}

void Deck::discard(int n)
{
    this->inDeck.erase(this->inDeck.begin(), this->inDeck.begin()+n);
}

int Deck::getCardsLeft()
{
    return this->inDeck.size();
}
