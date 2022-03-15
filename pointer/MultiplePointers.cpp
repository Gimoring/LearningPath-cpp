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
	// const char** a = pp�ּ�
	// *a = pp�� �������ִ� &msg�ּ�
	// �� msg �ּҸ� "Bye"�ּҷ�
	// cout << "pp�� �������ִ� &msg(hello �����ּ�)�� �ּ� " << a << endl;
	*a = "Bye"; // a == pp(&msg) -> *a == &msg(hello �����ּ�) = "Bye"("Bye" �ּ�)
}

int main()
{
	int a = 0;
	SetNumber(&a);
	// cout << a << endl;

	// .rdata [H][e][l][l][o][\0]
	// .rdata [B][y][e][\0]
	// 
	// msg[Hello�� �����ּ�] << 8bytes
	const char* msg = "Hello";

	//[�Ű�����][RET][�������� (msg(hello�� �ּ�)) ][�Ű����� a(Hello�� �ּ�)][RET][��������]
	// ���ο� ���� a �� hello�� �ּҸ� ����. (msg�� hello�� �ּ�) 
	// ���ο� ���� a �� �ּҸ� bye�� �ּҷ� �ٲ�.
	// msg ���� ����.
	SetMessage(msg);
	cout << msg << endl;
	
	// Hello�ּ�[.rdata [H][e][l][l][o][\0]]
	// &msg[Hello �ּ�] << 8����Ʈ
	// pp[&msg]  << 8����Ʈ
	const char** pp = &msg;

	//[�Ű�����][RET][�������� (msg(hello�� �ּ�)) ][�Ű�����(a((msg�� �ּ�)))][RET][��������]
	//���ο� ���� a �� pp(&msg)�� �ּҸ� ����.
	//*p�� pp �� �������ִ� &msg�ּ��� ���� ������ 
	// ���? �ּҰ� �� �ֳ�? -> �� �ּҸ� �ٲٴ� ��. (&msg�� �������ִ� ��(�ּ�)�� �ٲ�)
	// �׷��� �ٲ�� ��.
	SetMessage(pp);
	cout << msg << endl;
	return 0;
}