#include "seqList.h"

// 1、无头单向非循环链表增删查改实现 


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist)//头删类似Pop
{
	assert(plist);
	SListNode* tmp;
	while (plist->_head)
	{
		SListNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

SListNode* BuySListNode(SLTDataType x)
{

}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->_head)
	{
		SListNode* tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x) // 在pos的前面进行插入
{
	SListNode* cur = (SListNode*)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;
	pos->_next = cur;

}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* tmp = pos->_next;
	pos->_next = tmp->_next;
	free(tmp);
}
void SListRemove(SList* plist, SLTDataType x)
{

}
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
/*
链表如何遍历

for(cur = head; cur; cur = cur->next)单向不带头
{
	cur;
}
for(cur = head->next_or_pre; cur!=head; cur = cur->next)双向带头
{
	cur;
}
*/

void SListReverse(SList* plist)
{
#if 0
	assert(plist->_head);
	SListNode* tmp = plist->_head->_next;
	SListNode* cur = plist->_head;
	
	while (tmp)
	{
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;

		plist->_head = tmp;
		tmp = cur->_next;
	}
#else
	SListNode * tmp = plist->_head->_next; //记录next
	SListNode * cur = plist->_head;
	cur->_next = NULL; //断链，将头结点和他的next断开，有tmp记录，所以能找到
	while (tmp) //每次循环都要完成断链，然后和旧头重新成链的过程，当旧链结束(tmp为空)跳出循环
	{
		plist->_head = tmp; //换新头，tmp位置会成为新的头，旧头成了它的第一个节点
		tmp = tmp->_next; //记录下次循环中tmp 的位置，因为tmp在这次循环中已经用完了，而且后面马上就要断链，所以必须在这里记录
		plist->_head->_next = cur; //断链，与旧头形成新链
		cur = plist->_head; //记录旧头的位置，方便下次循环成链
	}

#endif
}






