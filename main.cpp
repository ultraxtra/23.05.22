
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <Windows.h>
#include <stdio.h>
#include <string>

using namespace std;

void Problem1();
void Problem2();
void Problem3();





int main()
{

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Problem1();
	Problem2();
	Problem3();

	_getch();
	return 0;
}





void Problem1() {
	cout << "--- Problem 1 ---\n";

	char buff1[512]{};
	char buff2[512]{};

	char fileName1[] = "myfile1.txt";
	char fileName2[] = "myfile2.txt";

	ifstream file1;
	ifstream file2;

	file1.open(fileName1);
	file2.open(fileName2);

	while (!file1.eof())
	{
		file1.getline(buff1, sizeof buff1);
		//cout << buff1 << endl;
		file2.getline(buff2, sizeof buff2);
		//cout << buff2 << endl;
		if (strcmp(buff1, buff2)) {
			cout << buff1 << endl;
			cout << buff2 << endl;
		}
	}
	file1.close();
	file2.close();

}

void Problem2() {
	cout << "--- Problem 2 ---\n";
	int stringCount = 0;
	int aCount = 0;
	int ACount = 0;
	int nCount = 0;
	char buff[512]{};


	char fileName1_2[] = "myfile1_2.txt";
	char fileName2_2[] = "myfile2_2.txt";


	ifstream fl1;
	ofstream fl2;

	fl1.open(fileName1_2);

	while (!fl1.eof())
	{
		stringCount++;
		fl1.getline(buff, sizeof buff);
		//cout << buff;
		for (int i = 0; i < strlen(buff); i++) {
			if (buff[i] >= '0' && buff[i] <= '9') {
				nCount++;
			}
			if (buff[i] >= 'a' && buff[i] <= 'z') {
				aCount++;
			}
			else if (buff[i] >= 'A' && buff[i] <= 'Z')
			{
				ACount++;
			}
		}
	}

	//cout << stringCount << endl;
	//cout << aCount << endl;
	//cout << ACount << endl;
	//cout << nCount << endl;

	fl2.open(fileName2_2);
	fl2 << stringCount << endl;
	fl2 << aCount << endl;
	fl2 << ACount << endl;
	fl2 << nCount << endl;
	fl2.close();
}

void Problem3() {
	cout << "--- Problem 3 ---\n";

	char fname1[256] = "CaesarCode.txt";
	char fname2[256] = "myfile3.txt";
	char buff1[256]{};
	char buff2[256]{};

	ifstream fin1;
	ofstream fin2;

	fin1.open(fname1);
	while (!fin1.eof())
	{
		fin1.getline(buff1, sizeof buff1);
		//cout << buff1 << endl;
	}
	fin1.close();

	int tmp = 3;

	int len = strlen(buff1);
	for (size_t i = 0; i < len; i++)
	{
		tmp = buff1[i];
		tmp += 3;
		buff2[i] = tmp;
		tmp = 0;
	}

	//cout << buff2;

	fin2.open(fname2);
	fin2 << buff2;
	fin2.close();
}

