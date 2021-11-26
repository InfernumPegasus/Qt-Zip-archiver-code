#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
    Widget widget;
    widget.setWindowTitle("Zip archiver by Vladimir Kirillov");
    widget.show();
    return app.exec();
}
