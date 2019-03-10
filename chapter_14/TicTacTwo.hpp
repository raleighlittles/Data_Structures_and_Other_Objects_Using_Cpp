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
        moves = 0;
        // TODO: Make sure not to check who last moved if the move count is 0
        set_all_elements_to_neutral();

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

        std::cout << "Current Game Status " << std::endl
        << std::string("=", 10) << std::endl;

        std::cout << "Human: " << this->human_score << " points"
        << "(" << WINNING_SCORE - this->human_score << " more to win )" << std::endl;

        std::cout << "Computer: " << this->computer_score << " points"
        << "(" <<  WINNING_SCORE - this->computer_score << " more to win )" << std::endl;

        std::cout << std::string("-", 10) << std::endl;
    }

    bool is_game_over() const override
    {
        // Count of the number of row-adjacent elements each user has and return true if it equals 4
        return (this->human_score == WINNING_SCORE) || (this->computer_score == WINNING_SCORE);
    }

    /
    bool is_legal(const std::string &move) const override
    {
        // Make sure the position (again in the same format as before) is not already
        // occupied

        //std::queue<std::string> unused;

        typedef std::queue<std::string> arg;

        //compute_moves(&&std::queue<std::string>());

        // compute_moves(static_cast<&std::queue<std::string>>(std::queue<std::string>()));

        // compute_moves(std::move(std::queue<std::string>()));

        /*
         * There's a good lesson about rvalues and lvalues in this next line.
         * Basically when a function is declared as:
         *
         *  void function(int& a);
         *
         *  That means the function is taking in a reference to an l-value. If you
         *  try to call this function using, for example, a constant integer, such as:
         *
         *  function(0);
         *
         *  then you'll get an error -- something along the lines of:
         *  " note: candidate function not viable: expects an l-value for 1st argument "
         *  or error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
         *
         *  Here, 0 is the rvalue type, and the error message is telling us that the function takes in a l-value
         *  reference, and in the case specifically of GCC, that it can't bind this rvalue into a non-const lvalue reference.
         *  This is reasonable, as it would cause issues if you could, as this would open up the possiblity of
         *  getting something weird like "0 == 1" (not going into it here, but you can see examples on Stack Overflow).
         *
         *  As a workaround, rvalue references were introduced in C++14. You could change your function's signature to
         *  be: void function(int&& a);  -- notice the double ampersands.
         *
         *  Then, function(0); will no longer generate a compiler error. Sweet!
         *
         *  The problem is that in this case, "compute_moves" was a function marked with override, and changing the
         *  calling signature (even if its just changing from an lvalue reference to an rvalue reference) would break
         *  compilation as it would no longer be overriding the virtual function in the parent class (technically these
         *  would be two different functions then!).
         *
         *  So, since I can't change the function signature to accept r-values, and given that I don't want to use the
         *  parameter to that function, what are my options?
         *
         *  Well, I could always just have instantiated a variable for that function parameter and called it "unused",
         *  or something, but that's no fun -- after all, why give a variable a name if it is unused? Furthermore worse
         *  yet, that potentially could have generated a warning about an unused variable -- or likely the compiler might
         *  have optimized it out.
         *
         *  But where's the fun in that?
         *
         */
        compute_moves (std::add_lvalue_reference<std::queue<std::string>>::type
                      ( std::forward<std::queue<std::string>>(std::queue<std::string>())));

        std::vector<std::pair<int, int>> available_moves = retrieve_neutral_coordinates();

        // convert the move into a pair of ints and make sure that pair is in the vector returned above

        std::istringstream iss(move);

       std::vector<int> raw_coordinates(( stoi(std::istream_iterator<std::string>(iss))),
                                                 stoi(std::istream_iterator<std::string>()));

        assert(raw_coordinates.size() == 2);

        std::pair<int, int> desired_coordinates_for_move = std::make_pair(raw_coordinates);

        return (std::find(available_moves.begin(), available_moves.end(), desired_coordinates_for_move) != -1);

    }

    who last_mover() const override
    {
        /* Remember that since the human moves first, and the starting move number is 0...
        then if the move count is an even number (greater than 0), it means the computer went on the last turn, or vice
         versa.

         Move # | Whose turn it is to move
         ---------------------------------
         0      | Human
         1      | Computer
         2      | Human
         3      | Computer

            (and so on..)
        */

        return (moves % 2 == 0) ? who::COMPUTER : who::HUMAN;
    }

    int moves_completed() const override
    {
        return moves;
    }

    who winning() const override
    {
        if (this->human_score > this->computer_score)
        {
            return who::HUMAN;

        }

        return who::COMPUTER;
    }

private:
    static const size_t BOARD_ROWS = 4;
    static const size_t BOARD_COLUMNS = BOARD_ROWS;
    static const uint8_t WINNING_SCORE = BOARD_COLUMNS;

    unsigned int human_score;
    unsigned int computer_score;
    unsigned int moves = 0;

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
    // read: http://boost.2283326.n4.nabble.com/multi-array-how-can-I-efficiently-have-a-column-selected-td2599360.html
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

        // TODO: Refactor the next 3 for loops (that handle row, column, diagonal scoring)

        for (std::size_t row_number = 0; row_number < BOARD_ROWS; row_number++)
        {
            row_or_column_type current_row_first_board = board1[boost::indices[row_number][range_type{ 0,
                                                                                           static_cast<int>(BOARD_ROWS )}]];

            row_or_column_type current_row_second_board = board2[boost::indices[row_number][range_type{ 0, static_cast<int>(BOARD_ROWS)}]];

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
            // I dont think you have to increment the number of entries each time
            row_or_column_type current_column_first_board = board1[boost::indices[range_type(0, BOARD_COLUMNS) ][column_number]];

            row_or_column_type current_column_second_board = board2[boost::indices[range_type(0, BOARD_COLUMNS) ] [column_number]];

            human_scores_per_board = {
                    std::count(current_column_first_board.begin(), current_column_first_board.end(), who::HUMAN),
                    std::count(current_column_second_board.begin(), current_column_second_board.end(), who::HUMAN)
            };

            computer_scores_per_board = {
                    std::count(current_column_first_board.begin(), current_column_first_board.end(), who::COMPUTER),
                    std::count(current_column_second_board.begin(), current_column_second_board.end(), who::COMPUTER)
            };

            if (*std::max_element(human_scores_per_board.begin(), human_scores_per_board.end()) > human_scores.second)
            {
                human_scores.second = *std::max_element(human_scores_per_board.begin(), human_scores_per_board.end());
            }

            if (*std::max_element(computer_scores_per_board.begin(), computer_scores_per_board.end()) > computer_scores.second)
            {
                computer_scores.second = *std::max_element(human_scores_per_board.begin(), human_scores_per_board.end());
            }

        }

        /* Wasn't able to figure out how to dynamically access the diagonal of a matrix using multi-array, so
         * I used a vector as a workaround */

        std::vector<who> diagonal_board1(BOARD_COLUMNS);

        std::vector<who> diagonal_board2(BOARD_COLUMNS);

        int i = -1;

        /* Remember that the "()" operator on a lambda is inherently const, so to capture a variable by-copy in a lambda
         * you must use the "mutable" lambda specifier : https://en.cppreference.com/w/cpp/language/lambda */
        std::generate(diagonal_board1.begin(), diagonal_board1.end(), [=]() mutable { return i++, board1[i][i]; });

        std::generate(diagonal_board2.begin(), diagonal_board2.end(), [=]() mutable { return i++, board2[i][i]; });


        human_scores_per_board = {
                std::count(diagonal_board1.begin(), diagonal_board1.end(), who::HUMAN),
                std::count(diagonal_board2.begin(), diagonal_board2.end(), who::HUMAN)
        };

        computer_scores_per_board = {
                std::count(diagonal_board1.begin(), diagonal_board1.end(), who::COMPUTER),
                std::count(diagonal_board2.begin(), diagonal_board2.end(), who::COMPUTER)
        };

        if (*std::max_element(human_scores_per_board.begin(), human_scores_per_board.end()) > human_scores.second)
        {
            human_scores.second = *std::max_element(human_scores_per_board.begin(), human_scores_per_board.end());
        }

        if (*std::max_element(computer_scores_per_board.begin(), computer_scores_per_board.end()) > computer_scores.second)
        {
            computer_scores.second = *std::max_element(human_scores_per_board.begin(), human_scores_per_board.end());
        }

        this->human_score = human_scores.second;
        this->computer_score = computer_scores.second;
        return { human_scores, computer_scores};
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
