#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
//ʹ�ú���ʵ���������Ľ�����

void swop(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main2()
{
	int a = 1, b = 5;
	swop(&a, &b);
	printf("%d %d \n", a, b);
	system("pause");
	return 0;
}