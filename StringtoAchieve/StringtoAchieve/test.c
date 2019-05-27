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
		;//�ҵ�str1��β
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
				//cp����str1�ĸ���Ԫ��
	char *substr = (char*)str2;
				//substr����str2�ĸ���Ԫ��
	char * s1 = NULL;
				//s1����str1�ĸ���Ԫ�ز���substr����Ԫ�ؽ��бȽ�
				//����ͬ��cp++, s1����cpλ�����¿�ʼ��substr�ıȽ�
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

int main()//strsok��ʹ��
{
	char *p = "teday.error@print/good!";
	const char* sep = ".@/";
	char arr[30];
	char *str = NULL;
	strcpy(arr, p);//�����ݿ���һ�ݣ�����arr���������
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
	system("pause");
	return 0;
}