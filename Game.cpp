#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;

Game::Game(Board *board_ptr, Rules *rules_ptr, ConsoleBoardCreator *creator_ptr)
{
    board = board_ptr;
    rules = rules_ptr;
    creator = creator_ptr;
}

void Game::switch_player()
{
    if (player_turn == 1) {
      player_turn = 2;
    }
    else if (player_turn == 2) {
      player_turn = 1;
    }
}

bool Game::three_in_a_row(string str) {
    return rules->three_in_a_row_in_the_top_row() == str ||
        rules->three_in_a_row_in_the_middle_row() == str ||
        rules->three_in_a_row_in_the_bottom_row() == str ||
        rules->three_in_a_row_in_the_left_column() == str ||
        rules->three_in_a_row_in_the_middle_column() == str ||
        rules->three_in_a_row_in_the_right_column() == str ||
        rules->three_in_a_row_in_the_left_diagonal() == str ||
        rules->three_in_a_row_in_the_right_diagonal() == str;
}

void Game::print_winner()
{
    if (three_in_a_row("X")) {
      cout << "The winner is Player 1!" << endl; 
    }

    if (three_in_a_row("O")) {
      cout << "The winner is Player 2!" << endl; 
    }

    if (rules->is_board_full() == true) {
      cout << "You've run out of room, this game is a draw!" << endl;
    }
}


void Game::start()
{
    string user_input = "";
    player_turn = 1;

    cout << "Welcome to Tic Tac Toe!\nThe goal is to get three in a row.\nPlayer 1 will be X's, and Player 2 will be O's" << endl;
    cout << "Here is a map of the cells:" << endl << endl << creator->print_map() << endl;

    while (rules->in_progress())
    {
      cout << endl;

      cout << creator->formatted_board();

      cout << endl << endl;

      if (player_turn == 1) {
        cout << "Player 1's turn: Which cell?  ";
        cin >> user_input;
        
        while (rules->validate_input(stoi(user_input)) == false) {
          cout << "Invalid input, please try again.  ";
          cin >> user_input;
        }

        board->make_move(stoi(user_input), 'X');
      }

      if (player_turn == 2) {
        cout << "Player 2's turn: Which cell?  ";
        cin >> user_input;

        while (rules->validate_input(stoi(user_input)) == false) {
          cout << "Invalid input, please try again.  ";
          cin >> user_input;
        }

        board->make_move(stoi(user_input), 'O');
      }

      switch_player();
    }

    print_winner();
}