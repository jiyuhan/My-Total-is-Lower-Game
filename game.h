/*------------------------------------------------------------------------------
 * Programmer: Jiyu Han
 * Name: game.h
 * Description: This file contains the function prototypes to be
 * implemented in the CIE My total is lower! Card Game
 -------------------------------------------------------------------------------*/
#include "card.h"

/* prototype of the function to shuffle a deck*/
/* Inputs:
 * Card [] = array of Cards (deck)
 * int = number of cards in deck
 * This function traverses the deck and swaps each card with a card whose index is
 * randomly generated.
 */
extern void shuffle(Card deck[], int n);

/* prototype of the function to print the cards in an array */
/* Inputs:
 * Card [] = array of Cards (deck)
 * int = number of cards in deck
 * This function traverses the deck and calls the printCard function for each card in
 * the deck.
 */
extern void printArray (Card deck[], int n);

/* prototype of the function to compute the score for an array of cards */
/* Inputs:
 * Card [] = array of Cards (hand)
 * int = number of cards in the hand
 *  Return:
 * int = the value of the hand
 * This function traverses array and accumulates the value of each card in
 * the hand.
 */
extern int computeTotal (Card a[], int n);

/* prototype of the function to initialize the deck for the CIE My total is lower! Game */
/* Inputs:
 * Card [] = array of Cards (deck)
 * int = number of cards in deck
 * This function initializes the deck.
 * YOU MUST PROVIDE A PSEUDOCODE FOR THIS FUNCTION
 */
extern void initDeck (Card deck[], int n);


/*PSEUDOCODE!!!!*/
/*
 *Algorithm initDeck(Card deck[], int n)
 * Inputs:
 *      Card [] = array of Cards (deck)
 *      int = number of cards in deck
 *
 *  for int i <- 0; to NMAX do assign faces and suits to the array
 *
 *      if i < 10 then
 *          deck[i].value <- -i;//hearts
 *          deck[i+13].value <- -i;//diamonds
 *          deck[i+26].value <- i;//spades
 *          deck[i+39].value <- i;//clubs
 *      else if i = 11 then
 *          deck[i].value <- -10;//hearts
 *          deck[i+13].value <- -10;//diamonds
 *          deck[i+26].value <- 10;//spades
 *          deck[i+39].value <- 10;//clubs
 *
 *      else if i = 12 then
 *          deck[i].value <- -10;//hearts
 *          deck[i+13].value <- -10;//diamonds
 *          deck[i+26].value <- 10;//spades
 *          deck[i+39].value <- 10;//clubs
 *
 *      else if i = 13 then
 *          deck[i].value <- -10;//hearts
 *          deck[i+13].value <- -10;//diamonds
 *          deck[i+26].value <- 10;//spades
 *          deck[i+39].value <- 10;//clubs
 *      endif
 *  endfor
 */


/* prototype of the function to play the CIE My total is lower! Game */
/* Inputs:
 * int = number of cards deal to each player
 * int = number of rounds for each game
 * YOU MUST PROVIDE A PSEUDOCODE FOR THIS FUNCTION
 */
extern void playGame (int nCards, int rounds);

/*Algorithm playGame
  inputs: cards in hand, number for rounds

    Initialize deck, player 1's hand, player 2's hand, an integer counts how many cards have been used, 
    two integers track the total of two players, an integer that says who wins the game.
 
    print Welcome to CIE My Total Is Lower! Card Game.
 
    //initiate the DECK
    initDeck(deck, CARDS)
    //shuffle the DECK
    shuffle(deck, CARDS)
    //print the DECK
    printArray(deck, CARDS)
    
    
    //dealing the cards to two players
    for i <- 0 to nCards do
        p1_hand[i] <- deck[card_count]
        p2_hand[i] <- deck[card_count+1]
        card_count += 2;
    endfor
 
    //printing their hands
    print "Player 1: "
    printArray(p1_hand, nCards)
    print "Player 2: "
    printArray(p2_hand, nCards)
 
    Initialize two strings for the choices later on, "pick card or new card" (AorB), and "choose card or discard" (chooseCard)
 
    for j <- 0 to rounds do
 
        print "------ ROUND j+1 ------"
        for int k <- 1 to 3 do
            print "Discard pile: [the next card with face and suit]"
            print "Player k's turn: "
            print "Do you want to pick up from the discard pile (A) or draw a new card (B)?"
            scan AorB
            
            if user input 'A' or 'a' then
                print "Which card would you like to replace? (1-4)"
                scan chooseCard
                if player one's turn then
                    p1_hand[chooseCard - 1] <- deck[card_count]
                    card_count++
                else if player two's turn then
                    p2_hand[chooseCard - 1] <- deck[card_count]
                    card_count++
                endif
            else if user input 'B' or 'b'
                card_count++;
                print "Card drawn: [the next card with face and suit]
                print "Enter 0 to discard it or a card number (1-4) to replace:
                scan chooseCard
                if !chooseCard then
                    card_count <- card_count;//do nothing
                else then
                    if player one's turn then
                        p1_hand[chooseCard - 1] <- deck[card_count]
                        card_count++
                    else if player two's turn then
                        p2_hand[chooseCard - 1] <- deck[card_count]
                        card_count++
                    endif
                endif
            endif
        endfor
    endfor
    
    
    p1 <- computeTotal(p1_hand, nCards)
    p2 <- computeTotal(p2_hand, nCards)
    winner <- whoWins(p1, p2)
    if game tied then
        print "game tied"
    
    else then
        print "Congrats!! Player 'winner' won the game!"
 
    endif
 */

/* prototype of the function to decide the winner of the CIE My total is lower! Game */
/* Inputs:
 * int = value of the player 1's hand
 * int = value of the player 2's hand
 *  Return:
 * int = winner (0- tie, 1- player 1 wins, 2- player 2 wins)
 * YOU MUST PROVIDE A PSEUDOCODE FOR THIS FUNCTION
 */
extern int whoWins (int p1, int p2);

/*PSEUDOCODE!!!!*/

/*Algorithm whoWins (int p1, int p2)
 *
 * Inputs:
 * int = value of the player 1's hand
 * int = value of the player 2's hand
 *  Return:
 * int = winner (0- tie, 1- player 1 wins, 2- player 2 wins)
 *
 * initialize integer winner <- 0
 *
 * if p1 and p2 equal or both are negative then winner <- 0
 * else if p1 is positive and p2 is negative then winner <- 1
 * else if p1 is negative and p2 is positive then winner <- 2
 * else if p1 and p2 are greater than zero, and p2 is greater than p1 then winner <- 1
 * else if p1 and p2 are greater than zero, and p1 is greater than p2 then winner <- 2
 *
 * return winner;
 *
 *
 */

 
 
 
