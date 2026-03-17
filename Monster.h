#pragma once
#include "Character.h"

class Monster : public Character
{
public:
	Monster() = default;
	Monster(string name);
	~Monster() = default;

	virtual void Attack(Character* target) override;
	virtual void PrintAttackAction() override;
};

