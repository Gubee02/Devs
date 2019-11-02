
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>
#include <string>
#include <time.h>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int n;
	int mass[255];
	setlocale(LC_ALL, "rus");
	cout << "Vvedite razmernost' massiva=  ";

	cin >> n;
	if (!cin) {
		cout << "Error, retry:  ";
		exit(0);
	}
	cout << "Viberite sposob zadachi massiva" << endl << "Vruchnuyu - 1" << endl << "Randomno - 2" << endl;
	int f;
	int i;

	cin >> f;
	if (!cin) {
		cout << "Error";
		exit(0);
	}
	switch (f) {
	case 1: {
		for (i = 1; i <= n; i++) {
		link2:
			cin >> mass[i];
			if (!cin) {
				cout << "Error, " << "Retry:  ";
				goto link2;
			}
		}break;
	}
	case 2:
	{
		for (i = 1; i <= n; i++) {
			while (mass[i] <= mass[i - 1]) {
				mass[i] = (rand() % 10 * i) - 6 * i;
				
			}cout << i <<". "<< mass[i] << endl;
			
		}break;
	}
	default:
	{cout << "ERROR";
	exit(0);
	break;
	}
	}
	link:
	cout << "Vvedite iskomoe znachenie:  ";
	int tar;
	int target;
	cin >> tar;
	if (!cin) {
		cout << "Error, retry:  ";
		exit(0);
	}
	int min = 1;
	int max = n;
	if ((mass[min] == tar) || (mass[max] == tar)) {
		if (mass[min] == tar) {
			cout << "Resultat:  " << min; goto link;
		}
		else {
			cout << "Resultat:  " << max; goto link;
		}
	}
	target = min;
	while (mass[target] != tar) {
		target =min +((max - min)/2);
		if (mass[target] == tar) {
			cout << "Resultat:  " << target;
			goto link;
		}
		else {
			if (mass[target] > tar) {
				max = target;
			}
			else {
				min = target;
			}
		}if (min + 1 == max) {
			break;
		}
	}
	if (min + 1 == max) {
		cout << "ZNACHENIYA V MASSIVE NET!"<<endl<<"retry: ";
		goto link;
	}

}

/*#include<windows.h>
#include<iostream>

int main() {
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFile("d:\\21*", &FindFileData);
	if (hf != INVALID_HANDLE_VALUE) {
		do {
			std::cout << FindFileData.cFileName << "\n";
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
}*/

