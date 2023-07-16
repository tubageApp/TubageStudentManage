#include "mainwindow.h"
#include "page_login.h"
#include <QApplication>
#include "stusqlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    StuSqlist sql;

    return a.exec();
}
