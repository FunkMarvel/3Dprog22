#ifndef CURVE_H
#define CURVE_H

#include "trianglesurface.h"

class Curve : public TriangleSurface
{
public:
    Curve();
    Curve(std::string file);

    virtual void init(GLint shader) override;
    virtual void draw() override;
};

#endif // CURVE_H
