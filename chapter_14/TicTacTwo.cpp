#include <queue>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>


#include "TicTacTwo.h"

// ********************
// HELPER FUNCTIONS
// ********************

/**
 * Returns a pair of arrays, representing the row of the first and second boards.
 * @param row_index
 * @return
 */
auto TicTacTwo::get_row(uint row_index) const
{
    // Outer index is rows, inner index is columns
    return std::make_pair(board1[row_index], board2[row_index]);
}

/**
 * Returns a pair of arrays, representing the column of the first and second boards.
 * @param column_index
 * @return
 */
auto TicTacTwo::get_column(uint column_index) const
{
    std::array<Game::who, NUMBER_OF_ROWS> column_on_first_board;
    std::array<Game::who, NUMBER_OF_ROWS> column_on_second_board;

    for (unsigned int row_index = 0; row_index < NUMBER_OF_ROWS; row_index ++)
    {
        column_on_first_board[row_index] = board1[row_index][column_index];
        column_on_second_board[row_index] = board2[row_index][column_index];
    }

    return std::make_pair(column_on_first_board, column_on_second_board);
}


/**
 * @brief Returns a pair of arrays, representing the diagonal of the first and second boards.
 * @return
 */
auto TicTacTwo::get_diagonal() const
{ // Remember diagonal entries in a square matrix are entries such that the row and column are the same.

    std::array<Game::who, NUMBER_OF_ROWS> diagonal_of_first_board;
    std::array<Game::who, NUMBER_OF_ROWS> diagonal_of_second_board;

    for (unsigned int index = 0; index < NUMBER_OF_ROWS; index++)
    {
        diagonal_of_first_board[index] = board1[index][index];
        diagonal_of_second_board[index] = board2[index][index];
    }

    return std::make_pair(diagonal_of_first_board, diagonal_of_second_board);
}

/**
 * @brief Checks if there's a winner in any of a row, column, or diagonal.
 *
 * @warning Requires that the winning score is equivalent to the board size.
 *
 * @param section[in] A pair of arrays. Array can represent any of: a row, column, or diagonal. First element in pair
 *                    represents the first board, second element in pair represents the second board.
 * @return
 */
bool TicTacTwo::is_section_won(std::pair<std::array<Game::who, NUMBER_OF_COLUMNS>,
        std::array<Game::who, NUMBER_OF_COLUMNS>>  section) const
{
    /* Remember that if all the elements in the array are equivalent to one element in the array, then the entire array
     * is occupied by the same value. */

    return std::all_of(section.first.begin(), section.first.end(),
                       [&](auto element)
                       {
                           return element == section.first.front();
                       }) and
           std::all_of(section.second.begin(), section.second.end(),
                       [&](auto element)
                       {
                           return element == section.second.back();
                       });
}

/**
 *  @brief Set all elements in array to be neutral
 */
void TicTacTwo::neutralize_boards()
{
    for (unsigned int row_index = 0; row_index < NUMBER_OF_ROWS; row_index++)
    {
            std::fill(board1[row_index].begin(), board1[row_index].end(), Game::who::NEUTRAL);
            std::fill(board2[row_index].begin(), board1[row_index].end(), Game::who::NEUTRAL);
    }
}

std::pair<unsigned int, unsigned int> TicTacTwo::convert_move_input_to_coordinates(const std::string& space_separated_move) const
{
    std::istringstream iss(space_separated_move);

    std::vector<std::string> coordinates {std::istream_iterator<std::string>{iss},
                                          std::istream_iterator<std::string>{}};

    assert(coordinates.size() == BOARD_DIMENSIONS);

    auto row = std::stoi(coordinates[0]);

    auto column = std::stoi(coordinates[1]);

    return std::make_pair(row, column);
}

std::pair<unsigned int, unsigned int> TicTacTwo::convert_coordinates_from_first_board_to_second_board(unsigned int row, unsigned int column)
{

    assert(row < NUMBER_OF_ROWS);
    assert(column < NUMBER_OF_COLUMNS);

    auto board_1_coordinates = std::make_pair(row, column);

    // can only switch on integer-evaluable type
    switch (board_1_coordinates.first)
    {
        case (0):
        {
            switch (board_1_coordinates.second)
            { // coordinates are in (row, column) layout
                case (0) : return std::make_pair(2, 3);

                case (1): return std::make_pair(0, 0);

                case (2) : return std::make_pair(1, 2);

                case (3) : return std::make_pair(3, 1);

                    // TODO: Change this to the correct error
                default: exit(1);
            }

        }

        case(1):
        {
            switch (board_1_coordinates.second)
            {
                case (0): return std::make_pair(1, 1);

                case (1):  return std::make_pair(3, 2);

                case (2): return std::make_pair(2, 0);

                case (3) : return std::make_pair(0, 3);

                    // TODO: Change this to the correct error
                default: exit(1);
            }
        }

        case (2):
        {
            // TODO: Put switch statement here

            switch (board_1_coordinates.second)
            {
                case (0) : return std::make_pair(3, 0);

                case (1) : return std::make_pair(1, 3);

                case (2) : return std::make_pair(0, 1);

                case (3) : return std::make_pair(2, 2);

                default: exit(1);
            }

        }


        case (3):
        {
            // TODO: Put switch statement here

            switch(board_1_coordinates.second)
            {
                case (0) : return std::make_pair(0, 2);

                case (1) : return std::make_pair(2, 1);

                case (2) : return std::make_pair(3, 3);

                case (3) : return std::make_pair(1, 0);

                default: exit(1);
            }
        }

        default:
        {

            exit(1);
        }
    }

}


// *************
// OVERRIDDEN FUNCTIONS
// **************

/**
 * Compute all the moves that the next player can make
 *
 * @param moves[out] A queue made of space-separated strings, where each space-separated
 *                   string represents a possible move (on board 1).
 */
void TicTacTwo::compute_moves(std::queue <std::string> &moves) const
{
    // Iterate through the first board and figure out which spots are neutral

    for (unsigned int row_index = 0; row_index < NUMBER_OF_ROWS; row_index++)
    {
        auto current_row = board1[row_index];

        for (unsigned int column_index = 0; column_index < NUMBER_OF_COLUMNS; column_index++)
        {
            if (current_row[column_index] == Game::who::NEUTRAL)
            {
                moves.push(std::to_string(row_index) + " " + std::to_string(column_index));
            }
        }
    }
}

/**
 * Print the full picture of each board. Display human values in green and computer values
 * in red.
 */
void TicTacTwo::display_status() const
{
    int row, column;

    std::cout << std::endl << "Current Game status (Human = " << human_player_representation << ", Computer = " << computer_player_representation << ")" << std::endl;

    std::cout << "Board 1" << std::endl;

    for (unsigned int row_index = 0; row_index < NUMBER_OF_ROWS; row_index++)
    {
        for (unsigned int column_index = 0; column_index < NUMBER_OF_COLUMNS; column_index++)
        {
            Game::who square_occupier = board1[row_index][column_index];

            switch (square_occupier)
            {
                case Game::who::COMPUTER:
                    std::cout << std::setw(NUMBER_OF_COLUMNS) << computer_player_representation;
                    break;

                case Game::who::HUMAN:
                    std::cout << std::setw(NUMBER_OF_COLUMNS) << human_player_representation;
                    break;

                case Game::who::NEUTRAL:
                    std::cout << std::setw(NUMBER_OF_COLUMNS) << "•";
                    break;
            }
        }
    }


}

/**
 * Use this function to compute the best location for the computer player to mark.
 *   Initial implementation: return the maximum of the number of elements that the computer has in each row, column, or diagonal.
 * @return
 */
int TicTacTwo::evaluate() const
{
 // TODO IMPLEMENT
}

/**
 * Game is over if any player has 4 continous elements in the same row, column, or diagonal.
 */
bool TicTacTwo::is_game_over() const
{

    if (moves_completed() == 0) { return false; }

    if (moves_completed() == NUMBER_OF_COLUMNS * NUMBER_OF_ROWS) { return true; }

    // Check if the diagonal has all the same value

    auto diagonal = get_diagonal();

    if (is_section_won(diagonal)) {
        return true;
    }

    for (unsigned int row_index = 0; row_index < NUMBER_OF_ROWS; row_index++)
    {
        auto current_row = get_row(row_index);

        if (is_section_won(current_row)) { return true; }
    }

    for (unsigned int column_index = 0; column_index < NUMBER_OF_COLUMNS; column_index++)
    {
        auto current_column = get_column(column_index);

        if (is_section_won(current_column)) { return true; }
    }

    // By now, you've checked every row, column, and diagonal, and both the minimum and maximum cases for # of moves.

    return false;

}
/**
 *  @brief Checks if the position requested is occupied by Neutral.
 *
 *  @warning Assumes that first board is initialized to all neutrals.
 *            Does not check position on second board because it assumes that coordinate mapping from board 1 to board 2
 *            is correct.
 *
 * @param move[in] A space-separated (row, column) entry representing the desired position
 * @return
 */
bool TicTacTwo::is_legal(const std::string &move) const
{

    auto [row, column] = convert_move_input_to_coordinates(move);

    return (board1[row][column] == Game::who::NEUTRAL);
}

/**
 * Make the actual placement of a move.
 * @param move[in] A space-separated (row, column) entry representing the users desired position
 */
void TicTacTwo::make_move(const std::string &move)
{

    assert(is_legal(move));

    auto [row, column] = convert_move_input_to_coordinates(move);

    board1[row][column] = next_mover();

    auto second_board_coordinates = convert_coordinates_from_first_board_to_second_board(row, column);

    board2[second_board_coordinates.first][second_board_coordinates.second] = next_mover();

    Game::make_move(move);


}

/**
 * Set both boards to be all neutral.
 */
void TicTacTwo::restart()
{

    neutralize_boards();

    Game::restart();

}

