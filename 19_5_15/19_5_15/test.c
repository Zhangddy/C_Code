#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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
	printf("��תǰ��%s\n", arr);
	printf("��ת��λ:");
	scanf("%d", &n);
	while (n < 1 || n > len - 1)//����������ת�ַ������ٽ�ֵ�жϣ��Ƿ񳬹��ַ�������
	{
		if (n == len)//��ת�ַ���Ϊ�ַ�������ʱ����ת����ַ�������תǰ���ַ���һ�£����Կ�ֱ�����
		{
			printf("%s", arr);
			system("pause");
			return 0;
		}
		else
		{
			printf("�������\n");
			scanf("%d", &n);
		}
	}
	left_remove(arr, n, len);//�������������ת�ַ��Ĺ���
	printf("��ת��: %s\n", arr);
	system("pause");
	return 0;
}
//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC



int main()//��������д���Ƚ��ַ���ת�ú�Ա�
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
		printf("���\n");
	else
		printf("�����\n");
	system("pause");
	return 0;
}