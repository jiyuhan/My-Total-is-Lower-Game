/*Implentation of the Card functions*/
/*See card.h for documentation */

/*Set to 1 if you are using the robot*/
#define ROBOTPRINT 0

#include "card.h"

#if ROBOTPRINT
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#define PRINT print
#else
#include <stdio.h>
#define PRINT(x)  printf("%s",x)
#endif // ROBOTPRINT

void printCard (Card c) {
    char s[4] = {c.face,c.suit,' ','\0'};
    PRINT(s);
}

