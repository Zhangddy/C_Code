#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
unsigned int round(unsigned n)
{
	int i;
	unsigned int tmp, sum = 0;

	for (i = 0; i < 32; i++, n /= 2)
	{
		tmp = n % 2;
		sum = sum * 2 + tmp;
	}
	return sum;
}

int main1()
{
	printf("%u\n", round(25));
	/*
	int n = 15;
	int i, tmp, sum = 0, sn = 2;

	�� sn ������� n :
	for (i = n; i; i /= sn)
	{
		tmp = i % sn;
		sum = sum * sn + tmp;
	}
	*/
	system("pause");
	return 0;
}

//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

int main2()
{
	int a=1;
	int b=2;
	int ret;
	//����һλ��ͬ�� 2 , ����һλ��ͬ�� 2 .
	ret = ((a + b) >> 1);
	printf("%d \n", ret);
	system("pause");
	return 0;
}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

int main3()
{
	int a[] = { 1, 2, 3, 2, 3, 1, 4, 5, 5 , 4, 9};
	int ret = 0;
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		ret ^= a[i];
		//��λ������ε���û�� , 0 ������������Ϊ������
	}
	printf("%d \n", ret);

	system("pause");
	return 0;
}

//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

//˼·: �Ƚ���������ת��, �ٽ�����ת��
//	1. i am a student
//	2. i ma a tneduts
//	3. student a am i
void reverse_string(char * str, int i, int j)
{
	char tmp;
	for (; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

void reverse_word(char* str)
{
	int star = 0;
	int end = 0;
	int i;
	for(i = 0; str[i] ; i++)
	{
		if (str[i] == ' ')
		{
			end = i - 1;
			reverse_string(str, star, end); // ��ÿ��������ת��
			star = i + 1;
		}
	}
	reverse_string(str, star, i - 1);// ת�����һ������

	reverse_string(str, 0, i - 1);//�����str������ת�þ͵õ��˽��
}


int main4()
{
	char str[] = "student a am i";
	reverse_word(str);
	puts(str);
	system("pause");
	return 0;
}










