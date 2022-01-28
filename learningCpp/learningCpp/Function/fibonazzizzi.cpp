#include <iostream>
using namespace std;
/*  for given n  print n rows and fibonazzizzi
    0                   i = 1    
 *  1   1               i = 2
 *  2   3   5           i = 3
 *  8   13  21  34      i = 4
 * 
*/


int main() {
    int n = 4;
    int i = 1;
    int firstFibo = 0;
    int secondFibo = 1;
    while(i <= n){
        int cnt = 1;
        while(cnt <= i){
            cout<<firstFibo<<"\t";
            int thirdFibo = firstFibo + secondFibo; 
            firstFibo = secondFibo; 
            secondFibo = thirdFibo; 
            cnt++;
        }
        i++;
        cout<<endl;
    }
    
    return 0;
}