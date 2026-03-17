#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(string name);
	~Warrior() = default;

	virtual void Attack(Character* target) override;
	virtual void PrintAttackAction() override;
};

