#include "Status.h"

Status::Status() : status(STATUS_COUNT)
{
}

Status::~Status()
{
}

Status::Status(span<const int> stats)
{
	status.assign(stats.begin(), stats.end());
}


void Status::PrintStatus()
{
	cout << "--------------------" << std::endl;
	cout << "[현재 스테이터스]" << std::endl;
	for (int i = 0; i < static_cast<int>(STATUS_COUNT); ++i) {
		cout << std::format("{} : {}\n", STATUS_NAMES[i], status[i]);
	}
	cout << "--------------------" << std::endl;
}

int Status::GetLevel() const
{
	return level;
}

int Status::GetStatus(STATUS name) const
{
	return status[name];
}

void Status::SetLevel(int level)
{
	this->level = level;
}

void Status::SetStatus(STATUS name, int value)
{
	status[name] = value;
}