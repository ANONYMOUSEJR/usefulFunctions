#pragma once

#include<iostream>
#include<string>
using namespace std;

// For times:
#include <chrono>
#include <thread>
#include <windows.h>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// For formatting:
#include <iomanip>
// EXAMPLE: file << setw(20) << "Scrolling effect = " << spd << ";" << endl;

void cls() {
	system("cls");
}

void print(string txt, short spd) {
	short x = 0;
	// Prints out the words letter-by-letter until the end character '\0'. 
	while (txt[x] != '\0') {
		cout << txt[x];
		sleep_for(milliseconds(spd)); // spd default is '1'.
		x++;
	}
}


void pause() {
	sleep_for(milliseconds(350)); cout << ".";
	sleep_for(milliseconds(350)); cout << ".";
	sleep_for(milliseconds(350)); cout << ".";
	sleep_for(milliseconds(350)); cout << endl;
}

void _pause(short x) {
	for (short i = 0; i < x; i++) {
		cout << "Waiting for " << (x - i) << " seconds.";
		Sleep(1000);
		cout << "\r"; // Moves cursor to the beginning of the line, effectiveley clearing it.
	}
}