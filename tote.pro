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
    citymodel.cpp \
    departamentmodel.cpp \
    neighborhoodmodel.cpp \
    geographymodel.cpp \
    geography.cpp \
    departamentform.cpp

HEADERS  += tote.h \
    brand.h \
    user.h \
    client.h \
    dbconn.h \
    brandmodel.h \
    utils.h \
    login.h \
    countrymodel.h \
    citymodel.h \
    departamentmodel.h \
    neighborhoodmodel.h \
    geographymodel.h \
    geography.h \
    departamentform.h \
    globals.h

FORMS    += tote.ui \
    brand.ui \
    user.ui \
    client.ui \
    login.ui \
    geography.ui \
    geography.ui \
    departamentform.ui

RESOURCES +=
