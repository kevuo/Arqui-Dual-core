#ifndef MAPEDITOR_H
#define MAPEDITOR_H
#include "admimagen.h"
#include "admmatriz.h"
#include "admxml.h"
#include "delegate.h"
#include "mylabel.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>

#include <iostream>
#include "string"
using namespace std;


namespace Ui {
    class MapEditor;
}

class MapEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapEditor(QWidget *parent = 0);
    ~MapEditor();

private slots:
    void on_actionAbrir_triggered();

    void on_Procesar_pressed();

    void on_Siguiente_pressed();

    void on_actionSalir_triggered();

    void on_ImageShow_clicked();


    void on_radioButton01_clicked();
    void on_radioButton02_clicked();
    void on_radioButton03_clicked();
    void on_radioButton04_clicked();
    void on_radioButton05_clicked();
    void on_radioButton06_clicked();
    void on_radioButton07_clicked();
    void on_radioButton08_clicked();
    void on_radioButton09_clicked();
    void on_radioButton10_clicked();
    void on_radioButton11_clicked();
    void on_radioButton12_clicked();
    void on_radioButton13_clicked();
    void on_radioButton14_clicked();
    void on_radioButton15_clicked();
    void on_radioButton16_clicked();
    void on_radioButton17_clicked();
    void on_radioButton18_clicked();
    void on_radioButton19_clicked();
    void on_radioButton20_clicked();
    void on_radioButton21_clicked();
    void on_radioButton22_clicked();
    void on_radioButton23_clicked();
    void on_radioButton24_clicked();
    void on_radioButton25_clicked();
    void on_radioButton26_clicked();
    void on_radioButton27_clicked();


    void on_actionGuardar_triggered();

private:
    AdmImagen aAdmImage;
    AdmMatriz aAdmMatriz;
    AdmXML aAdmXML;
    Ui::MapEditor *ui;
    QStandardItemModel *aModel;
    Delegate *aDelegate;
    int aColor;
    bool aEdit;
};

#endif // MAPEDITOR_H
