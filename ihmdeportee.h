#ifndef IHMDEPORTEE_H
#define IHMDEPORTEE_H

#include <QApplication>
#include <QGraphicsView>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QDateTimeEdit>
#include <QGroupBox>
#include <QSpinBox>
#include <QSlider>
#include <QDialog>
#include <QString>
#include "courbe.h"
#include "ui_courbe.h"


namespace Ui {
class IHMdeportee;
}

class IHMdeportee : public QDialog
{
    Q_OBJECT

public:
    explicit IHMdeportee(QWidget *parent = 0);
    ~IHMdeportee();
    QwtCourbe(QWidget *parent = 0);
    //void conditionsRespectees(int nombreImpulsions, QString valeur, QString largeur, QString periode, QString amplitude);
    //void conditionsRespectees();


public slots:
void fenetreCourbe();
//int recupererValeurs1();
//int recupererValeurs2();
//int recupererValeurs3();
//int recupererValeurs4();
//int recupererValeurs5();
//void autoriseBouton();
//void conditionsRespectees(int nombreImpulsions, QString valeur, QString largeur, QString periode, QString amplitude);

//signals:
//void boutonOK();

private:
    Ui::IHMdeportee *ui;
};

#endif // IHMDEPORTEE_H
