/*
 * mathematicalLibrary.h
 *
 *  Created on: Jan 19, 2018
 *      Author: Ahmed Fawzy
 */

#ifndef MATHEMATICALLIBRARY_H_
#define MATHEMATICALLIBRARY_H_
#include "math.h"
#include "dataTypes.h"
/*****************COMPLEX  ****************************/
#define Real 0
#define Imag 1

void complexAdd(const float64 *restrict Ptr1 ,const float64 *restrict Ptr2,float64 *Result );
void complexMult(const float64 *restrict Ptr1 ,const float64 *restrict Ptr2,float64 *Result );
////////////////////////////////////////////////////////////////
/*********************VECTORS*********************************/
#define xComponent 0
#define yComponent 1
#define zComponent 2



float64 vectorNorm(const float64 *vect);
void vectorNormalization(const float64 *vectPtr,float64 *normalizedVector);
float64 dotProduct(const float64 *restrict Ptr1,const float64 *restrict Ptr2 ,float64 radAngle);
float64 crossProduct(const float64 *restrict Ptr1,const float64 *restrict Ptr2 ,float64 radAngle);
////////////////////////////////////////////////////////////////////
/******************************quaternion**************************/
#define q4 0
#define q1 1
#define q2 2
#define q3 3
float64 quaternionNorm(const float64 *qPtr);
void quaternionNormalization(const float64 *quatrPtr,float64 *normalizedQuater);
void quaternionConjucate(const float64 *qutPtr,float64 *conPtr);
void quaternionMult(const float64 *restrict Q1,const float64 *restrict Q2,float64 *Result);
/////////////////////////////////////////////////////////////////
/*******************************MATRICES*******************************/

void matrixMultiplication(const float64 *restrict matPtr1,const float64 *restrict matPtr2,float64 *result ,uint8 matr1Row,uint8 matr1Column,uint8 matr2Column);
void matrixTranspose(const float64 *inputMatrix,uint8 row,uint8 col,float64 *transpose);
void identityMatrix(uint8 *I,uint8 Size);

///////////////////////////////////////////////
float64 absolute(float64 Parameter);
float64 factorial(float64 Parameter);
#endif /* MATHEMATICALLIBRARY_H_ */
