#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
void left_remove(char *p, int n, int len)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		char tmp = p[0];
		for (j = 0; j < len; j++)
		{
			p[j] = p[j + 1];
		}
		p[len - 1] = tmp;
	}
}
int main1()
{
	char arr[] = "abcdef";
	int n;
	int len = strlen(arr);
	printf("旋转前：%s\n", arr);
	printf("旋转几位:");
	scanf("%d", &n);
	while (n < 1 || n > len - 1)//对于输入旋转字符数的临界值判断，是否超过字符串长度
	{
		if (n == len)//旋转字符数为字符串长度时，旋转后的字符串与旋转前的字符串一致，所以可直接输出
		{
			printf("%s", arr);
			system("pause");
			return 0;
		}
		else
		{
			printf("输入错误\n");
			scanf("%d", &n);
		}
	}
	left_remove(arr, n, len);//函数用以完成旋转字符的功能
	printf("旋转后: %s\n", arr);
	system("pause");
	return 0;
}
//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC



int main()//采用上题写法先将字符串转置后对比
{
	char str1[] = "abcdef";
	char str2[] = "cdefab";
	int len = strlen(str1);
	int n2 = strlen(str2);
	left_remove(str1, 2, len);
	int status = 0;
	if (len == n2)
		status = strcmp(str1, str2);
	if (status == 0)
		printf("相等\n");
	else
		printf("不相等\n");
	system("pause");
	return 0;
}