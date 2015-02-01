#ifndef DBCONN_H
#define DBCONN_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

class DBConn : public QObject
{
    Q_OBJECT
public:
    explicit DBConn(QObject * parent = 0);

    static DBConn *_obj;
    static DBConn *obj();
    static QSqlDatabase _db;
    static QSqlDatabase db();
    static bool openConnection();
    static int insertMode;
    static int detailMode;
    static int updateMode;
    static int deleteMode;
    static int combinedMode;
    static void setParams(const QString dbHost, const int dbPort, const QString dbUser, const QString dbPass, const QString dbName);
};

#endif // DBCONN_H
