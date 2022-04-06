#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP : Object Oriented Programming)
// 1. 상속성
// 2. 은닉성
// 3. 다형성

// 메모리

// [ Knight ]
// [ [ Player ] ] 플레이어 생성자 호출 후 나이트 생성자 호출
// 정확하게는 나이트 생성자 호출할 때 부모의 생성자를 호출(실행) 후 다시 나이트 생성자의 내용물로 돌아간다.

// 상속? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N)개 생성 가능. 소멸자 (1) 하나만.

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택 ! 그냥 둘 다 호출하자!

// class 는 일종의 설계도
class Player
{
public:
    Player()
    {
        _hp = 0;
        _atk = 0;
        _def = 0;
        cout << "플레이어 기본 생성자입니다." << endl;
    }
    Player(int hp)
    {
        _hp = 0;
        _atk = 0;
        _def = 0;
        cout << "플레이어 hp들어간 생성자" << endl;
    }
    ~Player()
    {
        cout << "~플레이어 소멸자 호출" << endl;
    }

    void Attack() { cout << "Player 공격"; }
    void Move() { cout << "Player 이동"; }
    void Defense() { cout << "Player 방어"; }
public:
    int _hp;
    int _atk;
    int _def;
};

class Knight : public Player
{
public:
    Knight()
    {
        /*
        선(먼저)처리 영역
        - 여기서 Player() 생성자 호출
        */

        _stamina = 100;
        cout << "나이트 기본 생성자입니다." << endl;
    }
    Knight(int stamina) : Player(100)
    {
        /*
        선(먼저)처리 영역
        - 여기서 Player(int hp) 생성자 호출
        */
        _stamina = stamina;
        cout << "나이트(int stamina) 생성자 입니다." << endl;
    }
    ~Knight()
    {
        cout << "~나이트 소멸자 입니다." << endl;
    }
    /*
        후(나중에)처리 영역
        - 여기서 ~Player() 소멸자를 호출
    */

    // 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든?
    void Move() { cout << "나이트 Move 호출" << endl; }

public:
    int _stamina;
};

int main()
{
    Knight k1(100);

    return 0;
}