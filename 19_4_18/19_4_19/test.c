#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

void func(int* a, int n)
{
	int temp;
	int i = 0, j = n - 1;
	while (i <= j)
	{
		while (a[i] % 2 != 0 && i < n)
		{
			i++;
		}
		while (a[j] % 2 == 0 && j >= 0)
		{
			j--;
		}
		if(i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}

int main1()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	func(a, sizeof(a)/sizeof(a[0]));
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}



//2.
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组：
//1 2 3
//2 3 4
//3 4 5

//1 3 4
//2 4 5
//4 5 6

//1 2 3
//4 5 6
//7 8 9


//思路: 从数组的右上方开始或者左下方开始
int findNum(int a[][3], int x, int y, int f)
{
	int i = 0, j = y - 1;

	while (i < x && y >= 0)
	{
		if (a[i][j] > f)
		{
			j--;
		}
		else if (a[i][j] < f)
		{
			i++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main2()
{
	int a[][3] = { { 1, 3, 5 },
				   { 3, 5, 7 },
				   { 5, 7, 9 } };
	int found = 7;
	if (findNum(a, 3, 3, found))
	{
		printf("找到了! \n");
	}
	else
	{
		printf("没找到! \n");
	}
	system("pause");
	return 0;
}