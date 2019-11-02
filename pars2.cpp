#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <time.h>
#include <ctime>
#include <windows.h>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int pointer = 0;
	char str1[100];
	char comment;
	char commandchar[20];
	string name;
	string strconverted;
	string target;
	string command;
	setlocale(LC_ALL, "rus");
	ifstream file;
startfile:
	//cout << "Vvedite put' faila: ";
	//cin >> name;

	file.open("D:\\fug\\conf");
	if (!file.is_open()) {
		cout << "file error" << endl;
		goto startfile;
	}
	//cin >> str;



	command = "get param ";
	cout << "Vvedite komandu: ";
	getline(cin>>ws, target);

	while (target.find(command) == string::npos) {
		if (target.find(command) == string::npos) {
			cout << "Unknown command. Try again:" << endl;
		}if (command == target) {
			cout << "Pustoe imya poiska. Try again:" << endl;
		}
		getline(cin>>ws, target);
	}
	target.erase(0, target.find(command) + command.length());
	target = target + ' ';
	int i = 0;
	while (!file.eof()) {
		file.getline(str1, 100);
		if ((str1[0] != '#') && (str1[0] != ';')) {


			//cout << str1<<endl;
			strcpy(commandchar, target.c_str());

			if (strstr(str1, commandchar) != NULL) {

				cout <<target<<": "<< strstr(str1, commandchar) + target.length() << endl;
				//str.erase(0, (str.find(target) + target.length()));
				//cout <<target<<":  "<< str;
				i = 1;
			}
		}
	}
	if (i == 0) {
		cout << "Sovvpadenii ne naideno" << endl << endl;
	}
	file.close();
}

