#ifndef TEXASHOLDEM_EASY_H_INCLUDED
#define TEXASHOLDEM_EASY_H_INCLUDED

#include <string>
#include <vector>
#include <algorithm>

class Card
{
    private:
        int suit, face;
    public:
        Card (int, int);
        Card ();
        int getSuit();
        int getFace();
        std::string toStr();
};

class Player
{
    private:
        std::vector<Card> hand;
    public:
        Player(std::vector<Card>);
        std::vector<Card> getHand();
};

class Deck
{
    private:
        std::vector<Card> inDeck;
        std::vector<Card> discarded;
    public:
        Deck ();
        void shuffle();
        void discard(int);
        Card draw();
        int getCardsLeft();
};

#endif // TEXASHOLDEM_EASY_H_INCLUDED
