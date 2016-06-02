/********************************************************************************
** Form generated from reading UI file 'saltfilter.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALTFILTER_H
#define UI_SALTFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_SaltFilter
{
public:
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionSalir;
    QWidget *centralWidget;
    MyLabel *ImageShow;
    QPushButton *Procesar;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SaltFilter)
    {
        if (SaltFilter->objectName().isEmpty())
            SaltFilter->setObjectName(QStringLiteral("SaltFilter"));
        SaltFilter->resize(1049, 607);
        actionAbrir = new QAction(SaltFilter);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionGuardar = new QAction(SaltFilter);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionSalir = new QAction(SaltFilter);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralWidget = new QWidget(SaltFilter);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImageShow = new MyLabel(centralWidget);
        ImageShow->setObjectName(QStringLiteral("ImageShow"));
        ImageShow->setGeometry(QRect(20, 20, 811, 571));
        Procesar = new QPushButton(centralWidget);
        Procesar->setObjectName(QStringLiteral("Procesar"));
        Procesar->setGeometry(QRect(861, 137, 85, 27));
        SaltFilter->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SaltFilter);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1049, 18));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuArchivo->setGeometry(QRect(115, 109, 107, 101));
        SaltFilter->setMenuBar(menuBar);
        statusBar = new QStatusBar(SaltFilter);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        SaltFilter->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionSalir);

        retranslateUi(SaltFilter);

        QMetaObject::connectSlotsByName(SaltFilter);
    } // setupUi

    void retranslateUi(QMainWindow *SaltFilter)
    {
        SaltFilter->setWindowTitle(QApplication::translate("SaltFilter", "SaltFilter", 0));
        actionAbrir->setText(QApplication::translate("SaltFilter", "Abrir", 0));
        actionAbrir->setShortcut(QApplication::translate("SaltFilter", "Ctrl+O", 0));
        actionGuardar->setText(QApplication::translate("SaltFilter", "Guardar", 0));
        actionGuardar->setShortcut(QApplication::translate("SaltFilter", "Ctrl+S", 0));
        actionSalir->setText(QApplication::translate("SaltFilter", "Salir", 0));
        actionSalir->setShortcut(QApplication::translate("SaltFilter", "Ctrl+X", 0));
        ImageShow->setText(QString());
        Procesar->setText(QApplication::translate("SaltFilter", "Procesar", 0));
        menuArchivo->setTitle(QApplication::translate("SaltFilter", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class SaltFilter: public Ui_SaltFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALTFILTER_H
