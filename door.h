#ifndef DOOR_H
#define DOOR_H

#include "visualobject.h"

class Door : public VisualObject
{
public:
    Door();
    void init(GLint matrixUniform) override;
    void draw() override;
    void rotate(QMatrix4x4 matrix);

   // virtual void onOverlap(const QVector3D& hitPos) override;
};

#endif // DOOR_H
