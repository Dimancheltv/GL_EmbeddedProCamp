/*!
   @brief Exercise_1 - Program for demonstration function that copy digits.
   @details Task: Create function to copy all digits from input string to output string.
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include "alldigits.c"

int main(void){
        char string_in[129], string_out[128];
        puts("Please, enter mixed string (maximum 128 characters):");
        gets(string_in);
        get_digit(string_in, string_out);
        puts("All digits from input string: ");
        puts(string_out);
        /*! for demo test, pause in console */
        system("pause");
}
