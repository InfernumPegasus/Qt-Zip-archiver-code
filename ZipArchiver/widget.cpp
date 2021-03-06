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

// выбор файлов
void Widget::on_chooseFilesButton_clicked()
{
    toArchive = QFileDialog::getOpenFileNames(this, "Choose files", "/", "Files (*.*)");

    for (auto &file : toArchive)
    {
        ui->listWidget->addItem(file);
    }
}

// альтернативная версия выбора файлов с использованием пользовательского класса
void Widget::on_chooseFilesButtonAlter_clicked()
{
    chooseFileDialog = new ChooseFilesDialog(this);
    chooseFileDialog->show();

    // имитация сигнала для добавления файлов
    connect(chooseFileDialog, SIGNAL(mainWindow_ChooseFiles(QStringList&)), this, SLOT(copyFiles(QStringList&)));
}

// создание архива
void Widget::on_CreateArchiveButton_clicked()
{
    toArchive.removeDuplicates();
    const int nRows = toArchive.count();
    if (nRows < 1)
    {
        QMessageBox::critical(this, "Archive", "Choose files first!");
        return;
    }

    QString zipArchive = QFileDialog::getSaveFileName(this, "Create archive", "/", "Zip Files (*.zip)");

    if (JlCompress::compressFiles(zipArchive, toArchive))
    {
        QMessageBox::information(this, "Archive", "Archive created!");
    } else {
        QMessageBox::critical(this, "Archive", "Error while archiving!");
    }
}

// распаковка архива
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

// очистка списка файлов для архивации
void Widget::on_clearButton_clicked()
{
    if (ui->listWidget->count() < 1 || toArchive.count() < 1)
    {
        QMessageBox::critical(this, "Clear", "No files to clear!");
        return;
    }
    ui->listWidget->clear();
    toArchive.clear();
}

// добавление файлов для архивации альтернативным способом
void Widget::copyFiles(QStringList &files)
{
    for (auto &item : files)
    {
        toArchive.push_back(item);
        ui->listWidget->addItem(item);
    }
}
