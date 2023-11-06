#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Sum_Count_Replace(int** Z, const int rowCount, const int colCount, int& S, int& k);int main() {	srand((unsigned)time(NULL));
	int Low = 4;
	int High = 45;
	int rowCount = 9;
	int colCount = 7;	int** Z = new int* [rowCount];
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
	return 0;}void Create(int** Z, const int rowCount, const int colCount, const int Low,
	const int High){	srand(static_cast<unsigned>(time(nullptr)));	for (int i = 0; i < rowCount; i++) {		for (int j = 0; j < colCount; j++) {			Z[i][j] = Low + rand() % (High - Low + 1);		}	}}void Print(int** Z, const int rowCount, const int colCount){	cout << endl;	for (int i = 0; i < rowCount; i++)	{		for (int j = 0; j < colCount; j++)			cout << setw(4) << Z[i][j];		cout << endl;	}	cout << endl;}void Change(int** Z, const int col1, const int col2, const int colCount){	int tmp;
	for (int i = 0; i < colCount; i++)
	{
		tmp = Z[i][col1];
		Z[i][col1] = Z[i][col2];
		Z[i][col2] = tmp;	}}void Sort(int** Z, const int rowCount, const int colCount){	for (int j0 = 0; j0 < colCount - 1; j0++)		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)			if ((Z[0][j1] < Z[0][j1 + 1])				|| (Z[0][j1] == Z[0][j1 + 1] && Z[1][j1] > Z[1][j1 + 1])				|| (Z[0][j1] == Z[0][j1 + 1] && Z[1][j1] == Z[1][j1 + 1] && Z[2][j1] < Z[2][j1 + 1]))				Change(Z, j1, j1 + 1, rowCount);}void Sum_Count_Replace(int** Z, const int rowCount, const int colCount, int& S, int& k){	S = 0;	k = 0;	for (int i = 0; i < rowCount; i++) {		for (int j = 0; j < colCount; j++) {			if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {				S += Z[i][j];				k++;				Z[i][j] = 0;			}		}	}}