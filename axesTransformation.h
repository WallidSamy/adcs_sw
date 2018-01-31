/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   axesTransformation.h
 * Author: UNKNOWN
 *
 * Created on 27 يناير, 2018, 05:09 ص
 */

#ifndef axesTransformation_H
#define axesTransformation_H

#include "dataTypes.h"
#include "mathematicalLibrary.h"
#define We 7.292115*1e-5

#define Ve 0



void ICS2GSC(float64 *InputVector,float64 *S0,float64 *t,float64 *Result);
void GCS2ICS(double *InputVector,double *S0,double *t,double *Result);
void BCS2OCS(double *Vector,double *Quaternion,double *Result);
void OCS2BCS(double *Vector,double *Quaternion,double *Result);
void ICS2OCS(double *R_ICS,double *V_ICS,double *Vector_ICS,double *Result);
#endif




#ifdef __cplusplus
}
#endif

 /* axesTransformation_H */

