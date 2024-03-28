#include <iostream>
#include <array>
#include <algorithm> 
#include <functional>
using namespace std;

static function<void()> getLambda()
{
	return []() { cout << "Hello Lambda!" << endl; }; 
}

int main()
{
	auto foo = getLambda(); 

	foo(); 

	return 0;
}

