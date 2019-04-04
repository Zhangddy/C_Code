#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//2.编写一个函数实现n^k，使用递归实现

double Power(double n, int k)
{
	if (k == 0)
	{
		return 1.0;
	}
	if (k > 1)
	{
		return n * Power(n, k - 1);
	}
	if (k < -1)
	{
		return Power(n, k + 1) / n;
	}
	if (k == 1)
	{
		return n;
	}
	if (k == -1)
	{
		return 1/n;
	}

}

int main_2()
{
	double n;
	int k;
	scanf("%lf %d", &n,&k);
	//Fib
	printf("%f \n", Power(n,k));


	system("pause");
	return 0;
}