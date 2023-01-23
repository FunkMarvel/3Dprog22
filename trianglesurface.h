#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "linesegment.h"
#include "visualobject.h"

class TriangleSurface : public VisualObject
{
public:
    TriangleSurface();
    TriangleSurface(std::string filnavn);
    ~TriangleSurface() override;
    void readFile(std::string filnavn);

    virtual void init(GLint shader) override;
    virtual void draw() override;

    virtual void rotate(float deg, float x, float y, float z) override;

private:
    bool bDrawUnitNormals{false};
    std::vector<LineSegment*> mNormals{};

public:
    void drawUnitNormals(bool on) {
        bDrawUnitNormals = on;
    }
};

#endif // TRIANGLESURFACE_H
