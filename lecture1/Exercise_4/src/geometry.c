/*!
   @brief  constant for input data radius.
 */
#define RADIUS 6

/*!
   @brief  constant for the value of PI.
 */
#define PI 3.14159265359

/*!
   @brief function to calculate perimeter of a circle.
   @param radius is input data radius
   @return float perimeter of a circle.
 */
float c_perimetr(float radius)
{
        return 2 * PI * radius;
}

/*!
   @brief function to calculate area of a circle.
   @param radius is input data radius
   @return float area of a circle. 
 */
float c_area(float radius)
{
        return PI * radius * radius;
}
