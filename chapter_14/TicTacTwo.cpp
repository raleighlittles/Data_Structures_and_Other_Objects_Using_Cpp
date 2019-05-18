//
// Created by raleigh on 5/17/19.
//

#include <queue>

#include "TicTacTwo.h"

// ********************
// HELPER FUNCTIONS
// ********************

std::array<Game::who, TicTacTwo::NUMBER_OF_ROWS> TicTacTwo::get_row(uint row_index)
{

}


std::array<Game::who, TicTacTwo::NUMBER_OF_COLUMNS> TicTacTwo::get_column(uint column_index)
{

}




std::array<Game::who, TicTacTwo::NUMBER_OF_ROWS> TicTacTwo::get_diagonal()
{

}


// *************
// OVERRIDDEN FUNCTIONS
// **************

/**
 * Compute all the moves that the next player can make
 *
 * @param moves[out] A queue made of space separated strings, where each space-separated
 *                   string represents a possible move (on board 1).
 */
void TicTacTwo::compute_moves(std::queue <std::string> &moves) const
{

}

/**
 * Print the full picture of each board. Display human values in green and computer values
 * in red.
 */
void TicTacTwo::display_status() const
{

}

/**
 * Use this function to compute the best location for the computer player to mark.
 *   Initial implementation: return the maximum of the number of elements that the computer has in each row, column, or diagonal.
 * @return
 */
int TicTacTwo::evaluate() const
{

}

/**
 * Game is over if any player has 4 continous elements in the same row, column, or diagonal.
 * @return
 */
bool TicTacTwo::is_game_over() const
{

    if (moves_completed() == 0) { return false; }

    if (moves_completed() == NUMBER_OF_COLUMNS * NUMBER_OF_ROWS) { return true; }


}
/**
 *  Any position that is not occupied by another player is legal.
 *
 * @param move[in] A comma-separated (row, column) entry representing the desired position
 * @return
 */
bool TicTacTwo::is_legal(const std::string &move) const
{

}

/**
 * Make the actual placement of a move.
 * @param move[in] A comma-separated (row, column) entry representing the users desired position
 */
void TicTacTwo::make_move(const std::string &move)
{

}

/**
 * Set all the entries in the array to Neutral.
 */
void TicTacTwo::restart()
{

}

