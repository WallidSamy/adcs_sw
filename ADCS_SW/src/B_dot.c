/*
 * B_dot.c
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

#include "B_dot.h"


ErrorObject_t B_dotAlgorithm(double TimeStep,double *MagneticFieldInBodyCoordinates,double CutOffFrequency,double *DipoleMoment)
{
	ErrorObject_t Error=Null;
	SatelliteParametersObject_t *SatelliteParametersObject;

	/* Definition Of Counters Used in this Function */
	/*----------------------------------------------*/
	uint8 i=0;
	/*----------------------------------------------*/

	/* Step (1), Calculating the Dc gain for the Filter */
	double DcGain=(double)(CutOffFrequency/sqrt(5))*((pow(cos(CutOffFrequency*(TimeStep)/2)-1,2)+pow(sin(CutOffFrequency*(TimeStep)/2),2))/(pow(cos(CutOffFrequency*(TimeStep)/2)-exp(-CutOffFrequency*(TimeStep)),2)+pow(sin(CutOffFrequency*(TimeStep)/2),2)));
	double MagneticFieldDiffrentitationInBody[3]={0};

	for(i=0;i<3;i++)
	{
		MagneticFieldDiffrentitationInBody[i]=(double)(DcGain*(MagneticFieldInBodyCoordinates[i]-SatelliteParametersObject->PreviousMagneticFieldInBody[i])+SatelliteParametersObject->PreviousMagneticFieldDiffrentiationInBody[i]*exp(-CutOffFrequency*(TimeStep)));

	}


	/* Step(4) , Updating the Previous magnetic field and magnetic field Diffrentiation */
	for(i=0;i<3;i++)
	{
		SatelliteParametersObject->PreviousMagneticFieldDiffrentiationInBody[i]=MagneticFieldDiffrentitationInBody[i];
	}


	/* Step(5) , Calculatiing the Dipole Moment(L) */
	for(i=0;i<3;i++)
	{
		DipoleMoment[i]=-SatelliteParametersObject->B_dotControllerGains[i]*MagneticFieldDiffrentitationInBody[i];
	}



	Error=SuccessPASS;

	return Error;
}
