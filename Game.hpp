#include <string>
#include "Rules.hpp"
#include "Board.hpp"
#include "ConsoleBoardCreator.hpp"
using namespace std;
#pragma once

class Game
{
private:
  Board *board;
  Rules *rules;
  ConsoleBoardCreator *creator;
  int player_turn;

public:
  Game(Board *board_ptr, Rules *rules_ptr, ConsoleBoardCreator *creator_ptr);
  void switch_player();
  void print_winner();
  bool three_in_a_row(string str);
  void start();
};