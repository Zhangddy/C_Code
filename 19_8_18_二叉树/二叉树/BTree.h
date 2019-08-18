#ifndef _BTree_H_
#define _BTree_H_
#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;

typedef struct BinaryTreeNode 
{
	BTDataType _data;    
	struct BinaryTreeNode* _left;   
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##
BTNode* BinaryTreeCreate(BTDataType* src);

void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root); //
int BinaryTreeLeafSize(BTNode* root);//
int BinaryTreeLevelKSize(BTNode* root, int k);//第几层有几个节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 遍历 
void BinaryTreePrevOrder(BTNode* root); 
void BinaryTreeInOrder(BTNode* root); 
void BinaryTreePostOrder(BTNode* root);

// 非递归遍历
// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root); 
// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root); 
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void TestBinaryTree();

#endif // !