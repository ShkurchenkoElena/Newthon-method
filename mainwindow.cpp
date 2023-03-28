#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}
MainWindow::~MainWindow(){}

double MainWindow::firstDer(double u){
    return((function(u+h)-function(u-h))/(2*h));
}

double MainWindow::secondDer(double u){
    return((function(u+h)-2*function(u)+function(u+h))/(h*h));
}

void MainWindow::goldenSection(){
    double eps0=0.01;
    double a0=a;
    double b0=b;
    while(abs(b0-a0)>=eps0){
        double u1=a0+(3-sqrt(5))*0.5*(b0-a0);
        double u2=a0+(sqrt(5)-1)*0.5*(b0-a0);
        if(function(u1)<function(u2))
            b0=u2;
        else if(function(u1)>function(u2))
            a0=u1;
        else if(function(u1)==function(u2))
        {  b0=u2;
            a0=u1;
        }
    }
    minPoint=(b0+a0)*0.5;
}

void MainWindow::findMin(){
    goldenSection();
    while(abs(firstDer(minPoint))>eps){
        point.push_back(minPoint);
        minPoint=minPoint-(firstDer(minPoint)/secondDer(minPoint));
    }
    minValue=function(minPoint);
};

