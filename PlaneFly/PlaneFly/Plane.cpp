#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
//ȫ�ֱ���
int position_x, position_y;    //�ɻ�λ��
int bullet_x, bullet_y;    //�ӵ�λ��
int enemy_x, enemy_y;     //�л�λ��
int high, width;          //��Ϸ����ߴ�
int score;               //�÷�
//���ݳ�ʼ��
void startup() {
	high = 20;
	width = 30;
	position_x = high / 2;
	position_y = width / 2;
	bullet_x = -2;
	bullet_y = position_y;
	enemy_x = 0;
	enemy_y = position_y;
	score = 0;
}

void gotoxy(int x,int y) 
{  // ������ƶ�����x,y)λ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
//��ʾ����
void show() {
	gotoxy(0, 0);
	int i, j;;
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((i == position_x) && (j == position_y))
				printf("*");       //����ɻ�
			else if ((i == enemy_x) && (j == enemy_y))
				printf("@");         //����л�
			else if ((i == bullet_x) && (j == bullet_y))
				printf("|");          //����ӵ�
			else
				printf("  ");        //����ո�

		}
		printf("\n");
	}
	printf("�÷֣�%d\n", score);

}
void updateWithoutInput() {               //���û��޹صĸ���
	if (bullet_x > -1)
		bullet_x--;
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y))
	{
		score++;
		enemy_x = -1;                     //������1
		enemy_y = rand() % width;       //�����µķɻ�
		bullet_x = -2;                 //�ӵ���Ч

	}
	if (enemy_x > high)       //�л��ܳ���Ļ

	{
		enemy_x = -1;
		enemy_y = rand() % width;
	}

	//if ((enemy_x == position_x) && (enemy_y == position_y))
		//return -1;

	static int speed = 0;
	if (speed < 10)
		speed++;
	if (speed == 10)
	{
		enemy_x++;
		speed = 0;
	}
}
void updateWithInput()       //���û������йصĸ���
{
	char input;
	if (_kbhit())              //�ж��Ƿ�������
	{
		input = _getch();
		if (input == 'a')         //λ������
			position_y--;         
		if (input == 'd')         //λ������
			position_y++;
		if (input == 'w')         //λ������
			position_x--;
		if (input == 's')            //λ������
			position_x++;
		if (input = ' ')            //�����ӵ�
		{
			bullet_x = position_x - 1;
			bullet_y = position_y;
		}
	}
}
void HideCursor()           //���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int main()
{
	int flag;
	startup();
	while (1)         //��Ϸѭ������
	{
		show();      //��ʾ����
		updateWithoutInput();
		/*if (updateWithoutInput() == -1)       //���û������޹صĸ���
		{
			goto end;
		}*/
			updateWithInput();             //���û������йصĸ���
		
	}
//end:
	//printf("GAME OVER!")
	HideCursor();            //���ع��  
	return 0;
 }