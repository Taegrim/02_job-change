#pragma once
#include "Player.h"

class Thief : public Player
{
public:
	Thief(string name);
	~Thief() = default;

	virtual void Attack(Character* target) override;
	virtual void PrintAttackAction() override;
};
