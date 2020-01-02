/*!
   @brief Exercise_2 - Program for demonstration function that finds the biggest element.
   @details Task: Create function to find the biggest element in integer array.
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

#include "functions.c"

int main(void)
{

        int *arr;
        int size = 0;

        printf("Enter size of array: ");
        scanf("%i", &size);

        while(size < 1) {
                puts("Invalid array length, enter corect size: ");
                scanf("%i", &size);
        }

        arr = get_elements(arr, size);
        /*! usage function to find biggest element */
        printf("The biggest element = %d\n", biggestelem(arr, size));
        free(arr);

        /*! for demo test, pause in console */
        system("pause");
}
