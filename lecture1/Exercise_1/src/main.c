/*!
   @brief Exercise_1 - Program for demonstration swapping function.
   @details Task: Write swap16, swap32, swap64 functions that swap, bytes in uint16_t,
   unit32_t, and uint64_t functions.
   @author Dmytro Lytvyniuk
   @date November
   @warning This program was created for educational purposes.
 */

#include <stdio.h>
#include "swap.c"

int main(void)
{
        uint16_t u16_data = 0x22AA;
        uint32_t u32_data = 0x11AA02BB;
        uint64_t u64_data = 0xAABBCCDDEEFF1234;

        printf("Before swapping bytes uint16_t: %X\n", u16_data);
        swap16(&u16_data); /*!< swapping uint16_t */
        printf("After swapping bytes uint16_t:  %X\n\n", u16_data);

        printf("Before swapping bytes uint32_t: %X\n", u32_data);
        swap32(&u32_data); /*!< swapping uint32_t */
        printf("After swapping bytes uint32_t:  %X\n\n", u32_data);

        printf("Before swapping bytes uint64_t: 0x%I64X\n", u64_data);
        swap64(&u64_data); /*!< swapping uint64_t */
        printf("After swapping bytes uint64_t:  0x%I64X\n", u64_data);

        // for demo test, pause in console
        system("pause");
}
