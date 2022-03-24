#include <iostream>
using namespace std;

// �����ڿ� �Ҹ���

// [������ �� �Ҹ���]
// Ŭ������ �Ҽӵ� �Լ����� ��� �Լ���� ��.
// �� �߿��� ������ Ư���� �Լ� 2���� �ִµ�, �ٷ� [����]�� [��]�� �˸��� �Լ���
// -����(ź��) -> ������ (������ ���� ����)
// -��(��) -> �Ҹ��� (1���� ����)

// [�Ͻ���(implicit) ������
// �����ڸ� ��������� ������ ������,
// �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������.
// -> �׷��� �츮�� �����(explicit)���� �ƹ� ������ �ϳ� �����,
// �ڵ����� ��������� [�⺻ ������]�� �� �̻� ��������� ����.
 
  
// Ŭ������ ������ ���赵
class Knight
{
public:
    // [1] �⺻ ������ (���� ����)
    Knight()
    {
        cout << "Knight() �⺻ ������ ȣ��" << endl;

        _hp = 100;
        _attack = 10;
        _posY = 1;
        _posX = 1;
    }

    // [2] ���� ������ (�ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����
    // �Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� ����Ѵ�.
    Knight(const Knight& knight)
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posY = knight._posY;
        _posX = knight._posX;
    }

    // [3] ��Ÿ ������

    // �� �߿��� ���ڸ� 1���� �޴� [��Ÿ ������]��
    // [Ÿ�� ��ȯ ������]��� �θ��⵵ ��
    // �����Ϸ��� �Ͻ������� �ٲ�����µ� �츮�� �̰��� ��������� ����ϰڴ�.
    // explicit Ű���带 �ٿ��ָ� ��.

    explicit Knight(int hp)
    {
        cout << "Knight(int) ������ ȣ��" << endl;

        _hp = hp;
        _attack = 10;
        _posY = 1;
        _posX = 1;
    }

    Knight(int hp, int attack, int posX, int posY)
    {
        cout << "Knight(int) ������ ȣ��" << endl;

        _hp = hp;
        _attack = attack;
        _posY = posY;
        _posX = posX;
    }

    // �Ҹ���
    ~Knight()
    {
        cout << "Knight() �Ҹ��� ȣ��" << endl;
    }

    // ��� �Լ� ����
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        _hp = 0;    // ==
        this->_hp = 1;
        cout << "dead" << endl;
    }

public:
    // ��� ����
    int _hp;
    int _attack;
    int _posY;
    int _posX;

};

void Knight::Move(int y, int x)
{
    _posY = y;
    _posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << _attack << endl;
}

int main()
{
    Knight k1(100, 10, 0, 0);

    Knight k2(k1); // ���� ������
    Knight k3 = k1;  // ���� ������

    Knight k4; // ������
    k4 = k1; // ����

    k1.Move(1, 2);
    k1.Attack();
    k1.Die();

    // �Ͻ��� ����ȯ -> �����Ϸ��� �ٲ�ġ��
    int num = 1;
    float f = (float)num; // ����� < �츮�� �ڵ�� num�� float �ٱ��Ͽ� ������� �ֹ��ϰ� ����.
    double d = num; // �Ͻ��� << ���� ���ߴµ� �����Ϸ��� �˾Ƽ� ó���ϰ� ����.

    Knight k5;
    // k5 = 1; // explicit�� �ٿ����� ������ Ÿ�� ��ȯ ������( ���� 1���ִ� ��) ȣ���ϰ� �ִ� ���� �� �� ����. 
    // k5 = Knight(1);
    return 0;
}