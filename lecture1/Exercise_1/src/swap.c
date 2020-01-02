#include "../inc/swap.h"

void swap16(uint16_t *data)
{
        *data = (uint16_t)(*data >> 8) |
                (uint16_t)(*data << 8);
}

void swap32(uint32_t *data)
{
        *data = ((((*data) & 0xff000000) >> 24)|
                 (((*data) & 0x00ff0000) >> 8)|
                 (((*data) & 0x0000ff00) << 8)|
                 (((*data) & 0x000000ff) << 24));
}

void swap64(uint64_t *data)
{
        *data = ((((*data) & 0xff00000000000000ull) >> 56)|
                 (((*data) & 0x00ff000000000000ull) >> 40)|
                 (((*data) & 0x0000ff0000000000ull) >> 24)|
                 (((*data) & 0x000000ff00000000ull) >> 8)|
                 (((*data) & 0x00000000ff000000ull) << 8)|
                 (((*data) & 0x0000000000ff0000ull) << 24)|
                 (((*data) & 0x000000000000ff00ull) << 40)|
                 (((*data) & 0x00000000000000ffull) << 56));
}
