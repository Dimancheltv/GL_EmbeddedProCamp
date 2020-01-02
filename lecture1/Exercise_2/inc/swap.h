
#ifndef SWAP_H
#define SWAP_H

#include <stdint.h>

/*!
   @brief Function swap bytes in uint16_t.
   @param value the pointer of data for swap
 */
void swap16(uint16_t *value);

/*!
   @brief Function swap bytes in uint32_t.
   @param value the pointer of data for swap
 */
void swap32(uint32_t *value);

/*!
   @brief Function swap bytes in uint64_t.
   @param value the pointer of data for swap
 */
void swap64(uint64_t *value);

#endif
