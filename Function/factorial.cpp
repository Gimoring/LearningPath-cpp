/**
 * factorial  !     given n
 * what is the factorial?    if n => 5 then 1 * 2 * 3 * 4 *5. 120 = 5!.
 * so n! = n * (n-1) * (n-2) * ... * 1 
*/

#include <iostream>
using namespace std;


int factorial(int n) {
    int result = 1;
    for(int i = 2; i<=n; i++) {
        result *=i;
    }

    cout << "factorial " << n << " is " <<result;
    return result;
}

int main() {
    int n;
    cin>> n;

    factorial(n);

    return 0;
}