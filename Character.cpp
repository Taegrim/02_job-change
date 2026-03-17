#include "Character.h"

Character::Character(string name) : name{ name }
{
}

Character::Character(string name, span<const int> stats) : name{ name }, status{ stats }
{
}

const string& Character::GetName() const
{
	return name;
}

int Character::GetStatus(STATUS name) const
{
	return status.GetStatus(name);
}

void Character::SetName(const string& name)
{
	this->name = name;
}

void Character::SetStatus(STATUS name, int value)
{
	status.SetStatus(name, value);
}


void Character::Attack(Character* target)
{
	string target_name{ target->GetName() };
	cout << format("{}은(는) {}을(를) 공격했다!!\n", this->name, target_name);

	PrintAttackAction();

	int damage = CalculateDamage(target);

	for (int i = 0; i < attack_count; ++i) {
		cout << format("{}은(는) {}에게 {}의 데미지를 입혔다\n", this->name, target_name, damage);
	}

	SetRemainHp(target, damage);
}

int Character::CalculateDamage(const Character* target)
{
	int damage = (status.GetStatus(ATK) - target->GetStatus(DEF)) / attack_count;
	return max(1, damage);
}

void Character::SetRemainHp(Character* target, int damage)
{
	int remain_hp = target->GetStatus(HP) - (damage * attack_count);
	remain_hp = max(0, remain_hp);
	target->SetStatus(HP, remain_hp);

	if (remain_hp > 0) {
		cout << format("{}의 잔여 HP : {}\n", target->GetName(), remain_hp);
	}
}

void Character::PrintStatus()
{
	cout << endl;
	cout << format("{}의 스테이터스\n", name);
	status.PrintStatus();
}
