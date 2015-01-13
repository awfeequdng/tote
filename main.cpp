/*
 *
 *
 *
 *
 *
 *
 *
 */

#include "tote.h"
#include "dbconn.h"

#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tote w;




    QCoreApplication::setApplicationName("tote");
    QCoreApplication::setApplicationVersion("0.0.1");
    QCoreApplication::setOrganizationName("bayocr");
    QCoreApplication::setOrganizationDomain("bayocr.com");

    if (!DBConn::openConnection()) {
        QMessageBox::critical(0, "Error al Conectar a la Base de datos", DBConn::db().lastError().text());

        return 1;
    }
    //a.setStyle("fusion");

    w.show();
    return a.exec();
}
