#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PERSON_INFO_SIZE 300
typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];
}PersonInfo;

typedef struct AddressBook
{
	PersonInfo persons[MAX_PERSON_INFO_SIZE];
	int size;//[0,size)有效的取值
}AddressBook;

AddressBook g_address_book;//g_ 全局变量

int Menu()
{
	printf("====================\n");
	printf("1.新增联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.打印全部联系人\n");
	printf("6.排序联系人\n");  //待完成
	printf("7.清空联系人\n");
	printf("0.退出\n");
	printf("====================\n");
	printf("请输入您的选择: \n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Init()
{
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_INFO_SIZE; ++i)
	{
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
	}
}

void Empty()
{
	//啥都不干,凑数
}
void AddPersonInfo()
{
	printf("新增联系人\n");
	printf("请输入联系人姓名: ");
	//必须获取到一个指针
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE)
	{
		printf("新增联系人失败!\n");
		return;
	}
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	scanf("%s", person_info->name);
	printf("请输入联系人电话: ");
	scanf("%s", person_info->phone);
	++g_address_book.size;
	printf("新增联系人成功!\n");
}
void DelPersonInfo()
{
	printf("删除联系人\n");
	if (g_address_book.size <= 0)
	{
		printf("删除失败!通讯录为空!\n");
		return;
	}
	printf("请输入要删除的序号: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size)
	{
		printf("删除失败! 输入的序号有误!\n");
		return;
	}
	g_address_book.persons[id] = g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;
	printf("删除联系人成功!\n");
}
void FindPersonInfo()
{
	printf("查找联系人\n");
	if (g_address_book.size <= 0)
	{
		printf("修改失败,通讯录为空!\n");
		return;
	}
	printf("请输入要查找的姓名 :");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < g_address_book.size; ++i)
	{
		PersonInfo* info = &g_address_book.persons[i];
		if (strcmp(info->name, name) == 0)
		{
			printf("[%d] %s\t%s\n", i, info->name, info->phone);
		}
	}
	printf("查找成功!\n");
}
void UpDatePersonInfo()
{
	printf("更新联系人\n");
	if (g_address_book.size <= 0)
	{
		printf("修改失败,通讯录为空!\n");
		return;
	}
	printf("请输入要修改的序号: ");
	int id;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size)
	{
		printf("修改失败,输入的序号有误!\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("请输入新的姓名: (%s) 输入*号跳过\n", info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0)
	{
		strcpy(info->name, name);
	}
	char phone[1024] = { 0 };
	printf("请输入新的电话号码: (%s) 输入*号跳过\n", info->phone);
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(info->phone, phone);
	}
	printf("更新联系人成功!\n");
}
void PrintAllPersonInfo()
{
	printf("全部联系人\n");
	for (int i = 0; i < g_address_book.size; ++i)
	{
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n", i, info->name, info->phone);
	}
	printf("共打印了 %d 条数据 !", g_address_book.size);
	printf("打印全部联系人成功!\n");
}
void SortPersonInfo()
{
	//TODO
}
void ClearAllPersonInfo()
{
	printf("清空全部数据\n");
	printf("您真的要清空全部数据嘛? Y/N\n");
	char choice[1024] = { 0 };
	if (strcmp(choice, "Y") == 0)
	{
		g_address_book.size = 0;
		printf("清空全部数据成功!\n");
	}
	else
	{
		printf("清空操作取消!\n");
	}
}
typedef void(*Func)();
int main()
{
	//定义转移表
	Func arr[] =
	{
		Empty,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpDatePersonInfo,
		PrintAllPersonInfo,
		SortPersonInfo,
		ClearAllPersonInfo
	};
	Init();
	while (1)
	{
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0]))
		{
			printf("您的输入有误,请重新输入!\n");
			continue;
		}
		if (choice == 0)
		{
			printf("goodbye!\n");
			break;
		}
		arr[choice]();//转移表
	}

	system("pause");
	return 0;
}