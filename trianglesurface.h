#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include "visualobject.h"

class TriangleSurface : public VisualObject {
public:
    TriangleSurface();
    TriangleSurface(std::string filnavn);
    ~TriangleSurface() override;
    void readFile(std::string filnavn);

    void init(GLint shader) override;
    void draw() override;

    void move(float dx, float dy, float dz) override;
    void rotate(float deg, float x, float y, float z) override;

private:
    bool bDrawUnitNormals{false};
    std::vector<class LineSegment*> mNormals{};

public:
    void drawUnitNormals(bool on) {
        bDrawUnitNormals = on;
    }
};

#endif // TRIANGLESURFACE_H
