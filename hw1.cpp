/*------------------------------------------------------------------------------
 * Programmer: Jiyu Han
 * Name: hw1.cpp
 * Description: This is a game called "My Total is Lower!", designed as a home-
 *              work to test how well I learned from the class so far. This game
 *              will generate a deck first, and will show you the deck while
 *              assuming you didn't see it at all. Then deal 4 cards to two
 *              players. After several rounds, you compare which player has a
 *              lower total but not negative wins. Red ones are negative points
 *              btw...
 -------------------------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include "card.h"
#include "game.h"
using namespace std;

/*number of cards to be dealt*/
static const int N = 4;
/*number of rounds in the game*/
static const int R = 2;


int main( void )
{
    /*TODO: Initialize random number generator*/
    //Why??

    
    std::cout << "Welcome to CIE My Total Is Lower! Card Game.\n";
    
    //call the play game function
    playGame(N, R);
    
    /* print exit message */
    printf("Thank you for playing.\n");
    
    return 0;
}
