#include "widget.h"
#include "ui_widget.h"
#include <JlCompress.h>
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chooseFilesButton_clicked()
{
    QStringList toArchive = QFileDialog::getOpenFileNames(this, "Choose files", "/", "Files (*.*)");
    for (auto &item : toArchive)
    {
        ui->listWidget->addItem(item);
    }
}


void Widget::on_CreateArchiveButton_clicked()
{
    const int nRows = ui->listWidget->count();
    if (nRows < 1)
    {
        QMessageBox::critical(this, "Archive", "Choose files first!");
        return;
    }

    QString zipArchive = QFileDialog::getSaveFileName(this, "Create archive", "/", "Zip Files (*.zip)");
    QStringList files;

    for (int row = 0; row < nRows; row++)
    {
        files.append(ui->listWidget->item(row)->text());
    }

    if (JlCompress::compressFiles(zipArchive, files))
    {
        QMessageBox::information(this, "Archive", "Archive created!");
    } else {
        QMessageBox::critical(this, "Archive", "Error while archiving!");
    }
}


void Widget::on_unpackButton_clicked()
{
    QString zip = QFileDialog::getOpenFileName(this, "Zip File", "/", "Zip Files (*.zip)");
    if (zip == "")
    {
        QMessageBox::critical(this, "Unpack", "Choose file first!");
        return;
    }

    QStringList zipped = JlCompress::getFileList(zip);
    QString folder = QFileDialog::getExistingDirectory(this, "Choose archive", "/");

    if (!JlCompress::extractFiles(zip, zipped, folder).isEmpty())
    {
            QMessageBox::information(this, "Unpack", "Unpacked!");
    } else {
        QMessageBox::critical(this, "Unpack", "Error while unpacking!");
    }
}


void Widget::on_clearButton_clicked()
{
    if (ui->listWidget->count() < 1)
    {
        QMessageBox::critical(this, "Clear", "No files to clear!");
        return;
    }
    ui->listWidget->clear();
}

