#include <iostream>
using namespace std;
/*
    given n, pr]int the following pattern
    if n = 5
    1           i = 1       i     ?     
    0 1         i = 2       even  0
    1 0 1       i = 3       odd   1
    0 1 0 1     i = 4
    1 0 1 0 1   i = 5

*/
int main() {
    int n;
    cin >> n;

    int i = 1;
    while (i <= n) {
        int value = 0;
        if(i % 2 == 0) {
            value = 0;
        } else {
            value = 1;
        }

        int count = 1;
        while(count <= i) {
            cout<<value;

            if(value == 1) {
                value = 0;
            } else if (value == 0) {
                value = 1;
            }
            count++;
        }
        cout<<endl;
        i++;
    }
}