#include <iostream>
#include <vector>
#include <stack>
#include "DTW.h"

using namespace std;

int main()
{
	vector<double> a;
	vector<double> b;
	
	for(int i = 0; i < 10; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}

	DTW d(a,b);

	d.printMatrix(d.getMatrix());
    d.printVector(d.getArr1());
    d.printVector(d.getArr2());
    
	stack< vector<double> > stak1 = d.getRoute();
	
	while(!stak1.empty())
	{
		vector<double> point = stak1.top();
		stak1.pop();
		cout << "{" << point[0] << "," << point[1] << "}" << "\t";
	}
	cout << endl;

	for(int i = 9; i < 13; i++)
	{
		b.push_back(i+1);
		b.push_back(i-1);
	}
	
	for(int i = 9; i < 13; i++)
	{
		a.push_back(i+6);
		a.push_back(i-1);
	}
	
	//Create an instance of DTW with two vectors	
	//Then henry can call the instance.getMatrix() to draw the curve 
	//and .getArr1() and .getArr2() to get the x and y arrays.
	DTW d2(a,b); 

	d2.printMatrix(d2.getMatrix());
    d2.printVector(d2.getArr1());
    d2.printVector(d2.getArr2());

    stack< vector<double> > stak = d2.getRoute();

    while(!stak.empty())
	{
		vector<double> point = stak.top();
		stak.pop();
		cout << "{" << point[0] << "," << point[1] << "}" << "\t";
	}
	cout << endl;

}

