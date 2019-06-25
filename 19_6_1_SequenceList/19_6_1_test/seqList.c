#include "seqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->capicity = capacity;
	psl->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}

void CheckCapacity(SeqList* psl) //检查上限扩容
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType*)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//尾插 O(1)
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl || psl->size);
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//头插 O(N)
{
	assert(psl);
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos <= psl->size);
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//删掉某个下标元素
{
	assert(psl || pos < psl->size);
	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)//删除第一个值为X的元素
{
	assert(psl);

	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);
	psl->array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}