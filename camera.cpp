#include "camera.h"

Camera::Camera() : _mEye{0, 0, 0} {
    _mPMatrix.setToIdentity();
    _mVMatrix.setToIdentity();
}

void Camera::init(GLint pMatrixUniform, GLint vMatrixUniform) {
    _mPMatrix.setToIdentity();
    _mVMatrix.setToIdentity();
    _mPMatrixUniform = pMatrixUniform;
    _mVMatrixUniform = vMatrixUniform;
}

void Camera::perspective(int degrees, double aspect, double nearPlane, double farPlane) {
    _mPMatrix.perspective(degrees, aspect, nearPlane, farPlane);
}

void Camera::lookAt(const QVector3D& eye, const QVector3D& at, const QVector3D& up) {
    _mVMatrix.setToIdentity();
    _mVMatrix.lookAt(eye, at, up);
}

void Camera::lookAt(const QVector3D& at, const QVector3D& up) {
    lookAt(_mEye, at, up);
}

void Camera::update() {
    initializeOpenGLFunctions();
    glUniformMatrix4fv(_mPMatrixUniform, 1, GL_FALSE, _mPMatrix.constData());
    glUniformMatrix4fv(_mVMatrixUniform, 1, GL_FALSE, _mVMatrix.constData());
}

void Camera::translate(float dx, float dy, float dz) {
    _mEye += QVector3D{dx, dy, dz};
}

void Camera::setPosition(QVector3D pos)
{
    _mEye.setX(0);
    _mEye.setY(0);
    _mEye.setZ(0);

    translate(pos.x(), pos.y(), pos.z());
}
