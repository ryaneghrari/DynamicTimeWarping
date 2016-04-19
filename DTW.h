#ifndef DTW_H
#define DTW_H

#include <vector>

using namespace std;

/**
  Header file for the DTW class. 
*/
class DTW
{
    private:
        vector< vector<double> >     matrix;
		vector<double>               arr1;
		vector<double>               arr2;
		double                       runDTW(vector<double> arr1, vector<double> arr2, vector< vector<double> > matrix);
		void                         initMatrix(vector<double> arr1, vector<double> arr2);
    
    public:
        DTW();
        DTW(vector<double> arr1, vector<double> arr2);
        ~DTW();

		vector< vector<double> > getMatrix();
		vector<double>           getArrY();
		vector<double>           getArrX();
		vector<double>           getArr1();
		vector<double>           getArr2();
		void                     printVector(vector<double> vec); 
		void                     printMatrix(vector< vector<double> > matrix); 
};

#endif
