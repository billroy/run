/***
	run library - library to simulate the Bitlash "run func,interval" command

	This is the "run.ino" example.

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
