#include "utils.h"

QRegExp Utils::emptyLine = QRegExp(".{2,50}");

Utils::Utils()
{
}

QDateTime Utils::now()
{
    return QDateTime::currentDateTime();
}

QDate Utils::today()
{
    return QDate::currentDate();
}

QTime Utils::time()
{
    return QTime::currentTime();
}
