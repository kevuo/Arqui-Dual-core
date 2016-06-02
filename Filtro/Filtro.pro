#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T14:54:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Filtro
TEMPLATE = app


SOURCES += main.cpp\
    admimagen.cpp \
    filtro.cpp \
    saltfilter.cpp

HEADERS  += \
    admimagen.h \
    filtro.h \
    saltfilter.h

FORMS    += saltfilter.ui

OTHER_FILES += \
    Filtro.pro.user \
    Makefile
