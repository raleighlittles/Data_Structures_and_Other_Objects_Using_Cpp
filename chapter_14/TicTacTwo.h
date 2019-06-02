#ifndef CHAPTER_14_TICTACTWO_H
#define CHAPTER_14_TICTACTWO_H

#include <array>
#include <string>
#include <queue>

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
    Board 1      Board 2

    A B C D      B K M H
    E F G H      P E C J
    I J K L      G N L A
    M N O P      I D F O
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
    static const int BOARD_DIMENSIONS = 2;
    inline static const std::string human_player_representation = "X";
    inline static const std::string computer_player_representation = "O";

    using board_type = std::array<std::array<Game::who, NUMBER_OF_COLUMNS>, NUMBER_OF_ROWS>;

    using coordinate_type = std::pair<unsigned int, unsigned int>;

    /* 2-dimensional array to store 1st board information. */
    board_type board1;
    /* 2-dimensional array to store 2nd board information. */
    board_type board2;

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

private:
    // Helper functions

    auto get_row(uint row_index) const;

    auto get_column(uint column_index) const;

    auto get_diagonal(uint diagonal_index) const;

    bool is_section_won(std::pair<std::array<Game::who, NUMBER_OF_COLUMNS>,
            std::array<Game::who, NUMBER_OF_COLUMNS>>  section) const;

    void neutralize_boards();

    coordinate_type convert_move_input_to_coordinates(const std::string& space_separated_move) const;

    coordinate_type convert_coordinates_from_first_board_to_second_board(unsigned int row, unsigned int column);

    // Functions specifically for searching for best move

    coordinate_type minimax(board_type board1, board_type board2, Game::who player, unsigned int depth, int alpha, int beta);

    std::pair<int, int> score_boards(board_type board1, board_type board2, Game::who player) const;

    /* Remember that if a section contains more than one player in that section, its unwinnable */
    bool is_more_than_one_player_in_section(std::array<Game::who, NUMBER_OF_ROWS> section) const;

    bool is_section_empty(std::array<Game::who, NUMBER_OF_ROWS> section) const;


    std::size_t score_section(std::array<Game::who, NUMBER_OF_ROWS> section, Game::who player) const;




};

#endif //CHAPTER_14_TICTACTWO_H
