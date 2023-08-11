#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdio.h>
#include <stdlib.h>

#define ZERO_INIT 0
#define ZERO      0

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef signed char    sint8_t;
typedef signed short   sint16_t;
typedef signed int     sint32_t;

typedef enum return_status
{
    R_OK,
    R_NOK
}return_status_t;

#endif // STD_TYPES_H_
