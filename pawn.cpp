#include "octahedronball.h"
#include "pawn.h"

Pawn::Pawn()
{
    _visualComponents["ball"] = new OctahedronBall{3};
}

void Pawn::init(GLint matrixUniform)
{
    for (const auto& component : _visualComponents) {
        component.second->init(matrixUniform);
    }
}

void Pawn::draw()
{
    for (const auto& component : _visualComponents) {
        component.second->draw();
    }
}

void Pawn::move(float x, float y, float z)
{
    QVector4D moveVec{x,y,z, 1};
    moveVec = mRotation * moveVec;
    mPosition += moveVec;
    for (const auto& component : _visualComponents) {
        component.second->move(moveVec.x(), moveVec.y(), moveVec.z());
    }
}

void Pawn::rotate(float l, float r, float u, float d)
{
    mRotation.rotate(l, r, u, d);
    for (const auto& component : _visualComponents) {
        component.second->rotate(l, r, u, d);
    }
}

float Pawn::getRadius() const
{
    return 1.f;
}
