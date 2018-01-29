/*
 * SatelliteParameters.c
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

/* ================================================================================================================================================ */
/*                                                                Include Files                                                                     */
/* ================================================================================================================================================ */
#include "SatelliteParameters.h"


//This Function is used to set the Parameters of our satellite.
/*====================================================================*/

ErrorObject_t  SetSatelliteParameters(SatelliteParametersObject_t *SatelliteParametersObject )
{

	ErrorObject_t Error=Null;

	/* Definition Of Counters Used in this Function */
	/*----------------------------------------------*/
	uint8 i=0;
	uint8 j=0;
	/*----------------------------------------------*/

	double   InertiaMatrix[3][3]={ {0.06,0,0},{0,0.08,0},{0,0,0.004} };/* InertiaMatrix in kg.m^2*/
	double   SatelliteDimensions[3]={0.1,0.1,0.2}; /* SatelliteDimensions in m */
	double   SatellitePermenantMagnetism[3]={0.0006,0.0006,0.0006};
	double   SatelliteCenterOfMass[3]={-2.6e-3,-0.69e-3,3.213e-3};


	SatelliteParametersObject->SatelliteMass=10; /*Mass Of the satellite in Kg */
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
			SatelliteParametersObject->InertiaMatrix[j][i]=InertiaMatrix[j][i];/* InertiaMatrix in kg.m^2*/
		}
	}

	for(i=0;i<3;i++)
	{
		SatelliteParametersObject->SatelliteDimensions[i]=SatelliteDimensions[i]; /* SatelliteDimensions in m */
		SatelliteParametersObject->SatellitePermenantMagnetism[i]=SatellitePermenantMagnetism[i]; /* SatellitePermenantMagnetism in m */
		SatelliteParametersObject->SatelliteCenterOfMass[i]=SatelliteCenterOfMass[i];/* SatelliteCenterOfMass in m */
	}


	SatelliteParametersObject->MaximumDipoleMoment=0.076; /* MaximumDipoleMoment*/
	SatelliteParametersObject->ActuatorEfficiency= 1; /* ActuatorEfficiency*/
	SatelliteParametersObject->SemiMajorAxis=7046141.784; /* SemiMajorAxis*/
	SatelliteParametersObject->CutOffFrequency=0.7; /*CutOffFrequency*/
	SatelliteParametersObject->STD_AngularVelocity_MeasurementsNoise=4e-6; /* STD_AngularVelocity_MeasurementsNoise*/
	SatelliteParametersObject->STD_MagneticField_MeasurementsNoise=1e-7;/* STD_MagneticField_MeasurementsNoise*/
	SatelliteParametersObject->STD_AngularVelocity_ProcessNoise=0; /* STD_AngularVelocity_ProcessNoise*/
	SatelliteParametersObject->STD_MagneticField_ProcessNoise=0;/* STD_MagneticField_ProcessNoise*/
	SatelliteParametersObject->AtmosphericDesnity=5.68e-13; /* STD_MagneticField*/
	SatelliteParametersObject->DragCoefficient=2; /* DragCoefficient*/
	SatelliteParametersObject->SatelliteAbsorbtionCoefficient=0;/* SatelliteAbsorbtionCoefficient*/
	SatelliteParametersObject->SatelliteSpecularCoefficient=1;/* SatelliteSpecularCoefficient*/
	SatelliteParametersObject->SatelliteDiffusionCoefficient=0;/* SatelliteDiffusionCoefficient*/
	SatelliteParametersObject->SimulationStepTime=4; /* SimulationStepTime*/

	double Mu_EarthSun=398600e9;
	SatelliteParametersObject->OrbitalAngularVelocity=(double)(sqrt(Mu_EarthSun)/pow(SatelliteParametersObject->SemiMajorAxis,1.5));



	/* ------------------------- For B_dot Controller ----------------------------------- */
	double K_Bdot[3]={8*1e5,8*1e5,8*1e5};
	for(i=0;i<3;i++)
	{
		SatelliteParametersObject->PreviousMagneticFieldInBody[i]=0;
		SatelliteParametersObject->PreviousMagneticFieldDiffrentiationInBody[i]=0;
		SatelliteParametersObject->B_dotControllerGains[i]=K_Bdot[i];

	}

	/* ------------------------- For VelocityFeedback Controller ----------------------------------- */
	double K_VelocityFeedback[3]={0.6*1e-2,4*1e-2,4*1e-2};
	for(i=0;i<3;i++)
	{
		SatelliteParametersObject->VelocityFeedbackControllerGains[i]=K_VelocityFeedback[i];
	}

	/* ------------------------- For	PD  Controller ----------------------------------- */
	double Kp_PD[3]={0.3*1e-6,2*1e-6,2.5*1e-6};
	double Kv_PD[3]={1.2*1e-4,8e-4,8e-4};

	for(i=0;i<3;i++)
	{
		SatelliteParametersObject->PD_Kp_ControllerGains[i]=Kp_PD[i];
		SatelliteParametersObject->PD_Kv_ControllerGains[i]=Kv_PD[i];
	}

	 Error=SuccessPASS;

	return Error;
}
