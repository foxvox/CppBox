#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;

struct SumFunctor : public unary_function<int, void>
{
	SumFunctor(int& number) : sum(number) {} 

	void operator() (int& number)
	{
		sum += number; 
		cout << GetSum() << endl; 
	}

	int GetSum() const
	{
		return sum; 
	}

private:
	int& sum; 
};

int main()
{
	array<int, 5> numbers = { 1, 2, 3, 4, 5 }; 
	int num = 0; 

	for_each(numbers.begin(), numbers.end(), SumFunctor(num));

	num = 0; 

	for_each
	(numbers.begin(), numbers.end(), 
		[&num](int& number)
		{
			num += number;
			cout << num << endl; 
		}
	); 

	auto introduce = [](string name)
		{
			cout << "My name is " << name << endl;
		}; 

	introduce("Alex Yun"); 

	return 0;
}

