/*!
   @brief Exercise_6 - Program to print numbers.
   @details Task: Write a C program to print all numbers between 1 to 500
   which divided by a number specified by user.
   @author Dmytro Lytvyniuk
   @date November
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include "divider.c"

int main(void)
{
        printf("Program to print all numbers between %d to %d\nPlease, enter divider number: ", MIN_NUMBER, MAX_NUMBER );
        divider(validfloat());
        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
