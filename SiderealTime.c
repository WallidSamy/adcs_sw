/*
 * SiderealTime.c
 Author      : Amr Wahied
 Version     :
 Copyright   : Aerospace Department , Cairo University
 Description : Satellite Flight Simulator
 */


/* ================================================================================================================================================ */
/*                                                                Include Files                                                                     */
/* ================================================================================================================================================ */
#include "SiderealTime.h"

//This  is used to Calculate the Greenwich Mean Sidereal Time.
/*=================================================================*/

/* Brief Describtion
UniversalTime=[year, month, day,hour(24), min, sec]
Sidereal time as the hour angle of the vernal equinox relative to the local meridian
and it is a direct measure of the Earth's rotation and it's measured positively in
the counter-clockwise direction when viewed from the North pole.

 Ideally, the observations of a star would suffice for determining sidereal time. The changing instantaneous
axis of rotation, causes station locations to continually change. This produces a small
difference in the time of meridian transits, depending on the star's declination. Because
this effect vanishes at the equator, it's better to use stars with small declinations.

The concept of sidereal time would be perfect except that the equinox moves very
slowly due to precession, the apparent locations of the stars do change a little, and different
longitude definitions cause small deviations in the exact longitudes of sites.

Recall that the equinox results from the intersection ofthe Earth's equator and the ecliptic,
and both planes are moving. This permits a distinction for mean and apparent time.
Mean sidereal time, which is most commonly used, refers to a mean equinox that
moves only with secular motion (precession). We measure apparent sidereal time,
AST: from the true vernal equinox which includes secular and periodic contributions to
the motion of the vernal equinox. The difference between the mean equinox and the
apparent equinox [in the plane of the true equator] is the equation of the equinoxes

Refrences : Section 3.5 Vallado , Fundamentals of Astrodynamics and Applications

*/


ErrorObject_t SiderealTime(double *UniversalTime,double *ObserverLocalLongitude,double * GreenwichMeanSiderealTime,double *LocalSiderealTime)
{
	ErrorObject_t Error=Null;

	/*First, find the number of Julian centuries, T UTI' from the J2000.0 epoch */
	double JulianCenturiesElapsed=0;

	ErrorObject_t Error1=JulianCenturiesElapsedSinceJ200Epoch(UniversalTime,&JulianCenturiesElapsed);


	/* Then we calculate the Greenwich Mean Sidereal Time in seconds */
	 *GreenwichMeanSiderealTime=(double)(67310.54841+(876600.0*3600.0+8640184.812866)*JulianCenturiesElapsed+0.093104*pow(JulianCenturiesElapsed,2)-6.2e-6*pow(JulianCenturiesElapsed,3));


	/*rounding the value to the nearest number of seconds in a day (24 *60 *60 )*/
	 *GreenwichMeanSiderealTime=(double)(*GreenwichMeanSiderealTime-(int)(*GreenwichMeanSiderealTime/86400)*86400);


	/*rounding the value to Greenwich Mean Sidereal Time degrees degrees by dividing by 240 (1s = 1/240 degrees )*/
	 *GreenwichMeanSiderealTime=(double)(*GreenwichMeanSiderealTime/240);

	 /* Checking if the angle is less than 0 degrees */
	 if(*GreenwichMeanSiderealTime<0)
	 {
		 *GreenwichMeanSiderealTime=(double)(*GreenwichMeanSiderealTime+360);
	 }

	 /* Calculating Observer local Sidereal time */
	 *LocalSiderealTime=*GreenwichMeanSiderealTime+*ObserverLocalLongitude;


	 /* Converting Values to radians */
	 *GreenwichMeanSiderealTime=(double)(*GreenwichMeanSiderealTime*(Pi/180));
	 *LocalSiderealTime=(double)(*LocalSiderealTime*(Pi/180));

	Error=SuccessPASS;

	return Error;
}
