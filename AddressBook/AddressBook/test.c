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
	int size;//[0,size)��Ч��ȡֵ
}AddressBook;

AddressBook g_address_book;//g_ ȫ�ֱ���

int Menu()
{
	printf("====================\n");
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ӡȫ����ϵ��\n");
	printf("6.������ϵ��\n");  //�����
	printf("7.�����ϵ��\n");
	printf("0.�˳�\n");
	printf("====================\n");
	printf("����������ѡ��: \n");
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
	//ɶ������,����
}
void AddPersonInfo()
{
	printf("������ϵ��\n");
	printf("��������ϵ������: ");
	//�����ȡ��һ��ָ��
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE)
	{
		printf("������ϵ��ʧ��!\n");
		return;
	}
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	scanf("%s", person_info->name);
	printf("��������ϵ�˵绰: ");
	scanf("%s", person_info->phone);
	++g_address_book.size;
	printf("������ϵ�˳ɹ�!\n");
}
void DelPersonInfo()
{
	printf("ɾ����ϵ��\n");
	if (g_address_book.size <= 0)
	{
		printf("ɾ��ʧ��!ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("������Ҫɾ�������: ");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size)
	{
		printf("ɾ��ʧ��! ������������!\n");
		return;
	}
	g_address_book.persons[id] = g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;
	printf("ɾ����ϵ�˳ɹ�!\n");
}
void FindPersonInfo()
{
	printf("������ϵ��\n");
	if (g_address_book.size <= 0)
	{
		printf("�޸�ʧ��,ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("������Ҫ���ҵ����� :");
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
	printf("���ҳɹ�!\n");
}
void UpDatePersonInfo()
{
	printf("������ϵ��\n");
	if (g_address_book.size <= 0)
	{
		printf("�޸�ʧ��,ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("������Ҫ�޸ĵ����: ");
	int id;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size)
	{
		printf("�޸�ʧ��,������������!\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("�������µ�����: (%s) ����*������\n", info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0)
	{
		strcpy(info->name, name);
	}
	char phone[1024] = { 0 };
	printf("�������µĵ绰����: (%s) ����*������\n", info->phone);
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(info->phone, phone);
	}
	printf("������ϵ�˳ɹ�!\n");
}
void PrintAllPersonInfo()
{
	printf("ȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i)
	{
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n", i, info->name, info->phone);
	}
	printf("����ӡ�� %d ������ !", g_address_book.size);
	printf("��ӡȫ����ϵ�˳ɹ�!\n");
}
void SortPersonInfo()
{
	//TODO
}
void ClearAllPersonInfo()
{
	printf("���ȫ������\n");
	printf("�����Ҫ���ȫ��������? Y/N\n");
	char choice[1024] = { 0 };
	if (strcmp(choice, "Y") == 0)
	{
		g_address_book.size = 0;
		printf("���ȫ�����ݳɹ�!\n");
	}
	else
	{
		printf("��ղ���ȡ��!\n");
	}
}
typedef void(*Func)();
int main()
{
	//����ת�Ʊ�
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
			printf("������������,����������!\n");
			continue;
		}
		if (choice == 0)
		{
			printf("goodbye!\n");
			break;
		}
		arr[choice]();//ת�Ʊ�
	}

	system("pause");
	return 0;
}