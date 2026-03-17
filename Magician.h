#pragma once
#include "Player.h"

class Magician : public Player
{
public:

	Magician(string name);
	~Magician() = default;

	virtual void Attack(Character* target) override;
	virtual void PrintAttackAction() override;
};

