#include "camera.h"

Camera::Camera() : _mEye{0, 0, 0} {
    _mPMatrix.setToIdentity();
    _mVMatrix.setToIdentity();
    _mRotation.setToIdentity();
}

void Camera::init(GLint pMatrixUniform, GLint vMatrixUniform) {
    _mPMatrix.setToIdentity();
    _mVMatrix.setToIdentity();
    _mRotation.setToIdentity();

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
    QVector4D moveVec{dx,dy,dz, 1};
    moveVec = _mRotation * moveVec;
    _mEye += QVector3D{moveVec.x(), moveVec.y(), moveVec.z()};
}

void Camera::rotate(const QVector4D& rotation, const QVector3D& point)
{
    QMatrix4x4 transMat{};
    QVector4D camPos{_mEye.x(), _mEye.y(), _mEye.z(), 1.f};

    transMat.setToIdentity();
    transMat.translate(-point.x(), -point.y(), -point.z());
    camPos = transMat * camPos;

    transMat.setToIdentity();
    transMat.rotate(rotation.x(), rotation.y(), rotation.z(), rotation.w());
    _mRotation.rotate(rotation.x(), rotation.y(), rotation.z(), rotation.w());
    camPos = transMat * camPos;

    transMat.setToIdentity();
    transMat.translate(point.x(), point.y(), point.z());
    camPos = transMat * camPos;

    _mEye = QVector3D{camPos.x(), camPos.y(), camPos.z()};
}

void Camera::setPosition(QVector3D pos)
{
    _mEye.setX(0);
    _mEye.setY(0);
    _mEye.setZ(0);

    translate(pos.x(), pos.y(), pos.z());
}
