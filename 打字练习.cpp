#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> //�Ǳ�׼�⺯�� Sleep �����ͷ�ļ�
#include <conio.h>   //�Ǳ�׼�⺯�� kbhit �� getch �����ͷ�ļ�
using namespace std;
 
 
int main() {
	const int ESCKEY = 27; //�������ͳ���ESCKEY����ֵΪESC����ASCII����
	int pos, posmax = 72;  //��ǰλ�ã��ұ߽����λ��
	int win = 0, loss = 0; //��Ӯ�������������
 
	cout << "������Ϸ�����س�����ʼ����Ϸ�����а� ESC ������" << endl;
	getchar();
	int ch = 0, key = 0; //����ַ�����Ҽ����ַ�
	srand(time(0)); //�������������
	while (key != ESCKEY) { //��ѭ����key ���� ESC��ʱ����Ϸ
		ch = rand() % ('z' + 1 - 'a') + 'a'; //��������ַ�
		for (pos = 0; pos < posmax && key != 27; pos++) {
			cout << "\b--" << (char)ch;
			pos++;
			Sleep(150);
			if (kbhit() && (key = getch()) == ch) {
				win++;
				cout << "*\a";  //��� * ������
				break;
			}
		}
		if (key == ESCKEY) { //�û�����ESC������Ҫȷ��
			cout << "\n������Ϸ��(y/n)";
			while ((key = tolower(getchar())) != 'y' && ch != 'n')
				;    //��ѭ����
			key = (key == 'y' ? ESCKEY : 0); //���Ϊ'y'���Ϊ ESCKEY�����ڿ�����ѭ��
		}
		if (pos >= posmax) {  //�����ұ߽�
			loss ++;
		}
		cout << endl;
	}
 
	cout << "�ַ���ϰ������" << win + loss << "   ��ȷ���������" << win << endl;
	cout << "��Ϸ������ллʹ��" << endl;
	return 0;
}
