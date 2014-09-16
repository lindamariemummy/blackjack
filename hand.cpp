//
//  hand.cpp
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#include "hand.h"
#include "hand.h"
#include "card.h"
#include <vector>
#include "deck.h"
#include "deck.h"
#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include "hand.h"
#include "deck.h"
#include <vector>
#include "card.h"
#include <cstdlib>

using namespace std;
hand::hand()
{
	CardsInHand = vector<card>(10);
	totalCardsInHand = 0;
}


hand::~hand()
{
}

short hand::getCards()
{
	return 0;
}

//draws numCards from DeckofCards, places them in hand
void hand::DrawCards(short numCards, deck &DeckofCards)
{
	int i;
	for (i = 0; i < numCards; i++)
	{
		CardsInHand[i+totalCardsInHand] = DeckofCards.DrawCard();
	}
	totalCardsInHand = totalCardsInHand + numCards;
	
}

//replaces cards back into deck;
void hand::DiscardAll()
{
	CardsInHand = vector<card>(10);
	totalCardsInHand = 0;
}

//prints the current hand (with points)
void hand::DisplayHand(bool hideFirstCard)
{
	short i;
	short points;
	points = TotalPoints();
    
    if (hideFirstCard)
    {
        cout << "?? ";
    }
    else
    {
        CardsInHand[0].PrintCard();
    }
    
	for (i = 1; i < totalCardsInHand; i++)
	{
		CardsInHand[i].PrintCard();
	}
    
    if (hideFirstCard)
    {
        cout << " (a total of ?? points)";
    }
    else
    {
        cout << " (a total of " << points << ")";
    }
    
}

//calculates total points in current hand
short hand::TotalPoints()
{
	short sum;
	short i, cardValue, faceNumber, numAces;
	sum = 0;
	numAces = 0;
    
	for (i = 0; i < totalCardsInHand; i++)
	{
		faceNumber = CardsInHand[i].GetNumber();
		if (faceNumber == 1) // counts number of aces in hand
		{
			++numAces;
			cardValue = 11;
		}
		else if (faceNumber == 11 || faceNumber == 12 || faceNumber == 13)
		{
			cardValue = 10;
		}
		else
		{
			cardValue = faceNumber;
		}
		sum = sum + cardValue;
    }
    
    //special case: ace values are set to one if player hand exceeds 21
	if (sum > 21 && numAces != 0)
	{
		while (numAces > 0 && sum > 21)
		{
			sum = sum - 10;
			--numAces;
		}
	}
    
	return sum;
}
