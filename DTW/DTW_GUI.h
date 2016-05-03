#ifndef DTW_GUI_H
#define DTW_GUI_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
//#include <QLabel>

using namespace std;

namespace Ui {
    class DTW_GUI;
}

class DTW_GUI : public QMainWindow
{
    Q_OBJECT

    public:
	explicit DTW_GUI(QWidget *parent = 0);
        explicit DTW_GUI(vector<double> signal1, 
        	vector<double> signal2,vector<int> DTW,
            QWidget *parent = 0);
        ~DTW_GUI();

    private:
        Ui::DTW_GUI *ui;
        vector<double> signal1;
        vector<double> signal2;
        vector<int> DTW;

    protected:
        void paintEvent(QPaintEvent* e);
        void paintSignal1(QPaintEvent* e);
        void paintSignal2(QPaintEvent* e);
        void paintDTW(QPaintEvent* e);
};

#endif // DTW_GUI_H
