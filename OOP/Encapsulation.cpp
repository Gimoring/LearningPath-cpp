#include <iostream>
using namespace std;

// 은닉성(Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다.
// 숨기는 이유?
// -1) 정말 위험하고 건드리면 안되는 경우
// -2) 다른 경로로 접근하길 원하는 경우

/*
자동차
- 페달
- 핸들
- 엔진
- 문
- 각종 전기선

일반 구매자 입장에서 사용하는 것?
- 핸들/페달/문
몰라도 됨 (오히려 건드리면 큰일 남)
- 엔진, 각종 전기선
*/

// (멤버) 접근 지정자   public  protected  private
// - public  : 누구에게나 열려있음.
// - protected : 자신과 자신을 상속받는 객체도 사용가능
// - private : 자신만 사용가능

// 상속 접근 지정자 : 다음 세대에게 부모님의 유산을 어떻게 물려주지?
// 부모님한테 물려받은 유산을 꼭 나의 자식에게 물려줘야 하진 않음.
// - public : 공개적 상속 부모님의 설계 유산 그대로 (public -> public, protected -> protected)
// - protected : 보호받은 상속? 내 자손들에게만 물려줄꺼양 (public -> protected, protected -> protected) 
// - private : 개인적인 상속. 나만 쓰고 자손들한테 아무것도 안줄꺼.(이기적) (all to private)

class Car
{
public: // (멤버) 접근 지정자
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

class SuperCar : public Car // 상속 접근 지정자 -> 대부분의 경우 상속 받을 때 public 사용. 다른 것은 매우 드물게 사용한다.
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