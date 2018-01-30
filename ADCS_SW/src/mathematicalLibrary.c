/*
 * mathematicalLibrary.c
 *
 *  Created on: Jan 19, 2018
 *      Author: Ahmed Fawzy
 */

#include "mathematicalLibrary.h"
/*****************COMPLEX ADDITION ****************************/
void complexAdd(const float64 *restrict Ptr1 ,const float64 *restrict Ptr2,float64 *Result ){

    *(Result+Real) = *(Ptr1+Real) + *(Ptr2+Real);
    *(Result+Imag) = *(Ptr1+Imag) + *(Ptr2+Imag);

}

//////////////////////////////////////////////////////////////////

/*******************COMPLEX MULTIPLICATION *********************/
void complexMult(const float64 *restrict Ptr1 ,const float64 *restrict Ptr2,float64 *Result ){

	*(Result+Real) = *(Ptr1+Real) * *(Ptr2+Real) - *(Ptr1+Imag) * *(Ptr2+Imag);
	*(Result+Imag) = *(Ptr1+Real) * *(Ptr2+Imag) + *(Ptr1+Imag) * *(Ptr2+Real);

}
//////////////////////////////////////////////////////////////////
/**************************VECTORS*******************************/

float64 vectorNorm(const float64 *vect){
   register float64 retVect=0;
   retVect = sqrt(pow(*(vect+xComponent),2)+pow(*(vect+yComponent),2)+pow(*(vect+zComponent),2));
   return retVect;
}

void vectorNormalization(const float64 *vectPtr,float64 *normalizedVector){
	register float64 norm=0;
    norm = vectorNorm(vectPtr);
    *(normalizedVector+xComponent) = *(vectPtr+xComponent) / norm;
    *(normalizedVector+yComponent) = *(vectPtr+yComponent) / norm;
    *(normalizedVector+zComponent) = *(vectPtr+zComponent) / norm;

}
/***************************DOT PRODUCT**********************************/

float64 dotProduct(const float64 *restrict Ptr1,const float64 *restrict Ptr2 ,float64 radAngle){
	register float prodResult=0;
	prodResult = vectorNorm(Ptr1) * vectorNorm(Ptr2) * cos(radAngle);
	return prodResult;
}
/**************************CROSS PRODUCT**********************************/
float64 crossProduct(const float64 *restrict Ptr1,const float64 *restrict Ptr2 ,float64 radAngle){
	register float prodResult=0;
	prodResult = vectorNorm(Ptr1) * vectorNorm(Ptr2) * sin(radAngle);
	return prodResult;
}

/************************QUATERNION********************************************/
float64 quaternionNorm(const float64 *qPtr){
   register float64 retQ=0;
   retQ = sqrt(pow(*(qPtr+q4),2)+pow(*(qPtr+q1),2)+pow(*(qPtr+q2),2)+pow(*(qPtr+q3),2));
   return retQ;
}
void quaternionNormalization(const float64 *quatrPtr,float64 *normalizedQuater){
	register float64 norm=0;
	norm = quaternionNorm(quatrPtr);
	*(normalizedQuater+q4)   = *(quatrPtr+q4) / norm;
	*(normalizedQuater+q1)   = *(quatrPtr+q1) / norm;
	*(normalizedQuater+q2)   = *(quatrPtr+q2) / norm;
	*(normalizedQuater+q3)   = *(quatrPtr+q3) / norm;
}
void quaternionConjucate(const float64 *qutPtr,float64 *conPtr){
	*(conPtr+q4)   =  *(qutPtr+q4) ;
	*(conPtr+q1)   =  *(qutPtr+q1) ;
	*(conPtr+q2)   =  *(qutPtr+q2) ;
	*(conPtr+q3)   =  *(qutPtr+q3) ;

}


void quaternionMult(const float64 *restrict Q1,const float64 *restrict Q2,float64 *Result){
	*(Result+q4)   = *(Q1+q4) * *(Q2+q4) - *(Q1+q1) * *(Q2+q1) - *(Q1+q2) * *(Q2+q2) - *(Q1+q3) * *(Q2+q3);
	*(Result+q1)   = *(Q1+q4) * *(Q2+q1) + *(Q1+q1) * *(Q2+q4) + *(Q1+q2) * *(Q2+q3) - *(Q1+q3) * *(Q2+q2);
	*(Result+q2)   = *(Q1+q4) * *(Q2+q2) - *(Q1+q1) * *(Q2+q3) + *(Q1+q2) * *(Q2+q4) + *(Q1+q3) * *(Q2+q1);
	*(Result+q3)   = *(Q1+q4) * *(Q2+q3) + *(Q1+q1) * *(Q2+q2) - *(Q1+q2) * *(Q2+q1) + *(Q1+q3) * *(Q2+q4);
}
///////////////////////////////////////////////////////////////////////////////

/**************************MATRICES ******************************************/
void matrixMultiplication(const float64 *restrict matPtr1,const float64 *restrict matPtr2,float64 *result ,uint8 matr1Row,uint8 matr1Column,uint8 matr2Column){
  uint8 i=0,j=0,k=0;
  register float64 *p1 ,*p3;
  for(i=(matr1Row-1),p1=result,p3=matPtr1;i>=0;i++,p1 +=matr2Column,p3 +=matr1Column){
	  register float64 *p2 , *p6 ,*p5=matPtr2;
	  for(j=0,p2=p1,p6=p5;j<matr2Column;j++,p2 ++,p5 ++){
		  register float64 sum=0,*p4 ;
		  for(k=0,p4=p3;k<matr1Column;k++,p4 ++,p6 +=matr2Column)
			  sum += *p4 * *p6;
		  *p2 = sum;

	  }
  }

}

////////////////////////////////////////////////////////////////
void matrixTranspose(const float64 *inputMatrix,uint8 row,uint8 col,float64 *transpose){
	uint8 i=0,j=0;
	register float64 *p1,*p4,*p3=transpose;
	for(i=0,p1=inputMatrix;i<row;i++,p1 +=col, p3 ++){
		register float64 *p2;
		for(j=0,p2=p1,p4=p3;j<col;j++,p2 ++,p4 +=row){
			*p4=*p2;
		}

	}


}

void identityMatrix(uint8 *I,uint8 Size){
	uint8 i,j;
	register uint8 *p1;
	for(i=0,p1=I;i<Size;i++,p1 +=Size){
		register uint8 *p2;
		for(j=0,p2=p1;j<Size;j++,p2 ++){
			*p2=(i==j)?1:0;
		}
	}


}

//////////////////*ABSOLUTE *///////////////////
float64 absolute(float64 Parameter)
{
	return fabs(Parameter);
}

float64 factorial(float64 Parameter){
	register float64 fact=1;
	uint8 i;
	for(i=Parameter;i>0;i--){
		fact *=i;
	}
	return fact;
}
