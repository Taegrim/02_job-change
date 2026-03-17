#include "Magician.h"

Magician::Magician(string name) : Player(name, DEFAULT_STATS[MAGICIAN])
{
	job = JOB_NAMES[MAGICIAN];
	cout << format("{}로 전직하였습니다\n", job);
}

void Magician::Attack(Character* target)
{
	Player::Attack(target);
}

void Magician::PrintAttackAction()
{
	cout << "마법 화살을 쏩니다!" << endl;
}
