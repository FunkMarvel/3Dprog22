#ifndef CURVE_H
#define CURVE_H

#include "trianglesurface.h"

class Curve : public TriangleSurface {
public:
    Curve();
    Curve(std::string file);


    void init(GLint shader) override;
    void draw() override;

    QVector3D getPoint(float t);
};

#endif // CURVE_H
