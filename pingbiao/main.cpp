#include "mainwindow.h"

#include <QApplication>
#include "mainwidget.h"
#include "userwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    MainWidget m;
    m.show();
    UserWidget u;
    u.show();
    return a.exec();
}
