#include "mainwindow.h"
#include <QApplication>
#include <QMatrix4x4>
#include <QVector4D>

int main(int argc, char* argv[]) {
    //Forces the usage of desktop OpenGL - Qt uses OpenGL ES as default
    //Attribute must be set before Q(Gui)Application is constructed:
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

    //Makes a Qt application
    QApplication a(argc, argv);

    //Makes the Qt MainWindow and shows it.
    MainWindow w;
    w.show();

    blaze::DynamicMatrix<float> A{
        { 1, 1, 1 },
        { 5, 3, 2 },
        { 1, 3, 2 }
    };

    blaze::DynamicVector<float> b{
        {1},
        {2},
        {1}
    };

    blaze::invert(A);
    blaze::DynamicVector<float> result = A * b;

    qDebug() << "x = [" << result[0] << ", " << result[1] << ", " << result[2] << "]";

    return a.exec();
}
