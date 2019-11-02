
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include <ctime>
#include <windows.h>
#include <filesystem>
#include <vector>

using namespace std;



int main()
{
	string label[40];

	setlocale(LC_ALL, "rus");
	int i = 11;
	//wcout.imbue(std::locale("rus_RUS.866"));
	wstring p;

	int z(0);
	int lineLength = 40;
	char* lines;


	std::vector<string> files;
	for (auto& p : std::filesystem::directory_iterator("D:/21/")) {
		files.push_back(p.path().string());

	}


	std::cout << "files: " << '\n';
	for (string file : files)
	{
		//std::cout << "----" << file << '\n';
		label[i] = file;
		i++;

	}

	/*WIN32_FIND_DATA wfd;
	char buff[40];
	char buff1[50];
	HANDLE hFind = FindFirstFileW(L"D:/21/*.txt", &wfd);
	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			p = L"D:/21/";
			p += wfd.cFileName;
			ifstream fin(p);
			ofstream fout("data.txt", ios_base::app);



			std::wcout << wfd.cFileName << std::endl;
			fin.getline(buff, 40);
			//fout<< wfd.cFileName;
			fout << buff;
			wlabel[i] = wfd.cFileName;
			i++;
			//cout << label[i];
			//fout << buff;

			fin.close();
			fout.close();
		} while (NULL != FindNextFileW(hFind, &wfd));
		FindClose(hFind);
	}
	//system("pause");
	//return 0;*/
	ifstream file;
	/*file.open("data.txt");
	if (!file.is_open()) {
		cout << "error";
	}
	*/
	for (i = 11; i <= 21; i++) {
		//label[i] = file.getline;
		//cout << label[i] << endl;
	}
	string path = "d:\\21\\";


	//file.close();
	int r = 0;
	string name;
	setlocale(LC_ALL, "rus");
	int time = 11;
	string timestr;
	do {
		//link:
		cout << "Vvedite nazvanie ustroistva: ";
		string dev; cin >> dev;
		if (dev == "") {
			cout << "Pusto";
			exit(1);
		}
		dev = ":" + dev + ":";

		int lengh = dev.length();

		char gar[] = "garbage";
		char fry[100];
		strcpy(fry, dev.c_str());

		string str;
		ifstream fin;
		char* istr;
		char div[255];
		if (strstr(fry, gar) != NULL) {
			cout << "Musor!";
			exit(1);
		}
		for (i = 11; i <= 32; i++) {

			name = label[i];
			int r = 0;
			//cout << name;
			fin.open(name);
			if (!file.is_open()) {
				//cout << "error" << label[i];
			}
			cout << label[i] << ":  ";
			while (!fin.eof()) {
				str = "";		
				fin >> str;
				char div[255];
				char div1[255];
				strcpy(div, str.c_str());
				strcpy(div1, dev.c_str());

				if (strstr(div, div1) != NULL) {
					istr = strstr(div, div1);
					cout << istr + lengh << endl;
					r = 2;
					break;
				}
			}
			if (r == 0) {
				cout << "ustroistvo ne naideno" << endl;
			}
			fin.close();
		}//goto link;
	} while (true);
	return 0;
}





