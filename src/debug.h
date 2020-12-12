/*
 * sys.debug.h
 *
 *  Created on: 3 de out de 2019
 *      Author: Georgines
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "Arduino.h"

#define ENABLE_SERIAL_DEBUG_MASTER

#ifdef ENABLE_SERIAL_DEBUG_MASTER
#define SERIAL_DEBUG Serial
#define DBG(i) SERIAL_DEBUG.print(i);
#define DBG_PGM(i) SERIAL_DEBUG.print(F(i));
#define DBG_2(i, j) SERIAL_DEBUG.print(i, j);
#define DBG_LN(i) SERIAL_DEBUG.println(i);
#define DBG_LN_PGM(i) SERIAL_DEBUG.println(F(i));
#define DBG_LN2(i, j) SERIAL_DEBUG.println(i, j);
#define DBG_F(i, ...) SERIAL_DEBUG.printf((i), __VA_ARGS__);
#define DBG_F_LN(i, ...) SERIAL_DEBUG.printf((i), __VA_ARGS__);SERIAL_DEBUG.println();
#define DBG_FLUSH() SERIAL_DEBUG.flush();
#define DBG_DELAY(i) delay(i);
#else
#define DBG(i) do{}while(true);
#define DBG_PGM(i) do{}while(true);
#define DBG_2(i, j) do{}while(true);
#define DBG_LN(i) do{}while(true);
#define DBG_LN_PGM(i) do{}while(true);
#define DBG_LN2(i, j) do{}while(true);
#define DBG_F(i, ...) do{}while(true);
#define DBG_F_LN(i, ...)do{}while(true);
#define DBG_FLUSH() do{}while(true);
#define DBG_DELAY(i) do{}while(true);
#endif

#define ENABLE_DATA_DEBUG
#define DATA_DEBUG_MAP
#define DATA_DEBUG_IOs

#endif /* DEBUG_H_ */
