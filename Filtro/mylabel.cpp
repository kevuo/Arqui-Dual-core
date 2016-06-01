#include "mylabel.h"

MyLabel::MyLabel()
{
}

MyLabel::MyLabel( const QString & text, QWidget * parent )
:QLabel(parent)
{
connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}


MyLabel::MyLabel( QWidget * parent, Qt::WindowFlags f )
    : QLabel( parent, f ) {}


void MyLabel::slotClicked()
{
qDebug("Clicked");
}

void MyLabel::mousePressEvent ( QMouseEvent * event )
{
emit clicked();

}
