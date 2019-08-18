#include "seqList.h"

// 1����ͷ�����ѭ��������ɾ���ʵ�� 


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListDestory(SList* plist)//ͷɾ����Pop
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
void SListInsertAfter(SListNode* pos, SLTDataType x) // ��pos��ǰ����в���
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
������α���

for(cur = head; cur; cur = cur->next)���򲻴�ͷ
{
	cur;
}
for(cur = head->next_or_pre; cur!=head; cur = cur->next)˫���ͷ
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
	SListNode * tmp = plist->_head->_next; //��¼next
	SListNode * cur = plist->_head;
	cur->_next = NULL; //��������ͷ��������next�Ͽ�����tmp��¼���������ҵ�
	while (tmp) //ÿ��ѭ����Ҫ��ɶ�����Ȼ��;�ͷ���³����Ĺ��̣�����������(tmpΪ��)����ѭ��
	{
		plist->_head = tmp; //����ͷ��tmpλ�û��Ϊ�µ�ͷ����ͷ�������ĵ�һ���ڵ�
		tmp = tmp->_next; //��¼�´�ѭ����tmp ��λ�ã���Ϊtmp�����ѭ�����Ѿ������ˣ����Һ������Ͼ�Ҫ���������Ա����������¼
		plist->_head->_next = cur; //���������ͷ�γ�����
		cur = plist->_head; //��¼��ͷ��λ�ã������´�ѭ������
	}

#endif
}






