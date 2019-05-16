#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//思路:写一个AABCDAABCD, 让s2比对是否存在于它
//char* strstr(char* src, char* str)
//查找子串str的位置


void round_cat(char* src, int time)//time 左旋个数
{
	int len = strlen(src);
	int pos = len - time % len;//取余防止time 大于字符串长度，当time = 字符串长度时左旋后不变化
	char tmp[256] = { 0 };//创建临时存放

	strcpy(tmp, src + pos);
	strncat(tmp, src, pos);//将src前pos个接到tmp上
	strcpy(src, tmp);
}

int judge_round(char* src1, char* src2)
{
	char tmp[256] = { 0 };
	strcpy(tmp, src1);
	strcat(tmp, src1);
	char* p = strstr(tmp, src2);
	int status = -1;
	if ( p != NULL)
		status = 1;
	return status;
}

int main()
{
	//1
	int time;
	printf("请输入左旋的个数:\n");
	scanf("%d", &time);
	char arr[] = "abcdef";
	round_cat(arr, time);
	printf("旋转后: %s\n", arr);

	//2
	char arr1[] = "abcdef";
	char arr2[] = "efabcd";
	printf("结果为:%d \n", judge_round(arr1, arr2));
	system("pause");
	return 0;
}
