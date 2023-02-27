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

void Pawn::Rotate(float l, float r, float u, float d)
{
    for (const auto& component : _visualComponents) {
        component.second->Rotate(l, r, u, d);
    }
}
