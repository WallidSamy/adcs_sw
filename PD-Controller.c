/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PD-Controller.h"
ErrorObject_t PD_Ctrl(double *AngularVelocityBodyToInertial,double * Quaternion,double *MagneticFieldInBodyCoordinates,double *RequiredAngleAcquisition,double *DipoleMoment)
{
	ErrorObject_t Error=Null;
	SatelliteParametersObject_t *SatelliteParametersObject;

	/* Definition Of Counters Used in this Function */
	/*----------------------------------------------*/
	uint8 i=0;
	/*----------------------------------------------*/

	/* Step (1) , Getting the Required angular orbital velocity */
	double RequiredAngularVelocityOrbitalToInertial[3]={0,SatelliteParametersObject->OrbitalAngularVelocity,0};

	/* Step (2) , Transforming the Angular velocity to Body coordinates */
	double RequiredAngularVelocityBodyToInertial[3]={0}; /* Initialization */
	OCS2BCS(RequiredAngularVelocityOrbitalToInertial,Quaternion,RequiredAngularVelocityBodyToInertial);

	/* Step (3) , Calculating the Error in The Required Angular velocity */
	double ErrorInAngularVelocityBodyToInertial[3]={0};

	for(i=0;i<3;i++)
	{
		ErrorInAngularVelocityBodyToInertial[i]=AngularVelocityBodyToInertial[i]-RequiredAngularVelocityBodyToInertial[i];
	}


        /* Step(4) , Getting the Required Quaternion based on the Required angle acquisition */
	double RequiredQuaternion[4]={0};
	eulerToQuaternion(RequiredAngleAcquisition,RequiredQuaternion);

        /*   added */
        RequiredQuaternion=quaternionNormalization(RequiredQuaternion);

	 /* Step(5) , Getting the Error in the Required Quaternion */
        
	double RequiredQuaternionConjugate[4]={0};
	quaternionConjucate(RequiredQuaternion,RequiredQuaternionConjugate);
        
	double ErrorInQuaternion[4]={0};
	quaternionMult(RequiredQuaternionConjugate,Quaternion,ErrorInQuaternion);
	quaternionNormalization(ErrorInQuaternion);


	/* Step(6) , Getting the Required Control Moment */
	double RequiredControlMoment[3]={0};
	for(i=0;i<3;i++)
	{
		RequiredControlMoment[i]=(double)(-SatelliteParametersObject->PD_Kp_ControllerGains[i]*ErrorInQuaternion[i+1]-SatelliteParametersObject->PD_Kv_ControllerGains[i]*ErrorInAngularVelocityBodyToInertial[i]);
	}


        /* Step (6) , Getting the Dipole Moment using the BAC-CAB Rule */
	double MagneticFieldCrossControlMoment[3]={0};
	crossProduct(MagneticFieldInBodyCoordinates,RequiredControlMoment,MagneticFieldCrossControlMoment);

	double MagneticFieldNorm=vectorNorm(MagneticFieldInBodyCoordinates,3);

	for(i=0;i<3;i++)
	{
		DipoleMoment[i]=MagneticFieldCrossControlMoment[i]/pow(MagneticFieldNorm,2);
	}


	Error=SuccessPASS;

	return Error;
}