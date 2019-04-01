#include<stdio.h>
#define max 10
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
void Init(int a[])
{
	int i;
	for (i = 0; i < max; i++)
	{
		a[i] = i;
	}
}

void Empty(int a[])
{
	int i;
	for (i = 0; i < max; i++)
	{
		a[i] = 0;
	}
}

void Reverse(int a[])
{
	int right = max - 1, left = 0;
	int temp;
	while (left < right)
	{
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;
		left++;
		right--;
	}
}
 
int main3()
{
	int a[] = { 5,6,7,8,6,7,8,9,10 };
	Init(a);
	int i;
	Reverse(a);

	for (i = 0; i < max; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}