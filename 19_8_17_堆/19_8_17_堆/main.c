#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int data[10] = { 6, 2, 5, 4, 1, 9, 8, 10, 7, 3 };
	Heap hp;

	HeapInit(&hp, data, 10);


	HeapPush(&hp, 13);
	HeapPush(&hp, 11);

	HeapPop(&hp);

	HeapPrint(&hp);

	HeapSort(&hp);

	putchar('\n');
	HeapPrintS(&hp);

	HeapDestory(&hp);
	system("pause");
	return 0;
}