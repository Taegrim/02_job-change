#include "Monster.h"

Monster::Monster(string name) : Character(name, DEFAULT_MONSTER_STATS[SLIME])
{
}


void Monster::Attack(Character* target)
{
	Character::Attack(target);

	if (target->GetStatus(HP) <= 0) {
		cout << format("당신은 사망하였습니다\n");
	}
}

void Monster::PrintAttackAction()
{
	cout << "슬라임이 강하게 부딪칩니다!!" << endl;
}
