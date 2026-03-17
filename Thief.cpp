#include "Thief.h"

Thief::Thief(string name) : Player(name, DEFAULT_STATS[THIEF])
{
	job = JOB_NAMES[THIEF];
	cout << format("{}로 전직하였습니다\n", job);
	attack_count = 5;
}

void Thief::Attack(Character* target)
{
	Player::Attack(target);
}

void Thief::PrintAttackAction()
{
	cout << "단검으로 찌릅니다!" << endl;
}
