#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

void adjustDown(Heap* hp, int m)	//向下调整算法
{
	int cur = m;
	int n;
	
	while (cur * 2 + 1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size)
		{
			n = cur * 2 + 1;
		}
		else
		{
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur] < hp->data[n])
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;

			cur = n;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->capacity = 2 * n;
	hp->size = n;
	hp->data = (HPDataType*)calloc(hp->capacity, sizeof(HPDataType));

	for (int i = 0; i < n; i++)
	{
		hp->data[i] = a[i];
	}

	for (int i = n / 2 - 1; i >= 0; i--)	//最后一个非叶子节点 n / 2 - 1
	{
		adjustDown(hp, i);
	}
}

void HeapDestory(Heap* hp)
{
	if (hp->data)
	{
		free(hp->data);
	}
	hp->data = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

void HeapPush(Heap* hp, HPDataType x)	//向上调整算法
{
	if (hp->capacity == hp->size)
	{
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capacity * sizeof(HPDataType));
	}	

	int cur = hp->size;

	hp->data[hp->size] = x;
	hp->size++;

	while (cur > 0)
	{
		if (hp->data[cur] > hp->data[(cur - 1) / 2])
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;

			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* hp)
{
	if (hp->size == 0)
	{
		return;
	}
	hp->size--;

	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;

	adjustDown(hp, 0);
}

HPDataType HeapTop(Heap* hp)
{
	if (hp->size == 0)
	{
		return (HPDataType)0;
	}
	return hp->data[0];
}

int HeapSize(Heap* hp)
{
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

void HeapPrint(Heap* hp)
{
	int i;
	int rn = 0;
	int bin = 2;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			rn += bin;
			bin *= 2;
		}
	}
}

void HeapPrintS(Heap* hp)
{
	int i;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
}

void HeapSort(Heap* hp)	//pop函数会调用向下调整算法
{
	int temp = hp->size;

	while (hp->size > 1)
	{
		HeapPop(hp);
	}

	hp->size = temp;
}