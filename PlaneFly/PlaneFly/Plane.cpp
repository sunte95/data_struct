#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
//全局变量
int position_x, position_y;    //飞机位置
int bullet_x, bullet_y;    //子弹位置
int enemy_x, enemy_y;     //敌机位置
int high, width;          //游戏画面尺寸
int score;               //得分
//数据初始化
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
{  // 将光标移动到（x,y)位置
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
//显示画面
void show() {
	gotoxy(0, 0);
	int i, j;;
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((i == position_x) && (j == position_y))
				printf("*");       //输出飞机
			else if ((i == enemy_x) && (j == enemy_y))
				printf("@");         //输出敌机
			else if ((i == bullet_x) && (j == bullet_y))
				printf("|");          //输出子弹
			else
				printf("  ");        //输出空格

		}
		printf("\n");
	}
	printf("得分：%d\n", score);

}
void updateWithoutInput() {               //与用户无关的更新
	if (bullet_x > -1)
		bullet_x--;
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y))
	{
		score++;
		enemy_x = -1;                     //分数加1
		enemy_y = rand() % width;       //产生新的飞机
		bullet_x = -2;                 //子弹无效

	}
	if (enemy_x > high)       //敌机跑出屏幕

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
void updateWithInput()       //与用户输入有关的更新
{
	char input;
	if (_kbhit())              //判断是否有输入
	{
		input = _getch();
		if (input == 'a')         //位置左移
			position_y--;         
		if (input == 'd')         //位置右移
			position_y++;
		if (input == 'w')         //位置上移
			position_x--;
		if (input == 's')            //位置下移
			position_x++;
		if (input = ' ')            //发射子弹
		{
			bullet_x = position_x - 1;
			bullet_y = position_y;
		}
	}
}
void HideCursor()           //隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int main()
{
	int flag;
	startup();
	while (1)         //游戏循环进行
	{
		show();      //显示画面
		updateWithoutInput();
		/*if (updateWithoutInput() == -1)       //与用户输入无关的更新
		{
			goto end;
		}*/
			updateWithInput();             //与用户输入有关的更新
		
	}
//end:
	//printf("GAME OVER!")
	HideCursor();            //隐藏光标  
	return 0;
 }