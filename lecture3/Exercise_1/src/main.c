/*!
   @brief Exercise_1 - Program for demonstration function that copies one string to another.
   @details Task: Create void function that copies one string to another.
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include <stdlib.h>
#include "function.c"

/*! size string for demo */
#define SIZE 22

int main(void)
{
        char inputstr[SIZE] = "STAR";
        char outputstr[SIZE] = "WARS";

        printf("first str: %s\nsecond str: %s\n", inputstr, outputstr);
        copystr(inputstr, outputstr);
        puts("AFTER THE FUNCTION:");
        printf("first str: %s\nsecond str: %s\n", inputstr, outputstr);

        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
