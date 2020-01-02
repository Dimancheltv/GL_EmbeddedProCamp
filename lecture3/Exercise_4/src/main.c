/*!
   @brief Exercise_4 - Program for demonstration function, that receives pointer.
   @details Task: Create function, that receives pointer to other function as a parameter.
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include <stdlib.h>

/*! Pointer on returning function */
int (*param)(int);

/*! calculates square */
int squared(int input)
{
        return input *= input;
}

/*! function, that receives pointer to other function as a parameter */
int calculation(int (*param)(int), int value)
{
        return param(value);
}

int main(void)
{
        param = &squared;
        int value = 88;
        printf("Square of %i =  %i\n", value, calculation(param, value));

        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
