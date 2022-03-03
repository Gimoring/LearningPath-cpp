#include <iostream>
using namespace std;


int main() {
        int input;
        const int SCISSORS = 1;
        const int ROCK = 2;
        const int PAPER = 3;
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