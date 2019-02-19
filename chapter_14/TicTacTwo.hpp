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

protected:
    void make_move(const std::string &move) override
    {
        // Moves are space-separated coordinates in the form "r c" where
        // r and c are the row and column positions that the user wants to place
        // their symbol on

        // TODO: Extract this into its own function
        std::istringstream iss(move);

        std::vector<std::string> raw_coordinates(( std::istream_iterator<std::string>(iss)),
                                                std::istream_iterator<std::string>());

        assert(raw_coordinates.size() == 2);

        std::pair<int, int> new_coordinates = std::make_pair<int, int>(stoi(raw_coordinates[0]),
                                                                        stoi(raw_coordinates[1]));

        std::pair<int, int> converted_coordinates = convert_coordinates(new_coordinates.first, new_coordinates.second);

        // Find out whoever's turn it is and get their symbol

        who mover = current_mover();

        // Take their requested coordinates, mark it on both boards

        board1[new_coordinates.first][new_coordinates.second] = mover;

        board1[converted_coordinates.first][new_coordinates.second] = mover;
    }

    void restart() override
    {
        // Reset move number to 0
        // set_all_elements_to_neutral()
    }

    TicTacTwo* clone() const override
    {
        // Use the copy constructor to create a new Game object
        // return pointer to it
    }

    void compute_moves(std::queue<std::string> &moves) const override
    { // The parameter for this function seems kind of useless ; I don't understand why it was used
        // Examine the first board to see which positions are not occupied

        retrieve_neutral_coordinates();

    }

    void display_status() const override
    {
        // Print out the number of row-adjacent (meaning either in a row, column,
        // or diagonal) elements each user has on both boards
    }

    bool is_game_over() const override
    {
        // Count of the number of row-adjacent elements each user has and return true if it equals 4
    }

    bool is_legal(const std::string &move) const override
    {
        // Make sure the position (again in the same format as before) is not already
        // occupied

        compute_moves(/* put the correct type in here */);

        std::vector<std::pair<int, int>> available_moves = retrieve_neutral_coordinates();

        // convert the move into a pair of ints and make sure that pair is in the vector returned above

    }

    who last_mover() const override
    {

    }

    int moves_completed() const override
    {

    }

    who winning() const override
    {

    }

private:
    static const size_t BOARD_ROWS = 4;
    static const size_t BOARD_COLUMNS = BOARD_ROWS;
    static const uint8_t WINNING_SCORE = 4;
    using array_type_2D = boost::multi_array<who, 2>;
    using array_type_2D_index = array_type_2D::index;

    array_type_2D board1;
    array_type_2D board2;

    //boost::multi_array<who, 2> board1;
    //boost::multi_array<who, 2> board2;

    // array_type_2D board1(boost::extents[BOARD_ROWS][BOARD_COLUMNS]);

    void initialize_array()
    {
        //boost::array < boost::multi_array<who, 2>::index, 2 > dimensions = {{BOARD_ROWS, BOARD_COLUMNS}};

        // board1.reshape(dimensions);

        array_type_2D board1(boost::extents[BOARD_ROWS][BOARD_COLUMNS]);

        array_type_2D board2(boost::extents[BOARD_ROWS][BOARD_COLUMNS]);

        //board1.reshape(boost::extents[BOARD_ROWS][BOARD_COLUMNS]);

        //board2.reshape(boost::extents[BOARD_ROWS][BOARD_COLUMNS]);

        // board2.reshape(dimensions);
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

        // TODO: assert that board_1 coordinates in valid range

        // can only switch on integer-evaluable type
        switch (board_1_coordinates.first)
        {
            case (1):
            {
                switch (board_1_coordinates.second)
                { // coordinates are in (row, column) layout
                    case (1) : return std::make_pair(3, 4); break;

                    case (2): return std::make_pair(1, 1); break;

                    case (3) : return std::make_pair(2, 3); break;

                    case (4) : return std::make_pair(4, 2); break;

                    // TODO: Change this to the correct error
                    default: exit(1);
                }

            }

            case(2):
            {
                switch (board_1_coordinates.second)
                {
                    case (1): return std::make_pair(2, 2); break;

                    case (2):  return std::make_pair(4, 3); break;

                    case (3): return std::make_pair(3, 1); break;

                    case (4) : return std::make_pair(1, 4); break;

                        // TODO: Change this to the correct error
                    default: exit(1);
                }
            }

            case (3):
            {
                // TODO: Put switch statement here

                switch (board_1_coordinates.second)
                {
                    case (1) : return std::make_pair(4, 1); break;

                    case (2) : return std::make_pair(2, 4); break;

                    case (3) : return std::make_pair(1, 2); break;

                    case (4) : return std::make_pair(3, 3); break;

                    default: exit(1);
                }

            }


            case (4):
            {
                // TODO: Put switch statement here

                switch(board_1_coordinates.second)
                {
                    case (1) : return std::make_pair(1, 3); break;

                    case (2) : return std::make_pair(3, 2); break;

                    case (3) : return std::make_pair(4, 4); break;

                    case (4) : return std::make_pair(2, 1); break;

                    default: exit(1);
                }
            }

            default:
            {

                exit(1);
            }
        }

    }

    // TODO: Add copy-constructor

    // read: https://theboostcpplibraries.com/boost.multiarray
    std::vector<std::pair<who, int>> compute_scores()
    { // Computes the scores for each player

        // For each row, column, and the two diagonals..
        // count the number of entries by each player -- the maximum of these is their score

        std::vector<std::pair<who, int>> scores;


         typedef boost::multi_array<who, BOARD_ROWS>::array_view<1>::type row_or_column_type;
         typedef boost::multi_array_types::index_range range_type;

         std::pair<who, int> human_scores = std::make_pair<who, int>(who::HUMAN, 0);
        std::pair<who, int> computer_scores = std::make_pair<who, int>(who::COMPUTER, 0);

        std::array<long, 2> human_scores_per_board;
        std::array<long, 2> computer_scores_per_board;

        // TODO: Refactor the next two for loops

        for (std::size_t row_number = 0; row_number < BOARD_ROWS; row_number++)
        {
            row_or_column_type current_row_first_board = board1[boost::indices[row_number][range_type{ static_cast<int>(BOARD_ROWS * row_number), static_cast<int>(BOARD_ROWS * row_number + 3)}]];

            row_or_column_type current_row_second_board = board2[boost::indices[row_number][range_type{ static_cast<int>(BOARD_ROWS * row_number), static_cast<int>(BOARD_ROWS * row_number + 3)}]];

             human_scores_per_board =  {
                    std::count(current_row_first_board.begin(), current_row_first_board.end(), who::HUMAN),
                    std::count(current_row_second_board.begin(), current_row_second_board.end(), who::HUMAN) };


            computer_scores_per_board = {
                    std::count(current_row_first_board.begin(), current_row_first_board.end(), who::COMPUTER),
                    std::count(current_row_second_board.begin(), current_row_second_board.end(), who::COMPUTER) };

            if (*std::max_element(human_scores_per_board.begin(), human_scores_per_board.end()) > human_scores.second)
            {
                human_scores.second = *std::max_element(human_scores_per_board.begin(), human_scores_per_board.end());
            }

            if (*std::max_element(computer_scores_per_board.begin(), computer_scores_per_board.end()) > computer_scores.second)
            {
                computer_scores.second = *std::max_element(human_scores_per_board.begin(), human_scores_per_board.end());
            }
        }

        for (std::size_t column_number = 0; column_number < BOARD_COLUMNS; column_number++ )
        {

            // same thing as row
        }

        // For the diagonal case, iterate 


        scores = { human_scores, computer_scores};
        return scores;
    }

    /*
     * @brief Returns coordinates that are available (on the first board)
     */
    std::vector<std::pair<int, int>> retrieve_neutral_coordinates() const
    {
        std::vector<std::pair<int, int>> neutral_coordinates;

        for (std::size_t row = 0; row < board1.shape()[0]; row++)
        {
            for (std::size_t column = 0; column < board1.shape()[1]; column++)
            {
                if (board1[row][column] == who::NEUTRAL)
                {
                    neutral_coordinates.emplace_back(std::make_pair<int, int>(row, column));
                }
            }
        }

        return neutral_coordinates;
    }


    who current_mover()
    {
        return (last_mover() == who::HUMAN) ? who::COMPUTER : who::HUMAN;
    }




};

#endif //CHAPTER_14_TICTACTWO_H
