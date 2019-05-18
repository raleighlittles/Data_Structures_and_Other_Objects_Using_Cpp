//
// Created by raleigh on 1/4/19.
//

#ifndef CHAPTER_14_GAME_H
#define CHAPTER_14_GAME_H

#include <string>
#include <queue>

class Game {
public:
// ENUM TYPE
    enum class who {
        HUMAN,
        NEUTRAL,
        COMPUTER
    }; // Possible game outcomes
// CONSTRUCTOR and DESTRUCTOR
    Game() { move_number = 0; }

    virtual ~Game() = default;

    // PUBLIC MEMBER FUNCTIONS
// The play function should not be overridden. It plays one game, with the human player
// moving first and the computer second. The computer uses an alpha-beta look ahead
// algorithm to select its moves. The return value is the winner of the game (or
// NEUTRAL for a tie).
    who play();

protected:
// OPTIONAL VIRTUAL FUNCTIONS (overriding these is optional)
    virtual void display_message(const std::string &message) const;

    virtual std::string get_user_move() const;

    virtual who last_mover() const { return (move_number % 2 == 1 ? who::HUMAN : who::COMPUTER); }

    virtual int moves_completed() const { return move_number; }

    virtual who next_mover() const { return (move_number % 2 == 0 ? who::HUMAN : who::COMPUTER); }

    virtual who opposite(who player) const { return (player == who::HUMAN) ? who::COMPUTER : who::HUMAN; }

    virtual who winning() const;

// VIRTUAL FUNCTIONS THAT MUST BE OVERRIDDEN:
// The overriding function should call the original when it finishes.
// Have the next player make a specified move:
    virtual void make_move(const std::string &move) { ++move_number; }

// Restart the game from the beginning:
    virtual void restart() { move_number = 0; }

// PURE VIRTUAL FUNCTIONS (these must be provided for each derived class)
// Return a pointer to a copy of myself:
    virtual Game *clone() const = 0;

// Compute all the moves that the next player can make:
    virtual void compute_moves(std::queue<std::string> &moves) const = 0;

// Display the status of the current game:
    virtual void display_status() const = 0;

// Evaluate a board position (positive values are good for the player who just moved):
    virtual int evaluate() const = 0;

// Return true if the current game is finished:
    virtual bool is_game_over() const = 0;

// Return true if the given move is legal for the next player:
    virtual bool is_legal(const std::string &move) const = 0;

private:
    int move_number; // Number of moves made so far

    // STATIC MEMBER CONSTANT
    static const int SEARCH_LEVELS = 4;  // Levels for look-ahead evaluation

    // PRIVATE FUNCTIONS (these are the same for every game)
    int eval_with_lookahead(int look_ahead, int beat_this);
    void make_computer_move( );
    void make_human_move( );
};

#endif //CHAPTER_14_GAME_H
