//
//  main.cpp
//  blackJackGame
//
//  Created by Linda Mummy on 9/10/14.
//  Copyright (c) 2014 Linda Mummy. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include "hand.h"
#include "deck.h"
#include <vector>
#include "card.h"

using namespace std;

int main(int argc, const char * argv[])
{
    hand PlayerHand;
	hand DealerHand;
	deck DealerDeck;
	short DealerHandTotal = 0;
	short PlayerHandTotal = 0;
	char userInput = 'P'; //default to play
	bool dealerBusts;
	bool playerBusts;
	bool youWon = false;
    srand (time(NULL));
	
	while (userInput == 'P' || userInput == 'p')
	{
		dealerBusts = false;
		playerBusts = false;
        youWon =false;
        
		//shuffles deck if necessary
		DealerDeck.NeedShuffling();
		
		//Deals 2 cards to each player
		DealerHand.DrawCards(2, DealerDeck);
		PlayerHand.DrawCards(2, DealerDeck);
        
        //loops until user chooses to stay
		while (userInput != 's' && userInput != 'S')
		{
			cout << "Dealer's Hand: ";
			DealerHand.DisplayHand(true);
			cout << endl << "Your Hand: ";
			PlayerHand.DisplayHand(false);
            
			cout << endl << "Do you want to (h)it or (s)tay? ";
			cin >> userInput;
            
			if (userInput == 'h' || userInput == 'H')
			{
				PlayerHand.DrawCards(1, DealerDeck);
			}
			else if (userInput != 's' && userInput != 'S'){
                cout << "Not a valid option!";
            }
			cout << endl << endl;
			if (PlayerHand.TotalPoints() > 21)
			{
				cout << endl << "You just BUSTED with the hand: ";
				PlayerHand.DisplayHand(false);
				playerBusts = true;
				break;
			}
            
		}
        
        //if the player doesn't bust, the dealer takes his turn
		if (!playerBusts)
		{
            DealerHandTotal = DealerHand.TotalPoints();
			while (DealerHandTotal <= 16)
			{
				cout << "The Dealer hits: " << endl;
				DealerHand.DrawCards(1, DealerDeck);
				DealerHandTotal = DealerHand.TotalPoints();
			}
            
			if (DealerHandTotal > 21)
			{
				dealerBusts = true;
                youWon =true;
				cout << endl << "The dealer just BUSTED with the hand: ";

			}
            else
            {
                cout << "The dealer stays with the hand: ";
            }
            
            DealerHand.DisplayHand(false);
			DealerHandTotal = DealerHand.TotalPoints();
			PlayerHandTotal = PlayerHand.TotalPoints();
            
			cout << endl << "The dealer had " << DealerHandTotal << " points and you had " << PlayerHandTotal << " points." << endl;
		}
		
        //determines winner and displays appropriate message
        if ((DealerHandTotal > PlayerHandTotal && !dealerBusts) || playerBusts)
		{
			youWon = false;
		}
        else if (PlayerHandTotal > DealerHandTotal && !playerBusts)
        {
            youWon = true;
        }
        if (DealerHandTotal==PlayerHandTotal)
        {
            cout << endl << "You tied with the dealer." << endl;
        }
		else if (youWon)
		{
			cout << endl << "You won!" << endl;
		}
		else
		{
			cout << endl << "The dealer won." << endl;
		}
		do
		{
			cout << endl << "What do you want to do? (P)lay again or (E)xit?";
			cin >> userInput;
            
		} while (userInput != 'P' && userInput != 'p' &&userInput != 'e' &&userInput != 'E');
		
		PlayerHand.DiscardAll();
		DealerHand.DiscardAll();
        
		cout << endl << endl;
        
	}
    
    cout << endl  << "Thanks for playing!" << endl << endl;
    
	//cout << endl << endl << "Here is what your deck looks like: ";
	//DealerDeck.PrintDeck();
    
	return 0;
}
