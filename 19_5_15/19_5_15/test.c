#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
//˼·:дһ��AABCDAABCD, ��s2�ȶ��Ƿ��������
//char* strstr(char* src, char* str)
//�����Ӵ�str��λ��


void round_cat(char* src, int time)//time ��������
{
	int len = strlen(src);
	int pos = len - time % len;//ȡ���ֹtime �����ַ������ȣ���time = �ַ�������ʱ�����󲻱仯
	char tmp[256] = { 0 };//������ʱ���

	strcpy(tmp, src + pos);
	strncat(tmp, src, pos);//��srcǰpos���ӵ�tmp��
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
	printf("�����������ĸ���:\n");
	scanf("%d", &time);
	char arr[] = "abcdef";
	round_cat(arr, time);
	printf("��ת��: %s\n", arr);

	//2
	char arr1[] = "abcdef";
	char arr2[] = "efabcd";
	printf("���Ϊ:%d \n", judge_round(arr1, arr2));
	system("pause");
	return 0;
}
