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
#include <QTimer>
#include <QTime>


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
void lancerChronometre();
void pauseChronometre();
void stopChronometre();
void restartChronometre();
void refreshChronometre();
void displayChronometre();
void enabledWidget();
//signals:
//void boutonOK();

private:
    Ui::IHMdeportee *ui;
    QTime *chrono;
    QTimer *chronoTimer;
};

#endif // IHMDEPORTEE_H
