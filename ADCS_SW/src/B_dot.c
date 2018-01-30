/*
 * B_dot.c
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

#include "B_dot.h"

ErrorObject_t B_dotAlgorithm(double *TimeSinceSimulaion,double *TimeStep,double *MagneticFieldInBodyCoordinates,SatelliteParametersObject_t *SatelliteParametersObject,double *DipoleMoment){

	ErrorObject_t Error=Null;

	uint8 i=0;

	double DcGain=SatelliteParametersObject->CutOffFrequency/sqrt(5)*sqrt((2 - 2 * cos(SatelliteParametersObject->CutOffFrequency * (*TimeStep) / 2))/(1 - 2 * cos(SatelliteParametersObject->CutOffFrequency * (*TimeStep) / 2) * exp(-SatelliteParametersObject->CutOffFrequency * (*TimeStep)) + exp(-2 * SatelliteParametersObject->CutOffFrequency)));
}
