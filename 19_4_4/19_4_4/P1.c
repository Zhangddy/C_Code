#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.递归和非递归分别实现求第n个斐波那契数。

int Fib(int n)//非递归
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

int RFib(int n)//递归
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
	printf("非递归:	%d \n",Fib(n));
	printf("递归:	%d \n",RFib(n));

	system("pause");
	return 0;
}