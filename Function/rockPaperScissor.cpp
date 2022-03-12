#include <iostream>
using namespace std;


// 상수인건 알겠는데 따로 노는 느낌.
// 이럴 때에는 enum이란 것이 있다.
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 값을 안 넣어주면 기본적으로 0이 들어간다.
// 그 다음 값은 이전 값 + 1
enum ENUM_SRP
{
    ENUM_SCISSORS = 1,
    ENUM_ROCK,
    ENUM_PAPER,
};

// #이 붙은 것 -> 전처리 지시문
// #include <iostream> -> iostream이라는 파일을 찾아서 통째로 복붙 해주세요 라는 지시문.
// 전처리 -> 컴파일 -> 링크 순으로 동작.
#define DEFINE_SCISSORS 1
#define DEFINE_TEST cout << "Bonjoooour !" << endl;

int main() {

    DEFINE_TEST;

    int input;
    int winRate;
    int wins = 0;
    int total = 0;

    while(true) {
        srand(time(0)); // random number generator
        int ranVal = 1+ (rand() % 3);  // number 0 1 2  (+1)
        cout << "가위(1) 바위(2) 보(3)를 골라주세요!" << endl;
        cout << "나가기는 4번입니다.\n";
        cout << "> ";
        if (total == 0)
        {
            cout << "현재 승률 : 없음" <<endl;
        } else
        {
            winRate = (wins * 100) / total;
            cout << "현재 승률 : " << winRate << endl;
        }
        cin >> input;
        cout << "-------------" << endl;


        if(input == SCISSORS) 
        {
            if(ranVal == input) 
            {
                cout << "서로 비겼습니다" <<endl;
            }
            else if (ranVal == 2) 
            {
                cout << "사용자(가위)님이 컴퓨터(바위)에게 졌습니다" <<endl;
                total++;
            }
            else 
            {
                cout << "사용자(가위)님이 컴퓨터(보)에게 이겼습니다." <<endl;
                wins++;
                total++;
            }
        } 
        else if (input == ROCK) 
        {
            switch(ranVal)
            {
                case SCISSORS:
                    cout<< "사용자(바위)님이 컴퓨터(가위)에게 이겼습니다." << endl;
                    wins++;
                    total++;
                    break;
                case ROCK:
                    cout<< "서로 비겼습니다." << endl;
                    break;
                case PAPER:
                    cout<< "사용자(바위)님이 컴퓨터(보)에게 졌습니다." << endl; 
                    total++;
                    break;
            }
        } 
        else if (input == PAPER) 
        {
            switch(ranVal)
            {
                case SCISSORS:
                    cout<< "사용자(보)님이 컴퓨터(가위)에게 졌습니다." << endl;
                    total++;
                    break;
                case ROCK:
                    cout<< "사용자(보)님이 컴퓨터(바위)에게 이겼습니다." << endl;
                    wins++;
                    total++;
                    break;
                case PAPER:
                    cout<< "서로 비겼습니다." << endl; 
                    break;
            }
        } 
        else 
            break;
    }
}