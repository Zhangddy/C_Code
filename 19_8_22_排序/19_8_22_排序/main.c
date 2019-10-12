#include "sort.h"
#define BUFSIZE 100000

int main()
{
#if 1
	
	int src[11] = { 1, 3, 6, 7, 9, 2, 4, 8, 10, 5, 11 };
	//int src[6] = { 1, 3, 6, 7, 9, 2};

	//int src[3] = { 1, 3, 2 };
	//QuickSort(src, 11);
	SelectSort(src, 11);
	printArray(src, 11);
	//fun(src, 3);
#else
	srand(time(NULL));
	int src[BUFSIZE];
	int i;
	for (i = 0; i < BUFSIZE; i++)
	{
		src[i] = rand() % 5000 + 1;
	}
	QuickSortNonR(src, BUFSIZE);

	printArray(src, BUFSIZE);
	
#endif
	system("pause");
	return 0;
}