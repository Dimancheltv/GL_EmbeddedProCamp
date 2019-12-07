
#include <stdio.h>

/*!
   @brief  constant for value of maximal display number.
 */
#define MAX_NUMBER 500

/*!
   @brief  constant for value from which the counting begins.
 */
#define MIN_NUMBER 1

/*!
   @brief  function that divides numbers.
   @param value is represents divider
 */
void divider(float value)
{
        for(float i = MIN_NUMBER; i <= MAX_NUMBER; ++i)
        {
                printf("%lf ", (i / value));
        }
}

/*!
   @brief function validates the values entered by the user.
   @return float valid data
 */
float validfloat(void){
        float input;
        int temp, status;
        status = scanf("%f", &input);
        while(status != 1 || input == 0) {
                while((temp=getchar()) != EOF && temp != '\n');
                printf("Invalid input... please enter a number: ");
                status = scanf("%f", &input);
        }

        return input;
}
