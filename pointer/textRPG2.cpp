#include <iostream>
using namespace std;

// Text RPG 2 
// 전에는 전역에 만들어서 관리를했지만 이번에는 스택메모리에서 작업
// 나중에는 힙 메모리에 몬스터나 플레이어를 올릴 것.
// 참조, 포인터, 배열 등등에 대한 실습 차원

// main
// - EnterLobby
// -- CreatePlayer
// -- EnterGame
// --- CreateMonsters
// --- EnterBattle

enum PlayerType 
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp = 0;
	int atk = 0;
	int def = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* player);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* player);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
	srand((unsigned int)time(nullptr));
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장하였습니다.");

		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo);

		EnterGame(&playerInfo);
	}
}

void PrintMessage(const char* msg)
{
	cout << "************************" << endl;
	cout << msg << endl;
	cout << "************************" << endl;
}

void CreatePlayer(StatInfo* player)
{
	bool ready = false;

	while (ready == false)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 마법사");
		cout << "> ";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_Knight:
			player->hp = 100;
			// == (*player).hp = 100;
			player->atk = 10;
			player->def = 5;
			ready = true;
			break;
		case PT_Archer:
			player->hp = 80;
			player->atk = 15;
			player->def = 3;
			ready = true;
			break;
		case PT_Mage:
			player->hp = 50;
			player->atk = 25;
			player->def = 1;
			ready = true;
			break;
		}
	}
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "************************" << endl;
	cout << name << " : HP=" << info.hp << " ATK=" << info.atk << " DEF=" << info.def << endl;
	cout << "************************" << endl;
}

void EnterGame(StatInfo* player)
{
	const int MONSTER_COUNT = 2;

	PrintMessage("게임에 입장했습니다.");

	while (true)
	{
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			PrintStatInfo("Monster", monsterInfo[i]);
		}
		
		PrintStatInfo("Player", *player);

		PrintMessage("[1]전투 [2]전투 [3]도망");
		int input;
		cin >> input;

		if (input == 1 || input == 2)
		{
			int index = input - 1;
			bool victory = EnterBattle(player, &monsterInfo[index]);

			if (victory == false)
				break;
		}
		
	}
}

void CreateMonsters(StatInfo monsterInfo[], int count)
{
	for (int i = 0; i < count; i++) 
	{
		int randValue = 1 + (rand() % 3); //  1 + (0 1 2) 
		switch (randValue)
		{
		case MT_Slime:
			monsterInfo[i].hp = 30;
			monsterInfo[i].atk = 5;
			monsterInfo[i].def = 1;
			break;
		case MT_Orc:
			monsterInfo[i].hp = 40;
			monsterInfo[i].atk = 8;
			monsterInfo[i].def = 2;
			break;
		case MT_Skeleton:
			monsterInfo[i].hp = 50;
			monsterInfo[i].atk = 15;
			monsterInfo[i].def = 3;
			break;
		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
	while (true)
	{
		int dmg = playerInfo->atk - monsterInfo->def;
		if (dmg < 0)
			dmg = 0;

		monsterInfo->hp -= dmg;
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0)
		{
			PrintMessage("몬스터를 처치하였습니다.");
			return true;
		}

		dmg = monsterInfo->atk - playerInfo->def;
		if (dmg < 0)
			dmg = 0;
		playerInfo->hp -= dmg;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0)
		{
			PrintMessage("Game Over");
			return false;
		}
	}
}