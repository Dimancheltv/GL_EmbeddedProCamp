/*!
   @brief Exercise_5 - C program for demonstration factorial of 10.
   @details Task: Write a C program to compute factorial of 10.
   @author Dmytro Lytvyniuk
   @date November
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include "factorial.c"

int main(void)
{
        printf(" Factorial of %d = %d \n", FACTORIAL_VALUE, factorial(FACTORIAL_VALUE));

        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
