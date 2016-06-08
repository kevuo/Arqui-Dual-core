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
    mainwindow.cpp \
    api.cpp \
    PCIE.c \
    Interfaz.c

HEADERS  += \
    admimagen.h \
    filtro.h \
    mainwindow.h \
    api.h \
    PCIE.h \
    TERASIC_PCIE.h

FORMS    += \
    mainwindow.ui

OTHER_FILES += \
    Filtro.pro.user \
    Makefile \
    terasic_pcie_qsys.so


LIBS +=`pkg-config opencv --cflags --libs`\
-ldl

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp
