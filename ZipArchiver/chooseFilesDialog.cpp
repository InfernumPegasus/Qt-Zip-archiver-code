#include "chooseFilesDialog.h"
#include "ui_mainwindow.h"

ChooseFilesDialog::ChooseFilesDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setFilter(QDir::QDir::AllEntries);

    QString rootPath = "/";

    fileSystemModel->setRootPath(rootPath);

    ui->listView->setModel(fileSystemModel);
}

ChooseFilesDialog::~ChooseFilesDialog()
{
    delete ui;
}

// переход по папкам и выбор файла
void ChooseFilesDialog::on_listView_doubleClicked(const QModelIndex &index)
{
    // TODO сделать так чтобы открывалось только одно окно

    QListView *listView = (QListView*)sender();
    QFileInfo fileInfo = fileSystemModel -> fileInfo(index);

    if (fileInfo.fileName() == "..") {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView -> setRootIndex(fileSystemModel -> index(dir.absolutePath()));
    }
    else if (fileInfo.fileName() == ".") {
          listView -> setRootIndex(fileSystemModel -> index("/"));
    }
    else if (fileInfo.isDir()) {
        listView->setRootIndex(index);
    }
    else if (fileInfo.isFile()) {
        files.push_back(fileInfo.absoluteFilePath());
    }
}

// кнопка Ok
void ChooseFilesDialog::on_ok_cancel_button_accepted()
{
    emit mainWindow_ChooseFiles(files);
    close();
}

// кнопка Cancel
void ChooseFilesDialog::on_ok_cancel_button_rejected()
{
    close();
}

