#include "spherecollider.h"

namespace physics {

SphereCollider::SphereCollider()
{

}

SphereCollider::SphereCollider(float radius, QVector3D position) : _radius(radius), _position(position) {

}

bool SphereCollider::hitCheck(VisualObject *obj)
{
    return ((obj->position() - _position).length() <= _radius);
}

bool SphereCollider::hitCheck(const QVector3D &pos)
{
    return ((pos - _position).length() <= _radius);
}

bool SphereCollider::hitCheck(const QVector4D &pos)
{
    return hitCheck(QVector3D{pos.x(), pos.y(), pos.z()});
}

bool SphereCollider::hitCheck(SphereCollider &someCollider)
{
    return ((_position - someCollider.position()).length() <= _radius + someCollider.radius());
}

float SphereCollider::radius() const
{
    return _radius;
}

void SphereCollider::setRadius(float newRadius)
{
    _radius = newRadius;
}

QVector3D SphereCollider::position() const
{
    return _position;
}

void SphereCollider::setPosition(const QVector3D &newPosition)
{
    _position = newPosition;
}

} // namespace physics
