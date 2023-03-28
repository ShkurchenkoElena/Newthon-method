#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCharts/QtCharts>
#include<iostream>
QT_CHARTS_USE_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double a=-2;  double b=0;   //границы отрезка
    double eps=1e-15; //требуемая точность
    double h=0.01;    //шаг для поиска сеточных приближений первой и второй производной
    double minValue;  //минимальное значение функции
    double minPoint;   //точка минимума
    QVector<double> point;   //вектор перебранных точек в методе Ньютона

    double function(double u)
    {
        return (sin(u));
    };

    double firstDer(double u);
    double secondDer(double u);
    void goldenSection(); //сужение зоны поиска методом золотого сечения
    void findMin();       //поиск минимума методом Ньютона

};
#endif // MAINWINDOW_H
