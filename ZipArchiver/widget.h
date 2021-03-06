#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "chooseFilesDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_chooseFilesButton_clicked();

    void on_CreateArchiveButton_clicked();

    void on_unpackButton_clicked();

    void on_clearButton_clicked();

    // выбор файлов
    void copyFiles(QStringList &files);
    void on_chooseFilesButtonAlter_clicked();

protected:
    Ui::Widget *ui;
    ChooseFilesDialog *chooseFileDialog;

    QStringList toArchive;
};
#endif // WIDGET_H
