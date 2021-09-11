#include "iostream"
#include <QApplication>
#include "MainWindow/mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow* mw = new MainWindow();
    mw->show();
    std::cout << "Hello world";
    return app.exec();
}
