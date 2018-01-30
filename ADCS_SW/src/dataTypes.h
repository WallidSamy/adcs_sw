/*
 * dataTypes.h
 *
 *  Created on: Jan 20, 2018
 *      Author: embedded
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef unsigned char     uint8;
typedef char              int8;
typedef unsigned int      uint16;
typedef int               int16;
typedef unsigned long     uint32;
typedef long              int32;
typedef long long         uint64;
typedef float             float32;
typedef double            float64;

#define Pi 3.1415926535897932384626433832795028841971693993751058209749445923078164

typedef enum Error{
	Null=0,
	ErrorFAIL,
	SuccessPASS
}ErrorObject_t;

#endif /* DATATYPES_H_ */
