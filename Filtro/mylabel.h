#ifndef MYLABEL_H
#define MYLABEL_H
#include <QObject>
#include <QLabel>
#include <iostream>
#include "string"
using namespace std;

class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel();
    MyLabel( QWidget* parent = 0, Qt::WindowFlags f = 0 );
    MyLabel( const QString & text, QWidget * parent = 0 );

signals:
    void clicked();
     \
public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;
};

#endif // MYLABEL_H
