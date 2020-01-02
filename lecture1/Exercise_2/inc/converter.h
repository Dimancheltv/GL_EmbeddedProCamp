#ifndef CONVERT_H
#define CONVERT_H

/*!
   @brief Bitmask for red chanel.
 */
#define RED_MASK 0b11111000

/*!
   @brief Bitmask for green chanel.
 */
#define GREEN_MASK 0b11111100

/*!
   @brief Bit constant to shift red bits in RGB888->RGB565 conversion.
 */
#define RED_SHIFT 8

/*!
   @brief Bit constant to shift green bits in RGB888->RGB565 conversion.
 */
#define GREEN_SHIFT 3

/*!
   @brief Bit constant to shift blue bits in RGB888->RGB565 conversion.
 */
#define BLUE_SHIFT 3

/*!
   @brief function converts pixel rgb-colors from 3-byte to 2-byte format.
   @param *rgb888Pixel	3-byte array address of RGB888 color
   @return uint16_t 2-byte of RGB565 pixel color
 */
uint16_t converter(uint8_t *rgb888Pixel);

#endif
