#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;

public:
	Point(int _x = 0, int _y = 0)
		: x(_x), y(_y)
	{}

	bool operator==(const Point& arg) const
	{
		return x == arg.x && y == arg.y ? true : false;
	}

	bool operator!=(const Point& arg) const
	{
		return !(*this == arg);
	}
	// 전위--
	const Point& operator--()
	{
		--x;
		--y;
		return *this;
	}

	// 후위--
	const Point operator--(int)
	{
		Point pt(x, y);
		x--;
		y--;
		return pt;

		/*
		Point tmp = *this;
		// 전위++이 구현되어 있는 상태이고 그것을 사용하는 방식
		// 중복코드를 피하는 방법
		--*this;
		return tmp;
		*/
	}

	// 전위++
	const Point& operator++()
	{
		// this객체 변경 
		++x;
		++y;
		// 변경된 this객체 반환 
		return *this;
	}

	// 후위++
	const Point operator++(int)
	{
		// this객체의 위치 정보로 생성자 호출 
		Point pt(x, y);

		// this객체 변경! 
		x++;
		y++;

		// 변하기 전 this객체를 가진 pt를 반환한다. 
		return pt;

		/*
		Point tmp = *this;
		// 전위++이 구현되어 있는 상태이고 그것을 사용하는 방식
		// 중복코드를 피하는 방법
		++*this;
		return tmp;
		*/
	}

	const Point operator-(const Point& arg) const
	{
		return Point(x - arg.x, y - arg.y); 
	}

	void Print() const
	{
		cout << x << ',' << y << endl;
	}

	int GetX() const
	{
		return x;
	}

	int GetY() const
	{
		return y;
	}
};



int main()
{
	Point p1(2, 3), p2(5, 5); 
	Point p3; 

	p3 = p1 - p2; 

	p3.Print(); 	

	return 0;
}

