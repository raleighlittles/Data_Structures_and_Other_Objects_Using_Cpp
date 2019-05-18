//
// Created by raleigh on 1/4/19.
//

#ifndef CHAPTER_14_TICTACTWO_H
#define CHAPTER_14_TICTACTWO_H

#include <iostream>
#include <type_traits>
#include <utility>
#include <algorithm>

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
    static const int NUMBER_OF_ROWS = 4;
    static const int NUMBER_OF_COLUMNS = 4;
    /* 2-dimensional array to store 1st board information. */
    std::array<std::array<Game::who, NUMBER_OF_COLUMNS>, NUMBER_OF_ROWS> board1;
    /* 2-dimensional array to store 2nd board information. */
    std::array<std::array<Game::who, NUMBER_OF_COLUMNS>, NUMBER_OF_ROWS> board2;

    // CONSTRUCTOR . Follows convention from connect4.cxx
    TicTacTwo()
     : Game()
    {
        restart();
    }


protected:
    // *******************************************************************
    // VIRTUAL FUNCTIONS (these are overridden from the game base class)
    // *******************************************************************
    // Return a pointer to a copy of myself:
     Game* clone( ) const override
    {
        return new TicTacTwo(*this);
    }

    // Compute all the moves that the next player can make:
     void compute_moves(std::queue<std::string>& moves) const override;
    // Display the status of the current game:
     void display_status( ) const override;
    // Evaluate the current board position.
    // NOTE: Positive values are good for the computer.
     int evaluate( ) const override;
    // Return true if the current game is finished:
    bool is_game_over( ) const override;
    // Return true if the given move is legal for the next player:
    bool is_legal(const std::string& move) const override;
    // Have the next player make a specified move:
    void make_move(const std::string& move) override;
    // Restart the game from the beginning:
    void restart( ) override;


};

#endif //CHAPTER_14_TICTACTWO_H
