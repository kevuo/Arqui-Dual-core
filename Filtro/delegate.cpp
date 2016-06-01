#include "delegate.h"

Delegate::Delegate(QObject *parent) :
    QItemDelegate(parent)
{


}
QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    QSpinBox* Editor= new QSpinBox(parent);
    Editor->setMinimum(-1);
    Editor->setMaximum(50);
    return Editor;

}
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    int Value= index.model()->data(index,Qt::EditRole).toInt();
    QSpinBox *SpinBox= static_cast<QSpinBox*>(editor);
    SpinBox->setValue(Value);

}
void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    QSpinBox *SpinBox= static_cast<QSpinBox*>(editor);
    SpinBox->interpretText();
    int Value = SpinBox->value();
    model->setData(index,Value,Qt::EditRole);

}
void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    editor->setGeometry(option.rect);
}
