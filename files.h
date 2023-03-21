#pragma once

#include<iostream>
#include<string>
using namespace std;

#include <fstream>
#include <windows.h>

#undef max

void _cls() {
	system("cls");
}

void _load(bool x) { // If true it will create else it will delete.
	_cls();
	if (x) {
		cout << "Creating file";
	}
	else if (!x) {
		cout << "Deleting file";
	}
	for (short i = 0; i < 3; i++) {
		cout << ".";
		Sleep(500);
	}
	if (x) {
		_cls();
		cout << "File successfully created!\n";
	}
}

void _remFile() {
	_load(false);
	_cls();
	// Attempt to delete the file
	if (remove("config.txt") != 0) {
		cerr << "Error deleting file!\n";
	}
	else {
		cout << "File successfully deleted!\n";
	}
}

bool _isGud(short num) {
	if (cin.fail()) {
		// Input could not be interpreted as a short.
		return false;
	}
	else {
		// Input is a valid short.
		return true;
	}
}

void _cinFlush() {
	cin.clear(); // Clears any error flags in the input stream.
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores all characters up until the newline character.

}

void _ask() {
start:
	_cls();
	short choice = 0;
	cout << "Would you like to terminate program to fix issue yourself or would you rather have the program handle it?\n";
	cout << "1) Handle it myself.\n2) Let the program handle it.\n~> ";
	cin >> choice;
	if (!_isGud(choice)) {
		goto bad;
	}
	if (choice == 1) {
		exit(choice); // Failure.
	}
	else if (choice == 2) {
		return;
	}
	else {
	bad:
		cout << "Sorry that input is invalid, try again...\n"; _cinFlush();
	}
	goto start;
}

void saveConf(short x = 0) {
	fstream file;
	file.open("fileName.txt", ios::out);
	if (file.is_open()) {
		file << "The value of \"X\" is = " << x << ";" << endl;
		// For user info: 
		file << "\n#######################\n";
		file << "\nThis is supposed to be the Documentation area\n";
		file.close();
	}
}

void loadConf(short& x) {
	// Extra simple algorithm to seperate variable values from other characters.
	string n = "", line = "";
	short count = 0;
	bool error = false, check = false;
	fstream file;
	file.open("fileName.txt", ios::in);

	// Filling up the lines.
	if (file.is_open()) {
		while (getline(file, line)) {
			for (char c : line) {
				if (isdigit(c)) {
					if (count == 1) {
						n += c;
					}
				}
				else { // Simple checking for formatting of values...
					if (c == '=') {
						count++;
						check = true;
					}
					else if (c == ';') {
						check = false;
					}
					else if (c == '#') {
						goto end;
					}
					if (check && c != ' ' && c != '=') {
						error = true;
						cout << "Error: One or more values in the config file are invalid.\n"; goto err;
					}
				}
			}
		}
	end:

		// Check to see if values are valid:
		// X check (if X has to be between 0 and 3:
		if ((stoi(n) < 0) || (stoi(n) > 3)) {
			error = true;
			cout << "Error: One or more values in the config file are invalid.\n"; goto err;
		}

		// Simple conversion of the filtered digit string into integer.
		x = stoi(n); // StringToInteger.
		file.close();
	}
	else {
		cout << "Error: Config file not found in the current directory,\ncreating a new one with default values.\n";
	err:
		file.close();
		if (error) {
			_ask();
			_remFile();
		}
		_load(true);
		saveConf(x);
	}
}