#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t my_strlen(const char* str)
{
	assert(str != NULL);
	int size = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++size;
	}
	return size;
}

char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

char* my_strcat(char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	int i, j;
	for (i = 0; str1[i] != '\0'; i++)
	{
		;//找到str1结尾
	}
	for (j = 0; str2[i] != '\0'; i++, j++)
	{
		str1[i] = str2[j];
	}
	str1[i] = '\0';
	return str1;
}

int my_strcmp(char* str1, char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0' || *str2 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char *cp = (char*)str1;
				//cp遍历str1的各个元素
	char *substr = (char*)str2;
				//substr遍历str2的各个元素
	char * s1 = NULL;
				//s1遍历str1的各个元素并与substr素质元素进行比较
				//若不同则cp++, s1返回cp位置重新开始与substr的比较
	if (*str2 == '\n')
	{
		return NULL;
	}
	while (*cp)
	{
		s1 = cp;
		substr = (char*)str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
		{
			return cp;
		}
		cp++;
	}
	return NULL;
}

int main()//strsok的使用
{
	char *p = "teday.error@print/good!";
	const char* sep = ".@/";
	char arr[30];
	char *str = NULL;
	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
	system("pause");
	return 0;
}