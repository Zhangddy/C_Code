#ifndef _Stack_H_
#define _Stack_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BTree.h"

typedef BTNode * StDataType;

typedef struct Stack {
	StDataType* array;	// ָ��̬���ٵ�����
	size_t size;		// ��Ч���ݸ���
	size_t capicity;	// �����ռ�Ĵ�С
}Stack;

// ������ɾ��Ľӿ�
void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void StackPush(Stack* psl, StDataType x);
void StackPop(Stack* psl);
StDataType StackTop(Stack* psl);
int StackIsEmpty(Stack* psl);

#endif //_Stack_H_