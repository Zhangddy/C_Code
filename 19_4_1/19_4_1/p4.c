
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//ʵ��һ���������ж�һ�����ǲ���������

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