#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

int main()
{
	unique_ptr<Player> player = nullptr;
	int job{};

	// 이름 입력
	string name{};
	cout << "이름을 입력해주세요 : ";
	cin >> name;

	// 전직
	for (int i = 0; i < static_cast<int>(JOB_COUNT); ++i) {
		cout << format("{}. {}\n", i + 1, JOB_NAMES[i]);
	}
	while (true) {
		cout << "전직할 직업에 맞는 번호를 입력하세요 : ";
		if (cin >> job) {
			if (job >= 1 && job <= static_cast<int>(JOB_COUNT)) {
				break;
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "잘못된 값입니다. 다시 입력해주세요" << endl;
	}

	switch ((job - 1)) {
	case WARRIOR:
		player = make_unique<Warrior>(name);
		break;
	case MAGICIAN:
		player = make_unique<Magician>(name);
		break;
	case THIEF:
		player = make_unique<Thief>(name);
		break;
	case ARCHER:
		player = make_unique<Archer>(name);
		break;
	default:
		cout << "직업 할당 오류" << endl;
		break;
	}

	unique_ptr<Monster> monster = make_unique<Monster>("슬라임");

	int act{};
	bool loop = true;
	while (loop) {
		player->PrintStatus();
		monster->PrintStatus();

		cout << "1. 공격 / 2. 도망" << endl;
		cout << "당신이 할 행동을 선택하세요 : ";
		cin >> act;
		ClearScreen();

		switch (act) {
			
		case 1:
			player->Attack(monster.get());
			if (monster->GetStatus(HP) <= 0) {
				loop = false;
				cout << "게임을 종료합니다" << endl;
				break;
			}
			monster->Attack(player.get());
			if (player->GetStatus(HP) <= 0) {
				loop = false;
				cout << "게임을 종료합니다" << endl;
				break;
			}
			break;

		case 2:
			cout << "도망에 성공하였습니다!!" << endl;
			// 이후 선택지
			
			// --- 후퇴 테스트 ---
			cout << "게임을 종료합니다" << endl;
			loop = false;
			break;

		default:
			cout << "다시 입력하세요" << endl;
			break;
		}
	}


	return 0;
}