#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
//
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
//
//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ


int Fib(int n)//�ǵݹ�
{
	int sum;
	if (n < 3)
	{
		sum = 1;
	}
	int pre = 1, next = 1,i;
	for (i = 3; i <= n; i++)
	{
		sum = pre + next;
		pre = next;
		next = sum;
	}
	return sum;
}

int RFib(int n)//�ݹ�
{
	if (n <= 2)
		return 1;
	else
		return RFib(n - 1) + RFib(n - 2);
}

int main_1()
{
	int n;
	scanf("%d", &n);
	//Fib
	printf("�ǵݹ�:	%d \n",Fib(n));
	printf("�ݹ�:	%d \n",RFib(n));

	system("pause");
	return 0;
}