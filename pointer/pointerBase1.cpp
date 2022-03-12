#include <iostream>
using namespace std;

//--------------------------------------------------------------//
//                          POINTER                             //
//--------------------------------------------------------------//

int main ()
{
    // The way we used until now
    // make a box which has 4 bytes of integer data type and name it number
    // then allocate the (variable) box into stack memory ( because this box is located in the main function )
    // number = 1; means put 1 banana into the box
    // so it's like that we put a specific value into the box which places in stack memory.
    // for 'number' we named for the box, we can say, we named it to memory. (compiler does this job)
    int number = 1; 

    // pointer 
    // TYPE* name :
    
    // Yes, It is a box.
    // but this box saves the memory address 
    // 64비트면 8바이트 고정 크기.
    int* ptr;
    cout << ptr << endl;
    ptr = &number;
    cout << ptr << endl;

    // SO, What can we do with the address?
    // *NAME = someValue;
    // This means GO TO [A BOX WHICN HAS AN ADDRESS] and DO STH

    // If it's not understandable, think like this 'Go to portal, and teleport'
    // 1) When you declare a variable using *, this is just a box which contains its address
    // 2) When you just use it, this means you are teleporting to the address (and do whatever you like)

    int value1 = *ptr;
    cout << value1 << endl; //  assigning the value of ptr variable to value1 (if it's &ptr then the address.)
    *ptr = 2;
    cout << number << endl; 
    cout << ptr << endl; // address of ptr variable


    return 0;
}