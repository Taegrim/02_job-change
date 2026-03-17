#pragma once
#include"Status.h"

class Character
{
public:
	Character() = default;
	Character(string name);
	Character(string name, span<const int> stats);

	template <typename... Args>
	Character(string name, Args...args) : name{ name }, status{ args... } {}

	virtual ~Character() = default;


	const string& GetName() const;
	int GetStatus(STATUS name) const;

	void SetName(const string& name);
	void SetStatus(STATUS name, int value);

	virtual void Attack(Character* target);
	
	void PrintStatus();
	virtual void PrintAttackAction() = 0;

protected:
	int attack_count = 1;

private:
	virtual int CalculateDamage(const Character* target);
	virtual void SetRemainHp(Character* target, int damage);

	string name;
	Status status;
};

