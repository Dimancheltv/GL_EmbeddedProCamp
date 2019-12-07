/*!
   @brief Exercise_4 - Program calculate perimeter and area of a circle.
   @details Task: Write a C program to compute the perimeter and area
   of a circle with a radius of 6 meters
   @author Dmytro Lytvyniuk
   @date November
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include "geometry.c"

int main(void)
{
        printf("Circle radius: %0.2f m.\n", (float)RADIUS);
        printf("Circle perimeter: %.2f m.\n", c_perimetr((float)RADIUS));
        printf("Circle area: %.2f m.\n", c_area((float)RADIUS));

        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
