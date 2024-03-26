#include "mainwindow.h"
#include "form.h"
#include <QApplication>


//argc:命令行变量的数里 argv:命令行变量的数组
int main(int argc, char *argv[])
{
    //a:应用程序对象，必须要有且仅有1个
    QApplication a(argc, argv);
    //w:窗口对象
    MainWindow w;
    w.show();
    return a.exec();
}
