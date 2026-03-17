#include "Player.h"

Player::Player(string name) : Character(name)
{
}

Player::Player(string name, span<const int> stats) : Character(name, stats)
{
}

const string& Player::GetJobName()
{
	return job;
}

void Player::PrintJobName()
{
	cout << format("직업 : {}\n", job);
}

void Player::Attack(Character* target)
{
	Character::Attack(target);

	if (target->GetStatus(HP) <= 0) {
		cout << format("축하합니다! {}와(과)의 전투에서 승리하셨습니다\n", target->GetName());
	}
}
