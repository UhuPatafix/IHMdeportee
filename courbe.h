#ifndef COURBE_H
#define COURBE_H

#include <QApplication>
#include <QGraphicsView>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QDateTimeEdit>
#include <QDialog>

namespace Ui {
class courbe;
}

class courbe : public QDialog
{
    Q_OBJECT

public:
    explicit courbe(QWidget *parent = 0);
    ~courbe();

private:
    Ui::courbe *ui;
};

#endif // COURBE_H
