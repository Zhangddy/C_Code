#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10

typedef enum Status{
	success,
	fail,
	fatal,		//ÖÂÃü´íÎó
	range_error	//Ô½½ç´íÎó
}Status;

typedef int ElemType;

typedef struct SqList
{
	ElemType *elem;
	int length;
	int list_size;
}SqList, *Ptr;

typedef Ptr *SqlListPtr;

Status List_Init(SqlListPtr L)
{
	Status s = success;

	(*L)->list_size = LIST_INIT_SIZE;
	(*L)->length = 0;
	(*L)->elem = (ElemType)malloc(sizeof(ElemType) * (*L)->list_size);
	if ((*L)->elem == NULL)
		s = fatal;
	return s;
}

Status List_Retrival(SqlListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
	if (L)
	{
		if ((pos - 1) >= 0 && (pos - 1) < (*L)->length)
		{
			*elem = (*L)->elem[pos - 1];
			s = success;
		}
	}
	else
		s = fatal;
	return s;
}


int main()
{
	SqList L1, L2;
	Ptr sql1 = &L1;
	List_Init(&sql1);
	return 0;
}
