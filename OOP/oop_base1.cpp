#include <iostream>
using namespace std;

// 객체 지향의 시작

// Knight를 설계해보자
// - 속성 (데이터) : hp, attack, y, x
// - 기능 (동작 ) : Move, Attac, Die..

class Knight
{
public:
    // 멤버 함수 선언
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        hp = 0;
        cout << "dead" << endl;
    }

public:
    // 멤버 변수
    int hp;
    int attack;
    int posY;
    int posX;

};

void Knight::Move(int y, int x)
{
    posY = y;
    posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << attack << endl;
}

int main()
{



    return 0;
}
