#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

int DigitSum(int n)
{
	int sum = 0;
	for (int i = n; i; i /= 10)
	{
		sum += i % 10;
	}
	return sum;
}

int main_3()
{
	int n;
	scanf("%d", &n);
	printf("DigitSum is: %d \n", DigitSum(n));

	system("pause");
	return 0;
}