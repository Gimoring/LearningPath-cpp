#include <iostream>
using namespace std;

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	// const char** a = pp주소
	// *a = pp가 가지고있는 &msg주소
	// 이 msg 주소를 "Bye"주소로
	// cout << "pp가 가지고있는 &msg(hello 시작주소)의 주소 " << a << endl;
	*a = "Bye"; // a == pp(&msg) -> *a == &msg(hello 시작주소) = "Bye"("Bye" 주소)
}

int main()
{
	int a = 0;
	SetNumber(&a);
	// cout << a << endl;

	// .rdata [H][e][l][l][o][\0]
	// .rdata [B][y][e][\0]
	// 
	// msg[Hello의 시작주소] << 8bytes
	const char* msg = "Hello";

	//[매개변수][RET][지역변수 (msg(hello의 주소)) ][매개변수 a(Hello의 주소)][RET][지역변수]
	// 새로운 변수 a 는 hello의 주소를 가짐. (msg도 hello의 주소) 
	// 새로운 변수 a 의 주소를 bye의 주소로 바꿈.
	// msg 영향 없음.
	SetMessage(msg);
	cout << msg << endl;
	
	// Hello주소[.rdata [H][e][l][l][o][\0]]
	// &msg[Hello 주소] << 8바이트
	// pp[&msg]  << 8바이트
	const char** pp = &msg;

	//[매개변수][RET][지역변수 (msg(hello의 주소)) ][매개변수(a((msg의 주소)))][RET][지역변수]
	//새로운 변수 a 는 pp(&msg)의 주소를 가짐.
	//*p로 pp 가 가지고있는 &msg주소의 값을 가져옴 
	// 어라? 주소가 또 있네? -> 그 주소를 바꾸는 것. (&msg가 가지고있는 값(주소)를 바꿈)
	// 그래서 바뀌는 것.
	SetMessage(pp);
	cout << msg << endl;
	return 0;
}