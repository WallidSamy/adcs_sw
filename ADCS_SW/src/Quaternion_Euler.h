/*
 * Quaternion_Euler.h
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

#ifndef QUATERNION_EULER_H_
#define QUATERNION_EULER_H_

#include "stdio.h"
#include "stdlib.h"
#define PI 3.14159265358979323846
//for euler
#define phi 0
#define ceta 1
#define epsai 2
//for quaternion
#define w 0
#define x 1
#define y 2
#define z 3

double euler[3];
double quatern[4];

void eulerToQuaternion(double *pe,double *pq);
void quaternionToEuler(double *pq,double *pe);


#endif /* QUATERNION_EULER_H_ */
