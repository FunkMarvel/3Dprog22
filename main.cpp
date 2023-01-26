#include "mainwindow.h"
#include <QApplication>
#include <QMatrix4x4>
#include <QVector4D>

int main(int argc, char *argv[])
{
    //Forces the usage of desktop OpenGL - Qt uses OpenGL ES as default
    //Attribute must be set before Q(Gui)Application is constructed:
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    //Makes a Qt application
    QApplication a(argc, argv);

    //Makes the Qt MainWindow and shows it.
    MainWindow w;
    w.show();

    std::vector<float> AVals{
        1,1,1,0,
        5,3,2,0,
        1,3,2,0,
        0,0,0,1
    };
    QMatrix4x4 A{AVals.data()};
    QVector4D b{1,2,1,1};

    auto B = A.inverted();
    qDebug() << B*b;

    return a.exec();
}
