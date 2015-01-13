#ifndef UTILS_H
#define UTILS_H

#include <QDateTime>
#include <QDate>
#include <QRegExp>

class Utils
{
public:
    Utils();


public:
    static QDateTime now();
    static QDate today();
    static QTime time();

    static QRegExp emptyLine;
};

#endif // UTILS_H
