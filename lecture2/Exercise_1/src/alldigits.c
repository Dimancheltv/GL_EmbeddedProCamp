#include <ctype.h>

/*!
   @brief function to copy all digits from input string to output string.
   @param *input	pointer on input string
   @param *output	pointer on output string
 */
void get_digit(char *input, char *output)
{
        int i = 0; /*! < input counter */
        int j = 0; /*! < output counter */
        while(input[i]) {
                /*! check that number */
                if(isdigit(input[i])) {
                        /*! write output string */
                        output[j++] = input[i];
                }
                i++;
        }
        output[j] = '\0';
}
