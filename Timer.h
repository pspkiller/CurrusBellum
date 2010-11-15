/*
 * Timer.h
 *
 *  Created on: 15 nov. 2010
 *      Author: PsPKiller
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <irrlicht.h>
#include <map>

using namespace irr;

class Timer
{
public :
	Timer();
	void addTimer(int, f32);
	bool checkTimer(int);
private :
	//< <idTimer, Timing>, <lastTiming, actualTiming> >
	std::map<std::pair<int, f32>, std::pair<f32, f32> > timers;
};

#endif /* TIMER_H_ */
