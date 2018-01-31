/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PD-Controller.h
 * Author: UNKNOWN
 *
 * Created on 31 يناير, 2018, 02:08 ص
 */

#ifndef PD_CONTROLLER_H
#define PD_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include "dataTypes.h"
#include <math.h>
#include "MathematicalLibrary.h"
#include "SatelliteParameters.h"
#include "axesTransformation.h"
#include "Quaternion_Euler.h"


ErrorObject_t PD_Ctrl(double *AngularVelocityBodyToInertial,double * Quaternion,double *MagneticFieldInBodyCoordinates,double *RequiredAngleAcquisition,double *DipoleMoment);

#endif /* PD_CONTROLLER_H */

