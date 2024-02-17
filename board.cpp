#include <iostream>
#include <array>
#include <string>
#include "Board.hpp"

using namespace std;

Board::Board() {
    for (int i = 0; i < 9; i++) {
      board[i] = ' ';
    }
}

void Board::make_move(int cell, char mark) {
    board[cell - 1] = mark;
  }

string Board::get_mark(int cell)
  {
    return board[cell - 1];
  }
