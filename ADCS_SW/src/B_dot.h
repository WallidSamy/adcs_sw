/*
 * B_dot.h
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

#ifndef B_DOT_H_
#define B_DOT_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<SatelliteParameters.h>

typedef enum Error{
	Null=0,
	ErrorFAIL,
	SuccessPASS
}ErrorObject_t;

typedef unsigned char     uint8;

ErrorObject_t B_dotAlgorithm(double *TimeSinceSimulaion,double *TimeStep,double *MagneticFieldInBodyCoordinates,SatelliteParametersObject_t *SatelliteParametersObject,double *DipoleMoment);

#endif /* B_DOT_H_ */
