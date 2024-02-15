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
    // We need to ask the Board object if there are any spaces still open.
    // We also need to check if there a winner - three in a row, vertical, horizontal, or diagonal.
    // The code below is a partial implementation where we check for three in a row in the top row.
 

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

public:
  Game(Board *board_ptr, Rules *rules_ptr, ConsoleBoardCreator *creator_ptr)
  {
    board = board_ptr;
    rules = rules_ptr;
    creator = creator_ptr;
  }

  void start()
  {
    string user_input = "";

    while (rules->in_progress())
    {
      cout << creator->formatted_board();
      cout << "Which cell?" << endl;
      cin >> user_input;
      board->make_move(stoi(user_input), 'X');
    }
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
