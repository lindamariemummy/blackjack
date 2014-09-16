//
//  hand.h
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#ifndef __blackJackGame__hand__
#define __blackJackGame__hand__

#include <iostream>
#include "hand.h"
#include "card.h"
#include <vector>
#include "deck.h"
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class hand
{
public:
	hand();
	~hand();
	short getCards();
	void DrawCards(short numCards, deck &DeckofCards);
	void DisplayHand(bool hideFirstCard); //enter parameter of true if first card should be hidden from user
	short TotalPoints();
	void DiscardAll();
    
private:
	vector<card> CardsInHand;
	short totalCardsInHand;
	bool busted;
};

#endif /* defined(__blackJackGame__hand__) */
