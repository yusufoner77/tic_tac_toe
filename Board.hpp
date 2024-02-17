#include <string>
#include <array>
#pragma once

using namespace std;

class Board
{
public:
array<string, 9> board;

Board();
void make_move(int cell, char mark);
string get_mark(int cell);
};