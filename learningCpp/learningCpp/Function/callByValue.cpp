#include <iostream>
using namespace std;

void myswap(int a, int b) {
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    cout << "In function"<< endl;
    cout << a << " " << b << endl;
}

int main () {
    int a, b;
    a = 7;
    b = 10;
    cout << "Before swapping" << endl;
    cout << a << " " << b << endl;
    myswap(a, b);

    cout << "After swapping" << endl;
    cout << a << " " << b << endl;
    // they are same because they have different scope.
}