#ifndef PHYSICS_SPHERECOLLIDER_H
#define PHYSICS_SPHERECOLLIDER_H

#include "visualobject.h"

#include <QVector3D>



namespace physics {

class SphereCollider
{
public:
    SphereCollider();
    SphereCollider(const SphereCollider &) = default;
    SphereCollider(SphereCollider &&) = default;
    SphereCollider &operator=(const SphereCollider &) = default;
    SphereCollider &operator=(SphereCollider &&) = default;
    SphereCollider(float radius, QVector3D position = QVector3D{0, 0, 0});

    bool hitCheck(VisualObject* obj);
    bool hitCheck(const QVector3D& pos);
    bool hitCheck(const QVector4D& pos);
    bool hitCheck(const SphereCollider& someCollider);

    float radius() const;
    void setRadius(float newRadius);
    QVector3D position() const;
    void setPosition(const QVector3D &newPosition);

private:
    float _radius{};
    QVector3D _position{};
};

} // namespace physics

#endif // PHYSICS_SPHERECOLLIDER_H
