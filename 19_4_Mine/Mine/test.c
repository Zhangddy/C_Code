#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define ROW 9
#define COL 9
#define MAX_MINE 10

void Init(char show_map[ROW][COL], char mine_map[ROW][COL])//初始化地图
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

int MineNum(char show_map[ROW][COL], char mine_map[ROW][COL], int row,int col)//返回此坐标周围8个格的地雷数
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
		printf("请输入坐标:\n");
		int row, col;
		scanf("%d %d", &row, &col);
		if (show_map[row][col] != '*')
		{
			printf("坐标已经存在或不合法,请重新输入:\n");
			continue;
		}
		else if (mine_map[row][col] == '1')
		{
			system("cls");
			Print(mine_map);
			printf("游戏结束!\n");
			printf("按任意键继续...\n");
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
			printf("恭喜你,游戏胜利!\n");
			printf("按任意键继续...\n");
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
	printf("=====1.开始游戏=====\n");
	printf("=====2.退出程序=====\n");
	printf("====================\n");
	printf("===请输入您的选择:==\n");
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
			printf("正在退出...\n");
			break;
		}
		else
		{
			printf("输入错误,请重新输入!\n");
		}
	}
	system("pause");
	return 0;
}
