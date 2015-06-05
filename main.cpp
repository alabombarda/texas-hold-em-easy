#include <iostream>
#include "TexasHoldEm_easy.h"

int main()
{
    //input how many players at the table
    int numPlayers;
    std::cout << "How many players at the table? \n";
    std::cin >> numPlayers;

    //initialize our variables
    Deck d;                         //deck of 52 cards, randomized order
    std::vector<Card> flop;         //3 card flop
    Card turn, river;               //1 card turn, 1 card river
    std::vector<Player> players;    //vector of players at the table

    //temporary storage variable
    std::vector<Card> sHand;

    for (int i = 0; i < numPlayers; i++)
    {
        //deal each player two cards
        sHand.push_back(d.draw());
        sHand.push_back(d.draw());
        //add the player to our vector of players
        players.push_back(Player(sHand));
        sHand.clear();
    }

    std::cout << "Burned: " << d.draw().toStr() << "\n";

    //draw three cards into the flop
    for (int i = 0; i < 3; i ++)
        flop.push_back(d.draw());

    std::cout << "Burned: " << d.draw().toStr() << "\n";
    //draw a card into the turn
    turn = d.draw();
    std::cout << "Burned: " << d.draw().toStr() << "\n";
    //draw a card into the river
    river = d.draw();

    std::cout << "\n";
    for (int i = 0; i < numPlayers; i ++)
    {
        //it's me!
        if (i == 0)
            std::cout << "Your Hand: ";
        //it's not me
        else
            std::cout << "Player #" << (i+1) << "'s Hand: ";

        //grab player[i]'s hand and output each card
        std::vector<Card> pHand = players[i].getHand();
        for (Card c : pHand)
            std::cout << c.toStr() << " ";

        std::cout << "\n";
    }
    std::cout << "\n";

    //output flop
    std::cout << "Flop: ";
    for (Card c : flop)
        std::cout << c.toStr() << " ";
    std::cout << "\n";

    //output turn and river
    std::cout << "Turn: " << turn.toStr() << "\n";
    std::cout << "River: " << river.toStr() << "\n\n";
}

/*
SAMPLE OUTPUT

How many players at the table?
4
Burned: Four of Spades
Burned: Seven of Spades
Burned: Jack of Clubs

Your Hand: King of Hearts Two of Hearts
Player #2's Hand: Ten of Hearts Jack of Diamonds
Player #3's Hand: Ace of Hearts Two of Spades
Player #4's Hand: Jack of Spades Six of Spades

Flop: Seven of Diamonds Six of Clubs Eight of Diamonds
Turn: Two of Diamonds
River: King of Diamonds
*/
