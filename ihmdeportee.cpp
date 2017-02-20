#include "ihmdeportee.h"
#include "ui_ihmdeportee.h"


#include<QGridLayout>


#include "D:/Qwt/qwt-6.1.3/qwt-6.1.3/src/qwt_plot.h"
#include "D:/Qwt/qwt-6.1.3/qwt-6.1.3/src/qwt_plot_curve.h"
#include "D:/Qwt/qwt-6.1.3/qwt-6.1.3/src/qwt_series_data.h"


IHMdeportee::IHMdeportee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IHMdeportee)
{
    ui->setupUi(this);

    QwtPlot *myPlot = new QwtPlot(ui->simulation);

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
    ui->simulation->setLayout(layout);

    myPlot->replot();



    //connect(ui->nombreImpulsions, SIGNAL(valueChanged(int)), this, SLOT(recupererValeurs1()));
    //connect(ui->largeurImpulsion, SIGNAL(sliderMoved(int)), this, SLOT(recupererValeurs2()));
    //connect(ui->largeurFenetre, SIGNAL(sliderMoved(int)), this, SLOT(recupererValeurs3()));
    //connect(ui->periodicite, SIGNAL(sliderMoved(int)), this, SLOT(recupererValeurs4()));
    //connect(ui->amplitudeMax, SIGNAL(sliderMoved(int)), this, SLOT(recupererValeurs5()));

    //conditionsRespectees();

    //conditionsRespectees();

    //connect(ui->boutonValider, SIGNAL(clicked(bool)), this, SLOT(fenetreCourbe()));
    //connect(qApp, SIGNAL(boutonOK()), ui->boutonValider, SLOT(autoriseBouton()));

}

IHMdeportee::~IHMdeportee()
{
    delete ui;
}




/*void IHMdeportee::autoriseBouton(int nombreImpulsions, int valeurLargeurImpulsion, int valeurLargeurFenetre, int valeurPeriode, int valeurAmplitude)
{
    if (nombreImpulsions < 11 && valeurLargeurImpulsion < 200 && valeurLargeurFenetre < 100 && valeurPeriode < 100 && valeurAmplitude < 100)
    {
        ui->boutonValider->isEnabled();
    }
}
*/

/*
int IHMdeportee::recupererValeurs1()
{

    int nombreImpulsions;
    nombreImpulsions = ui->nombreImpulsions->value();

}

int IHMdeportee::recupererValeurs2()
{
    bool ok;
    QString valeur;
    valeur = ui->valeurLargeurImpulsion->text();
    int resultat1 = valeur.toInt(&ok,10);
    int valeur;
    valeur = ui->largeurImpulsion->value();

}


int IHMdeportee::recupererValeurs3()
{
    bool ok;
    QString largeur;
    largeur = ui->valeurLargeurFenetre->text();
    int resultat2 = largeur.toInt(&ok,10);

    int largeur;
    largeur = ui->largeurFenetre->value();
}


int IHMdeportee::recupererValeurs4()
{
    bool ok;
    QString periode;
    periode = ui->valeurPeriode->text();
    int resultat3 = periode.toInt(&ok,10);

    int periode;
    periode = ui->periodicite->value();
}


int IHMdeportee::recupererValeurs5()
{
    bool ok;
    QString amplitude;
    amplitude = ui->valeurAmplitude->text();
    int resultat4 = amplitude.toInt(&ok,10);

    int amplitude;
    amplitude = ui->amplitudeMax->value();
}

*/

/*
void IHMdeportee::conditionsRespectees()
{
   bool ok;

   int nombreImpulsions;
   nombreImpulsions = ui->nombreImpulsions->value();

   int valeur;
   valeur = ui->largeurImpulsion->value();

   int largeur;
   largeur = ui->largeurFenetre->value();

   int periode;
   periode = ui->periodicite->value();

   int amplitude;
   amplitude = ui->amplitudeMax->value();


    if (nombreImpulsions < 11 && nombreImpulsions != 0 && valeur != 0 && largeur != 0 && periode != 0 && amplitude != 0)
    {
        //emit boutonOK();
        ui->boutonValider->setEnabled(true);
    }
}

void IHMdeportee::autoriseBouton()
{
    ui->boutonValider->setEnabled(true);
}
*/


/*void IHMdeportee::fenetreCourbe()
{
    //this ->close();
    courbe *NouvelleFenetre = new courbe;
    NouvelleFenetre->show();
}
*/


