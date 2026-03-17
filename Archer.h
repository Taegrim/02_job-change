#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(string name);
	~Archer() = default;

	virtual void Attack(Character* target) override;
	virtual void PrintAttackAction() override;
};

