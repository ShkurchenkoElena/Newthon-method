#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.findMin();
    w.show();
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries();


    for(float j=w.a;j<w.b;j+=0.01)
        series->append(j,w.function(j));

    //chart->addSeries(series);
    chart->addSeries(series);

    chart->setTitle("QT Charts example");


    //add axis to the chart
    QValueAxis *axisX = new QValueAxis;
    axisX->setTickCount(1);
    axisX->setTitleText("X");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("f(x)");
    axisX->setTickCount(1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    w.setCentralWidget(chartView);

    for(int i=0;i<w.point.size();i++)
         std::cout<<w.point[i]<<std::endl;

    std::cout<<"minP "<<w.minPoint<<std::endl;
    std::cout<<"minV "<<w.minValue<<std::endl;

    return a.exec();
}
