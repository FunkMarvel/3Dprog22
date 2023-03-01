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
    for (const auto& component : _visualComponents) {
        component.second->move(x, y, z);
    }
}

void Pawn::rotate(float l, float r, float u, float d)
{
    for (const auto& component : _visualComponents) {
        component.second->rotate(l, r, u, d);
    }
}

float Pawn::getRadius() const
{
    return 1.f;
}
