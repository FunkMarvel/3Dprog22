#ifndef CUBE_H
#define CUBE_H

#include "visualobject.h"

class Cube : public VisualObject {
public:
    Cube();
    void init(GLint matrixUniform) override;
    void draw() override;
    void rotate(QMatrix4x4 matrix);
    static bool ContainsPoint(QVector3D Point);
 };


#endif // CUBE_H
