//
//  card.cpp
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#include "card.h"
#include "hand.h"
#include <vector>
#include "deck.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "card.h"
#include <cstdlib>
using namespace std;

card::card()
{
	cardNumber = 0;
	cardSuit = "";
}


card::card(short number, string suit)
{
	cardNumber = number;
	cardSuit = suit;
}

//displays the suit and number of the card
void card::PrintCard()
{
	cout << cardSuit;
	if (cardNumber == 11)
	{
		cout << 'J';
	}
	else if (cardNumber == 12)
	{
		cout << 'Q';
	}
	else if (cardNumber == 13)
	{
		cout << 'K';
	}
	else if (cardNumber == 1)
	{
		cout << 'A';
	}
	else
	{
		cout << cardNumber;
	}
	cout << " ";
	return;
}

short card::GetNumber()
{
	return cardNumber;
}

string card::GetSuit()
{
    return cardSuit;
}
