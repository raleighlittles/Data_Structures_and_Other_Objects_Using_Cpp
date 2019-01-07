//
// Created by raleigh on 1/4/19.
//

#ifndef CHAPTER_14_TICTACTWO_H
#define CHAPTER_14_TICTACTWO_H

#include "game.h"
#include "boost/multi_array.hpp"

/*
 Problem statement

 Tic-Tac-Twice is a game invented by Pat
Baggett and Andrzej Ehrenfeucht. It is
distributed by the Aristoplay company. The
rules are simple, starting with two 4x4 boards that
each have a pattern of 16 letters (or other objects). If
you use the letters A through P, then the two boards
have these patterns:
Board 1
Board 2
8
A B C D B K M H
E F G H P E C J
I J K L G N L A
M N O P I D F O
The two players (human and computer) take alter-
nate turns. During your turn, you can place a checker
of your color on an empty spot on Board 1. At the
same time, you put a checker of your color on the
square in Block 2 with the same letter. For example,
if you put your checker in the bottom-left corner of
Board 1 (letter M), then you would simultaneously
put one of your checkers on the third spot of the top
row of Board 2 (also letter M).
You win the game by having four of your circles
in a row (horizontally, diagonally, or vertically) on
either of the boards. Note that you don’t need four in
a row on both boards, just on one of them.
Implement a class that lets a user play Tic-
Tac-Twice against the computer. Use the game class
from Section 14.3 as your base class.

 */
class TicTacTwo : public Game
{
public:
    TicTacTwo()
    {

        initialize_array();

        set_all_elements_to_neutral();

    }


private:
    static const size_t BOARD_ROWS = 4;
    static const size_t BOARD_COLUMNS = 4;

    boost::multi_array<who, 2> board1;
    boost::multi_array<who, 2> board2;

    void initialize_array()
    {
        boost::array < boost::multi_array<who, 2>::index, 2 > dimensions = {{BOARD_ROWS, BOARD_COLUMNS}};

        board1.reshape(dimensions);

        board2.reshape(dimensions);
    }

    void set_all_elements_to_neutral()
    {
        assert(board1.shape() == board2.shape());

        for (std::size_t row = 0; row < board1.shape()[0]; row++)
        {
            for (std::size_t column = 0; column < board1.shape()[1]; column++)
            {
                board1[row][column] = who::NEUTRAL;
                board2[row][column] = who::NEUTRAL;
            }
        }

    }

    std::pair<int, int> convert_coordinates(int row, int column)
    { // TODO: Refactor this
        auto board_1_coordinates = std::make_pair(row, column);

        // TODO: assert that board_1 coordainates in valid range

        // can only switch on integer-evaluable type
        switch (board_1_coordinates.first)
        {
            case (1):
            {

                if (board_1_coordinates.second == 1)
                {
                    // (1,1) maps to (3,4)
                    return std::make_pair(3, 4);
                }

                else if (board_1_coordinates.second == 2)
                {
                    // (1,2) maps to (1,1)
                    return std::make_pair(1,1);
                }

                else if (board_1_coordinates.second == 3)
                {
                    // (1,3) maps to (2,3)
                    return std::make_pair(2,3);
                }

                else if (board_1_coordinates.second == 4)
                {
                    // (1,4) maps to (4,2)
                    return std::make_pair(4,2);
                }

            }

            case(2):
            {
                if (board_1_coordinates.second == 1)
                {
                    // (2,1) maps to (2,2)
                    return std::make_pair(2,2);
                }

                else if (board_1_coordinates.second == 2)
                {
                    // (2,2) maps to (4,3)
                    return std::make_pair(2,3);
                }

                else if (board_1_coordinates.second == 3)
                {
                    // (2,3) maps to (3,1)
                    return std::make_pair(3,1);
                }

                else if (board_1_coordinates.second == 4)
                {
                    // (2,4) maps to (1,4)
                    return std::make_pair(1,4);
                }
            }

            case (3):
            {
                // TODO: Put switch statement here
            }


            case (4):
            {
                // TODO: Put switch statement here
            }

            default:
            {

                break;
            }
        }

    }



};

#endif //CHAPTER_14_TICTACTWO_H
