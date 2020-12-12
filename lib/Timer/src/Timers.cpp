/*
 * Timers.cpp
 *
 *  	Created on: 18 de nov de 2019
 *      Author: Georgines Bezerra Pereira
 *      Email: geoginae.p2@gmail.com
 *
 */

#include "Timers.h"

void Timers::begin() {
}

void Timers::registerTimerUC(unsigned long (*function)(void)) {
	this->currentTimer = function;
}

void Timers::registerStopEvent(void (*stopFunction)(void)) {
	this->runStopFunction = stopFunction;
	this->registered_stop = true;
}

void Timers::registerStartEvent(void (*startFunction)(void)) {
	this->runStarFunction = startFunction;
	this->registered_start = true;
}

void Timers::registerPauseEvent(void (*pauseFunction)(void)) {
	this->runPauseFuntion = pauseFunction;
	this->registered_pause = true;
}

void Timers::registerEndTimeEvent(void (*endTimeFunction)(void)) {
	this->runEndTimeFuntion = endTimeFunction;
	this->registered_end_time = true;
}

void Timers::registerDebugEvent(void (debugFunction)(int)) {
	this->runDebugFunction = debugFunction;
	this->registered_debug = true;
}

void Timers::setTime(int time, int unity) {
	this->resetTime();
	if(time < 0){
		this->totalTime = 0;
		return;
	}
	this->totalTime = calculeteTotalTime(time, unity);
}

void Timers::setTimeAtRuntime(unsigned long time, int unity) {
	int calculated = calculeteTotalTime(time, unity);
	int newTime = calculated - this->timeCounted;
	this->setTime(newTime, S);
}

void Timers::incrementTime(unsigned int time, int unity) {
	this->totalTime += calculeteTotalTime(time, unity);
}

void Timers::decrementTime(unsigned int time, int unity) {
	this->totalTime -= calculeteTotalTime(time, unity);
	if (this->totalTime <= 0)
		this->totalTime = 0;
}

void Timers::resetTime() {
	this->totalTime = 0;
	this->timeCounted = 0;
}

void Timers::setAction(int action) {
	selectAction(action);
}

void Timers::run() {

	bool cond = (action == START || action == PAUSE);

	if (this->currentTimer() - this->lastTime >= 1000) {

		if (this->action == START) {
			this->decrementTime(1, S);
			this->timeCounted++;
		} else if (this->action == STOP) {
			this->resetTime();
		} else if (this->action == PAUSE) {
			this->decrementTime(0, S);
		}

		if (registered_debug && cond) {
			this->runDebugFunction(this->totalTime);
		}

		this->lastTime = this->currentTimer();
	}

	if (totalTime == 0 && cond) {
		this->setAction(END_TIME);
	}
}

//privates methods
int Timers::calculeteTotalTime(unsigned int time, int unity) {
	int result = 0;
	switch (unity) {
	case S:
		result = (time);
		break;
	case M:
		result = (time * 60);
		break;
	case H:
		result = (time * 3600);
		break;
	}
	return result;
}

void Timers::selectAction(int action) {

	if (this->lastAction == action) {
		action = NO_ACTION;
	}

	switch (action) {
	case START:
		this->action = START;
		if (this->registered_start) {
			this->runStarFunction();
		}
		break;
	case STOP:
		this->action = STOP;
		if (this->registered_stop) {
			this->runStopFunction();
		}
		break;
	case PAUSE:

		this->action = PAUSE;
		if (this->registered_pause) {
			this->runPauseFuntion();
		}
		break;
	case END_TIME:

		this->action = END_TIME;
		if (this->registered_end_time) {
			this->runEndTimeFuntion();
		}
		break;
	}

	if (action != NO_ACTION) {
		this->lastAction = action;
	}

}

long Timers::map(long x, long in_min, long in_max, long out_min, long out_max) {
	long divisor = (in_max - in_min);
	if (divisor == 0) {
		return -1;
	}
	return (x - in_min) * (out_max - out_min) / divisor + out_min;
}
