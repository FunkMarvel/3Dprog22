#include "Door.h"
#include "octahedronball.h"
#include "pawn.h"
#include "points.h"
#include "cube.h"

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
    _lastPos = mPosition;
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

QVector3D Pawn::rotatePoint(QVector3D Point)
{
    QVector4D TempPoint{Point.x(),Point.y(),Point.z(),1};
    QMatrix4x4 tempMat;

    tempMat.setToIdentity();

    tempMat.translate(-Point);

    TempPoint = tempMat * TempPoint;

    tempMat.setToIdentity();

    TempPoint = mRotation * TempPoint;

    tempMat.translate(Point);

    TempPoint = tempMat * TempPoint;

    return QVector3D{TempPoint.x(),TempPoint.y(),TempPoint.z()};
}

float Pawn::getRadius() const
{
    return 1.f;
}

QVector3D Pawn::getLastPos() const
{
    return QVector3D{_lastPos.x(),_lastPos.y(),_lastPos.z()};
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
        if(obj.first == "Door"){

        auto door = reinterpret_cast<Door*>(obj.second);
            if(_collider.hitCheck(door->_collider)){
            InRangeForDoor = true;

            }
            else InRangeForDoor = false;
            continue;
        }

        if (_collider.hitCheck(obj.second)) obj.second->onOverlap(position());
    }
}
