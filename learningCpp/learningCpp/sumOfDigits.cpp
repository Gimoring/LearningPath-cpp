//
//  sumOfDigits.cpp
//  learningCpp
//
//  Created by Junpil Byeon on 2022/01/23.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    
    int sum = 0;
    
    while(n != 0) {
        int lastDigit = n % 10;
        sum += lastDigit;
        
        n = n/10;
    }
    
    cout<<sum<<endl;
    
    return 0;
}
