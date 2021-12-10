#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

const int SIZE = 100;
// Tao mang 2 chieu  va tao khung
void build(char k[SIZE][SIZE], int rong, int cao)
{
	for (int i = 0; i < cao; i++)
		for (int j = 0; j < rong; j++)
		{
			if (i == cao - 1)

				k[i][j] = '=';
			else if (j == 0 || j == rong - 1)
				k[i][j] = '|';
			else
				k[i][j] = ' ';
		}
}
//Vi tri  de gach
void putBrick(char k[SIZE][SIZE], int rong, int cao, int length = 3, bool isHorizontal = true) //lenght = kich thuoc vien gach
{
	int xStart, yStart;
	bool f = true;

	if (isHorizontal == true)
	{

		for (int i = cao - 2; i >= 0 && f == true; i--)
		{
			for (int j = 1; j < rong - 1 && f == true; j++)
				if (k[i][j] == ' ' && rong - j - 2 >= length) 
				{
					xStart = i;
					yStart = j;
					f = false;

				}
		}
		for (int j = yStart; j < yStart + length; j++)
			k[xStart][j] = '*';
	}

	else
	{
		for (int i = cao - 2; i >= 0 && f == true; i--)
		{
			for (int j = 1; j < rong - 1 && f == true; j++)
				if (k[i][j] == ' ')
				{
					xStart = i;
					yStart = j;
					f = false;
				}
		}
		for (int i = xStart - length + 1; i <= xStart; i++)
			k[i][yStart] = '*';
	}

}
// Dung de xuat mang
void output(char k[SIZE][SIZE], int rong, int cao)
{
	for (int i = 0; i < cao; i++)
	{
		for (int j = 0; j < rong; j++)
			cout << k[i][j];
		cout << endl;
	}
}
//random so vien gach
int random()
{
	int sao;
	srand(time(0));// dung that doi so di voi thu vien #include <time.h> , dung de thay doi rand theo thoi gian
	sao = rand() % 4 + 1; // cong thuc random tu a den b  : rand() % (b-a + 1 ) + a;
	return sao;
}
int main()
{
	char k[SIZE][SIZE];
	int sao;
	int rong, cao;
	bool c = true; // dung de kiem tra co vuot qua chieu cao khong
	int diem = 0;
	cout << "Moi ban nhap : \n";
	cout << "rong = ";
	cin >> rong;
	rong += 2;
	cout << "cao = ";
	cin >> cao;
	cao += 1;
	build(k, rong, cao);
	output(k, rong, cao);
	while (c == true)
	{
		
		int chon;
		sao = random();
		cout << "Kich thuoc vien gach " << sao << endl;
		cout << "Chon 1 de gach nam ngang \n";
		cout << "Chon 2 de gach nam doc \n";
		cin >> chon;
		system("cls");
		cout << endl;
		switch (chon)
		{
		case 1:
			putBrick(k, rong, cao, sao, true);
			break;
		case 2:
			putBrick(k, rong, cao, sao, false);
			break;
		}
		output(k, rong, cao);
		diem = diem + sao * 10;
		for (int i = 0; i <= rong; i++)
		{
			if (k[0][i] == '*')
				c = false;
		}
		
	}

	cout << "Ban dat duoc so diem la: " << diem << endl;
	system("pause");
	return 0;
}