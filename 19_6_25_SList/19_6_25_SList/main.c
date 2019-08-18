#include "seqList.h"


int main()
{

	SList test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 4);
	SListPushFront(&test, 6);
	SListPushFront(&test, 9);

	SListPrint(&test);
	SListReverse(&test);
	SListPrint(&test);
	SListDestory(&test);
	system("pause");
	return 0;
}