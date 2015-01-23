#-------------------------------------------------
#
# Project created by QtCreator 2014-11-02T05:20:21
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tote
TEMPLATE = app


SOURCES += main.cpp\
        tote.cpp \
    brand.cpp \
    user.cpp \
    client.cpp \
    dbconn.cpp \
    brandmodel.cpp \
    utils.cpp \
    login.cpp \
    countrymodel.cpp \
    geography.cpp \
    image.cpp \
    citymodel.cpp \
    departamentmodel.cpp \
    neighborhoodmodel.cpp

HEADERS  += tote.h \
    brand.h \
    user.h \
    client.h \
    dbconn.h \
    brandmodel.h \
    utils.h \
    login.h \
    countrymodel.h \
    geography.h \
    image.h \
    citymodel.h \
    departamentmodel.h \
    neighborhoodmodel.h

FORMS    += tote.ui \
    brand.ui \
    user.ui \
    client.ui \
    login.ui \
    geography.ui \
    image.ui

RESOURCES += \
    rsctote.qrc
