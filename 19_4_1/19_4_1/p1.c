#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
int main1()
{
	int max, i, j;
	scanf("%d", &max);
	for (i = 1; i <= max; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %d	", j, i, j*i);
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}