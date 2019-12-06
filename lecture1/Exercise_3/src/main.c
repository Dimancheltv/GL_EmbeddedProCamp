/*!
   @brief Exercise_3 - Program calculate perimeter and area (in inches)
   @details Task: Write program that get from user height and weight of rectangle
   (in meters) and calculate perimeter and area (in inches).
   @author Dmytro Lytvyniuk
   @date November
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include "geometry.c"

int main(void)
{
        /*! initialization of variable */
        float height, width = 0;

        /*! get valid height from user */
        printf("Please enter height in meters: ");
        height = validfloat();

        /*! get valid width from user */
        printf("Please enter width in meters: ");
        width = validfloat();

        /*! calculate and print result */
        printf("Perimetr in inches: %.2f\n", MTOINCH (perimetr(width, height)));
        printf("Area in inches: %.2f\n", MTOINCH (area(width, height)));

        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
