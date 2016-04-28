#ifndef SIGNAL_H
#define SIGNAL_H
#include <vector>
#include <string>
using namespace std;

class Signal
{
	public:
		Signal(string fileName);
		~Signal();
		vector<double> getSignal();

	private:
		vector<double> columns;   //vector that contains all unmodified signals
		vector<double> myColumn; //vector that contains one column of unmodified signals
		vector<double> signal;  //vector that contains concatenated, normalized signals

		void readFile(string fileName);
		void getColumn(int col);
		double getMin();
		double getMax();
		double getRange();
		void normalize(double min, double range);
		void concatenate(vector<double> column);

};

#endif