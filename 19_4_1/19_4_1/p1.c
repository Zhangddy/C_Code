#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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