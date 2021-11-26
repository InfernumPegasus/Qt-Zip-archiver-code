#ifndef ARCHIVER_H
#define ARCHIVER_H

#include <JlCompress.h>
#include <QFileDialog>
#include <QMessageBox>

#include "widget.h"

class Archiver
{
public:
    Archiver();
    ~Archiver();

    void ChooseFiles();

    void CreateArchive();

    void UnpackArchive();
};

#endif // ARCHIVER_H
