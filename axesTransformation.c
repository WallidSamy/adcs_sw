/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "axesTransformation.h"
 void ICS2GCS( double *InputVector,double *S0,double *t,double *Result)
{

  double S=(*S0)+We*((double)1+Ve)*(*t);

  double T_ICS_GCS[3][3]={{cos(S)  ,sin(S)  ,0},
                          {-sin(S) ,cos(S)  ,0},
			  {0       ,0       ,1}};
matrixMultiplication(T_ICS_GCS,InputVector,Result,3,3,1);

}

  void GCS2ICS(double *InputVector,double *S0,double *t,double *Result){
   
      double S=(*S0)+We*((double)1+Ve)*(*t);
      double T_GCS_ICS[3][3]={{cos(S)  ,-sin(S)  ,0},
                              {sin(S)  ,cos(S)   ,0},
			      {0       ,0        ,1}};
      
     matrixMultiplication(T_GCS_ICS,InputVector,Result,3,3,1);

  }
   
  void BCS2OCS(double *Vector,double *Quaternion,double *Result)
{

	/* Definition Of Counters Used in this Function */
	/*----------------------------------------------*/
	uint8 i=0;
	/*----------------------------------------------*/
//  quaternion b ,*p=&b;
        //quaternionNormalization(Quater,p);
	double QuaternionNormalized[4]={0};
	for(i=0;i<4;i++)
	{
		QuaternionNormalized[i]=Quaternion[i];
	}
	quaternionNormalization(QuaternionNormalized);


	double VectorQuat[4],ConjQuat[4],QuatResult[4],temp[4];

	VectorQuat[0]=0;   //Quaternion->q4=0;
	VectorQuat[1]=Vector[0];//Quaternion->q4=Vector->xComponent;
	VectorQuat[2]=Vector[1];
	VectorQuat[3]=Vector[2];

	quaternionConjucate(QuaternionNormalized,ConjQuat);

	quaternionMult(QuaternionNormalized,VectorQuat,temp);
	quaternionMult(temp,ConjQuat,QuatResult);

	Result[0]=QuatResult[1];
	Result[1]=QuatResult[2];
	Result[2]=QuatResult[3];
}

  
  void OCS2BCS(double *Vector,double *Quaternion,double *Result)
{

	/* Definition Of Counters Used in this Function */
	/*----------------------------------------------*/
	uint8 i=0;
	/*----------------------------------------------*/
	double QuaternionNormalized[4]={0};
	for(i=0;i<4;i++)
	{
		QuaternionNormalized[i]=Quaternion[i];
	}
	quaternionNormalization(QuaternionNormalized);


	double VectorQuat[4],ConjQuat[4],QuatResult[4],temp[4];

	VectorQuat[0]=0;
	VectorQuat[1]=Vector[0];
	VectorQuat[2]=Vector[1];
	VectorQuat[3]=Vector[2];

	quaternionConjucate(QuaternionNormalized,ConjQuat);

	quaternionMult(ConjQuat,VectorQuat,temp);
	quaternionMult(temp,QuaternionNormalized,QuatResult);

	Result[0]=QuatResult[1];
	Result[1]=QuatResult[2];
	Result[2]=QuatResult[3];

}

  
  void ICS2OCS(double *R_ICS,double *V_ICS,double *Vector_ICS,double *Result)
{
	double K[3] , j[3] , i[3] , VR[3] , A_matrix[3][3];
	double VR_mag;
	double R_mag=(double)sqrt((double)pow(R_ICS[0],2)+(double)pow(R_ICS[1],2)+(double)pow(R_ICS[2],2));

	K[0]=R_ICS[0]/R_mag;
	K[1]=R_ICS[1]/R_mag;
	K[2]=R_ICS[2]/R_mag;

	crossProduct(R_ICS,V_ICS,VR);

	VR_mag=(double)sqrt((double)pow(VR[0],2)+(double)pow(VR[1],2)+(double)pow(VR[2],2));

	j[0]=VR[0]/VR_mag;
	j[1]=VR[1]/VR_mag;
	j[2]=VR[2]/VR_mag;

	crossProduct(j,K,i);

	A_matrix[0][0]=i[0];
	A_matrix[0][1]=i[1];
	A_matrix[0][2]=i[2];

	A_matrix[1][0]=j[0];
	A_matrix[1][1]=j[1];
	A_matrix[1][2]=j[2];

	A_matrix[2][0]=K[0];
	A_matrix[2][1]=K[1];
	A_matrix[2][2]=K[2];

	matrixMultiplication(A_matrix,Vector_ICS,Result,3,3,1);

}