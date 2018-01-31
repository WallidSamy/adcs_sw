/*
 * JulianCenturiesElapsed.c
 Author      : Amr Wahied
 Version     :
 Copyright   : Aerospace Department , Cairo University
 Description : Satellite Flight Simulator

 */



/* ================================================================================================================================================ */
/*                                                                Include Files                                                                     */
/* ================================================================================================================================================ */
#include "JulianCenturiesElapsed.h"

//This  is used to Calculate the Julian Centuries since Epoch J2000.
/*=================================================================*/

/* Brief Describtion
UniversalTime=[year, month, day,hour(24), min, sec]

The JD provides a continuous, simple, concise method of preserving year-monthday-
hour-minute-second infonnation in one variable, which is especially nice for computer
applications. In addition, many relations for astronomical equations of motion use
the number of Julian centuries from a partiCUlar epoch (i.e. 12000.0). These relations
,require Julian centuries that reference a particular time scale

To find the Julian date from a known date and time within the
period March I, 1900 to February 28,2100, we use the following algorithm

 This Algorithm is valid for any of the time systems and should be identified to avoid confusion (JDUT1 , JDTDP JDTDB, ••• ).
Unless specified, JD usually implies a time based on UTi

Because Julian Centuries are often used as the time scale, a shorthand notation such
as Jl900.0 or 12000.0 is common. To be precise, I've shown the J2000.0 epoch using
TT, although we often use UT1 for most problems. Some commonly used epochs are
GPS epoch = 2,444,244.5 = January 6, 1980 00:00:00.000 UTC
J2000.0 = 2,451,545.0 = January 1,200012:00:00.000 TT
J1900.0 = 2,415,021.0 = January I, 1900 12:00:00.000 UTI
B1900.0 = 2,415,020.3\3 52 = December 31,189919:31:28.128 UTI
B 1950.0 = 2,433,282.423 459 05 = December 31, 194922:09:46.862 UTI

Refrences : Section 3.5 Vallado , Fundamentals of Astrodynamics and Applications

*/


ErrorObject_t JulianCenturiesElapsedSinceJ200Epoch(double *UniversalTime,double *JulianCenturiesElapsed)
{
	ErrorObject_t Error=Null; /*Initialization */

	double JulianDate=0;
	/* Calculating Julian Date from 1900 to 2100 */
	JulianDate=(double)( 367*UniversalTime[0]-(int)(7*(UniversalTime[0]+ (int)((UniversalTime[1]+9)/12))/4)+ (int)(275*UniversalTime[1]/9)+	UniversalTime[2] + 1721013.5 + (((UniversalTime[5]/60+UniversalTime[4])/60)+UniversalTime[3])/24 );


	double J2000Epoch=2451545;
	double JulianCentury=36525;

	*JulianCenturiesElapsed=(double)((JulianDate-J2000Epoch)/JulianCentury);

	Error=SuccessPASS;

	return Error;
}


