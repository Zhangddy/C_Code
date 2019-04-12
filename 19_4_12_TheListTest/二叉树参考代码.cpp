#include <stdio.h>
#include <malloc.h> 
#include  <string.h>

struct BiTreeNode
{
	char data;
	BiTreeNode *lchild, *rchild;
}*root;

BiTreeNode *create(char* str, int pose, int size)
{
	char ch;
	BiTreeNode * t;
	char* p=str;
	ch = p[pose]; 
	
	if(ch==' '|| ch=='\n'|| pose>=size)
		return NULL;
	else
	{
		t=(BiTreeNode *)malloc(sizeof(BiTreeNode)); 
		t->data=ch;
		t->lchild=create(p, 2*pose+1,size);//递归创建左子树 
		t->rchild=create(p, 2*pose+2,size);//递归创建右子树 
	}
	return(t);
}

//先序 
void Preorder(BiTreeNode *root)
{
	BiTreeNode *t=root;
	if(NULL!=t)
	{
		printf("%c", t->data); 
		Preorder(t->lchild); 
		Preorder(t->rchild); 
	}
}
//中序 
void Inorder(BiTreeNode *root)
{
	BiTreeNode *bt=root;
	if(NULL!=bt)
	{		
		Inorder(bt->lchild); 
		printf("%c", bt->data);
		Inorder(bt->rchild); 
	}
}

 
int main()
{

	char s[20];
	scanf("%s", s);
	root=create(s, 0,strlen(s));
 	printf("\n先序遍历序列: ");
	Preorder(root);

	printf("\n中序遍历序列: ");
	Inorder(root);
	return 0;
}
