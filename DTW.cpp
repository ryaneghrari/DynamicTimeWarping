#include "DTW.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <float.h>

using namespace std;

DTW::DTW(){}

DTW::DTW(vector<double> arr1, vector<double> arr2)
{
	this->arr1 = arr1;
	this->arr2 = arr2;
	initMatrix(arr1,arr2);
	runDTW(arr1,arr2,this->matrix);
}

DTW::~DTW(){}

vector< vector<double> > DTW::getMatrix()
{
	vector< vector<double> > temp(matrix);
	return temp;
}

vector<double> DTW::getArrY()
{
	vector<double> temp(arr1);
	return temp;
}

vector<double> DTW::getArrX()
{
	vector<double> temp(arr2);
	return temp;
}

vector<double> DTW::getArr1()
{
	vector<double> temp(arr1);
	return temp;
}

vector<double> DTW::getArr2()
{
	vector<double> temp(arr2);
	return temp;
}

/*
 * Initialize Matrix to with arr1 on the y axis, and
 * arr2 on the x axis.                             
 */
void DTW::initMatrix(vector<double> arr1, vector<double> arr2)
{
	vector< vector<double> > temp_matrix(arr1.size());

	for(int i = 0; i < temp_matrix.size(); i++)
	{
		temp_matrix[i].resize(arr2.size());
	}

	this->matrix = temp_matrix;
}

double DTW::runDTW(vector<double> arr1, vector<double> arr2, vector< vector <double> > matrix)
{	
	int n = matrix.size() - 1;    //row
	int m = matrix[0].size() -1;  //col

	for(int i = 0; i < n; i++)
	{
		matrix[i][0] = DBL_MAX;
	}
	
	for(int j = 0; j < m; j++)
	{
		matrix[0][j] = DBL_MAX;	
	}	

	matrix[0][0] = 0;

	double cost;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cost = (arr1[i] - arr2[j]);
			matrix[i][j] = cost + min(matrix[i][j],min(matrix[i][j+1],matrix[i+1][j]));
		}
	}
    
	this->matrix = matrix; //save matrix
    return matrix[n][m];	
}

void DTW::printVector(vector<double> vec)
{
	cout << "[ \t";
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\t";
	}
	cout << "]" << endl;
}

void DTW::printMatrix(vector< vector<double> > matrix)
{
	for(int i = 0; i < matrix.size(); i++)
	{	
		for(int j = 0; j < matrix[i].size(); j++)
		{	
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}




