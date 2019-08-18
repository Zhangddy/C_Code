#ifndef _SLIST_H_
#define _SLIST_H_
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//无头单链表
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;//无头单链表,头也保存数据
}SList;


void SListInit(SList* plist); 
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x); // 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x); // 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist); void TestSList();

#endif //SLIST_H_