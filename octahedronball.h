#pragma once
#include "visualobject.h"

class OctahedronBall : public VisualObject {
private:
    int _mRecursions;
    int _mIndex; // brukes i rekursjon, til � bygge m_vertices
    void makeTriangle(const QVector3D& v1, const QVector3D& v2, const QVector3D& v3);
    void subDivide(const QVector3D& a, const QVector3D& b, const QVector3D& c, int n);
    void octahedronUnitBall();

public:
    explicit OctahedronBall(int n = 0);
    ~OctahedronBall() override;
    void init(GLint matrixUniform) override;
    void draw() override;

};
