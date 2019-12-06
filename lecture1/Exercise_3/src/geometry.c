/*! Convert meters to inches */
#define MTOINCH(m) (m/0.0254)

/*!
   @brief function to calculate the perimeter.
   @param width	is width of rectangle
   @param height is height of rectangle
   @return float value of perimeter
 */
float perimetr(float width, float height)
{
        return (width + height) * 2;
}

/*!
   @brief function to calculate the erea.
   @param width	is width of rectangle
   @param height is height of rectangle
   @return float value of area
 */
float area(float width, float height)
{
        return (width * height);
}

/*!
   @brief function validates the values entered by the user.
   @return float valid data
 */
float validfloat(void){
        float input;
        int temp, status;
        status = scanf("%f", &input);

        while(status != 1) {
                while((temp=getchar()) != EOF && temp != '\n');
                printf("Invalid input... please enter a number: ");
                status = scanf("%f", &input);
        }
        
        return input;
}
