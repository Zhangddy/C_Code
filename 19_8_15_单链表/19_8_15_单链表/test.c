#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum Status {
	success,
	fail,
	fatal,		//ÖÂÃü´íÎó
	range_error	//Ô½½ç´íÎó
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