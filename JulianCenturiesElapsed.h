/*
 * JulianCenturiesElapsed.h
 Author      : Amr Wahied
 Version     :
 Copyright   : Aerospace Department , Cairo University
 Description : Satellite Flight Simulator

 */

#ifndef JULIANCENTURIESELAPSED_H_
#define JULIANCENTURIESELAPSED_H_

/* ================================================================================================================================================ */
/*                                                                Include Files                                                                     */
/* ================================================================================================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include <math.h>
#include "MathematicalLibrary.h"

ErrorObject_t JulianCenturiesElapsedSinceJ200Epoch(double *UniversalTime,double *JulianCenturiesElapsed);

#endif /* JULIANCENTURIESELAPSED_H_ */
