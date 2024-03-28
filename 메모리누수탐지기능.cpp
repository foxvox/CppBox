#include <iostream>
#include <conio.h> 
#include <stdlib.h>
#include <crtdbg.h> 

#define _CRTDBG_MAP_ALLOC

#if _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	// Code here...


	_CrtDumpMemoryLeaks();
	return 0;
}

