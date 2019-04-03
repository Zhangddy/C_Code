#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define ROW 3
#define COL 3

char board[ROW][COL];

void Init()
{
	for(int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
}

void Print()
{  
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}


void PlayerMove()
{
	int row, col;
	printf("该你啦!请输入一个坐标:\n");
	while (1)
	{
		scanf("%d %d", &row, &col);
		if (board[row][col] != ' ')
			printf("您的输入有误!请重新输入\n");
		else
		{
			break;
		}
	}
	board[row][col] = 'X';
}

char Judge()
{
	char status = 'p';
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				status = 0;
			}
		}

	for (int i = 0; i < COL; i++)
	{
		if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
		{
			status = 'X';
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
		{
			status = 'X';
		}
	}

	for (int i = 0; i < COL; i++)
	{
		if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
		{
			status = 'O';
		}
	}
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
		{
			status = 'O';
		}
	}

	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[0][0] != ' ')
	{
		status = board[0][0];
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ')
	{
		status = board[2][0];
	}

	if (status == 'p')
	{
		printf("你他娘真是个人才!跟阿尔法狗五五开!\n");
	}	
	if (status == 'X')
	{
		printf("恭喜你,下赢了阿尔法狗!\n");
	}	
	if (status == 'O')
	{
		printf("胜败乃兵家常事,请继续努力!\n");
	}
	return status;
}

void AIMove()
{
	printf("阿尔法狗正在思考中...\n");
	Sleep(1000);
	while (1)
	{
//		srand((unsigned int)time(NULL));
		int i = rand() % 3;
		int j = rand() % 3;
		if (board[i][j] != ' ')
		{
			continue;
		}
		else
		{
			board[i][j] = 'O';
			break;
		}
	}
}

void game()
{
	while (1)
	{
		system("cls");
		Print();
		PlayerMove();
		system("cls");
		Print();
		if (Judge())
		{
			break;
		}
		AIMove();
		system("cls");
		Print();
		if (Judge())
		{
			break;
		}
	}
}

int main()
{

	int s;
	while (1)
	{

		printf("-------------------\n");
		printf("------1.play--------\n");
		printf("------0.exit-------\n");
		printf("-------------------\n");
		printf("请输入:\n");
			scanf("%d", &s);
		if (s == 1)
		{
			Init();
			game();
		}
		else if(s == 0)
		{
			break;
		}
		else
		{
			printf("您的输入有误!\n");
		}
		system("pause");
		system("cls");
	}
	system("pause");
}