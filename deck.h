//
//  deck.h
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#ifndef __blackJackGame__deck__
#define __blackJackGame__deck__

#include <iostream>
#include "hand.h"
#include "card.h"
#include <vector>
#include "deck.h"
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class deck
{
public:
	deck();
	~deck();
	void PrintDeck();
	card DrawCard();
	void Shuffle();
	void NeedShuffling(); //determine if over half the deck has been used
	
private:
	vector<card> deckOfCards;
	short chooseFrom;
	short numCardsInDeck;
	short cardsUsed;  //Count number of cards used. Shuffle occurs when over half the deck has been used.
};



#endif /* defined(__blackJackGame__deck__) */
