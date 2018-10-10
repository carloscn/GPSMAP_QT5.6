#include "widget.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QApplication::setWindowIcon(QIcon("ic.ico"));
    w.show();

    return a.exec();
}
