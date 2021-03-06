QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

VERSION = 1.0.1
QMAKE_TARGET_COMPANY = Wise man
QMAKE_TARGET_PRODUCT = Zip Archiver
QMAKE_TARGET_DESCRIPTION = Simple zip archiver
QMAKE_TARGET_COPYRIGHT = Vladimir Kirillov

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp widget.cpp \
    chooseFilesDialog.cpp

HEADERS += widget.h \
    chooseFilesDialog.h

FORMS += widget.ui \
    chooseFilesDialog.ui

RC_FILE = icon.rc

INCLUDEPATH += "C:/Users/USER/Desktop/ZipFilesLibrary/include"

LIBS += -L"C:/Users/USER/Desktop/ZipFilesLibrary/lib"
LIBS += -lquazip -lzlib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_CXXFLAGS += -std=gnu++14
