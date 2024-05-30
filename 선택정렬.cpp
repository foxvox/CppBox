#include <iostream>
#include <array>
#include <algorithm> 
#include <functional>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std; 

#pragma warning(disable:4996) 

void printArray(int values[], int count);
void SelectionSort(int values[], int count); 

void SelectionSort(int values[], int count)
{
	int i = 0, j = 0; 
	int min = 0, temp = 0; 

	for (i = 0; i < count - 1; i++)
	{
		//정렬 안된 요소의 첫번째 요소의 index를 min으로 잡고 순회하다 최소값이 찾아지면 
		//최소값의 index를 min변수에 할당한다.  
		min = i; 
		//비교대상 index 1부터 끝까지 이동하면서 가장 작은 수의 index를 찾아낸다. 
		for (j = i + 1; j < count; j++)
		{
			if (values[j] < values[min])
				min = j; 
		}
		//찾아낸 최소값의 index를 현재 focusing된 순회 index 위치의 값과 교환한다. 
		//즉 정렬 안된 요소들 중 가장 작은 값을 가장 앞으로 보낸다. 
		temp = values[i]; 
		values[i] = values[min]; 
		values[min] = temp;

		printf("Step-%d:  ", i + 1); 
		printArray(values, 8); 
		printf("\n"); 
	}
}

void printArray(int values[], int count)
{
	int i = 0; 
	for (i = 0; i < count; i++)
		printf("%d  ", values[i]); 	
}


int main() 
{
	int values[] = { 80, 75, 10, 60, 15, 49, 12, 25 }; 

	printf("선택 정렬 실행 전 \n"); 
	printArray(values, 8);
	cout << endl; 

	printf("\n선택 정렬이 시작됩니다. \n"); 
	SelectionSort(values, 8); 

	printf("\n선택 정렬 결과 \n"); 
	printArray(values, 8); 
	cout << endl; 

	return 0;
}

