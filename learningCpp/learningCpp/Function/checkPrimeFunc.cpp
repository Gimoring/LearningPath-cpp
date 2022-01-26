#include <iostream>
using namespace std;

bool checkPrimeFunc(int n) {
    for(int i = 2; i <= n-1; i++) {
        if(n%i == 0) {
            return false;
        } 
    }
    return true;
} 

int main() {
    int n = 5;
    // cin >>n;
    if(checkPrimeFunc(n)) {
        cout<<"prime"<<endl;
    } else {
        cout<<"not prime"<<endl;
    }

    return 0;
}