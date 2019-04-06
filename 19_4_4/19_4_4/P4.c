#include <stdio.h>
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

int Strlen(char *str)
{
	if (*str == '\0')    //当传入的字符串中没有字符
		return 0;		//字符串长度为0
	else
		return 1 + Strlen(str + 1);	/*运用递归，每递归一次
	长度加1，直到遍历到的'\0'时结束递归*/
}
/*******递归方式写字符串反转*******/
void reverse_string(char *string)
{
	int len = Strlen(string);//调用上面的字符串长度函数;
	if (len <= 1)	//当字符串长度小于等于1时，不执行；
		return;
	else
	{
		char temp = string[0];	 //将第一个字符的值保存在temp中;
		string[0] = string[len - 1];//将最后一个字符赋给第一个字符;
		string[len - 1] = '\0';	//将最后一个字符的内容赋为'\0';
		reverse_string(string + 1);//递归调用下一次反转；
		string[len - 1] = temp;	//将temp赋给当前的最后一个字符；
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