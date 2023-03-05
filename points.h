#ifndef POINTS_H
#define POINTS_H

#include "visualobject.h"

class Points : public VisualObject
{
public:
    Points();
    Points(std::string filename, int pointSize = 5);
    void readFile(std::string filnavn);

    void draw() override;
    void init(GLint matrixUniform) override;

    virtual void onOverlap(const QVector3D& hitPos) override;
    QVector4D getClosestPoint(const QVector3D& pos) const;

    bool bEmpty{false};

private:
    int m_pointSize{1};
};

#endif // POINTS_H
