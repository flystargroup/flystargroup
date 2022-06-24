#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> //非标准库函数 Sleep 所需的头文件
#include <conio.h>   //非标准库函数 kbhit 和 getch 所需的头文件
using namespace std;
 
 
int main() {
	const int ESCKEY = 27; //定义整型常量ESCKEY，赋值为ESC键的ASCII编码
	int pos, posmax = 72;  //当前位置，右边界最大位置
	int win = 0, loss = 0; //已赢局数和已输局数
 
	cout << "打字游戏（按回车键开始，游戏过程中按 ESC 结束）" << endl;
	getchar();
	int ch = 0, key = 0; //随机字符，玩家键入字符
	srand(time(0)); //设置随机数种子
	while (key != ESCKEY) { //主循环。key 不是 ESC键时玩游戏
		ch = rand() % ('z' + 1 - 'a') + 'a'; //产生随机字符
		for (pos = 0; pos < posmax && key != 27; pos++) {
			cout << "\b--" << (char)ch;
			pos++;
			Sleep(150);
			if (kbhit() && (key = getch()) == ch) {
				win++;
				cout << "*\a";  //输出 * 并响铃
				break;
			}
		}
		if (key == ESCKEY) { //用户键入ESC键，需要确认
			cout << "\n结束游戏吗？(y/n)";
			while ((key = tolower(getchar())) != 'y' && ch != 'n')
				;    //空循环体
			key = (key == 'y' ? ESCKEY : 0); //如果为'y'则改为 ESCKEY，用于控制主循环
		}
		if (pos >= posmax) {  //到达右边界
			loss ++;
		}
		cout << endl;
	}
 
	cout << "字符练习个数：" << win + loss << "   正确键入个数：" << win << endl;
	cout << "游戏结束，谢谢使用" << endl;
	return 0;
}
