#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <array>
#include <span>


using namespace std;

enum STATUS { HP, MP, ATK, DEF, SPD, ACC, STATUS_COUNT };
enum JOB { WARRIOR, MAGICIAN, THIEF, ARCHER, JOB_COUNT };
enum MONSTER { SLIME, MONSTER_COUNT };

inline const std::string STATUS_NAMES[]{ "HP", "MP", "공격력", "방어력", "속도", "정확도" };
inline const string JOB_NAMES[]{ "전사", "마법사", "도적", "궁수" };

using StatArray = array<int, STATUS_COUNT>;
inline constexpr array<StatArray, JOB_COUNT> DEFAULT_STATS = {{
	{150, 10, 40, 30, 10, 10},		// WARRIOR
	{80, 100, 20, 10, 20, 10},		// MAGICIAN
	{80, 30, 30, 20, 40, 20},		// THIEF
	{90, 30, 35, 20, 30, 30}		// ARCHER
}};

inline constexpr array<StatArray, MONSTER_COUNT> DEFAULT_MONSTER_STATS = {{
	{40, 0, 30, 10, 10, 10},		// SLIME
}};


inline void ClearScreen() {
	cout << "\033[2J\033[1;1H";
}