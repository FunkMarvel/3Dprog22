#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>
#include <QOpenGLFunctions_4_1_Core>
#include <qvectornd.h>


class Camera : QOpenGLFunctions_4_1_Core
{
private:
   GLint  _mPMatrixUniform;        //OpenGL reference to the Uniform in the shader program
   GLint  _mVMatrixUniform;        //OpenGL reference to the Uniform in the shader program
   QVector3D _mEye;
   QMatrix4x4 _mPMatrix{};         // denne,
   QMatrix4x4 _mVMatrix{};         // og denne, skal legges inn i kameraklasse

public:
   Camera();
   ~Camera() override = default;
   void init(GLint pMatrixUniform, GLint vMatrixUniform);
   void perspective(int degrees, double aspect, double nearPlane, double farPlane);
   void lookAt(const QVector3D& eye, const QVector3D& at, const QVector3D& up);
   void update();
   void translate(float dx, float dy, float dz);

};

#endif // CAMERA_H
