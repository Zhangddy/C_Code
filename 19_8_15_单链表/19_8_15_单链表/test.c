#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum Status {
	success,
	fail,
	fatal,		//��������
	range_error	//Խ�����
}Status;

typedef int ElemType;

typedef struct Node
{
	ElemType elem;
	struct Node *next;
}Node, *Ptr;

typedef Ptr *SqListPtr;

int main()
{

	return 0;
}