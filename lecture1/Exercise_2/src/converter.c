#include <stdio.h>
#include <stdint.h>
#include "../inc/converter.h"

uint16_t converter(uint8_t *rgb888Pixel)
{
        /*! select channels */
        uint8_t red   = rgb888Pixel[0];
        uint8_t green = rgb888Pixel[1];
        uint8_t blue  = rgb888Pixel[2];

        /*! masking and shifting bits */
        uint16_t Rgb565 = (((red & RED_MASK) << RED_SHIFT)|
                           ((green & GREEN_MASK) << GREEN_SHIFT)|
                           (blue >> BLUE_SHIFT));

        printf("RGB888 - %X%X%X\n", red, green, blue);
        printf("RGB565 - %X\n\n", Rgb565);

        return Rgb565;
}
