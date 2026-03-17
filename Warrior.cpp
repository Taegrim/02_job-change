#include "Warrior.h"

Warrior::Warrior(string name) : Player(name, DEFAULT_STATS[WARRIOR])
{
	job = JOB_NAMES[WARRIOR];
	cout << format("{}·Î ÀüÁ÷ÇÏ¿´½À´Ï´Ù\n", job);
}

void Warrior::Attack(Character* target)
{
	Player::Attack(target);
}

void Warrior::PrintAttackAction()
{
	cout << "Ä®À» ÈÖµÎ¸¨´Ï´Ù!" << endl;
}
