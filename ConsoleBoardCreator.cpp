#include <string>
#include "ConsoleBoardCreator.hpp"
#include "Board.hpp"

using namespace std;

Board *board;

ConsoleBoardCreator::ConsoleBoardCreator(Board *inputted_board)
{
    board = inputted_board;
}  

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

string ConsoleBoardCreator::formatted_board()
{
    return first_row() + make_line() + second_row() + make_line() + third_row();
}

string ConsoleBoardCreator::print_map()
{
    return " 1 | 2 | 3 " + make_line() + " 4 | 5 | 6 " + make_line() + " 7 | 8 | 9 ";
}