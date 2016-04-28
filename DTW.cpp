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
	this->backTrackRoute = backTrack(arr1,arr2,this->matrix);

}

DTW::~DTW(){}

stack< vector<double> > DTW::getRoute()
{
	stack< vector<double> > route(this->backTrackRoute);

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

/****************************************************/
/**************need to be finished**********************/

stack< vector <double> > DTW::backTrack(vector<double> arr1, vector<double> arr2, vector< vector <double> > matrix)
{
	stack< vector<double> > points;
	
	int m = matrix.size()-2;
	int n = matrix[m].size()-2;

	vector<double> point(2);
	point[0] = m; 
	point[1] = n;
	points.push(point);
	
	for(int i = m; i > 0;)
	{   
		for(int j = n; j > 0;)
		{ 
			vector<double> point(2);

		    double cost = (arr1[i] - arr2[j]);
            
			double possibility1 = matrix[i-1][j]   + cost; 
			double possibility2 = matrix[i][j-1]   + cost; 
			double possibility3 = matrix[i-1][j-1] + cost; 

		    double curr = matrix[i][j];

//			cout << "i: " << i << "  j: " << j << endl;
		
			if(curr == possibility1)
			{
//			cout << "1curr: " << curr << "\t" << "pos1: " << possibility1 << "pos2: " << possibility2 << "pos3: " << possibility3 << endl;
				point[0] = i-1;
				point[1] = j;
				points.push(point);
				i = i - 1;
			}
			else if(curr == possibility2)
			{
//			cout << "2curr: " << curr << "\t" << "pos1: " << possibility1 << "pos2: " << possibility2 << "pos3: " << possibility3 << endl;
				point[0] = i;
				point[1] = j-1;
				points.push(point);
				j = j - 1;
			}
			else if(curr == possibility3)
			{
//			cout << "3curr: " << curr << "\t" << "pos1: " << possibility1 << "pos2: " << possibility2 << "pos3: " << possibility3 << endl;
				point[0] = i-1;
				point[1] = j-1;
				points.push(point);
				i = i - 1;
				j = j - 1;
			}
			else
			{
				j = j - 1;
			}
		}
		i = i - 1;
	}
	return points;
}
/****************************************************/

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



