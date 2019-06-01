#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];
}PersonInfo;

typedef struct AddressBook
{
	PersonInfo* persons;
	int size;//[0,size)��Ч��ȡֵ
	int capacity;//�������
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
	g_address_book.capacity = 100;
	g_address_book.persons = (PersonInfo*)malloc(g_address_book.capacity * sizeof(PersonInfo));

	for (int i = 0; i < g_address_book.capacity; ++i)
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
	system("cls");
	int status = 1;
	printf("������ϵ��\n");
	printf("����*�Ž���\n");
	while (status == 1)
	{
		printf("��������ϵ������: ");
		//�����ȡ��һ��ָ��
		if (g_address_book.size >= g_address_book.capacity)
		{
			printf("��ǰ�ռ䲻��!��������!\n");
			g_address_book.capacity += 100;
			
			//1.ʹ��relloc��������:
			//g_address_book.persons = (PersonInfo*)realloc(g_address_book.persons, g_address_book.capacity * sizeof(PersonInfo));
			
			//2.ʹ��malloc���´����������������:
			PersonInfo* p = (PersonInfo*)malloc(g_address_book.capacity * sizeof(PersonInfo));
			
			for (int i = 0; i < g_address_book.size; ++i)
			{
				p[i] = g_address_book.persons[i];
			}
			free(g_address_book.persons);
			g_address_book.persons = p;
		}
		PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
		scanf("%s", person_info->name);
		if (strcmp(person_info->name,"*") == 0)
		{
			strcpy(person_info->name, "");
			printf("����������ϵ��.\n");
			system("pause");
			system("cls");
			return;
		}

		printf("��������ϵ�˵绰: ");
		scanf("%s", person_info->phone);
		++g_address_book.size;
		printf("������ϵ�˳ɹ�!\n");
	}
	system("pause");
	system("cls");
}
void DelPersonInfo()
{
	system("cls");
	printf("ɾ����ϵ��\n");
	if (g_address_book.size <= 0)
	{
		printf("ɾ��ʧ��!ͨѶ¼Ϊ��!\n");
		system("pause");
		system("cls");
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
	system("pause");
	system("cls");
}
void FindPersonInfo()
{
	system("cls");
	printf("������ϵ��\n");
	if (g_address_book.size <= 0)
	{
		printf("�޸�ʧ��,ͨѶ¼Ϊ��!\n");
		system("pause");
		system("cls");
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
	system("pause");
	system("cls");
}
void UpDatePersonInfo()
{
	system("cls");
	printf("������ϵ��\n");
	if (g_address_book.size <= 0)
	{
		printf("�޸�ʧ��,ͨѶ¼Ϊ��!\n");
		system("pause");
		system("cls");
		return;
	}
	printf("������Ҫ�޸ĵ����: ");
	int id;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size)
	{
		printf("�޸�ʧ��,������������!\n");
		system("pause");
		system("cls");
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
	system("pause");
	system("cls");
}
void PrintAllPersonInfo()
{
	system("cls");
	printf("ȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i)
	{
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n", i, info->name, info->phone);
	}
	printf("����ӡ�� %d ������ !", g_address_book.size);
	printf("��ӡȫ����ϵ�˳ɹ�!\n");
	system("pause");
	system("cls");
}
void SortPersonInfo()
{
	system("cls");
	printf("����������\n");
	int i, j;
	if (g_address_book.size <= 0)
	{
		printf("��ϵ�˹���,�޷�����!\n");
		system("pause");
		system("cls");
		return;
	}
	for (i = 0; i < g_address_book.size; ++i)
	{
		for (j = 0; j < g_address_book.size - i - 1; j++)
		{
			if (strcmp(g_address_book.persons[j].name,g_address_book.persons[j + 1].name) > 0)
			{
				char temp1[1024] = "";
				char temp2[1024] = "";
				strcpy(temp1,g_address_book.persons[j].name);
				strcpy(g_address_book.persons[j].name, g_address_book.persons[j + 1].name);
				strcpy(g_address_book.persons[j + 1].name, temp1);
				strcpy(temp2, g_address_book.persons[j].phone);
				strcpy(g_address_book.persons[j].phone, g_address_book.persons[j + 1].phone);
				strcpy(g_address_book.persons[j + 1].phone, temp2);
			}
		}
	}
	printf("����������ɹ�!\n");
	system("pause");
	system("cls");
}
void ClearAllPersonInfo()
{
	system("cls");
	printf("���ȫ������\n");
	printf("�����Ҫ���ȫ��������? Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", &choice);
	if (strcmp(choice, "Y") == 0)
	{
		g_address_book.size = 0;
		printf("���ȫ�����ݳɹ�!\n");
	}
	else
	{
		printf("��ղ���ȡ��!\n");
	}
	system("pause");
	system("cls");
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