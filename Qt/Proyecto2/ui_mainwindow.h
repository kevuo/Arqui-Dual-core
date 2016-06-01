/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *labelImagen1;
    QSlider *paralelismo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelImagen2;
    QLabel *labelPorcentaje;
    QLabel *label_5;
    QPushButton *pushButtonIniciar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1181, 633);
        MainWindow->setWindowOpacity(5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 111, 21));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setAutoDefault(false);
        labelImagen1 = new QLabel(centralWidget);
        labelImagen1->setObjectName(QStringLiteral("labelImagen1"));
        labelImagen1->setGeometry(QRect(20, 70, 561, 461));
        paralelismo = new QSlider(centralWidget);
        paralelismo->setObjectName(QStringLiteral("paralelismo"));
        paralelismo->setGeometry(QRect(590, 10, 441, 21));
        paralelismo->setCursor(QCursor(Qt::PointingHandCursor));
        paralelismo->setMouseTracking(false);
        paralelismo->setAutoFillBackground(false);
        paralelismo->setMinimum(0);
        paralelismo->setMaximum(100);
        paralelismo->setSingleStep(5);
        paralelismo->setValue(50);
        paralelismo->setSliderPosition(50);
        paralelismo->setTracking(true);
        paralelismo->setOrientation(Qt::Horizontal);
        paralelismo->setInvertedControls(false);
        paralelismo->setTickPosition(QSlider::TicksBelow);
        paralelismo->setTickInterval(5);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 10, 221, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 560, 51, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 560, 401, 16));
        labelImagen2 = new QLabel(centralWidget);
        labelImagen2->setObjectName(QStringLiteral("labelImagen2"));
        labelImagen2->setGeometry(QRect(600, 70, 561, 461));
        labelPorcentaje = new QLabel(centralWidget);
        labelPorcentaje->setObjectName(QStringLiteral("labelPorcentaje"));
        labelPorcentaje->setGeometry(QRect(1040, 10, 21, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1060, 10, 21, 17));
        pushButtonIniciar = new QPushButton(centralWidget);
        pushButtonIniciar->setObjectName(QStringLiteral("pushButtonIniciar"));
        pushButtonIniciar->setGeometry(QRect(1090, 10, 71, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1181, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Filtro de im\303\241genes", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Presione para cargar una imagen.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("MainWindow", "Presione para cargar una imagen", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "Cargar imagen", 0));
        labelImagen1->setText(QString());
#ifndef QT_NO_TOOLTIP
        paralelismo->setToolTip(QApplication::translate("MainWindow", "Seleccione el porcentaje de paralelismo", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Porcentaje de paralelismo NIOS", 0));
        label_2->setText(QApplication::translate("MainWindow", "Tiempo", 0));
        label_3->setText(QString());
        labelImagen2->setText(QString());
        labelPorcentaje->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "%", 0));
        pushButtonIniciar->setText(QApplication::translate("MainWindow", "Iniciar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
