#include <iostream>
using namespace std;

class Array
{
private:
	int* arr; 
	int size; 
	int capa; 

public:
	Array(int cap = 100)
		: arr(0), size(0), capa(cap)
	{
		arr = new int[capa]; 
	}

	~Array()
	{
		delete[] arr; 
	}

	void Add(int data)
	{
		if (size < capa)
			arr[size++] = data; 
	}

	int Size() const
	{
		return size; 
	}

	int operator[](int idx) const
	{
		return arr[idx]; 
	}
};

int main()
{
	Array ar(10);

	ar.Add(10); 
	ar.Add(20); 
	ar.Add(30); 

	for (int i = 0; i < ar.Size(); i++)
		cout << ar[i] << endl; 

	return 0;
}

