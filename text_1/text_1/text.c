#include<stdio.h>
//编写一个程序，可以一直接收键盘字符， 
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。

int main()
{
	int i;
	char str[20];
	while (1)
	{
		gets(str);
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] <= 'Z' && str[i] >= 'A')
			{
				str[i] = str[i] + 32;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
			}
			if (str[i]< '0' || str[i] > '9')
			{
				putchar(str[i]);
			}
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}