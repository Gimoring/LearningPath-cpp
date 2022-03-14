#include <iostream>
using namespace std;

struct StatInfo
{
    int hp;
    int atk;
    int def;
};

void CreateMonster(StatInfo* info)
{
    info->hp = 10;
    info->atk = 5;
    info->def = 1;
}

// 1) �� ���� ���
// [�Ű�����][RET][��������(info)][�Ű�����(info)][RET][��������]
// ����ü ������ �Ű������� �ѱ�.
void PrintInfoByCopy(StatInfo info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATK : " << info.atk << endl;
    cout << "DEF : " << info.def << endl;
    cout << "--------------------------------" << endl;
}

// 2) �ּ� ���� ���
// [�Ű�����][RET][��������(info)][�Ű�����(&info)][RET][��������]
// ����ü�� �ּ� �Ű������� �ѱ�.

StatInfo globalInfo;
void PrintInfo(const StatInfo* const info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATK : " << info->atk << endl;
    cout << "DEF : " << info->def << endl;
    cout << "--------------------------------" << endl;

    // �� �ڿ� ���δٸ� ? StatInfo* const info
    // info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����.
    // info�� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����϶�� �Ҹ�. 
    //info = &globalInfo;

    // �� ������ ���δٸ� ? const StatInfo* info
    // info->hp = 100;
    // info�� ����Ű�� �ִ� �ٱ����� ���빰�� �ٲ� �� ����.
    // �ּ��� �����͸� �ٲ� �� ���ٴ� �Ҹ�. 
    
    // �� �� const ����.

    // info [�ּҰ�]    �ּҰ� [������]
}

// 3) ���� ���� ���
// -- �� ����ó�� ���ϰ� ����ϰ�
// -- �ּ� ����ó�� �ּҰ��� �̿��� ������ �ǵ帮��
// -- �ϼ������� ��� !

void PrintInfo(const StatInfo& info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATK : " << info.atk << endl;
    cout << "DEF : " << info.def << endl;
    cout << "--------------------------------" << endl;

    // ������ �Դ�!
    // info.hp = 10; ������ const �ٿ��༭ info -> readonly ������.
}

int main()
{
    StatInfo info;

    // ������ vs ���� ������ ��� 
    // ���� : �Ȱ��� !
    // ���Ǽ� : ���� �� 

    // 1) ���Ǽ��� ���ٴ°� �� ������ �ƴϴ�.
    // �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִµ�,
    // ������ �ڿ������� �𸣰� ����ĥ �� ����.
    // ex) ������� ��ģ�ٸ�?
    // -> const�� ����ؼ� ������� ��ġ�� �κ� ���� ����.

    // �����͵� const ��� ����.
    // *�� �������� �տ� ���̴���, �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶�����.

    // 2) �ʱ�ȭ ����
    // ���� Ÿ���� �ٱ����� 2��° �̸�
    // -> �����ϴ� ����� ������ �ȵ�
    // -> �ʱ�ȭ�� �Բ� ����� �Ѵٴ� �Ҹ�.
    // �ݸ� �����ʹ� �׳� � ~�ּҶ�� �ǹ�
    // -> ����� �������� ���� ���� ����. (���� ���� ���)
    
    StatInfo* ptr = nullptr;
    ptr = &info;
    PrintInfo(ptr);
   
    StatInfo& reference = info;
    PrintInfo(reference);
    return 0;
}