#include <string.h>

/*!
   @brief Function copies one string to another.
   @param *inputstr	pointer on input string
   @param *outputstr	pointer on output string
 */
void copystr(char *inputstr, char *outputstr)
{
        for (int i = 0; i < strlen(inputstr); ++i)
        {
                outputstr[i] = inputstr[i];
        }

        /*! or use strcpy(outpustrt, inputstr); */
}
