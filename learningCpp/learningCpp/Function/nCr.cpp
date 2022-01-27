#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for(int i = 2; i<=n; i++) {
        result *=i;
    }

    cout << "factorial " << n << " is " <<result<< endl;
    return result;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(n-r) * factorial(r));
}

int main () {
    int n, r;
    cin >> n >> r;

    cout<<nCr(n, r);

}