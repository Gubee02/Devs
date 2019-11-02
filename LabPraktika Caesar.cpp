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
	ifstream ifile;
	ofstream ofile;
	vector<char> text;
	vector<char> alph;
	vector<char> decalph;
	char n;
	int i;
	string name;
	string random;
	int y;
	char buff[100];
	int pointer;
start:
	cout << "Viberite deistvie: " <<endl<<"1. Генерация ключа"<< endl << "2. Шифровка" << endl << "3. Дешифровка" << endl;;
	cin >> pointer;
	switch (pointer) {
	case 1: {alph.clear();
		decalph.clear();
		text.clear();
		random = rand();
		cout << "Vvedite imya klucha: ";
		cin >> name;
		
		ifile.open("D:\\fug\\MyFile.txt");
		while (!ifile.eof()) {
			alph.push_back(ifile.get());
		}
		ifile.close();
		random_shuffle(alph.begin(), alph.end());
		ofile.open("D:\\fug\\" + name + ".key");
		ofile << "Shuffle" << endl;
		y = 0;
		while (y < alph.size())
		{
			ofile << alph[y];
			y++;
		}
		cout << "Ключ записан" << endl<<"Директория: "<< "D:"<<"\\"<<"\\fug\\"<<"\\" + name + ".key"<<endl<<endl;
		ofile.close();
		break;
	}
	case 2: {alph.clear();
		decalph.clear();
		text.clear();
		ifile.open("D:\\fug\\MyFile.txt");
		if (!ifile.is_open())
		{
			cout << "-";
		}
		i = 0;
		
		while(!ifile.eof()){
			alph.push_back(ifile.get());
			
			i++;
			
		}
		
		
		//cout << "Алфавит загружен" << endl;
		ifile.close();
	link:
		cout << "Введите директорию ключа: ";
		cin >> random;
		ifile.open(random);
		//ifile.open("D:\\fug\\Key).txt");
		if (!ifile.is_open())
		{
			cout << "-";
		}
		i = 0;
		ifile >> random;
		ifile.get();
		if (random == "Shuffle") {
			while (!ifile.eof()) {
				decalph.push_back(ifile.get());
				i++;
			}
		}
		else {
			cout << "Nepodhodyachii tip klucha" << endl;
			goto link;
		}ifile.close();
		ifile.open("D:\\fug\\Text.txt");
		i = 0;
		while (!ifile.eof())
		{
			text.push_back(ifile.get());
			i++;
		}
	
		  //cout << "Текст загружен" << endl;
		  ifile.close();

		  ofile.open("D:\\fug\\Result.encode");
		  y = 0;
		  while (y < text.size()-1) {
			  auto it = find(alph.begin(), alph.end(), text[y]);
			  auto spot = std::distance(alph.begin(), it);

			  ofile << decalph[spot];
			  y++;
		  }cout << "Результат записан" << endl<<endl;
		  ofile.close();
		  break;
	}
	case 3: {link1:
	alph.clear();
	decalph.clear();
	text.clear();
	cout << "Введите директорию ключа: ";
	cin >> random;
	ifile.open(random);
		if (!ifile.is_open())
		{
			cout << "-";
		}ifile >> random;
		ifile.get();
		if (random == "Shuffle") {
			i = 0;
			while (!ifile.eof()) {
				decalph.push_back(ifile.get());
				i++;
			}
		}
		else {
			cout << "Nepodhodyachii tip klucha" << endl;
			goto link1;
		}
		
		//cout << "Алфавит загружен" << endl;
		ifile.close();
		ifile.open("D:\\fug\\MyFile.txt");
		if (!ifile.is_open())
		{
			cout << "-";
		}
		i = 0;
		while (!ifile.eof())
		{
			
			alph.push_back(ifile.get());
			//decalph.push_back(n);
			i++;
		}
		ifile.close();
		ifile.open("D:\\fug\\Result.encode");
		i = 0;
		while (!ifile.eof())
		{
			ifile >> n;
			text.push_back(n);
			i++;
		}//cout << i;
		ifile.close();
		ofile.open("D:\\fug\\Decoded.txt");
		y = 0;
		while (y < text.size() - 1) {
			auto it = find(decalph.begin(), decalph.end(), text[y]);
			auto spot = std::distance(decalph.begin(), it);

			ofile << alph[spot];
			y++;
		}  cout << "Результат записан" << endl << endl;
		ofile.close();
		break;
	}
	default: {
		cout << "input error" << endl;
		goto start;
		break;
	}
	}goto start;
}



	
