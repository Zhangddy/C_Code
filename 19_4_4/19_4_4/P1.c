#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.递归和非递归分别实现求第n个斐波那契数。
//
//2.编写一个函数实现n^k，使用递归实现
//
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//
//5.递归和非递归分别实现strlen
//6.递归和非递归分别实现求n的阶乘
//7.递归方式实现打印一个整数的每一位


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