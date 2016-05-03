#include "DTW.h"
#include <vector>
#include <stack>
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
	backTrack();
}

DTW::~DTW(){}

int DTW::getMax()
{
	int n = matrix.size() - 1;
	int m = matrix[n].size() - 1;
	return(this->matrix[n][m]);
}

stack< double > DTW::getRoute()
{
	stack< double > route(this->backTrackRoute);
	return route;
}

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
	vector< vector<double> > temp_matrix(arr1.size()+1);

	for(int i = 0; i < temp_matrix.size(); i++)
	{
		temp_matrix[i].resize(arr2.size()+1);
	}

	this->matrix = temp_matrix;
}

double DTW::runDTW(vector<double> arr1, vector<double> arr2, vector< vector <double> > matrix)
{	
	int n = matrix.size();     //row
	int m = matrix[0].size();  //col

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

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			cost = calcCost(arr1[i-1],arr2[j-1]);

			matrix[i][j] = cost + minimum(matrix[i-1][j-1],minimum(matrix[i][j-1],matrix[i-1][j]));
		}
	} 


	this->matrix = matrix; //save matrix
    return matrix[n-1][m-1];	
}

void DTW::backTrack()
{
		double diagonal =  0.0;
		double right    =  1.0;
		double down     =  -1.0;

        vector< vector<double> > matrix(this->matrix);

		int i = matrix.size()-1;
		int j = matrix[i].size()-1;

		cout << "i: " << i << "j: " << j << "MATRIX: " << matrix[i][j] << endl;
		
		double cost;

		while(i > 1 && j > 1)
		{
			cost = calcCost(this->arr1[i-1],this->arr2[j-1]);
			
			if(matrix[i][j] == cost + matrix[i-1][j-1])
			{
				this->backTrackRoute.push(diagonal);
				i--;
				j--;
			}
			else if(matrix[i][j] == cost + matrix[i][j-1])
			{
				this->backTrackRoute.push(right);
				j--;
			}
			else if(matrix[i][j] == cost + matrix[i-1][j])
			{
				this->backTrackRoute.push(down);
				i--;
			}
		}
}


double DTW::calcCost(double a, double b)
{
	double diff = a - b;
	
	if(diff < 0)
	{
		diff = diff * -1;
	}

	return diff;
}

double DTW::minimum(double a, double b)
{
	if(a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
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
	cout << "***************************" << endl;
	for(int i = 0; i < matrix.size(); i++)
	{	
		for(int j = 0; j < matrix[i].size(); j++)
		{	
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "***************************" << endl;
	
}



