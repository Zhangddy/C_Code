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
		t->lchild=create(p, 2*pose+1,size);//�ݹ鴴�������� 
		t->rchild=create(p, 2*pose+2,size);//�ݹ鴴�������� 
	}
	return(t);
}

//���� 
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
//���� 
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
 	printf("\n�����������: ");
	Preorder(root);

	printf("\n�����������: ");
	Inorder(root);
	return 0;
}
