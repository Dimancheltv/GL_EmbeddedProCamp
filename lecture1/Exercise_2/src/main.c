/*!
   @brief Exercise_2 - Program for demonstration function that converts RGB 888 to RGB 565.
   @details Task: Write function that converts RGB 888 to RGB 565.
   @author Dmytro Lytvyniuk
   @date November
   @warning This program was created for educational purposes.
 */

#include "converter.c"
#include "swap.c"
#include <assert.h>

int main (void)
{
        /*! opening input file */
        FILE *fb = fopen("../tests/rgb888.bin", "rb");
        assert(fb);
        /*! opening output file */
        FILE *tmp = fopen("../tests/rgb565.bin", "wb");
        assert(tmp);

        uint8_t rgb888[3];
        while (!feof(fb)) {
                /*! read input file */
                fread(rgb888, sizeof(uint8_t), 3, fb);
                /*! use convert function */
                uint16_t rgb565 = converter(rgb888);
                /*! swapping bytes before writing */
                swap16(&rgb565);
                /*! write output file */
                fwrite(&rgb565, sizeof(uint16_t), 1, tmp);
        }
        /*! close files */
        fclose(fb);
        fclose(tmp);
        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
