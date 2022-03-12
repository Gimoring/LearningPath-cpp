#include<iostream>
using namespace std;

void print(int n){
    // complete this function
    for(int i = 1; i<=n; i++) {
        if(i>1) {
            cout<<i-1;
        } else {
            cout<<i;   
        }
        for(int j = 1; j<=i-2; j++) {
            cout<<"0";
        }
        if(i> 1) {
            cout<<i-1<<endl;
        } else {
            cout<<endl;
        }
    }
}

int main() {

    print(5);

    return 0;
}