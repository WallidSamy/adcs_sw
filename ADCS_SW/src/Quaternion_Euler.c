/*
 * Quaternion_Euler.c
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

#include "Quaternion_Euler.h"

void eulerToQuaternion(double *pe,double *pq){
	*(pq + w) = cos(0.5 * *(pe + phi)) * cos(0.5 * *(pe + ceta)) * cos(0.5 * *(pe + epsai)) - sin(0.5 * *(pe + phi)) * sin(0.5 * *(pe + ceta)) * sin(0.5 * *(pe + epsai));
	*(pq + x) = sin(0.5 * *(pe + phi)) * cos(0.5 * *(pe + ceta)) * cos(0.5 * *(pe + epsai)) + cos(0.5 * *(pe + phi)) * sin(0.5 * *(pe + ceta)) * sin(0.5 * *(pe + epsai));
	*(pq + y) = cos(0.5 * *(pe + phi)) * sin(0.5 * *(pe + ceta)) * cos(0.5 * *(pe + epsai)) - sin(0.5 * *(pe + phi)) * cos(0.5 * *(pe + ceta)) * sin(0.5 * *(pe + epsai));
	*(pq + z) = sin(0.5 * *(pe + phi)) * sin(0.5 * *(pe + ceta)) * cos(0.5 * *(pe + epsai)) + cos(0.5 * *(pe + phi)) * cos(0.5 * *(pe + ceta)) * sin(0.5 * *(pe + epsai));
}
//void quaternionToEuler(int *pq,int *pe);

int main(){
	euler[phi]=0.5;
	euler[ceta]=0.5;
	euler[epsai]=0.5;
	quatern[w]=0.5;
	eulerToQuaternion(&euler,&quatern);
	printf("%f\n",quatern[w]);
	printf("%f\n",quatern[x]);
	printf("%f\n",quatern[y]);
	printf("%f\n",quatern[z]);
	return 0;
}

