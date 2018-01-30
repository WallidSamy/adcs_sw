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
	double MagneticFieldDiffrentitationInBody[3]={0};

	for(i=0;i<3;i++){
			MagneticFieldDiffrentitationInBody[i]=(double)(DcGain*(MagneticFieldInBodyCoordinates[i]-SatelliteParametersObject->PreviousMagneticFieldInBody[i])+SatelliteParametersObject->PreviousMagneticFieldDiffrentiationInBody[i]*exp(-SatelliteParametersObject->CutOffFrequency*(*TimeStep)));

	}

	for(i=0;i<3;i++){
			SatelliteParametersObject->PreviousMagneticFieldDiffrentiationInBody[i]=MagneticFieldDiffrentitationInBody[i];
	}

	Error=SuccessPASS;
	return Error;


}
