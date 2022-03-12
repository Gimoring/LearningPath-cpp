#include <iostream>
using namespace std;

// 1) 주소 연산자 &
// 2) 산술 연산자 + -
// 3) 간접 연산자 *
// 4) 간접 멤버 연산자


struct Player
{
    int hp;
    int damage;
};

int main()
{

    int number = 1;

    // 1) 주소 연산자 &
    // - 해당 변수의 주소를 알려주세요
    // 더 정확히 말하자면 해당 변수 타입(TYPE)에 따라서 TYPE* 변환 (TYPE대로 주소의 데이터를 읽어주세요.)
    int* pointer = &number;

    // 2) 산술 연산자

    number += 1;

    // int*
    // - * :  포인터 타입 (8바이트) 주소를 담는 바구니 !
    // - int : 주소를 따라가면 int(4바이트 정수형 바구니)가 있다고 가정해라 !

    // [!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면,
    // 정말 '그 숫자'를 더하거나 빼라는 내용이 아니다.
    // 한번에 TYPE의 크기만큼을 이동하라는 의미.
    // 다음/이전 바구니로 이동하고 싶다 >> [바구니 단위]의 이동으로
    // 즉, 1을 더하면 바구니 1개만큼 이동시켜라.
    // 3을 더하면 바구니 3개만큼 이동시켜라. 

//    pointer += 2; // 바구니 단위마큼 이동.  2 * pointer(4bytes integer) 4 => 8 , 8/number바구니(4bytes integer) 4 => 2 바구니 2번 이동.

    // 3) 간접 연산자 *
    // 포탈을 타고 포인터가 가리키는 주소로 슝~ 이동
    number = 3;
    // ==
    *pointer = 3; 

    // 포인터와 구조체의 콜라보레이션
    Player player;
    player.hp = 100;
    player.damage = 200;

    Player* playerptr = &player;
    (*playerptr).hp = 150;
    (*playerptr).damage = 10;

    // 4) 간접 멤버 연산자 ->
    // * 간접 연산자 (포탈타고 해당 위치로 GO)
    // . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리 언어로 까보면 . 사실상 그냥 덧셈)
    // -> 는 *와 . 를 한방에 처리
    playerptr->hp = 200; // == (*playerptr).hp = 200;

    return 0;
}