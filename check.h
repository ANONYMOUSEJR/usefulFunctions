#pragma once

#include<iostream>

using namespace std;

#undef max// This somehow fixes an error code that could come from "max()" in the cin.ignore function, 
// Here's where I got it from: [https://stackoverflow.com/a/21959303].

bool isGud(short num) {
	if (cin.fail()) {
		// Input could not be interpreted as a short.
		return false;
	}
	else {
		// Input is a valid short.
		return true;
	}
}

// Clears out a potentially corrupted cin.
void cinFlush() {
	cin.clear(); // Clears any error flags in the input stream.
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores all characters up until the newline character.
}

