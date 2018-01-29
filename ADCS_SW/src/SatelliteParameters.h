/*
 * SatelliteParameters.h
 *
 *  Created on: Jan 29, 2018
 *      Author: Wallid Samy
 */

#ifndef SATELLITEPARAMETERS_H_
#define SATELLITEPARAMETERS_H_



/* ================================================================================================================================================ */
/*                                                                Include Files                                                                     */
/* ================================================================================================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum Error{
	Null=0,
	ErrorFAIL,
	SuccessPASS
}ErrorObject_t;
typedef unsigned char     uint8;
typedef struct SatelliteParameters{

	double                              SatelliteMass;
	double                   			InertiaMatrix[3][3];
    double    							SatelliteDimensions[3];
	double    							SatellitePermenantMagnetism[3];
	double                              MaximumDipoleMoment;
	double                              ActuatorEfficiency;
	double                              SemiMajorAxis;
	double                              CutOffFrequency;
	double                              STD_AngularVelocity_MeasurementsNoise;
	double                              STD_MagneticField_MeasurementsNoise;
	double                              STD_AngularVelocity_ProcessNoise;
	double                              STD_MagneticField_ProcessNoise;
	double                              AtmosphericDesnity;
	double                              DragCoefficient;
	double                              SatelliteCenterOfMass[3];
	double                              SatelliteAbsorbtionCoefficient;
	double                              SatelliteSpecularCoefficient;
	double                              SatelliteDiffusionCoefficient;
	double								OrbitalAngularVelocity;
	double 								SimulationStepTime;

	/*================================ Extra Parameters ====================================================*/

	/* ------------------------- For B_dot Controller ----------------------------------- */
	double								B_dotControllerGains[3];
	double								PreviousMagneticFieldInBody[3];
	double								PreviousMagneticFieldDiffrentiationInBody[3];

	/* ------------------------- For VelocityFeedback Controller ----------------------------------- */
	double								VelocityFeedbackControllerGains[3];  /* To control the Quaternion */


	/* ------------------------- For PD Controller ----------------------------------- */
	double								PD_Kp_ControllerGains[3];  /* To control the Quaternion */
	double								PD_Kv_ControllerGains[3];  /* To control the AngularVelocity */



}SatelliteParametersObject_t;




ErrorObject_t  SetSatelliteParameters(SatelliteParametersObject_t *SatelliteParametersObject );



#endif /* SATELLITEPARAMETERS_H_ */
