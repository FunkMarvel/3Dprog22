#include "octahedronball.h"
#include "pawn.h"
#include "points.h"

Pawn::Pawn()
{
    _visualComponents["ball"] = new OctahedronBall{3};
    _collider = physics::SphereCollider{1.25f};
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
    _collider.setPosition(position());
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

void Pawn::collisionChecker(std::unordered_map<std::string, VisualObject *>& objectsToCheck)
{
    for (const auto& obj : objectsToCheck) {
        if (obj.first == "Scatter") {
            auto scatter = reinterpret_cast<Points*>(obj.second);
            auto closestPoint = scatter->getClosestPoint(position());

            if (_collider.hitCheck(closestPoint)) {
                scatter->onOverlap(QVector3D{closestPoint.w(), 0, 0});
                score++;
            }

            continue;
        }

        if (_collider.hitCheck(obj.second)) obj.second->onOverlap(position());
    }
}
