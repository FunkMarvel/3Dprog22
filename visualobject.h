#ifndef VISUALOBJECT_H
#define VISUALOBJECT_H

#include <QOpenGLFunctions_4_1_Core>
#include <QMatrix4x4>
#include <vector>
#include "vertex.h"

class VisualObject : public QOpenGLFunctions_4_1_Core {
public:
    VisualObject();
    ~VisualObject() override;
    virtual void init(GLint matrixUniform) = 0;
    virtual void draw() = 0;
    virtual void move(float x, float y, float z); // pure virtual
    //Test function
    virtual void move(float dt) {
    }

    virtual void rotate(float l, float r, float u, float d);
    virtual void rotate(QVector3D point, float l, float r, float u, float d);

    virtual void onOverlap(const QVector3D& hitPos);

    virtual QVector3D position() const {
        return QVector3D{mPosition.x(), mPosition.y(), mPosition.z()};
    }

    QMatrix4x4 rotation() const;

protected:
    std::vector<Vertex> mVertices;
    GLuint mVAO{0};
    GLuint mVBO{0};
    GLint mMatrixUniform{0};
    QMatrix4x4 mMatrix;

    QVector4D mPosition{0, 0, 0, 1};
    QMatrix4x4 mRotation;
};
#endif // VISUALOBJECT_H
