#include "DTW_GUI.h"
#include "ui_DTW_GUI.h"
#define OFFSET 20

using namespace std;

DTW_GUI::DTW_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DTW_GUI)
{
    ui->setupUi(this);
}

DTW_GUI::DTW_GUI(vector<double> signal1, 
            vector<double> signal2,vector<int> DTW,
            QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DTW_GUI)
{
    this->signal1 = signal1;
    this->signal2 = signal2;
    this->DTW = DTW;
    ui->setupUi(this);
}

DTW_GUI::~DTW_GUI()
{
    delete ui;
}

void DTW_GUI::paintEvent(QPaintEvent *e)
{
    // This is an example paintEvent method only.  You should
    // modify appropriately, consulting Qt references for 
    // alternate components to do the job you need....

    this->setWindowTitle("Timeseries Allignment");

    QPainter painter(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(2);

    QPen pointPen2(Qt::black);
    pointPen.setWidth(1);

    painter.setPen(pointPen);

    painter.drawRect(QRect(0+OFFSET,0+OFFSET,100,200));
    painter.drawRect(QRect(110+OFFSET,210+OFFSET,200,100));
    painter.drawRect(QRect(110+OFFSET,0+OFFSET,200,200));

    painter.setPen(pointPen2);
    painter.drawLine(15,195+OFFSET,25,195+OFFSET);
    //painter.drawLine(15, )

    paintSignal1(e);
    paintSignal2(e);
    paintDTW(e);

}

void DTW_GUI::paintSignal1(QPaintEvent* e)
{
    QPainter painter(this);
    QPen linePen(Qt::black);

    linePen.setWidth(4);
    painter.setPen(linePen);

    QPoint p1,p2;
    p1.setX(50+OFFSET); p1.setY(190+OFFSET);

    for (int i = 0; i < signal1.size(); i++)
    {
        p2.setX(OFFSET + 100 * signal1[i]); p2.setY(199 + OFFSET - 20 * i);

        painter.drawLine(p1,p2);

        p1 = p2;

    }

}

void DTW_GUI::paintSignal2(QPaintEvent* e)
{
    QPainter painter(this);
    QPen linePen(Qt::black);

    linePen.setWidth(4);
    painter.setPen(linePen);

    QPoint p1,p2;
    p1.setX(111 + OFFSET); p1.setY(260 + OFFSET);

    for (int i = 0; i < signal2.size(); i++)
    {
        p2.setX(111 + OFFSET + 20 * i); p2.setY(310 + OFFSET - 100 * signal2[i]);

        painter.drawLine(p1,p2);

        p1 = p2;

    }

}

void DTW_GUI::paintDTW(QPaintEvent* e)
{
    QPainter painter(this);
    QPen linePen(Qt::black);

    linePen.setWidth(4);
    painter.setPen(linePen);

    QPoint p1,p2;
    p1.setX(120+OFFSET); p1.setY(200+OFFSET);
    p2 = p1;

    /*for (int i = 0; i < signal1.size() ; ++i)
    {
        p2.setY(200 + OFFSET - 10 * (i)); 

        for (int j = 0; j < signal1.size(); ++j)
        {
            if (DTW[i][j] == 1)
            {
                p2.setX(120 + OFFSET + 10 * j);

                painter.drawLine(p1,p2);
                p1 = p2;
            }
        }
    }*/

    int y = 0;
    int x = 0;

    for (int i = 0; i < DTW.size(); ++i)
    {
        if (DTW[i] == 1)
        {
            p2.setX(120 + OFFSET + 10 * x);

            painter.drawLine(p1,p2);
            p1 = p2;
            x++;
        }

        if (DTW[i] == -1)
        {
            p2.setY(200 + OFFSET - 10 * y);

            painter.drawLine(p1,p2);
            p1 = p2;
            y++;
        }
        else{
            p2.setX(120 + OFFSET + 10 * x);
            p2.setY(200 + OFFSET - 10 * y);

            painter.drawLine(p1,p2);
            p1 = p2;
            x++;
            y++;
        }
    }
}
