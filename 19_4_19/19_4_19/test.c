#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�

void func(int* a, int n)
{
	int temp;
	int i = 0, j = n - 1;
	while (i <= j)
	{
		while (a[i] % 2 != 0 && i < n)
		{
			i++;
		}
		while (a[j] % 2 == 0 && j >= 0)
		{
			j--;
		}
		if(i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}

int main1()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	func(a, sizeof(a)/sizeof(a[0]));
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}



//2.
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
//1 2 3
//2 3 4
//3 4 5

//1 3 4
//2 4 5
//4 5 6

//1 2 3
//4 5 6
//7 8 9


//˼·: ����������Ϸ���ʼ�������·���ʼ
int findNum(int a[][3], int x, int y, int f)
{
	int i = 0, j = y - 1;

	while (i < x && y >= 0)
	{
		if (a[i][j] > f)
		{
			j--;
		}
		else if (a[i][j] < f)
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main2()
{
	int a[][3] = { { 1, 3, 5 },
				   { 3, 5, 7 },
				   { 5, 7, 9 } };
	int found = 7;
	if (findNum(a, 3, 3, found))
	{
		printf("�ҵ���! \n");
	}
	else
	{
		printf("û�ҵ�! \n");
	}
	system("pause");
	return 0;
}