#include <iostream>
using namespace std;

// ���м�(Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�.
// ����� ����?
// -1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// -2) �ٸ� ��η� �����ϱ� ���ϴ� ���

/*
�ڵ���
- ���
- �ڵ�
- ����
- ��
- ���� ���⼱

�Ϲ� ������ ���忡�� ����ϴ� ��?
- �ڵ�/���/��
���� �� (������ �ǵ帮�� ū�� ��)
- ����, ���� ���⼱
*/

// (���) ���� ������   public  protected  private
// - public  : �������Գ� ��������.
// - protected : �ڽŰ� �ڽ��� ��ӹ޴� ��ü�� ��밡��
// - private : �ڽŸ� ��밡��

// ��� ���� ������ : ���� ���뿡�� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڽĿ��� ������� ���� ����.
// - public : ������ ��� �θ���� ���� ���� �״�� (public -> public, protected -> protected)
// - protected : ��ȣ���� ���? �� �ڼյ鿡�Ը� �����ٲ��� (public -> protected, protected -> protected) 
// - private : �������� ���. ���� ���� �ڼյ����� �ƹ��͵� ���ٲ�.(�̱���) (all to private)

class Car
{
public: // (���) ���� ������
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()
	{
		RunEngine();
	}
protected:
	void RunEngine() {} // Turn the Engine on
	void DisassembleCar() {} // Disassemble the car
	void ConnectCircuit() {} // Connect the circuits.
public:
	// Handle
	// Pedal
	// Engine...
	// Door
	// some circuits
};

class SuperCar : public Car // ��� ���� ������ -> ��κ��� ��� ��� ���� �� public ���. �ٸ� ���� �ſ� �幰�� ����Ѵ�.
{
public:
	void RunRemoteController() {
		TurnKey();
	}
};

class TestSuperCar : public SuperCar
{
public:
	void Test()
	{
		RunRemoteController();
	}
};

int main()
{
	SuperCar car2;
	car2.RunRemoteController();

	TestSuperCar car;
	car.RunRemoteController();

	return 0;
}