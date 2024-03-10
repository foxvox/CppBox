#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

	friend const Point& operator-(const Point& argL, const Point& argR);

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

	/*
	const Point& operator-(const Point& arg) const
	{
		return Point(x - arg.x, y - arg.y);
	}
	*/

	int operator[](int idx) const
	{
		if (idx == 0)
			return x;
		else if (idx == 1)
			return y;
		else
			throw "이럴 수는 없는 거야!"; 
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

const Point& operator-(const Point& argL, const Point& argR)
{
	// return Point(argL.GetX() - argR.GetX(), argL.GetY() - argR.GetY());
	// friend const Point& operator-(const Point& argL, const Point& argR); 
	// 설정을 해 놓았기때문에 private x, y에 직접 접근이 가능해졌다. 
	return Point(argL.x - argR.x, argL.y - argR.y);
}

int main()
{
	Point p1(2, 3);
	p1.Print(); 

	cout << p1[0] << ',' << p1[1] << endl; 

	return 0;
}

