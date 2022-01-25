#include <iostream>
using namespace std;

int main() {
    // start    0, 
    // end      array.length-1;
    int a[5] = {1, 2, 3, 4, 5};

    int start = 0;
    int end = 5-1;

    while(start <= end) {
        swap(a[start], a[end]);

        start++;
        end--;
    }

    for(int i=0; i < 5; i++) {
        cout<<a[i]<<endl;
    }

    return 0;
}