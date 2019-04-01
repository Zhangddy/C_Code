
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//实现一个函数，判断一个数是不是素数。

int Isprime(int num)
{
	int i, flag = 1;
	for (i = 2; i < num; i++)
	{
		if (num%i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

int main4()
{
	int num, i, j;
	scanf("%d", &num);
	if (Isprime(num))
	{
		printf("%d is prime.", num);
	}
	else
	{
		printf("%d is not prime.", num);
	}
	system("pause");
	return 0;
}