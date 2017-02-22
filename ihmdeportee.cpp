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


    //Chrono

    chrono = new QTime ( 0, 0, 0 ) ;
    chronoTimer = new QTimer () ;

    connect(ui->start, SIGNAL(clicked(bool)), this, SLOT(lancerChronometre())); // quand on appuie sur commencer le chrono demarre
    connect(chronoTimer, SIGNAL (timeout()), this, SLOT (refreshChronometre())) ; // mise à jour de la valeur du chrono

    connect(ui->stop, SIGNAL(clicked(bool)), this, SLOT (stopChronometre())) ; // quand on appuie sur stop, le chrono s'arrete
    connect(ui->stop, SIGNAL(clicked(bool)), this, SLOT (enabledWidget())) ;

    connect(ui->pause, SIGNAL(clicked(bool)), this, SLOT (pauseChronometre())) ; // pause
    connect(ui->reprendre, SIGNAL(clicked(bool)), this, SLOT (restartChronometre())) ; //reprendre



    // Courbe

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

}


IHMdeportee::~IHMdeportee()
{
    delete ui;
}


//Démarrer le chrono

void IHMdeportee::lancerChronometre()
{
   chronoTimer -> start ( 1000 ) ;    // On lance un affichage toutes les 1000 milisecondes
   displayChronometre();
}

//Pause

void IHMdeportee::pauseChronometre()
{
        chronoTimer->stop();

}


// arrêt d'urgence et pause

void IHMdeportee::stopChronometre()
{
        chronoTimer->stop();

}

//Relancer le chrono après la pause

void IHMdeportee::restartChronometre()
{
    chronoTimer->start();

}

//Mise à jour du chrono

void IHMdeportee::refreshChronometre()
{
    *chrono = chrono->addSecs(1);
    displayChronometre();
}

//afficher chrono

void IHMdeportee::displayChronometre()
{
    ui->chronometre -> display( chrono->toString("h:mm:ss")) ;
}


//disable les bouton pause, reprendre et commencer quand on appuie sur arret d'urgence

void IHMdeportee::enabledWidget()
{
    QPushButton *bouton1 = new QPushButton;
    bouton1 = ui->reprendre;
    bouton1->setEnabled(false);

    QPushButton *bouton2 = new QPushButton;
    bouton2 = ui->pause;
    bouton2->setEnabled(false);

    QPushButton *bouton3 = new QPushButton;
    bouton3 = ui->start;
    bouton3->setEnabled(false);
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


/*void IHMdeportee::fenetreChrono()
{
    //this ->close();

    NouvelleFenetre->show();
} */



