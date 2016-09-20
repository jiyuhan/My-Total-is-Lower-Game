/*------------------------------------------------------------------------------
 * Programmer: Jiyu Han
 * Name: game.cpp
 * Description: Implement the homework functions here...see game.h for documentation
 -------------------------------------------------------------------------------*/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "card.h"
#include "game.h"
using namespace std;

/*number of cards in the deck*/
static const int CARDS = 52;
/*number of cards in a suit*/
static const int NMAX = 13;
/*symbols to represent the cards of a suit*/
static const char faces[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
/*symbols to represent the suits*/
static const char suits[] = {'H','D','S','C'};

//Function: Shuffle
//this function shuffles the deck to make it "random".
//First, it uses a random number from 0 to 51 to call a random card.
//Then the card that was just called will be swaped with the first one.
//Next, another random card is selected, and swaped with the second one in the deck.
//This will continue until the card has to swap with the last one in the deck.
//It can be accomplished by using a for loop.

//input: the deck array, number of cards in a deck
//no output needed.
void shuffle(Card deck[], int n)
{
    int random;
    srand(time(NULL));      //using seed to generate pseudo-random numbers!
    //So I could get different shuffle results every time I shuffle the card.
    Card temp;//this will be a temporary "jumping board" for a card so two cards can swap
    for(int j = 0; j < 10; j++)//shuffle ten times!!
    {
        for(int i = 0; i < n; i++)//for loop from the first card (0) to the last (51)
        {
            
            //This is going to traverse the deck and swap random cards at the same time, to make it totally random.
            //under one "for" loop to keep the big-Oh low...
            //first part, traverse it!
            if(i < 26)//it will stop once it loops 26 times
            {
                temp = deck[i];
                deck[i] = deck[51-i];
                deck[51-i] = temp;
            }
            
            //second part, swap two cards!
            random = rand() % 52;//random number initialized and set to a random number 0 ~ 51
            temp = deck[i];//switching "A to B", A to C first
            deck[i] = deck[random];//then B to A
            deck[random] = temp;//then C to B
        }
    }
}

//Function: printArray
//This function traverses the deck and calls the printCard function for each card in
//the deck by using a for loop.
// Inputs:
//      Card [] = array of Cards (deck)
//      int = number of cards in deck

void printArray (Card deck[], int n)
{
    for(int i = 0; i<n; i++)
    {
        std::cout << deck[i].face << deck[i].suit <<" ";
    }
    cout << endl;
}

// Function: computeTotal
//This function traverses array and accumulates the value of each card in the hand.
//Inputs:
//  Card [] = array of Cards (hand)
//  int = number of cards in the hand
//Return:
//  int = the value of the hand

int computeTotal (Card a[], int n)
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum = sum + a[i].value;
    }
    return sum;
}

//Function: InitDeck
//This function initializes the deck.
//Inputs:
//  Card [] = array of Cards (deck)
//  int = number of cards in deck

/***********************************************
 *  FOR THE PSEUDOCODE, PLEASE CHECK "GAME.H"  *
 ***********************************************/

void initDeck(Card deck[], int n)
{
    for(int i = 0; i < NMAX; i++)//I'm trying to use only one for loop to eliminate the running time to initialize the deck.
    {
        deck[i].face = faces[i];
        deck[i].suit = suits[0];
        
        deck[i+13].face = faces[i];
        deck[i+13].suit = suits[1];
        deck[i+26].face = faces[i];
        deck[i+26].suit = suits[2];
        deck[i+39].face = faces[i];
        deck[i+39].suit = suits[3];
        
        if(i < 11)
        {
            deck[i].value = -(i + 1);//hearts
            deck[i+13].value = -(i + 1);//diamonds
            deck[i+26].value = i + 1;//spades
            deck[i+39].value = i + 1;//clubs
        }
        else
        {
            deck[i].value = -10;//hearts
            deck[i+13].value = -10;//diamonds
            deck[i+26].value = 10;//spades
            deck[i+39].value = 10;//clubs
        }
    }
}

/* prototype of the function to play the CIE My total is lower! Game */
/* Inputs:
 * int = number of cards deal to each player
 * int = number of rounds for each game
 * YOU MUST PROVIDE A PSEUDOCODE FOR THIS FUNCTION
 */

/***********************************************
 *  FOR THE PSEUDOCODE, PLEASE CHECK "GAME.H"  *
 ***********************************************/


void playGame (int nCards, int rounds)
{
    Card deck[52];//a new deck
    Card p1_hand[4];//player 1's hand
    Card p2_hand[4];//player 2's hand
    int card_count = 0;//it counts the deck to simulate the deck decreasing while playing.
    int winner = 0;//winner indicator
    int p1;//player 1's total points
    int p2;//player 2's total points
    char AorB;//player's first choice
    int chooseCard;//player's second choice
    char keepPlay;//the option to keep playing or not.
    

    //DO-WHILE loop covers the EXTRA credit part for this assignment, but it WILL NOT be covered on the pseudocode since it's extra credit, and it would be easier to understand the original code from pseudocode as well
    do{
        //if there's not enough cards left to play the game, a new deck will be generated, otherwise, the same deck would work.
        if((card_count < (nCards - (8 + 4 * rounds))) || card_count == 0)// one player can draw two cards in one round, two players can draw 4 in one round, therefore minimum cards for a game would be 8 + 4 * rounds
        {
            //initializing, shuffling, and printing a new deck
            initDeck(deck, CARDS);
            shuffle(deck, CARDS);
            printArray(deck, CARDS);
            card_count = 0;
            
        }
        else//play using the same deck if the deck is not totally discarded yet (And there are enough cards to play a game)
            cout << "The game will play from the same deck." << endl;
        
        for(int i = 0; i < nCards; i++)//dealing cards to player
        {
            p1_hand[i] = deck[card_count];
            p2_hand[i] = deck[card_count+1];
            card_count += 2;
        }
        
        cout << "Player 1: ";
        printArray(p1_hand, nCards);//printing p1's hand
        cout << "Player 2: ";
        printArray(p2_hand, nCards);//printing p2's hand
        
        for(int j = 0; j < rounds; j++)
            //number of rounds. It could be modified fairly easily by editing the variable in the main function.
        {
            cout << "------ ROUND " << j + 1 << " ------" << endl;
            for(int k = 1; k < 3; k++)//a for loop to switch players
            {
                cout << "Discard pile: " << deck[card_count].face << deck[card_count].suit << "\nPlayer "<< k <<"'s turn: "<< endl;
                cout << "Do you want to pick up from the discard pile (A) or draw a new card (B)?" << endl;
                cin >> AorB;
                
                switch (AorB)
                {
                    case 'A': case 'a'://if choose A
                        cout << "Which card would you like to replace? (1-4)" << endl;
                        cin >> chooseCard;
                        switch(k)//new card either way
                    {
                        case 1://if it's player 1's turn
                            p1_hand[chooseCard - 1] = deck[card_count];
                            card_count++;
                            break;
                        case 2://if it's player 2's turn
                            p2_hand[chooseCard - 1] = deck[card_count];
                            card_count++;
                            break;
                    }
                        break;
                    case 'B': case 'b'://if B's chosen
                        card_count++;//new card
                        cout << "Card drawn: " << deck[card_count].face << deck[card_count].suit << endl;
                        cout << "Enter 0 to discard it or a card number (1-4) to replace: " << endl;
                        cin >> chooseCard;
                        
                        if(chooseCard != 0)//if zero, no new card was drawn, therefore, no action. if not then...
                        {
                            switch(k)
                            {
                                case 1://player 1's turn
                                    p1_hand[chooseCard - 1] = deck[card_count];
                                    card_count++;
                                    break;
                                case 2://player 2's turn
                                    p2_hand[chooseCard - 1] = deck[card_count];
                                    card_count++;
                                    break;
                            }
                        }
                        break;
                }
                
                //std::cout << "Player 1: ";
                //printArray(p1_hand, nCards);
                //std::cout << "Player 2: ";
                //printArray(p2_hand, nCards);
                
                //for testing purposes, it shows both player's hands after any decision.
            }
        }//rounds end
        
        //checking scores
        p1 = computeTotal(p1_hand, nCards);
        p2 = computeTotal(p2_hand, nCards);
        
        //check who's the winner!!'
        winner = whoWins(p1, p2);
        
        //print who's the winner!
        if(winner == 0)
            cout << "game tied." << endl;
        else
            cout << "Congrats!! Player " << winner << " won the game!";
        
        //ask for another game
        cout << "Do you want to play another game?(Y/N)" << endl;
        cin >> keepPlay;
        
    }while(keepPlay == 'Y' || keepPlay == 'y');//check if the players want to keep playing
}

//Function: whoWins
//to decide who is the winner with understanding of the game rules of "My Total is Lower!"
//Inputs:
//  int = value of the player 1's hand
//  int = value of the player 2's hand
//Return:
//  int = winner (0- tie, 1- player 1 wins, 2- player 2 wins)

/***********************************************
 *  FOR THE PSEUDOCODE, PLEASE CHECK "GAME.H"  *
 ***********************************************/

int whoWins (int p1, int p2)
{
    int winner = 0;//initialize an integer shows who's the winner, or if the game's tied
    if(p1 == p2||(p1 < 0 && p2 < 0)) winner = 0;//if p1 and p2 equal or both are negative
    else if(p1 >= 0 && p2 < 0) winner = 1;//if p1 is positive and p2 is negative
    else if(p1 < 0 && p2 >= 0) winner = 2;//if p1 is negative and p2 is positive
    else if(0 < p1 && p1 < p2) winner = 1;//if p1 and p2 are greater than zero, and p2 is greater than p1
    else if(0 < p2 && p2 < p1) winner = 2;//if(p1 and p2 are greater than zero, and p1 is greater than p2
    return winner;
}





