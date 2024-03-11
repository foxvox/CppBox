#include <iostream>
using namespace std;

int main()
{
	int array[3] = { 10, 20, 30 }; 
	int* pArray; 

	pArray = array; 

	printf("%d \n", pArray[0]); 
	printf("%d \n", pArray[1]); 
	printf("%d \n", pArray[2]); 

	return 0; 
}

