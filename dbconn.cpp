#include "dbconn.h"


QSqlDatabase DBConn::_db = QSqlDatabase::addDatabase("QPSQL");
DBConn *DBConn::_obj = new DBConn;
int DBConn::insertMode = 0;
int DBConn::detailMode = 1;
int DBConn::updateMode = 2;
int DBConn::deleteMode = 3;
int DBConn::combinedMode = 4;


/**
 * @brief DBConn::DBConn
 * @param parent
 *
 * Contructor Class
 */
DBConn::DBConn(QObject *parent) :
    QObject(parent)
{
//    _db.setHostName("192.168.1.254");
//    _db.setUserName("postgres");
//    _db.setPassword("120.125");
//    _db.setPort(5432);
//    _db.setDatabaseName("tote");
}


DBConn *DBConn::obj()
{
  if (!_obj) {
      _obj = new DBConn();
  }

  return _obj;
}


QSqlDatabase DBConn::db ()
{
    return _db;
}


/*
 * Open Database Connection
 */
bool DBConn::openConnection()
{
    if (!_db.open()) {
        return false;
    }

    return true;
}

void DBConn::setParams(const QString dbHost, const int dbPort, const QString dbUser, const QString dbPass, const QString dbName)
{
    _db.setHostName(dbHost);
    _db.setUserName(dbUser);
    _db.setPassword(dbPass);
    _db.setPort(dbPort);
    _db.setDatabaseName(dbName);
}
