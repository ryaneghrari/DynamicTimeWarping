#include "Signal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

Signal::Signal(string fileName)
{
	readFile(fileName);

	for (int i = 0; i <= 16; i++)
	{
		getColumn(i);

		double min = getMin();
		double max = getMax();
		double range = getRange();

		normalize(min, range);
		concatenate(myColumn);
	}
}

//Signal Destructor
Signal::~Signal()
{

}

//Return a vector containing all 17 normalized, concatenated signals
vector <double> Signal::getSignal()
{
	return signal;
}

//Read in a signal from a file
void Signal::readFile(string fileName)
{
	//Opens the input file and checks to see if it fails to open
	ifstream infile;
	infile.open(fileName.c_str(), ios::in);
	if (!infile.is_open())
	{
		cerr << "The file could not be opened. " << endl;
		exit(1);
	}

	//Reads in entries from the file
	double i = 0.00;
	while (infile.good())
	{
		infile >> i;

		if (infile.fail())
		{
			break;
		}

		columns.push_back(i);
	}
	infile.close();
}

//Get a single column from the signal
void Signal::getColumn(int col)
{
	myColumn.clear();

	myColumn.push_back(columns.at(col));

	col += 17;
	while (col < columns.size())
	{
		try
		{
			myColumn.push_back(columns.at(col));
		}
		catch (const out_of_range& oor)
		{
			return;
		}
		col += 17;
	}
}

//Get the minimum value in a column
double Signal::getMin()
{
	double min = myColumn.at(0);
	for (int i = 1; i < myColumn.size(); i++)
	{
		if (min > myColumn.at(i))
		{
			min = myColumn.at(i);
		}
	}
	return min;
}

//Get the maximum value in a column
double Signal::getMax()
{
	double max = myColumn.at(0);
	for (int i = 1; i < myColumn.size(); i++)
	{
		if (max < myColumn.at(i))
		{
			max = myColumn.at(i);
		}
	}
	return max;
}

//Get the range of the column
double Signal::getRange()
{
	return ( getMax() - getMin() );
}


//Normalize the values for a column in the signal
void Signal::normalize(double min, double range)
{
	for (int i = 0; i < myColumn.size(); i++)
	{
		myColumn.at(i) = (myColumn.at(i) - min) / range;
	}

}

//Concatenate normalized signals
void Signal::concatenate(vector<double> column)
{
	for (int i = 0; i < column.size(); i++)
	{
		signal.push_back(column.at(i));
	}
}



