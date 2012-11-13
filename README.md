# The Run Library

This is a little Arduino library that makes it easy to run several functions asynchronously
at specified intervals (like the Bitlash 'run' command).  Scheduling is non-preemptive
and round-robin, so your functions can't hog the CPU.  (Don't even think of calling 
delay(); that behavior is what this library is intended to extinguish.)

If you need more than 10 functions, increase NUMRUNS below.

## Functions

There are three functions:

- run(function, interval); schedules your C function to run at the given interval (in ms)

	Call this from setup()
	Your function must be declared to be of type void myFunc(void).

- runner(); runs the scheduled functions

	Call this from loop() 

- snooze(interval); call this to set a different task sleep interval (in ms)

## Example

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

