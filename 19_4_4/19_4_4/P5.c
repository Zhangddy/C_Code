#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ

int rStrlen(char *str)//�ݹ�
{
	if (*str == '\0')    //��������ַ�����û���ַ�
		return 0;		//�ַ�������Ϊ0
	else
		return 1 + rStrlen(str + 1);	/*���õݹ飬ÿ�ݹ�һ��
	���ȼ�1��ֱ����������'\0'ʱ�����ݹ�*/
}

int sStrlen(char *str)//�ǵݹ�
{
	int length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return length;
}

int  rFactor(int n)  //�ݹ�
{
	if (n == 1)
	{
		return 1;
	}
	return n * rFactor(n - 1);
}

int Factor(int n) //�ǵݹ�
{
	int sum = 1;
	for (; n > 0; n--)
	{
		sum *= n;
	}
	return sum;
}

void print(int n)
{
	if (n < 10)
	{
		printf("%d ", n);
	}
	else
	{
		print(n / 10);
		printf("%d ", n % 10);
	}
}

int main_5()
{
	char string[] = "abcdefg";
	printf("%d\n", sStrlen(string));
	print(12345);
	system("pause");
	return 0;
}