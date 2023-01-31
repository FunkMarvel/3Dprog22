#include "camera.h"

Camera::Camera() : _mEye{0,0,5}
{
	_mPMatrix.setToIdentity();
	_mVMatrix.setToIdentity();
}

void Camera::init(GLint pMatrixUniform, GLint vMatrixUniform)
{
	_mPMatrix.setToIdentity();
	_mVMatrix.setToIdentity();
	_mPMatrixUniform = pMatrixUniform;
	_mVMatrixUniform = vMatrixUniform;
}

void Camera::perspective(int degrees, double aspect, double nearPlane, double farPlane)
{
	_mPMatrix.perspective(degrees, aspect, nearPlane, farPlane);
}

void Camera::lookAt(const QVector3D& eye, const QVector3D& at, const QVector3D& up)
{
	_mVMatrix.lookAt(eye, at, up);
}

void Camera::update()
{
	initializeOpenGLFunctions();
	glUniformMatrix4fv(_mPMatrixUniform, 1, GL_FALSE, _mPMatrix.constData());
	glUniformMatrix4fv(_mVMatrixUniform, 1, GL_FALSE, _mVMatrix.constData());
}

void Camera::translate(float dx, float dy, float dz)
{
	_mEye + QVector3D{dx,dy,dz};
}
