#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

bool szukaj(int **lab1, int **sciezka, int x, int y)
{
	if ((x < 0) || (x > 19) || (y < 0) || (y > 19)) return false; // poza mapą
	if ((lab1[x][y] == 1) || (sciezka[x][y] == 1)) return false; // bieżący
	sciezka[x][y] = 1;
	if ((x == 19) && (y == 18)) return true; // wyjście
	if (szukaj(lab1, sciezka, x, y - 1)) return true; // w górę
	if (szukaj(lab1, sciezka, x + 1, y)) return true; // w prawo
	if (szukaj(lab1, sciezka, x, y + 1)) return true; // w dół
	if (szukaj(lab1, sciezka, x - 1, y)) return true; // w lewo
	sciezka[x][y] = 0;
	return false;
}

int main()
{
	fstream plik("Labirynt.txt");
	if (!plik.good())
		cout << "Nie mozna otworzyc pliku " << endl;

	char r;
	int **lab = (int**)malloc(20 * sizeof(int*));
	for (int k = 0; k < 20; ++k)
		lab[k] = (int*)malloc(20 * sizeof(int));

	cout << "Twoj labirynt :" << endl;
	for (int i = 0; i<20; i++)
	{
		cout << endl;
		for (int j = 0; j<20; j++)
		{
			plik >> r;
			lab[i][j] = (int)(r - 48);
			cout << lab[i][j];
		}
	}
	cout << endl << endl;
	cout << "Oto sciezka :" << endl;

	int **sciezka = (int**)malloc(20 * sizeof(int*));
	for (int i = 0; i < 20; i++)
		sciezka[i] = (int*)malloc(20 * sizeof(int));
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			sciezka[i][j] = 0;

	szukaj(lab, sciezka, 0, 1);
	for (int m = 0; m<20; m++)
	{
		cout << endl;
		for (int n = 0; n<20; n++)
		{   if(sciezka[m][n] != 1)
			cout << lab[m][n];
			else cout<<(char)212;
		}
	}
	cout << endl;
	system("PAUSE");
	free(*lab);
	plik.close();
	return 0;
}
