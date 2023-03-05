#ifndef DOOR_H
#define DOOR_H

#include "spherecollider.h"
#include "visualobject.h"

class Door : public VisualObject
{
public:
    Door();
    void init(GLint matrixUniform) override;
    void draw() override;

    virtual void onOverlap(const QVector3D& pos) override;

    physics::SphereCollider _collider;
    bool DoorIsOpen = false;

};



#endif // DOOR_H
