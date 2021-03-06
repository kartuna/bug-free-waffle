/*
 * Console.cpp
 */
#include "Console.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void Console::printBoard() const {
	//First row of the board
    cout << " ";
    for (int i = 1; i <= size_; i++) {
        cout << "| " << i << " ";
    }
    cout << "|" << endl;
    cout << string(size_ * 4 + 2, '-') << endl;
    //All other rows of the board
    for (int i = 0; i < size_; i++) {
        cout << i + 1;
        for (int j = 0; j < size_; j++) {
            cout << "| " << board_[i][j] << " ";
        }
        cout << "|" << endl;
        cout << string(size_ * 4 + 2, '-') << endl;
    }
}
