#include <iostream>
using namespace std;
/*
    given n number, and print the following pattern
    ____1       i=1     5-1 = 4 spaces      starting from i = 1     middle = 2-1 = 1        to end (from 2*1-2 )  0 ? => x
    ___232      i=2     5-2 = 3 spaces      starting from i = 2     middle = 4-1 = 3        to end (from 2*2-2 ) = 2 to 2   (i)
    __34543     i=3     5-3 = 2 spaces      starting from i = 3     middle = 6-1 = 5        to end (from 2*3-2 ) = 4 to 3   (i)
    _4567654    i=4     5-4 = 1 spaces      starting from i = 4     middle = 8-1 = 7        to end (from 2*4-2 ) = 6 to 4   (i)
    567898765   i=5     5-5 = 0 spaces      starting from i = 5     middle = 10-1 = 9       to end (from 2*5-2 ) = 8 to 5   (i)
*/
int main() {
    int n;
    cin >> n;

    int i = 1;
    while(i <= n) {
        //spaces
        int space = 1;
        while(space <= n-i) {
            cout<<" ";
            space++;
        }
        //start    
        int start = i;              // start = 1            // start = 2        // start = 3
        while(start <= (2*i)-1) {   // 1 <=  2*1 -1 = 1     // 2 <= 2*2 -1 = 3  // 3 <= 3
            cout<<start;            // true   1             // true      2      // true       3 
            start++;                // start = 2            // start = 2        // start = 4
        }
        //end
        int end = 2*i-2;            // end = 0              // end = 2          
        while(end >= i) {         // 0 >= 1  false        // 2 >= 2 
            cout<<end;              // false                // true
            end--;                   
        }

        cout<<endl;
        i++;
    }

    return 0;      
}