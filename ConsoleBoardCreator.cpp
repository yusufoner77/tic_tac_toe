#include <string>
#include "ConsoleBoardCreator.hpp"
#include "Board.hpp"

using namespace std;

Board *board;

ConsoleBoardCreator::ConsoleBoardCreator(Board *inputted_board)
{
    board = inputted_board;
}  

// These functions break up the creation of the board into rows and lines so it's not one huge string.

string ConsoleBoardCreator::make_line()
{
    return "\n-----------\n";
}

string ConsoleBoardCreator::first_row()
{
    return " " + board->get_mark(1) + " | " + board->get_mark(2) + " | " + board->get_mark(3) + " ";
}

string ConsoleBoardCreator::second_row()
{
    return " " + board->get_mark(4) + " | " + board->get_mark(5) + " | " + board->get_mark(6) + " ";
}

string ConsoleBoardCreator::third_row()
{
    return " " + board->get_mark(7) + " | " + board->get_mark(8) + " | " + board->get_mark(9) + " "; 
}

// This function actually creates the board the players are using

string ConsoleBoardCreator::formatted_board()
{
    return first_row() + make_line() + second_row() + make_line() + third_row();
}

// This prints a board containing the cell numbers for the players at the start of a game

string ConsoleBoardCreator::print_map()
{
    return " 1 | 2 | 3 " + make_line() + " 4 | 5 | 6 " + make_line() + " 7 | 8 | 9 ";
}