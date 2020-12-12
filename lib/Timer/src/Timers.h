/*
 * Timers.h
 *
 *  	Created on: 18 de nov de 2019
 *      Author: Georgines Bezerra Pereira
 *      Email: geoginae.p2@gmail.com
 *
 */

#ifndef TIMERS_H_
#define TIMERS_H_
#include "stdlib.h"
#include "math.h"
#include "Arduino.h"

class Timers {

public:
	enum {
		S, M, H, START, PAUSE, STOP, END_TIME, INITIAL_ACTION, NO_ACTION
	};

	void begin();
	void registerTimerUC(unsigned long (*function)(void));
	void registerStopEvent(void (*stopFunction)(void));
	void registerStartEvent(void (*startFunction)(void));
	void registerPauseEvent(void (*pauseFunction)(void));
	void registerEndTimeEvent(void (*endTimeFunction)(void));
	void registerDebugEvent(void(*debugFunction)(int));
	void setTime(int time = 0, int unity = S);
	void setTimeAtRuntime(unsigned long time = 0, int unity = S);
	void incrementTime(unsigned int time = 0, int unity = S);
	void decrementTime(unsigned int time = 0, int unity = S);
	void resetTime();
	void setAction(int action = 7);
	void run();

private:
	unsigned long (*currentTimer)(void);
	void (*runStopFunction)(void);
	void (*runStarFunction)(void);
	void (*runPauseFuntion)(void);
	void (*runEndTimeFuntion)(void);
	void (*runDebugFunction)(int);

	bool registered_start = false;
	bool registered_stop = false;
	bool registered_pause = false;
	bool registered_end_time = false;
	bool registered_debug = false;

	unsigned long lastTime = 0;
	int totalTime = 0;
	unsigned long timeCounted = 0;
	int action = INITIAL_ACTION;
	int lastAction = NO_ACTION;

	int calculeteTotalTime(unsigned int time = 0, int unity = S);
	void selectAction(int action);
	long map(long x, long in_min, long in_max, long out_min, long out_max);

};

#endif /* TIMERS_H_ */
