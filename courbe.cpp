#include "courbe.h"
#include "ui_courbe.h"

#include<QGridLayout>

#include "D:/Qwt/qwt-6.1.3/qwt-6.1.3/src/qwt_plot.h"
#include "D:/Qwt/qwt-6.1.3/qwt-6.1.3/src/qwt_plot_curve.h"
#include "D:/Qwt/qwt-6.1.3/qwt-6.1.3/src/qwt_series_data.h"

courbe::courbe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courbe)
{
    ui->setupUi(this);

    QwtPlot *myPlot = new QwtPlot(this);

    QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");


    QwtPointSeriesData* myData = new QwtPointSeriesData;


    QVector<QPointF>* samples = new QVector<QPointF>;

    samples->push_back(QPointF(1.0,1.0));
    samples->push_back(QPointF(2.0,2.0));
    samples->push_back(QPointF(3.0,3.0));
    samples->push_back(QPointF(4.0,5.0));

    myData->setSamples(*samples);

    curve1->setData(myData);

    curve1->attach(myPlot);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(myPlot, 0, 1);
    this->setLayout(layout);

    myPlot->replot();

}

courbe::~courbe()
{
    delete ui;
}

