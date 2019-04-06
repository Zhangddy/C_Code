#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//5.递归和非递归分别实现strlen
//6.递归和非递归分别实现求n的阶乘
//7.递归方式实现打印一个整数的每一位

int rStrlen(char *str)//递归
{
	if (*str == '\0')    //当传入的字符串中没有字符
		return 0;		//字符串长度为0
	else
		return 1 + rStrlen(str + 1);	/*运用递归，每递归一次
	长度加1，直到遍历到的'\0'时结束递归*/
}

int sStrlen(char *str)//非递归
{
	int length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return length;
}

int  rFactor(int n)  //递归
{
	if (n == 1)
	{
		return 1;
	}
	return n * rFactor(n - 1);
}

int Factor(int n) //非递归
{
	int sum = 1;
	for (; n > 0; n--)
	{
		sum *= n;
	}
	return sum;
}

void print(int n)
{
	if (n < 10)
	{
		printf("%d ", n);
	}
	else
	{
		print(n / 10);
		printf("%d ", n % 10);
	}
}

int main_5()
{
	char string[] = "abcdefg";
	printf("%d\n", sStrlen(string));
	print(12345);
	system("pause");
	return 0;
}