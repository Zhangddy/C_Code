#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
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

	按 sn 进制输出 n :
	for (i = n; i; i /= sn)
	{
		tmp = i % sn;
		sum = sum * sn + tmp;
	}
	*/
	system("pause");
	return 0;
}

//2.不使用（a + b） / 2这种方式，求两个数的平均值。

int main2()
{
	int a=1;
	int b=2;
	int ret;
	//左移一位等同乘 2 , 右移一位等同除 2 .
	ret = ((a + b) >> 1);
	printf("%d \n", ret);
	system("pause");
	return 0;
}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）

int main3()
{
	int a[] = { 1, 2, 3, 2, 3, 1, 4, 5, 5 , 4, 9};
	int ret = 0;
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		ret ^= a[i];
		//按位异或两次等于没变 , 0 异或任意数结果为任意数
	}
	printf("%d \n", ret);

	system("pause");
	return 0;
}

//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。

//思路: 先将各个单词转置, 再将整体转置
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
			reverse_string(str, star, end); // 将每个单词先转置
			star = i + 1;
		}
	}
	reverse_string(str, star, i - 1);// 转置最后一个单词

	reverse_string(str, 0, i - 1);//将结果str整体再转置就得到了结果
}


int main4()
{
	char str[] = "student a am i";
	reverse_word(str);
	puts(str);
	system("pause");
	return 0;
}










