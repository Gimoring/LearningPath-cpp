#include <iostream>
using namespace std;
/* given n number and print following pattern
    ____1       i = 1       5-1 = 4 spaces      2*1-1 = 1   from 1 to 1 
    ___123      i = 2       5-2 = 3 spaces      2*2-1 = 3   from 1 to 3
    __12345     i = 3       5-3 = 2 spaces      2*3-1 = 5   frin 1 to 5
    _1234567    i = 4       5-4 = 1 spaces      2*4-1 = 7   from 1 to 7
    123456789   i = 5       5-5 = 0 spaces      2*5-1 = 9   from 1 to 9

    ====>   for space it follows like this (n-i);
    ====>   for numbers it follows like this (2i-1)
 */
int main () {
    int n;
    cin >> n;

    int i = 1;
    while (i <= n) {
        int space = 1;
        while(space <= n-i) {
            cout<<" ";
            space++;
        }

        int num = 1;
        while(num <= i*2-1) {
            cout<<num;
            num++;
        }
        cout<<endl;

        i++;
    }
}