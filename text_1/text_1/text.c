#include<stdio.h>
//��дһ�����򣬿���һֱ���ռ����ַ��� 
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������

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