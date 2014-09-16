//
//  card.h
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#ifndef __blackJackGame__card__
#define __blackJackGame__card__

#include <iostream>
using namespace std;

class card
{
public:
	card();
	card(short number, string suit);
	void PrintCard();
	short GetNumber();
	string GetSuit();
    
    
private:
	short cardNumber;
	string cardSuit;
};

#endif /* defined(__blackJackGame__card__) */
