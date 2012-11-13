/***
	run library - library to simulate the Bitlash "run func,interval" command

	See the file README.md for documentation.

	The author can be reached at: bill@bitlash.net

	Copyright (C) 2012 Bill Roy

	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:
	
	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.

***/

/*****

The Run Library

This is a little library that makes it easy to run several functions asynchronously
at specified intervals (like the Bitlash 'run' command).  Scheduling is non-preemptive
and round-robin, so your functions can't hog the CPU.  (Don't even think of calling 
delay(); that behavior is what this library is intended to extinguish.)

If you need more than 10 functions, increase NUMRUNS below.

There are three functions:

- run(function, interval); schedules your C function to run at the given interval (in ms)

	Call this from setup()
	Your function must be declared to be of type void myFunc(void).

- runner(); runs the scheduled functions

	Call this from loop() 

- snooze(interval); call this to set a different function sleep interval (in ms)


Here is a simple example sketch, you'll also find it in the examples/ folder

#include "run.h"
void toggle13(void) {
	digitalWrite(13, !digitalRead(13));
}
void toggle12(void) {
	digitalWrite(12, !digitalRead(12));
}
void setup(void) {
	pinMode(13, OUTPUT);
	run(toggle13, 100);		// call run() to run toggle13 every 100 ms

	pinMode(12, OUTPUT);
	run(toggle12, 125);		// call runner() to run toggle12 every 125 ms
}	
void loop(void) {
	runner();				// call runner() to run the function scheduler
}

*****/

#include "Arduino.h"

// call this from setup: run(myFunc, 100);
//
void run(void (*)(void), unsigned long);

// call snooze(millis) from your function to set a non-default run interval
void snooze(unsigned long);

// call this from loop: runner();
//
void runner(void);
