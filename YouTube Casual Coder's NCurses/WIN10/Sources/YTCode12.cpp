/*
* Ncurses Tutorial 12 - 'chtype' (In-depth), & Extracting Attributes/Colors
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void chtypeBits64(chtype ch) {
	cout <<
		bitset<48>(ch >> 16) << ' ' <<
		bitset<8>(ch >> 8) << ' ' <<
		bitset<8>(ch) << endl;
}

void attrBits64(attr_t attr) {
	cout <<
		bitset<48>(attr >> 16) << ' ' <<
		bitset<8>(attr >> 8) << ' ' <<
		bitset<8>(attr) << endl << endl;
}

int main(int argc, char** argv)
{
	// Start ncurses
	initscr();
	if (has_colors() == FALSE) {
		endwin();
		printf("Color can't be used.");
		return -1;
	}
	
	start_color();

	// Define 2 color_pairs
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	endwin();

	char c = 'A';
	const int size_c = sizeof(c);
	
	cout << string(66, 's') << endl;
	cout.width(66);
	cout << right << "Type: char | sizeof(char) = 1 byte = 8 bits" << endl;
	cout << string(66, '-') << endl;

	cout.width(58);
	cout << right << ' ';
	cout << right <<
		bitset<8>(c) << endl;

	cout.width(58);
	cout << right << ' ';
	cout.width(3);
	cout << left << "Text" << endl << endl;

	cout << string(66, '=') << endl;

	chtype ch = 'A' | A_REVERSE | COLOR_PAIR(1);
	const int size_ch = sizeof(ch);

	cout.width(66);
	cout << right << "Type: chtype | sizeof(chartype) = 8 byte = 64 bits" << endl;
	cout << string(66, '-') << endl;

	chtypeBits64(ch);

	cout.width(49);
	cout << left << "Attributes";
	cout.width(9);
	cout << left << "Colors";
	cout.width(9);
	cout << left << "Text" << endl << endl;

	cout << string(66, '=') << endl;

	cout.width(66);
	cout << right << "A_CHARTEXT" << endl;
	cout << string(66, '-') << endl;
	attrBits64(A_CHARTEXT);

	cout << string(66, '=') << endl;

	cout.width(66);
	cout << right << "A_COLOR" << endl;
	cout << string(66, '-') << endl;
	attrBits64(A_COLOR);

	cout << string(66, '=') << endl;

	cout.width(66);
	cout << right << "A_ATTRIBUTES" << endl;
	cout << string(66, '-') << endl;
	attrBits64(A_ATTRIBUTES);

	#define A_ATTRS (A_ATTRIBUTES ^ A_COLOR)

	cout << string(66, '=') << endl;

	cout.width(66);

	cout.width(66);
	cout << right << "A_ATTRS" << endl;
	cout << string(66, '-') << endl;
	attrBits64(A_ATTRS);

	return 0;
}