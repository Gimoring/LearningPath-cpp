#include <iostream>
using namespace std;
/*
    given n, m numbers and swap them.
*/
int main() {
    
    int a, b;
    cin >> a >> b;
    /* solution 1번째 
    int temp = a;
    a = b;
    b = temp;
    */
    // solution 2
    swap(a, b);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;


    return 0;
}