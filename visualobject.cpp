// VisualObject.cpp
#include "visualobject.h"

VisualObject::VisualObject() {
    mRotation.setToIdentity();
}

VisualObject::~VisualObject() {
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);
}

void VisualObject::move(float dx, float dy, float dz) {
    QVector4D transVec{dx,dy,dz, 1.f};
    transVec = mRotation.inverted() * transVec;
    mMatrix.translate(transVec.x(), transVec.y(), transVec.z()); // need to tell it to move
    mPosition = mMatrix * QVector4D{0, 0, 0, 1};
}

void VisualObject::rotate(float dl, float dr, float du, float dd) {
    mRotation.rotate(dl, dr, du, dd);
    mMatrix.rotate(dl, dr, du, dd);
}

void VisualObject::rotate(QVector3D point, float l, float r, float u, float d)
{
    mRotation.rotate(l, r, u, d);
    mMatrix.translate(-point.x(), -point.y(), -point.z());
    mMatrix.rotate(l, r, u, d);
    mMatrix.translate(point.x(), point.y(), point.z());
}

void VisualObject::onOverlap(const QVector3D &hitPos)
{

}
