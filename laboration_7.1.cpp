#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Sum_Count_Replace(int** Z, const int rowCount, const int colCount, int& S, int& k);
	int Low = 4;
	int High = 45;
	int rowCount = 9;
	int colCount = 7;
	for (int i = 0; i < rowCount; i++)
		Z[i] = new int[colCount];
	cout << "Start Matrix: " << endl;
	Create(Z, rowCount, colCount, Low, High);
	Print(Z, rowCount, colCount);
	cout << "Sorted Matrix: " << endl;
	Sort(Z, rowCount, colCount);
	Print(Z, rowCount, colCount);
	int S = 0;
	int k = 0;
	Sum_Count_Replace(Z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	cout << " " << endl;
	cout << "Modified Matrix: " << endl;
	Print(Z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] Z[i];
	delete[] Z;
	return 0;
	const int High)
	for (int i = 0; i < colCount; i++)
	{
		tmp = Z[i][col1];
		Z[i][col1] = Z[i][col2];
		Z[i][col2] = tmp;