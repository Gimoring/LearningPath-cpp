#include <iostream>
using namespace std;

// ������ ���� : �迭

struct StatInfo
{
	int hp;
	int atk;
	int def;
};

int main()
{
	// TYPE �̸�[����];

	// �迭�� ũ��� ���������.(VC �����Ϸ� ����)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// ���²� �������� [�̸�]�� �ٱ����� �̸��̾���.
	int a = 10;
	int b = a;

	// �׷��� �迭�� [�̸�]�� ���� �ٸ��� �����Ѵ�.
	//StatInfo players[10];
	//players = monsters; ERROR

	// �׷� �迭�� �̸��� ����?
	// �迭�� �̸��� �� �迭�� ���� �ּ�.
	// ��Ȯ���� ���� ��ġ�� ����Ű�� (TYPE*) ������
	auto WhoAmI = monsters;

	// �ּ�[ (100, 10, 1) ], StatInfo[ ], StatInfo[ ], StatInfo[ ], ...
	// monster_0[ �ּ� ]
	StatInfo* monsters_0 = monsters;
	monsters_0->hp = 100;
	monsters_0->atk = 10;
	monsters_0->def = 1;

	// �������� ����, ��¥ 1�� ���϶�°� �ƴ϶�, StatInfo Ÿ�� �ٱ��� ũ�⸸ŭ 1���� �̵��϶�� �ǹ�
	// StatInfo[ ], �ּ�[ (200,20,2) ], StatInfo[ ], StatInfo[ ], ...
	// monster_1[ �ּ� ]
	StatInfo* monsters_1 = monsters + 1;
	monsters_1->hp = 200;
	monsters_1->atk = 20;
	monsters_1->def = 2;

	// ���� �� �ڵ�ȭ �Ѵٸ� ?
	for (int i = 0; i < 10; i++) {
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.atk = 10 * (i + 1);
		monster.def = (i + 1);
	}

	// �ٵ� *(monsters + i) �������� �ʹ� ������. �� ���� ���? -> �ε���
	// �迭�� 0������ ����. N��° �ε����� �ش��ϴ� �����Ϳ� �����Ϸ��� �迭�̸�[N]
	// *(monsters + i) = monsters[i]

	monsters[0].hp = 100;
	monsters[0].atk = 10;
	monsters[0].def = 1;

	return 0;
}