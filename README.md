# The Run Library

This is a little Arduino library that makes it easy to run several functions asynchronously
at specified intervals (like the Bitlash 'run' command).  Scheduling is non-preemptive
and round-robin, so your functions mustn't hog the CPU.  (Don't even think of calling 
delay(); that behavior is what this library is intended to extinguish.)

If you need to run more than 10 functions, increase NUMRUNS in run.cpp.

## Run Library API

There are three functions:

### run(function, interval)

- Schedules your C function to run at the given interval (in ms)
- Call this from setup()
- Your function must be declared to be of type void myFunc(void) (see toggle13 below)
- If interval is 0 your function is run 'as often as possible'
- Even magic can't make your 20 ms function run every 10 ms
- So, don't let your functions hog the CPU.
- Don't even think of calling delay()

### runner()

- Runs the scheduled functions
- Call this from loop() 

### snooze(interval)

- Call this from your C function to set a different function sleep interval (in ms)

## Example

This example sketch toggles pin 13 every 100ms and pin 12 every 125 ms.

You'll find it in the examples/run folder.


	#include "run.h"
	void toggle13(void) {
		digitalWrite(13, !digitalRead(13));
	}
	void toggle12(void) {
		digitalWrite(12, !digitalRead(12));
	}
	void setup(void) {
		pinMode(13, OUTPUT);
		run(toggle13, 100);		// call run() to schedule toggle13 every 100 ms
	
		pinMode(12, OUTPUT);
		run(toggle12, 125);		// call run() to schedule toggle12 every 125 ms
	}	
	void loop(void) {
		runner();				// call runner() to run the function scheduler
	}

