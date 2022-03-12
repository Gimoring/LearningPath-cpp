#include <iostream>
using namespace std;

/**
 * ::variableName = scope resolution operator  가장 우선순위가 높은 연산자 라고 한다. 
 * 변수의 이름 앞에 붙이면 해당 변수는 전역변수로 사용.
 * 클래스에 이 연산자를 사용하면 네임스페이스 멤버를 식별하거나, 클래스의 정적 멤버를 호출할 수 있다.
 * ex) std::cout....
*/
int x = 10;

int main() {
    x = 12;
    int x = 10;

    int i;
    for(i=0;i<5;i++) {
        x=i;
        cout<<x<<"--"<<::x<<endl;
    }

    cout<<"value of x is "<<x<<endl;

    ::x = ::x + 2;
    cout<<"value of global x is "<<::x<<endl;
    cout<<i<<endl;
    
    return 0;
}