#include <QApplication>
#include <iostream>
#include "DTW_GUI.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    double signal1[] = {.3,.5,.9,.1};
    vector<double> sig1(signal1, signal1 + 
    					sizeof(signal1)/sizeof(double));
    double signal2[] = {.2,.1,.8,.5};
    vector<double> sig2(signal2, signal2 + 
    					sizeof(signal2)/sizeof(double));

    /*int row1[] = {1, 0, 0, 0};
    int row2[] = {1, 1, 0, 0};
    int row3[] = {0, 1, 0, 0};
    int row4[] = {0, 0, 1, 1};
    int *rowa = &row1[0];
    int *rowb = &row2[0];
    int *rowc = &row3[0];
    int *rowd = &row4[0];
    int* array[] = {rowa, rowb, rowc, rowd};*/

    int DTW[] = {1, -1, 1, 0, 0, 1};
    vector<int> DTW1(DTW, DTW + sizeof(DTW)/sizeof(int));

    int temp = 3;
    int *duh = &temp;
    DTW_GUI *w = new DTW_GUI(sig1,sig2,DTW1,0);
    w->show();

    return a.exec();
}
