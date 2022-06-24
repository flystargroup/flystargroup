#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
 
using namespace std;
 
const int h=50,w=50,MaxLen=400;
void gotoxy(short y,short x) {
	COORD pos= {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
struct node {
	int x,y;
};
node s[MaxLen];
node food;
int dir,len;
int Map[h+5][w+5];
int Time[7]= {0},level;
 
 
void FoodCreate() {
	srand ((unsigned)time(NULL));
	while(1) {
		food.x=rand()%h,food.y=rand()%w;
		if(food.x>0&&food.y>0&&Map[food.x][food.y]==0)break;
	}
	gotoxy(food.x,food.y),printf("@");
	gotoxy(h+1,0);
}
 
void init() {
	system("cls");
	for(int i=0; i<=h; i++) {
		for(int j=0; j<=w; j++) {
			if(i==0||j==0||i==h||j==w)Map[i][j]=1,printf("#");
			else Map[i][j]=0,printf(" ");
		}
		printf("\n");
	}
 
	len=2;
	dir=0;
	s[1].x=12,s[1].y=4;
	s[len].x=12,s[len].y=3;
	Map[s[1].x][s[1].y]=Map[s[len].x][s[len].y]=1;
	gotoxy(s[1].x,s[1].y),printf("*");
	gotoxy(s[len].x,s[len].y),printf("*");
	gotoxy(h+1,0);
 
	FoodCreate();
}
 
int move() {
	node next=s[1];
	switch(dir) {
		case 0:
			next.y++;
			break;
		case 1:
			next.x--;
			break;
		case 2:
			next.y--;
			break;
		case 3:
			next.x++;
			break;
	}
	if(Map[next.x][next.y])return 0;
	if(next.x==food.x&&next.y==food.y) {
		len++;
		FoodCreate();
	} else {
		gotoxy(s[len].x,s[len].y),printf(" ");
		Map[s[len].x][s[len].y]=0;
	}
 
	gotoxy(next.x,next.y),printf("*");
	gotoxy(h+1,0);
	Map[next.x][next.y]=1;
	for(int i=len; i>1; i--)s[i]=s[i-1];
	s[1]=next;
	Sleep(100);
	return 1;
}
 
void GameOver() {
	for(int i=1; i<=3; i++) {
		gotoxy(s[1].x,s[1].y);
		printf(" ");
		Sleep(300);
		gotoxy(s[1].x,s[1].y);
		printf("*");
		Sleep(300);
	}
	gotoxy(h+1,0);
	printf("GameOver\n");
	printf("Press any key to continue...");
}
void Welcome() {
	printf("为了您的游戏体验，请先调整控制台字体和布局（记得不要忘了默认设置）：\n");
	printf("右键白色框->属性->字体 选择点阵字体并调整字体大小为8×8\n");
	printf("再选择布局设置窗口大小，推荐60×60\n\n");
	printf("WASD控制方向\n");
 
	printf("\n任意键进入贪吃蛇皮...");
	getch();
 
}
int main() {
	Welcome();
	init();
	while(1) {
		if(kbhit()) {
			char ch=getch();
			int temp=dir;
			switch(ch) {
				case 'd':
					temp=0;
					break;
				case 'w':
					temp=1;
					break;
				case 'a':
					temp=2;
					break;
				case 's':
					temp=3;
					break;
			}
			if((temp+dir)%2)dir=temp;
		}
		if(move()==0) {
			GameOver();
			getch();
			init();
		}
	}
 
}
