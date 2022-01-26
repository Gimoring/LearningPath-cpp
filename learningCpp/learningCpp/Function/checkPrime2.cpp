#include <iostream>
using namespace std;

void checkPrimeFunc2(int n) {
    for(int i = 2; i<=n; i++) {
        for(int j = 2; j <= i-1; j++) {
            if(i%j == 0) {
                break;
            }
            cout<<i<<" ";
            // 처음에 break을 안걸어줬더니 계속 안쪽 루프돌면서 찍음. 왠지 이유를 자꾸 못찾겠어서 디버거 찍어보니 뇌피셜이 맞았음.
            break;
        }
    }
}



int main() {
    int n;
    cin>>n;
    checkPrimeFunc2(n);

    return 0;
}