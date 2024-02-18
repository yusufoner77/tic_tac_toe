#include <string>
#include <iostream>
#include "Rules.hpp"
#include "Board.hpp"

Rules::Rules(Board *inputted_board)
{
    board = inputted_board;
}

// Only inputs of 1-9 are acceptable

bool Rules::validate_input(int input)
{
    string current_mark = board->get_mark(input);
    if (input < 1 || input > 9 || current_mark != " ")
    {
      return false;
    }

    return true;
}

// The following functions check for three in a row and return X or O if its found. If not, it returns an underscore.

string Rules::three_in_a_row_in_the_top_row()
{
    if (board->get_mark(1) == board->get_mark(2) && board->get_mark(2) == board->get_mark(3) && board->get_mark(1) != " ")
    {
      return board->get_mark(1);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_middle_row()
{
    if (board->get_mark(4) == board->get_mark(5) && board->get_mark(5) == board->get_mark(6) && board->get_mark(4) != " ")
    {
      return board->get_mark(4);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_bottom_row()
{
    if (board->get_mark(7) == board->get_mark(8) && board->get_mark(8) == board->get_mark(9) && board->get_mark(7) != " ")
    {
      return board->get_mark(7);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_left_column()
{
    if (board->get_mark(1) == board->get_mark(4) && board->get_mark(4) == board->get_mark(7) && board->get_mark(1) != " ")
    {
      return board->get_mark(1);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_middle_column()
{
    if (board->get_mark(2) == board->get_mark(5) && board->get_mark(5) == board->get_mark(8) && board->get_mark(2) != " ")
    {
      return board->get_mark(2);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_right_column()
{
    if (board->get_mark(3) == board->get_mark(6) && board->get_mark(6) == board->get_mark(9) && board->get_mark(3) != " ")
    {
      return board->get_mark(3);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_left_diagonal()
{
    if (board->get_mark(1) == board->get_mark(5) && board->get_mark(5) == board->get_mark(9) && board->get_mark(1) != " ")
    {
      return board->get_mark(1);
    }
    else
    {
      return "_";
    }
}

string Rules::three_in_a_row_in_the_right_diagonal()
{
    if (board->get_mark(3) == board->get_mark(5) && board->get_mark(5) == board->get_mark(7) && board->get_mark(3) != " ")
    {
      return board->get_mark(3);
    }
    else
    {
      return "_";
    }
}

// returns false if any element in the array is not yet marked

bool Rules::is_board_full()
{
    for (int i = 1; i < 10; i++) {
      if (board->get_mark(i) == " ") {
        return false;
      }
    }

    return true;
}

// These conditions will end the game if they are true. Three in a row or a full board will end the game.

bool Rules::in_progress()
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

