#include <iostream>
#include <array>
#include <cassert>
#include <string>

using namespace std;

class Board
{
  array<string, 9> board;

public:
  Board()
  {
    for (int i = 0; i < 9; i++)
    {
      board[i] = '_';
    }
  }

  void make_move(int cell, char mark)
  {
    board[cell - 1] = mark;
  }

  string get_mark(int cell)
  {
    return board[cell - 1];
  }
};

class ConsoleBoardCreator
{
  Board *board;

private:
  string make_line()
  {
    return "\n-----------\n";
  }

  string first_row()
  {
    return " " + board->get_mark(1) + " | " + board->get_mark(2) + " | " + board->get_mark(3) + " ";
  }

  string second_row()
  {
    return " " + board->get_mark(4) + " | " + board->get_mark(5) + " | " + board->get_mark(6) + " ";
  }

  string third_row()
  {
    return " " + board->get_mark(7) + " | " + board->get_mark(8) + " | " + board->get_mark(9) + " "; 
  }

  

public:
  ConsoleBoardCreator(Board *inputted_board)
  {
    board = inputted_board;
  }

  string formatted_board()
  {
    // This implementation is incomplete. Make sure you fill in the rest! It would also help to break this long string up using some private methods.
    return first_row() + make_line() + second_row() + make_line() + third_row();
  }

  string print_map()
  {
    return " 1 | 2 | 3 " + make_line() + " 4 | 5 | 6 " + make_line() + " 7 | 8 | 9 ";
  }
};

class Rules
{
  Board *board;

public:
  Rules(Board *inputted_board)
  {
    board = inputted_board;
  }

  bool validate_input(int input)
  {
    string current_mark = board->get_mark(input);
    if (input < 1 || input > 9 || current_mark != "_")
    {
      return false;
    }

    return true;
  }

  bool in_progress()
  {

    if (three_in_a_row_in_the_top_row() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_middle_row() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_bottom_row() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_left_column() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_middle_column() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_right_column() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_left_diagonal() != "_")
    {
      return false;
    }

    if (three_in_a_row_in_the_right_diagonal() != "_")
    {
      return false;
    }

    if (is_board_full() == true)
    {
      return false;
    }

    return true;
  }

  bool is_board_full()
  {
    for (int i = 1; i < 10; i++) {
      if (board->get_mark(i) == "_") {
        return false;
      }
    }

    return true;
  }

  string three_in_a_row_in_the_top_row()
  {
    if (board->get_mark(1) == board->get_mark(2) && board->get_mark(2) == board->get_mark(3) && board->get_mark(1) != "_")
    {
      return board->get_mark(1);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_middle_row()
  {
    if (board->get_mark(4) == board->get_mark(5) && board->get_mark(5) == board->get_mark(6) && board->get_mark(4) != "_")
    {
      return board->get_mark(4);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_bottom_row()
  {
    if (board->get_mark(7) == board->get_mark(8) && board->get_mark(8) == board->get_mark(9) && board->get_mark(7) != "_")
    {
      return board->get_mark(7);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_left_column()
  {
    if (board->get_mark(1) == board->get_mark(4) && board->get_mark(4) == board->get_mark(7) && board->get_mark(1) != "_")
    {
      return board->get_mark(1);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_middle_column()
  {
    if (board->get_mark(2) == board->get_mark(5) && board->get_mark(5) == board->get_mark(8) && board->get_mark(2) != "_")
    {
      return board->get_mark(2);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_right_column()
  {
    if (board->get_mark(3) == board->get_mark(6) && board->get_mark(6) == board->get_mark(9) && board->get_mark(3) != "_")
    {
      return board->get_mark(3);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_left_diagonal()
  {
    if (board->get_mark(1) == board->get_mark(5) && board->get_mark(5) == board->get_mark(9) && board->get_mark(1) != "_")
    {
      return board->get_mark(1);
    }
    else
    {
      return "_";
    }
  }

  string three_in_a_row_in_the_right_diagonal()
  {
    if (board->get_mark(3) == board->get_mark(5) && board->get_mark(5) == board->get_mark(7) && board->get_mark(3) != "_")
    {
      return board->get_mark(3);
    }
    else
    {
      return "_";
    }
  }
};

class Game
{
private:
  Board *board;
  Rules *rules;
  ConsoleBoardCreator *creator;
  int player_turn;

public:
  Game(Board *board_ptr, Rules *rules_ptr, ConsoleBoardCreator *creator_ptr)
  {
    board = board_ptr;
    rules = rules_ptr;
    creator = creator_ptr;
  }

  void switch_player()
  {
    if (player_turn == 1) {
      player_turn = 2;
    }
    else if (player_turn == 2) {
      player_turn = 1;
    }
  }

  void print_winner()
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

  bool three_in_a_row(string str) {
    return rules->three_in_a_row_in_the_top_row() == str ||
        rules->three_in_a_row_in_the_middle_row() == str ||
        rules->three_in_a_row_in_the_bottom_row() == str ||
        rules->three_in_a_row_in_the_left_column() == str ||
        rules->three_in_a_row_in_the_middle_column() == str ||
        rules->three_in_a_row_in_the_right_column() == str ||
        rules->three_in_a_row_in_the_left_diagonal() == str ||
        rules->three_in_a_row_in_the_right_diagonal() == str;
  }

  void start()
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
};

int main()
{
  Board board;
  Board *board_ptr = &board;

  ConsoleBoardCreator creator = ConsoleBoardCreator(board_ptr);
  ConsoleBoardCreator *creator_ptr = &creator;

  Rules rules = Rules(board_ptr);
  Rules *rules_ptr = &rules;

  Game game = Game(board_ptr, rules_ptr, creator_ptr);
  game.start();

  return 0;
}
