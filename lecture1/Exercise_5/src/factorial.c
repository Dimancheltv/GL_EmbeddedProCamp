/*!
   @brief  constant for value of factorial.
 */
#define FACTORIAL_VALUE 10

/*!
   @brief  function that compute factorial.
   @param value is input number to calculate factorial
   @return int value of factorial
 */
int factorial(int value)
{
        int factorial = 1;

        if(value == 0 || value == 1)
        {
                return 1;
        }
        for(int i = 1; i <= value; ++i)
        {
                factorial *= i;
        }

        return factorial;
}
