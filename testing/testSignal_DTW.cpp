#include "Signal.h"
#include "DTW.h"

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	
	if(argc != 3)
	{
	   cout << "Usage: " << argv[0] << " <input signal name> <input signal name>" << endl;
	   exit(0);
	}
	
	string fileName = argv[1];
	string fileName2 = argv[2];

	Signal a_signal(fileName);
	Signal b_signal(fileName2);
	
	vector<double> a;
	vector<double> b;

	a = a_signal.getSignal();
	b = b_signal.getSignal();

	DTW d(a,b);

	cout << d.getMax() << endl;

//  d.printVector(d.getArr1());
//  d.printVector(d.getArr2());

//	d.printMatrix(d.getMatrix());

	
	
	

	return (0);
}
