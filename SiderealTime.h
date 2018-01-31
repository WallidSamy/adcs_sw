/*
 * SiderealTime.h
 Author      : Amr Wahied
 Version     :
 Copyright   : Aerospace Department , Cairo University
 Description : Satellite Flight Simulator
 */

#ifndef SIDEREALTIME_H_
#define SIDEREALTIME_H_

/* ================================================================================================================================================ */
/*                                                                Include Files                                                                     */
/* ================================================================================================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include <math.h>
#include "MathematicalLibrary.h"
#include "JulianCenturiesElapsed.h"


ErrorObject_t SiderealTime(double *UniversalTime,double *ObserverLocalLongitude,double * GreenwichMeanSiderealTime,double *LocalSiderealTime);

#endif /* SIDEREALTIME_H_ */
