#include <iostream>

using namespace std;


int main () {
    int n;
    cin>>n;
    // 1번째 자리수 n%10;
    int rev = 0;
    while(n!=0) {
        int lastDigit = n % 10;
        rev = rev * 10 + lastDigit;
        n = n / 10;
    }

    cout<<rev<< endl;
    return 0;
}
