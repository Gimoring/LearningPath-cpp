#include <iostream>
using namespace std;
/**
 *
 * 1
 * 11
 * 111      중간 -2 인 이유 => 처음과 끝 -1-1 => -2
 * 1001     i가 홀수일경우 중간 1  중간 1의 개수 5-2 => 3
 * 11111    i 2배수일 때  처음, 끝 1   중간 0  중간 0의 개수 => i-2 => 4-2 => 2 
 * 100001 
 * 
 */
void print(int n){
    // complete this function
    int i = 1;
    while(i<=n) {
        int j = 1;
        // start
        cout<<"1";
        
        // middle
        while(j <= i-2) { // 3번째 부터 중간이 들어가야하기 때문에 i-2 => 3-2 = 1   1 == j 
            if((i-2)%2 == 0) {
                cout<<"0";
            } else {
                cout<<"1";
            }
            j++;
        }
        // end
        if(i > 1) {
            cout<<"1"<<endl;
        } else {
            cout<<endl;
        }
        i++;
    }
}

int main (){
    print(6);
}