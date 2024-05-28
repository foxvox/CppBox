#include <iostream>
#include <array>
#include <algorithm> 
#include <functional>
#include <stdio.h> 
using namespace std; 

#pragma warning(disable:4996)

//현재 배열 상태를 보여준다. 
void trace(int A[], int N)
{
	int i; 
	for (i = 0; i < N; i++)
	{
		if (i > 0) printf(" "); 
		printf("%d", A[i]); 
	}
	printf("\n"); 
}

void insertionSort(int A[], int N)
{
	int i, j, v; 
	for (i = 1; i < N; i++)
	{
		//두번째 자료부터 하나씩 증가시키면서 focusing data를 옮겨간다. 
		v = A[i]; 
		//focusing data 바로 앞 index를 j에 할당한다. 
		j = i - 1; 
		while (j >= 0 && A[j] > v)
		{
			//focusing된 자료보다 비교 자료가 더 크면 뒤로 한칸씩 밀어서 
			A[j + 1] = A[j]; 
			j--; 
		}
		//자신보다 큰수를 뒤로 한칸씩 밀면서 자신의 index를 찾으면 바로 위 j--에 의해 한칸 앞 index를 가리키므로 
		//j + 1 위치에 insert하기 위해 준비된 v를 삽입한다. 그리고 다음 자료를 같은 방식으로 자신의 index 위치에 
		//계속해서 삽입해 나간다. 
		A[j + 1] = v; 
		trace(A, N); 
	}
}

int main() 
{
	int N, i; 
	int A[100]; 

	printf("삽입정렬할 자료의 개수: "); 
	//삽입정렬할 자료의 개수를 입력받는다. 
	scanf("%d", &N); 
	//개수 만큼 실제 정수 자료를 입력받는다. 
	printf("%d개 만큼 자료를 입력해 주세요: ", N); 
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]); 

	//입력 받은 최초 상태를 보여준다. 
	trace(A, N); 
	//삽입정렬을 수행하면서 단계별 상태를 출력해서 보여준다. 
	insertionSort(A, N); 

	return 0;
}

