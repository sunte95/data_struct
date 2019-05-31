#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
//ȫ�ֱ���
int high, width;    //��Ϸ�����С
int ball_x, ball_y;  //С�������
int ball_vx, ball_vy;  //С����ٶ�
int position_x, position_y; //��������ĵ�����
int ridus;    //����İ뾶��С
int left, right; //���������λ��
int ball_number; //����С��Ĵ���
int block_x, block_y;  //ש���λ��
int score; //����ש��ĸ���

void gotoxy(int x, int y)  //������ƶ�����x,y����λ��
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void startup()  //���ݵĳ�ʼ��
{
	high = 13;
	width = 17;
	ball_x = 0;
	ball_y = width / 2;
	ball_vx = 1;
	ball_vy = 1;
	ridus = 6;
	position_x = high;
	position_y = width / 2;
	left = position_y - ridus;
	right = position_y + ridus;
	ball_number = 0;
	block_x = 0;
	block_y = width / 2 + 1;
	score = 0;

}
void show()  //��ʾ����
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i <= high + 1; i++)
	{
		for (j = 0; j < width / 2; j++)
		{
			if ((i == ball_x) && (j == ball_y))
				printf("0");         //���С��
			 if (j == width)
				printf("|");  //�����
			 if ((i == high) && (j > left) && (j < right))
				printf("*");    //�������
			 if ((i == block_x) && (j == block_y))
				printf("B");   //���ש��
			else
				printf("  ");

		}
		printf("\n");
	}
	printf("����С������%d\n", ball_number);
	printf("������ש������%d\n", score);
}
void UpdateWithoutInput()    //���û������޹ص�����
{
	if (ball_x == high - 1)
	{
		if ((ball_y > left) && (ball_y < right))  //�����嵲ס
		{
			ball_number++;
			printf("\a");   //����
			//ball_y = ball_y + rand() * 4 - 2;
		}
		else
		{
			printf("��Ϸʧ��\n");
			system("pause");
			exit(0);
		}
	}
	if ((ball_x == block_x) && (ball_y == block_y))     //С�����ש��
	{
		score++;
		block_y = rand() % width;    //�����µ�ש��
	}
	ball_x = ball_x + ball_vx;
	ball_y = ball_y + ball_vy;
	if ((ball_x == 0) || (ball_x == high - 1))
		ball_vx = -ball_vx;
	if ((ball_y == 0) || (ball_y == width - 1))
		ball_vy = -ball_vy;
	Sleep(100);
}

void UpdateWithInput()      //���û������йصĸ���
{
	char input;
	if (_kbhit())      //�ж��Ƿ�������
	{
		input = _getch();   //�����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == 'a')
		{
			position_y--;    //λ������
			left = position_y - ridus;
			right = position_x + ridus;


		}
		if (input == 'd')
		{
			position_y++;    //λ������
			left = position_y - ridus;
			right = position_x + ridus;
		}
	}

}
int main()
{
	startup();   //���ݵĳ�ʼ��
	while (1)    //��Ϸѭ��ִ��
	{
		show();   //��ʾ����
		UpdateWithoutInput();   //���û������޹صĸ���
		UpdateWithInput();   //���û������йصĸ���
	}
	return 0;
}