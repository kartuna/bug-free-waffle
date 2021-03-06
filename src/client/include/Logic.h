/*
 * Logic.h
 */
#ifndef LOGIC_H_
#define LOGIC_H_
#include <vector>
#include <set>
#include <map>
#include "Board.h"
#include "Move.h"
using namespace std;
/**
 * Class logic. Calculating moves of the players.
 */
class Logic {
public:
	// making other typedef of the map for easily using
	typedef map<Move, set<Move> > MoveArrayMap;
	/**
	 * Constructor.
	 */
	Logic(int);
	/**
	 * Destructor.
	 */
	~Logic();
	/**
	 * Search for all possible moves.
	 */
	void possibleMove(char, char);
	/**
 	 * Helpful function that check all the surrounding of the current player for making
	 * the possible moves. This function running iterativly for every opponent cell he
	 * find near the current player and if found possible move insert the
	 * enemies to set which will add to the map.
     * row - the row of current player
     * col - the col of current player
	 * Player - the opponent we loking for
     */
    void checkSurrounding(int, int, char);
    /**
	 * Checking if the move that user want to make is valid. Comparing to all the possible moves.
	 * Move - the move that user want to make
	 */
	bool isPossibleMoveValidality(Move);
	/**
	 * Checking if moves vector is empty after checking.
	 */
	bool isEmpty() const;
	/**
	 * Printing all the possible moves that the algorithm find for us.
	 */
	void printMoves() const;
	/**
	 * Finishing move by making the destroy enemy algorithm,
	 * reseting the moves and adding the move we did
	 * to the array
	 */
	void finishMove(int, int, char, int *, int *);
	/**
	 * Return board by reference.
	 */
	Board *getBoard() { return gaming_board_; }
    /**
	 * Returning the number of destroyed enemies after the algorithm for calulating the count
	 * of each player.
	 */
    unsigned int getDestroyed();
    /**
     * Grading the best move for the opponent.
     * Return the max grade.
     */
    int bestOpponentMove(int, int);
    /**
     * Min-Max algorithm that found best cpu move depends on the move
     * of the user that will come afterwards.
     * Returns the minnimum graded move of the best opponent moves.
     */
    Move minMaxAlgorithm(char, int, char, int);
    /**
     * Return string represantation of possible moves
     */
    string getSelectedMove() const;
    /**
     * Checking if board is full.
     */
    bool isFinished();
protected:
    string selectedMove_;
    MoveArrayMap moves_;
    //list of all the soldiers on the field
    vector<Move> soldiers_;
    unsigned int destroyed_enemies_;
    Board *gaming_board_;
};

#endif /* LOGIC_H_ */
