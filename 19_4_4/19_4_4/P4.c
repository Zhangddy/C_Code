#include <stdio.h>
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

int Strlen(char *str)
{
	if (*str == '\0')    //��������ַ�����û���ַ�
		return 0;		//�ַ�������Ϊ0
	else
		return 1 + Strlen(str + 1);	/*���õݹ飬ÿ�ݹ�һ��
	���ȼ�1��ֱ����������'\0'ʱ�����ݹ�*/
}
/*******�ݹ鷽ʽд�ַ�����ת*******/
void reverse_string(char *string)
{
	int len = Strlen(string);//����������ַ������Ⱥ���;
	if (len <= 1)	//���ַ�������С�ڵ���1ʱ����ִ�У�
		return;
	else
	{
		char temp = string[0];	 //����һ���ַ���ֵ������temp��;
		string[0] = string[len - 1];//�����һ���ַ�������һ���ַ�;
		string[len - 1] = '\0';	//�����һ���ַ������ݸ�Ϊ'\0';
		reverse_string(string + 1);//�ݹ������һ�η�ת��
		string[len - 1] = temp;	//��temp������ǰ�����һ���ַ���
	}
}

int main_4()
{
	char string[] = "abcdefg";
	reverse_string(string);
	puts(string);
	system("pause");
	return 0;
}