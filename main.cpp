#include <QApplication>
#include <QtWidgets>
#include "ihmdeportee.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    IHMdeportee fenetre;
    fenetre.show();

    return app.exec();
}
