#include <iostream>
#include <malloc.h>
using namespace std;

const int n = 20;

#define TRUE 1
#define FALSE 0
#define UNFOUND -1 
#define   MAX_SIZE  10

/*-------------------------------------------------------------------------------------------*/
typedef struct
{
	int num;
	char name;
	char sex;
	float english;
	float math;
}Stu;

typedef struct
{
	Stu data;
	int length;
}Sqlist,*SqlistPtr;

typedef struct BiTreeNode//�����Ķ����� 
{
	Stu infor;
	struct BiTreeNode *lchild,*rchild;
}BiTNode,*BiTree; 

typedef struct node
{
	Stu data;
	struct node *next;
}Node,*Link;

/*-------------------------------------------------------------------------------------------*/
void Initlist(Stu *s)
{
	s=(Stu*)malloc(sizeof(Stu)*n);
}

void getlistinfo(Stu *s)
{
	Stu *p = s;
	FILE *f;
	int i;
	f=fopen("xx.txt","r");
	for (i = 1; i <= n; i++)
	{
		fscanf(f, "%d %c %c %f %f\n", &p->num, &p->name, &p->sex, &p->english, &p->math);
		p++;	 
	}
	fclose(f);
}

void Printlist(Stu *s)
{
	Stu *p = s;

	int i;
	for (i = 1; i <= n; i++) {
		printf("%d %c %c %.2f %.2f\n", p->num, p->name, p->sex,p->english, p->math);
		p++;
	}
}
/*-------------------------------------------------------------------------------------------*/
void qksortenglish(Stu *s,int t=0,int w=20-1)
{
	Stu *p = s;
	int i, j,k;
	Stu x;
	if(t>=w) return;
	i=t;j=w;x=p[i];
	while(i<j)
	{
		while ((i<j)&&(p[j].english<=x.english)) 
			j--;
		if(i<j) 
		{
			p[i]=p[j];
			i++;	
		}
		while ((i<j)&&(p[i].english>=x.english)) 
			i++;
		if(i<j)
		{
			p[j]=p[i];
			j--;
		}
	}
	p[i]=x;
	qksortenglish(s,t,j-1);
	qksortenglish(s,j+1,w);
} 
/*-------------------------------------------------------------------------------------------*/
int BinarySearch(Stu *s,int key,int u=20)//����λ�� 
{
	Stu *p = s;
	int low=0;
	int high=u-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key == p[mid].english)
			return mid;
		else if(key>p[mid].english)
			high=mid-1;
		else low=mid+1;
	}
	return UNFOUND;
}

void HashFun()
{
	
}

/*-------------------------------------------------------------------------------------------*/
void Preorder(BiTree t)
{	
	BiTree root = t;
	if(NULL!=t)
	{
		printf("%c",root->infor.name);
		Preorder(root->lchild); 
		Preorder(root->rchild); 
	}
}


int SearchBST(BiTree T,char key,BiTree f,BiTree &p )//������ 
{  
	 if(!T)  {p=f;return 0;}
   		else if (key==T->infor.name) 
		   {p=T;return 1;}
    	else if(key<T->infor.name) 
			SearchBST(T->lchild,key,T,p);
        else 
			SearchBST(T->rchild,key,T,p); 
}
  
int InsertBST(BiTree &T,Stu key)//���� 
{  
    if(!T)
    {  
        T=(BiTree)malloc(sizeof(BiTNode)); 
        T->infor=key;  
        T->lchild=(T)->rchild=NULL;  
    }  
    if(key.name==T->infor.name) return 0;  
    if(key.name>T->infor.name) InsertBST(T->rchild,key); 
    else InsertBST(T->lchild,key); 
} 

int CostomSearchBST(BiTree T,char key,BiTree f,BiTree &p )//���Ʋ��� 
{  
	 if(!T)  {p=f;return 0;}
   		else if (key==T->infor.name) 
		   {
				p=T;
		   		printf("ѧ����ϢΪ��%d %c %c %f %f",p->infor.num,p->infor.name,p->infor.sex,p->infor.english,p->infor.math);
		   		return 1;
		   }
    	else if(key<T->infor.name) 
			CostomSearchBST(T->lchild,key,T,p);
        else 
			CostomSearchBST(T->rchild,key,T,p); 
}
/*-------------------------------------------------------------------------------------------*/
void HashFun(Stu *s)
{
	Stu *ptr = s;
	int i,m,j;
	Link head[13]={NULL};
	Link p,q;
	Node key;
	for(i=0;i<=n-1;i++)
	{
		key.data.num=ptr[i].num%13;
		p=(Link)malloc(sizeof(Node));
		p->data =ptr[i];
		p->next =NULL;
		
		if(!head[key.data.num]) 
			head[key.data.num]=p;//���ͷ���Ϊ�գ���ֱ��Ϊͷ��㸳ֵ
		else
		{
			for(q=head[key.data.num];
			q->next ;q=q->next );//q��pǰ��
		    q->next =p;
		} 


	}
	printf("\n������Ҫ���ҵ�ѧ��:");
	scanf("%d",&m);
	for(j=1;j<=13;j++)
	{
		if(head[j])
		{
			q=head[j];
			while(q)
			{
				if(q->data.num == m)
					printf("��ѯ���Ϊ��%d %c %c %f %f",q->data.num,q->data.name,q->data.sex,q->data.english,q->data.math);
				q=q->next;
			}
		}
	}
	
}

/*-------------------------------------------------------------------------------------------*/

int main()
{
	Stu liststu[n];

	Initlist(liststu);
	getlistinfo(liststu);
	Printlist(liststu);
	
	qksortenglish(liststu,0,20);
	printf("\nӢ��ɼ�����\n");
	Printlist(liststu);
/*--------------------------------*/
	printf("\n����������ҵ�Ӣ��ɼ���\n");
	int a,key;
	scanf("%d",&key);
	a=BinarySearch(liststu,key,20);
	if(a==UNFOUND) 
		printf("\nû�ҵ�Ŷ\n");
	else 
		printf("������ϢΪ��\n%d %c\n",liststu[a].num,liststu[a].name);
/*----------------------*/
	Stu *ptr=liststu;
	int i;
	BiTree T= NULL,f,p;
	for (i = 0; i < 20; i++) 
	{  				// ͨ�������������������������
        InsertBST(T, *ptr);
        ptr++;
    }
	Preorder(T);
	char key2;
	getchar();
	printf("\n���������ѯ��ѧ������:");
	scanf("%c",&key2);
	if(!CostomSearchBST(T,key2,f,p))
		printf("   û�ҵ�!\n");
/*--------------------------------*/
	HashFun(liststu); 
	system("pause");
	return 0;
}


