/*
 * Cpu.h
 *	Alex Kartun & Ofir Sharon
 *	324429216   & 204717664
 */
#ifndef CPU_H_
#define CPU_H_
#include "Player.h"
#include "Logic.h"
/**
 * Cpu implements player class.
 */
class Cpu: public Player {
public:
	Cpu(char);
	void makeMove(Player *, Logic *);
	unsigned int getSoldiers() const;
	char getValue() const;
	void setSoldiers(int);
	bool isPlayed() const;
	void setPlayed(bool);
private:
	//value of the player
	char value_;
	//actual count of this player's soldiers on the field
	int count_soldiers_;
	//boolean if played = true or false if dont have any move to make
	bool played_;
};

#endif /* CPU_H_ */
