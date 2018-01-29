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
void quaternionToEuler(double *pq,double *pe){
	*(pe + phi)=atan2(2 * (*(pq + w) * *(pq + x) + *(pq + y) * *(pq + z)),(1 - 2 *(*(pq + x) * *(pq + x) + *(pq + y) * *(pq + y))));
	if(fabs(2 * (*(pq + w) * *(pq + y) - *(pq + z) * *(pq + x))) >= 1){
		*(pe + ceta)=copysign(PI/2,2 * (*(pq + w) * *(pq + y) - *(pq + z) * *(pq + x)));
	}else{
		*(pe + ceta)=asin(2 * (*(pq + w) * *(pq + y) - *(pq + z) * *(pq + x)));
	}
	*(pe + epsai)=atan2((2 * (*(pq + w) * *(pq + z) + *(pq + x) * *(pq + y))),(1 - 2 * (*(pq + y) * *(pq + y) + *(pq + z) * *(pq + z))));
}

int main(){
	euler[phi]=0.3;
	euler[ceta]=0.3;
	euler[epsai]=0.3;
	eulerToQuaternion(&euler,&quatern);
	printf("%f\n",quatern[w]);
	printf("%f\n",quatern[x]);
	printf("%f\n",quatern[y]);
	printf("%f\n",quatern[z]);
	printf("/////////////////////////////////////////////////////////////////////////////////////////\n");
	quaternionToEuler(&quatern,&euler);
	printf("%f\n",euler[phi]*180/PI);
	printf("%f\n",euler[ceta]*180/PI);
	printf("%f\n",euler[epsai]*180/PI);
	return 0;
}

