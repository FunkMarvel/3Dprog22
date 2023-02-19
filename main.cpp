#include "mainwindow.h"
#include <QApplication>
#include <QMatrix4x4>
#include <QVector4D>
#include <Eigen/Eigen>

int main(int argc, char* argv[]) {
    //Forces the usage of desktop OpenGL - Qt uses OpenGL ES as default
    //Attribute must be set before Q(Gui)Application is constructed:
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    //Makes a Qt application
    QApplication a(argc, argv);

    //Makes the Qt MainWindow and shows it.
    MainWindow w;
    w.show();

    Eigen::Matrix<float, 3, 3> A{
        {1, 2, 3},
        {2, 3, 1},
        {3, 1, 2}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            qDebug() << A(i,j);
        }
    }

    return a.exec();
}
