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
#include <QFileDialog>
#include <QSettings>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tote w;
    QSettings *settings;
    const QString settingFilePath = QDir::homePath()+"/.tote/tote.ini";
    QFile toteInitFile(settingFilePath);

    QCoreApplication::setApplicationName("tote");
    QCoreApplication::setApplicationVersion("0.0.1");
    QCoreApplication::setOrganizationName("bayocr");
    QCoreApplication::setOrganizationDomain("bayocr.com");

    settings = new QSettings(settingFilePath, QSettings::IniFormat);

    if (!toteInitFile.exists()) {
        QMessageBox::StandardButtons fileMessage;
        fileMessage = QMessageBox::question(0, "Error al cargar la Configuracion", "No se encuentra el archivo de configuracion\n Desea Crearlo", QMessageBox::Yes | QMessageBox::No);
        if (fileMessage == QMessageBox::Yes) {
            qDebug() << "YES";
            settings->beginGroup("db");
//            settings->setValue("dbHost", "localhost");
//            settings->setValue("dbPort", 5432);
//            settings->setValue("dbUser", "postgres");
//            settings->setValue("dbPass", "120.125");
//            settings->setValue("dbName", "tote");
            settings->setValue("dbHost", QString("localhost"));
            settings->setValue("dbPort", int(5432));
            settings->setValue("dbUser", QString("postgres"));
            settings->setValue("dbPass", QString("120.125"));
            settings->setValue("dbName", QString("tote"));
            settings->endGroup();

        } else {

            return 1;
        }
    }

    DBConn::setParams(settings->value("db/dbHost").toString(), settings->value("db/dbPort").toInt(), settings->value("db/dbUser").toString(), settings->value("db/dbPass").toString(), settings->value("db/dbName").toString());
    if (!DBConn::openConnection()) {
        QMessageBox::critical(0, "Error al Conectar a la Base de datos", DBConn::db().lastError().text());

        return 1;
    }

//    w.show();
    w.showMaximized();

    return a.exec();
}
