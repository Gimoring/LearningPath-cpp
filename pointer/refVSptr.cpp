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

StatInfo globalInfo;
void PrintInfo(const StatInfo* const info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATK : " << info->atk << endl;
    cout << "DEF : " << info->def << endl;
    cout << "--------------------------------" << endl;

    // 별 뒤에 붙인다면 ? StatInfo* const info
    // info라는 바구니의 내용물(주소)를 바꿀 수 없다.
    // info는 주소값을 갖는 바구니 -> 이 주소값을 고정하라는 소리. 
    //info = &globalInfo;

    // 별 이전에 붙인다면 ? const StatInfo* info
    // info->hp = 100;
    // info가 가리키고 있는 바구니의 내용물을 바꿀 수 없음.
    // 주소의 데이터를 바꿀 수 없다는 소리. 
    
    // 둘 다 const 가능.

    // info [주소값]    주소값 [데이터]
}

// 3) 참조 전달 방식
// -- 값 전달처럼 편리하게 사용하고
// -- 주소 전달처럼 주소값을 이용해 진퉁을 건드리는
// -- 일석이조의 방식 !

void PrintInfo(const StatInfo& info)
{
    cout << "--------------------------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATK : " << info.atk << endl;
    cout << "DEF : " << info.def << endl;
    cout << "--------------------------------" << endl;

    // 신입이 왔다!
    // info.hp = 10; 오류뜸 const 붙여줘서 info -> readonly 데이터.
}

int main()
{
    StatInfo info;

    // 포인터 vs 참조 세기의 대결 
    // 성능 : 똑같음 !
    // 편의성 : 참조 승 

    // 1) 편의성이 좋다는게 꼭 장점은 아니다.
    // 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데,
    // 참조는 자연스럽게 모르고 지나칠 수 있음.
    // ex) 마음대로 고친다면?
    // -> const를 사용해서 마음대로 고치는 부분 개선 가능.

    // 포인터도 const 사용 가능.
    // *을 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다.

    // 2) 초기화 여부
    // 참조 타입은 바구니의 2번째 이름
    // -> 참조하는 대상이 없으면 안됨
    // -> 초기화도 함께 해줘야 한다는 소리.
    // 반면 포인터는 그냥 어떤 ~주소라는 의미
    // -> 대상이 실존하지 않을 수도 있음. (선언만 해줄 경우)
    
    StatInfo* ptr = nullptr;
    ptr = &info;
    PrintInfo(ptr);
   
    StatInfo& reference = info;
    PrintInfo(reference);
    return 0;
}