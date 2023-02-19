#include "mainwindow.h"
#include <QApplication>
#include <QMatrix4x4>
#include <QVector4D>
#include <Eigen/Eigen>
#include <iostream>

int main(int argc, char* argv[]) {
    //Forces the usage of desktop OpenGL - Qt uses OpenGL ES as default
    //Attribute must be set before Q(Gui)Application is constructed:
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    //Makes a Qt application
    QApplication a(argc, argv);

    //Makes the Qt MainWindow and shows it.
    MainWindow w;
    w.show();

    Eigen::Matrix3d A{
        {1, 2, 3},
        {2, 3, 1},
        {3, 1, 2}
    };

    std::cout << A << std::endl;

    return a.exec();
}
