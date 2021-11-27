#ifndef CHOOSEFILESDIALOG_H
#define CHOOSEFILESDIALOG_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDir>

namespace Ui {
class MainWindow;
}

class ChooseFilesDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseFilesDialog(QWidget *parent = nullptr);
    ~ChooseFilesDialog();

private slots:
    // добавление файлов QStringList files
    void on_listView_doubleClicked(const QModelIndex &index);

    // кнопка Ok
    void on_ok_cancel_button_accepted();

    // кнопка Cancel
    void on_ok_cancel_button_rejected();

signals:
    void mainWindow_ChooseFiles(QStringList &files);

private:
    Ui::MainWindow   *ui;
    QFileSystemModel *fileSystemModel;

    QStringList files;
};

#endif // CHOOSEFILESDIALOG_H
