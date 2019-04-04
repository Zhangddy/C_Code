#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19

int DigitSum(int n)
{
	int sum = 0;
	for (int i = n; i; i /= 10)
	{
		sum += i % 10;
	}
	return sum;
}

int main_3()
{
	int n;
	scanf("%d", &n);
	printf("DigitSum is: %d \n", DigitSum(n));

	system("pause");
	return 0;
}