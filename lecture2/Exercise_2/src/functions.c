#include <stdio.h>
#include <stdlib.h>

/*!
   @brief function for getting elemets of array from user.
   @param *arr	pointer on array
   @param size int is value of array length
   @return int array from user
 */
int *get_elements(int *arr, int size)
{
        arr = (int*)malloc(size * sizeof(int));
        for (int i = 0; i<size; i++)
        {
                printf("a[%i] = ", i);
                scanf("%i", &arr[i]);
        }
        return arr;
}

/*!
   @brief function for find the biggest element in integer array.
   @param *arr	pointer on array
   @param size int is value of array length
 */
int biggestelem(int *arr, int size)
{
        int max = arr[0];
        for (int i = 0; i<size; i++)
        {
                arr[i] > max ? (max = arr[i]) : 0;
        }
        return max;
}
