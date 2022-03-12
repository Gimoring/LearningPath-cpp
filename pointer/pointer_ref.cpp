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

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(info)][RET][지역변수]
// 구조체 복사후 매개변수로 넘김.
void PrintInfoByCopy(StatInfo info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATK : " << info.atk << endl;
    cout << "DEF : " << info.def << endl;
    cout << "--------------------------------" << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
// 구조체의 주소 매개변수로 넘김.
void PrintInfoByPtr(StatInfo *info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATK : " << info->atk << endl;
    cout << "DEF : " << info->def << endl;
    cout << "--------------------------------" << endl;
}

// 만약 StatInfo 구조체가 1000바이트 짜리 대형 구조체라면?
// - (값 전달) : StatInfo로 넘기면 1000바이트가 복사됨.
// - (주소 전달) : StatInfo*는 8바이트 (운영체제가 32비트 라면 4바이트)
// 포인터는 4~8바이트 고정
// - (참조 전달) : 

int main ()
{
    // 4바이트 정수형 바구니 사용할꺼임
    // 이 바구니 이름 number임
    int number = 1;

    // * 주소를 담는 바구니임.
    // int 이 바구니 따라가면 int형 데이터(바구니)있음
    int* pointer = &number;

    // 참조 전달
    // 로우레벨(어셈블리) 관점에서 실제 작동 방식은 포인터와 같음.
    int& reference = number;

    // C++관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
    // number라는 바구니에 reference라는 또 다른 이름을 지어줌.
    // reference바구니(짭퉁)에 뭘 꺼내거나 넣으면
    // number(진퉁) 바구니에 넣어질꺼임


    StatInfo info;
    CreateMonster(&info);

    PrintInfoByCopy(info);
    PrintInfoByPtr(&info);
    return 0;
}