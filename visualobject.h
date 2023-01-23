#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include "vertex.h"
#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>


class VisualObject : public QOpenGLFunctions_4_1_Core
{
public:
    VisualObject();
    ~VisualObject();

    virtual void init(GLint matrixUniform) = 0;
    virtual void draw() = 0;

protected:
    std::vector<Vertex> mVertices{};
    GLuint mVAO{0};
    GLuint mVBO{0};
    GLint mMatrixUniform{0};

public:
    QMatrix4x4 mMatrix;
    virtual void rotate(float deg, float x, float y, float z);
};

#endif // VISUALOBJECT_H
