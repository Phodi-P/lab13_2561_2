#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

// Write definition of inputMatrix(),matrixMultiply() and showMatrix() here

void findLocalMax(const double data[][N], bool output[][N])
{
	for(int i = 0 ; i < N ; i ++)//loop to set output to all false
	{
		for(int j = 0 ; j <N ; j++)
		{
			output[i][j] = false;
		}
	}

	for(int i = 1 ; i < N-1 ; i ++)//actual calculation
	{
		for(int j = 1 ; j <N-1 ; j++)
		{
			if(data[i][j] >= data[i+1][j] && data[i][j] >= data[i-1][j] && data[i][j] >= data[i][j+1] && data[i][j] >= data[i][j-1])
			{
				output[i][j] = true;
			}
		}
	}
}

void inputMatrix(double data[][N])
{
	for(int i = 1 ; i <= N ; i++)
	{
		cout << "Row " << i << " : ";
		for(int j = 0 ; j < N ; j++)
		{
			cin >> data[i-1][j];
		}
	}
}

void showMatrix(const bool data[][N])
{
	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}
