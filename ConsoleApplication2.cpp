#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	vector<char> text;
	vector<int> swaporder;
	vector<char> swaporderreserve;
	int pointer;
	int i;
	int n;
	char symb;
	string random;
	
	ifstream ifile;
	ofstream ofile;
	string name;
	link2:
	cout << "Выберите действие: " << endl <<"1. Генерация ключа"<<endl<< "2. Шифровка" <<endl<< "3. Дешифровка" << endl;
	cin >> pointer;
	switch (pointer) {
	case 1: {swaporderreserve.clear();
		swaporder.clear();
		text.clear();
		random = rand();
		cout << "Введите резмерность секвенции перестановки: ";
		cin >> n;
		for (i = 0; i < n; i++) {
			swaporder.push_back(i + 1);
		}

		random_shuffle(swaporder.begin(), swaporder.end());
		cout << "Vvedite imya klucha: ";
		cin>> name;
		ofile.open("D:\\fug\\guf\\" + name + ".key");

		ofile << "Disorder" << endl;
		i = 0;
		ofile << n;
		ofile << ' ';
		//ofile << n;
		while (i != n)
		{
			ofile << swaporder[i];
			ofile << ' ';
			i++;
		}
		ofile.close();
		cout << "Ключ записан" << endl << "Директория: " << "D:\\fug\\guf\\" + name + ".key" << endl << endl;
		break;
	}
	case 2: {link: swaporderreserve.clear();
		swaporder.clear();
		text.clear();
		cout << "Введите директорию ключа: ";
		cin >> random;
		ifile.open(random);
		i = 0;
		ifile >> random;
		ifile.get();
		if (random == "Disorder") {
			ifile >> n;
			while (!ifile.eof()) {
				ifile >> pointer;
				swaporder.push_back(pointer);
				i++;
			}
		}
		else {
			cout << "Nepodhodyachii tip klucha" << endl;
			goto link;
		}ifile.close();
		

		ifile.open("D:\\fug\\guf\\Text.txt");
		ofile.open("D:\\fug\\guf\\Result.encode");
		//ofile << n;
		while (!ifile.eof()) {

			for (i = 1; i <= n; i++) {
				if (!ifile.eof()) {
					symb=ifile.get();
				}
				swaporderreserve.push_back(symb);
				symb = '[';

			}i = 0;
			while (i < swaporder.size()-1) {
				ofile << swaporderreserve[swaporder[i] - 1];
				i++;
			}
			swaporderreserve.clear();
		}
		ifile.close();
		ofile.close();

		break;
	}

	case 3: {link1:swaporderreserve.clear();
		swaporder.clear();
		text.clear();
		cout << "Vvedite put' ispolzuemogo klucha: ";
		cin >> name;
		ifile.open(name);
		ifile >> random;
		ifile.get();
		if (random == "Disorder") {

			
			ifile >> n;
			i = 0;
			while (i != n) {
				ifile >> pointer;
				swaporder.push_back(pointer);
				i++;
			}
		}
		else {
			cout << "Nepodhodyachii tip klucha" << endl;
			goto link1;
		}ifile.close();
		
		ifile.open("D:\\fug\\guf\\Result.encode");
		string leng;
		string leng1;
		while (!ifile.eof()) {
			ifile >> leng;
			leng1 = leng1 + leng + 'a';
		}
		int point = (leng1.length()) / n;
		ifile.close();
		ifile.open("D:\\fug\\guf\\Result.encode");
		//ifile >> n;
		ofile.open("D:\\fug\\guf\\Decoded.txt");
		for (n = 0; n<point+1; n++) {

			for (i = 1; i <= swaporder.size(); i++) {
				if (!ifile.eof()) {
					symb=ifile.get();
				}
				else {
					symb = ' ';
				}
				swaporderreserve.push_back(symb);
			}i = 0;
			while (i < swaporder.size()) {
					auto it = find(swaporder.begin(), swaporder.end(), i+1);
					auto spot = std::distance(swaporder.begin(), it);
				if (swaporderreserve[spot] != '[' && swaporderreserve[spot] != 'я') {
					ofile << swaporderreserve[spot];
				}
				i++;
			}
			swaporderreserve.clear();
			
		}
		ifile.close();
		ofile.close();
		break;
	}
	default: {
		cout << "input error";
		break;
	}
	}goto link2;
}




	