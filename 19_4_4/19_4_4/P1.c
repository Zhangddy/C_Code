#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������

int Fib(int n)//�ǵݹ�
{
	int sum;
	if (n < 3)
	{
		sum = 1;
	}
	int pre = 1, next = 1,i;
	for (i = 3; i <= n; i++)
	{
		sum = pre + next;
		pre = next;
		next = sum;
	}
	return sum;
}

int RFib(int n)//�ݹ�
{
	if (n <= 2)
		return 1;
	else
		return RFib(n - 1) + RFib(n - 2);
}

int main_1()
{
	int n;
	scanf("%d", &n);
	//Fib
	printf("�ǵݹ�:	%d \n",Fib(n));
	printf("�ݹ�:	%d \n",RFib(n));

	system("pause");
	return 0;
}