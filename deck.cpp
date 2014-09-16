//
//  deck.cpp
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#include "hand.h"
#include "card.h"
#include <vector>
#include "deck.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

deck::deck()
{
	short i;
	string j = "";
	numCardsInDeck=52;
	chooseFrom=numCardsInDeck;
	cardsUsed = 0;
	deckOfCards = vector<card>(numCardsInDeck);
	
    //assigns suits to all 52 cards
    for (i = 0; i < numCardsInDeck; i++)
	{
        if (i == 0)
			j = "\u2666";
		else if (i == 12)
			j = "\u2665";
		else if (i == 26)
			j = " \u2663";
		else if (i == 39)
			j = "\u2660";
		card Card(i%13+1, j);
		deckOfCards[i] = Card;
	}
}


deck::~deck()
{
}

void deck::PrintDeck()
{
	int i;
    
	for (i = 0; i < numCardsInDeck; i++)
	{
		deckOfCards[i].PrintCard();
	}
	return;
}

card deck::DrawCard()
{
	int cardNumber;
	card temp;
	++cardsUsed;
	cardNumber = rand() % chooseFrom;
    
    //move chosen card to the back of the deck array
	temp = deckOfCards[cardNumber];
	deckOfCards[cardNumber] = deckOfCards[chooseFrom - 1];
	deckOfCards[chooseFrom - 1] = temp;
	
    //decrease number of cards to choose from
    chooseFrom = chooseFrom - 1;
    
	return temp;
	
}

//resets the deck
void deck::Shuffle()
{
	chooseFrom = numCardsInDeck;
}

//checks if deck needs to be shuffled, automatically shuffles if necessary
void deck::NeedShuffling() {
	if (cardsUsed >= numCardsInDeck/2)
	{
		Shuffle();
		cout << "Deck has been shuffled." << endl;
	}
	
	return;
}