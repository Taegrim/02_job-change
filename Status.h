#pragma once
#include <type_traits>
#include "Common.h"

class Status
{
public:
	Status();
	~Status();

	// span을 받는 생성자
	Status(span<const int> stats);

	// 가변인자를 이용한 생성자
	// span을 넘겨도 가변인자에 우선적으로 들어오는 문제가 있음
	//  -> requires 구문으로 조건 만족시에만 해당 생성자로 넘어오게 함 (오버로딩 해결용)
	template <typename... Args>
	requires (sizeof...(Args) > 0) && (std::is_convertible_v<Args, int> && ...)
	Status(Args... args) {
		// 가변인자 개수 체크
		// 에러 메세지 출력 용도
		static_assert(sizeof...(args) <= STATUS_COUNT,
			"인자가 STATUS_COUNT 를 초과했습니다.");

		// 타입 체크는 상단에서 하므로 넘김


		// 가변인자를 이용한 status 채우기
		/*int i = 0;
		status.resize(STATUS_COUNT, 0);
		((status[i++] = static_cast<int>(args)), ...);*/

		// c++ 스타일 이니셜라이저 리스트
		status = { static_cast<int>(args)... };
		status.resize(STATUS_COUNT, 0);
	}

	int GetLevel() const;
	int GetStatus(STATUS name) const;

	void SetLevel(int level);
	void SetStatus(STATUS name, int value);

	void PrintStatus();

private:
	int level = 1;
	std::vector<int> status;
};

