#include <iostream>
using namespace std;

// 오늘의 주제 : 배열

struct StatInfo
{
	int hp;
	int atk;
	int def;
};

int main()
{
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야함.(VC 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음.
	int a = 10;
	int b = a;

	// 그런데 배열의 [이름]은 조금 다르게 동작한다.
	//StatInfo players[10];
	//players = monsters; ERROR

	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소.
	// 정확히는 시작 위치를 가리키는 (TYPE*) 포인터
	auto WhoAmI = monsters;

	// 주소[ (100, 10, 1) ], StatInfo[ ], StatInfo[ ], StatInfo[ ], ...
	// monster_0[ 주소 ]
	StatInfo* monsters_0 = monsters;
	monsters_0->hp = 100;
	monsters_0->atk = 10;
	monsters_0->def = 1;

	// 포인터의 덧셈, 진짜 1을 더하라는게 아니라, StatInfo 타입 바구니 크기만큼 1개씩 이동하라는 의미
	// StatInfo[ ], 주소[ (200,20,2) ], StatInfo[ ], StatInfo[ ], ...
	// monster_1[ 주소 ]
	StatInfo* monsters_1 = monsters + 1;
	monsters_1->hp = 200;
	monsters_1->atk = 20;
	monsters_1->def = 2;

	// 조금 더 자동화 한다면 ?
	for (int i = 0; i < 10; i++) {
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.atk = 10 * (i + 1);
		monster.def = (i + 1);
	}

	// 근데 *(monsters + i) 가독성이 너무 떨어짐. 더 편한 방법? -> 인덱스
	// 배열은 0번부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) = monsters[i]

	monsters[0].hp = 100;
	monsters[0].atk = 10;
	monsters[0].def = 1;

	return 0;
}