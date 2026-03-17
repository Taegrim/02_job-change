#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player() = default;
	Player(string name);
	Player(string name, span<const int> stats);

	template <typename... Args>
	Player(string name, Args...args) : Character(name, args...) {}

	virtual ~Player() = default;

	const string& GetJobName();

	void PrintJobName();
	virtual void Attack(Character* target) override;

	virtual void PrintAttackAction() = 0;

protected:
	string job;
};

