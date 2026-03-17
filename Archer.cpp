#include "Archer.h"

Archer::Archer(string name) : Player(name, DEFAULT_STATS[ARCHER])
{
	job = JOB_NAMES[ARCHER];
	cout << format("{}로 전직하였습니다\n", job);
	attack_count = 3;
}

void Archer::Attack(Character* target)
{
	Player::Attack(target);
}

void Archer::PrintAttackAction()
{
	cout << "활을 쏩니다!" << endl;
}
