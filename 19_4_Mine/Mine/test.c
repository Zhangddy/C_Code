#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define ROW 9
#define COL 9
#define MAX_MINE 10

void Init(char show_map[ROW][COL], char mine_map[ROW][COL])//��ʼ����ͼ
{
	for (int i = 0; i < ROW ; i++)
	{
		for (int j = 0; j < COL ; j++)
		{
			show_map[i][j] = '*';
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			mine_map[i][j] = '0';
		}
	}

		int row, col;
		int i = 0;
		while (i < MAX_MINE)
		{
			row = rand() % ROW;
			col = rand() % COL;

			if (mine_map[row][col] == '1')
			{
				continue;
			}
			else
			{
				mine_map[row][col] = '1';
				i++;
			}
		}
}

void Print(char map[ROW][COL])
{
	printf("   |");
	for (int i = 0; i < ROW; i++)
	{
		printf(" %d ",i);
	}
	printf("\n");
	printf("------------------------------\n");

	for (int i = 0; i < ROW; i++)
	{
		printf(" %d | ", i);
		for (int j = 0; j < COL; j++)
		{
			printf("%c  ",map[i][j]);
		}
		printf("\n");
	}
}

int MineNum(char show_map[ROW][COL], char mine_map[ROW][COL], int row,int col)//���ش�������Χ8����ĵ�����
{
	int mine_count = 0;
	if (row -1 >= 0 && col -1 >= 0 && mine_map[row - 1][col - 1] == '1')
	{
		mine_count++;
	}
	if (row - 1 >= 0 && mine_map[row - 1][col] == '1')
	{
		mine_count++;
	}
	if (row - 1 >= 0 && col + 1 <= COL && mine_map[row - 1][col + 1] == '1')
	{
		mine_count++;
	}
	if (col - 1 >= 0 && mine_map[row][col - 1] == '1')
	{
		mine_count++;
	}
	if (col + 1 <= COL && mine_map[row][col + 1] == '1')
	{
		mine_count++;
	}
	if (row + 1 <= ROW && col - 1 >= 0 && mine_map[row + 1][col - 1] == '1')
	{
		mine_count++;
	}
	if (row + 1 <= ROW && mine_map[row + 1][col] == '1')
	{
		mine_count++;
	}
	if (row + 1 <= ROW && col + 1 <= COL && mine_map[row + 1][col + 1] == '1')
	{
		mine_count++;
	}
	return mine_count;
}

int Judge(char show_map[ROW][COL], char mine_map[ROW][COL])
{
	while (1)
	{
		printf("����������:\n");
		int row, col;
		scanf("%d %d", &row, &col);
		if (show_map[row][col] != '*')
		{
			printf("�����Ѿ����ڻ򲻺Ϸ�,����������:\n");
			continue;
		}
		else if (mine_map[row][col] == '1')
		{
			system("cls");
			Print(mine_map);
			printf("��Ϸ����!\n");
			printf("�����������...\n");
			system("pause");
			system("cls");
			return 0;
		}
		show_map[row][col] = MineNum(show_map, mine_map, row, col) + '0';
		break;
	}
}

void Game()
{
	int counttimes = 0;
	char show_map[ROW][COL];
	char mine_map[ROW][COL];
	Init(show_map, mine_map);
	while (1)
	{
		system("cls");
		Print(show_map);
		int n = 1;
		n = Judge(show_map,mine_map);
		counttimes++;
		if (counttimes == ROW * COL - MAX_MINE)
		{ 
			system("cls");
			Print(mine_map);
			printf("��ϲ��,��Ϸʤ��!\n");
			printf("�����������...\n");
			system("pause");
			system("cls");
			break;
		}
		if (n == 0)
		{
			break;
		}
	}
}

int Menu()
{
	int choice;
	printf("====================\n");
	printf("=====1.��ʼ��Ϸ=====\n");
	printf("=====2.�˳�����=====\n");
	printf("====================\n");
	printf("===����������ѡ��:==\n");
	scanf("%d", &choice);
	return choice;
}

int main()
{
	int n;
	srand((unsigned int)time(0));
	while (1)
	{
		n = Menu();
		if (n == 1)
		{
			Game();
		}
		else if (n == 2)
		{
			printf("�����˳�...\n");
			break;
		}
		else
		{
			printf("�������,����������!\n");
		}
	}
	system("pause");
	return 0;
}
