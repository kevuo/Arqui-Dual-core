#ifndef SALTFILTER_H
#define SALTFILTER_H
#include "admimagen.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>

#include <iostream>
#include "string"

using namespace std;


namespace Ui {
    class SaltFilter;
}

class SaltFilter : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaltFilter(QWidget *parent = 0);
    ~SaltFilter();

private slots:
    void on_actionAbrir_triggered();
    void on_Procesar_pressed();
    void on_actionSalir_triggered();
    void on_actionGuardar_triggered();
    
private:
    AdmImagen aAdmImage;
    Ui::SaltFilter *ui;
};

#endif // SALTFILTER_H
