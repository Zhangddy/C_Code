#include "BTree.h"
#include "queue.h"
#include "stack.h"
//函数内部带static的只能调用一次哦
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int s_n;

BTNode *BinaryTreeCreateExe(BTDataType * src)
{
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	s_n++;

	cur->_left = BinaryTreeCreateExe(src);
	cur->_right = BinaryTreeCreateExe(src);
	return cur;
}

BTNode *BinaryTreeCreate(BTDataType * src)
{
	s_n = 0;
	return BinaryTreeCreateExe(src);
}


void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		putchar(root->_data);
	}
}

void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
	}
}

void BinaryTreeLevelOrder(BTNode* root)	//层序遍历,借助队列
{
	Queue qu;
	BTNode* cur;
	QueueInit(&qu);
	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->_data);

		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}

void BinaryTreePrevOrderNonR(BTNode* root)	//非递归先序,堆栈
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);

	while (cur)
	{
		putchar(cur->_data);
		if (cur->_right)
		{
			StackPush(&st, cur->_right);
		}

		if (cur->_left)
		{
			cur = cur->_left;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	StackInit(&st, 100);

	BTNode* cur = root;

	while (1)
	{
		for (; cur; cur = cur->_left)
		{
			StackPush(&st, cur);
		}

		cur = StackTop(&st);
		if (!cur)	//栈为空时
		{
			break;
		}
		putchar(cur->_data);
		StackPop(&st);
		cur = cur->_right;
	}
	StackDestory(&st);
}
void BinaryTreePostOrderNonR(BTNode* root)	//建议背
{
	char tag[64];
	Stack st;
	StackInit(&st, 100);

	BTNode* cur = root;

	do
	{
		for (; cur; cur = cur->_left)	//遍历左子树,将所有节点入栈,且清空LT标记
		{
			StackPush(&st, cur);
			tag[st.size - 1] = 0;
		}

		while (!StackIsEmpty(&st) && tag[st.size - 1])	//连续出栈
		{
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);	//会导致size--;
		}

		if (!StackIsEmpty(&st))
		{
			cur = StackTop(&st);
			tag[st.size - 1] = 1;
			cur = cur->_right;
		}
	} while (!StackIsEmpty(&st));
	StackDestory(&st);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->_data);
		if (cur->_right && !cur->_left)
		{
			return 0;
		}
		if (tag && (cur->_right || cur->_left))
		{
			return 0;
		}
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}



int BinaryTreeSize(BTNode* root)
{
	static int TreeSize;
	if (root)
	{
		TreeSize++;
		BinaryTreeSize(root->_left);
		BinaryTreeSize(root->_right);
	}

	return TreeSize;
}



int BinaryTreeLeafSize(BTNode* root)
{
	static int TreeLeafSize;
	if (root)
	{
		if ((root->_left) == NULL && (root->_right) == NULL)
		{
			TreeLeafSize++;
		}
		BinaryTreeLeafSize(root->_left);
		BinaryTreeLeafSize(root->_right);
	}
	
	return TreeLeafSize;
}



int BinaryTreeLevelKSize(BTNode* root, int k)
{
	static int K;
	static int LevelKSize;
	if (root)
	{
		K++;
		if (k == K)
		{
			LevelKSize++;
		}
		BinaryTreeLevelKSize(root->_left, k);
		BinaryTreeLevelKSize(root->_right, k);
		K--;
		
	}
	return LevelKSize;
}



BTNode* BinaryTreeFind(BTNode* root, BTDataType x)	//返回相同数值的节点
{
	static BTNode* cur;
	if (root)
	{
		if (root->_data == x)
		{
			cur = root;
		}
		BinaryTreeFind(root->_left, x);
		BinaryTreeFind(root->_right, x);
	
	}
	if (cur)
	{
		return cur;
	}
	else
	{
		return (BTDataType)0;
	}
}