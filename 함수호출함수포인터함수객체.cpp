#include <iostream>
using namespace std;

// Print3는 FuncObject 클래스의 객체이며 함수처럼 동작합니다. 

struct FuncObject
{
public:
	// 함수호출연산자 정의
	void operator() (int arg) const
	{
		cout << "정수: " << arg << endl; 
	}
};

void Print1(int arg)
{
	cout << "정수: " << arg << endl; 
}

int main()
{
	void (*Print2)(int) = Print1;   
	FuncObject Print3; 

	Print1(10);  // 첫째, '함수'를 사용한 정수 출력 
	Print2(10);  // 둘째, '함수포인터'를 사용한 정수 출력 
	Print3(10);  // 셋째, '함수객체'를 사용한 정수 출력 (Print3.operator(10)과 같음 

	return 0;
}