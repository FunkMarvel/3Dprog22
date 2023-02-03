#include <iostream>
#include <sstream>
#include "octahedronball.h"

void OctahedronBall::makeTriangle(const QVector3D& v1, const QVector3D& v2, const QVector3D& v3) {
    Vertex v{v1.x(), v1.y(), v1.z(), v1.x(), v1.y(), v1.z()};
    mVertices.push_back(v);
    v = Vertex{v2.x(), v2.y(), v2.z(), v2.x(), v2.y(), v2.z()};
    mVertices.push_back(v);
    v = Vertex{v3.x(), v3.y(), v3.z(), v3.x(), v3.y(), v3.z()};
    mVertices.push_back(v);
}

void OctahedronBall::subDivide(const QVector3D& a, const QVector3D& b, const QVector3D& c, int n) {
    if (n>0) {
        QVector3D v1 = a+b; v1.normalize();
        QVector3D v2 = a+c; v2.normalize();
        QVector3D v3 = c+b; v3.normalize();
        subDivide(a, v1, v2, n-1);
        subDivide(c, v2, v3, n-1);
        subDivide(b, v3, v1, n-1);
        subDivide(v3, v2, v1, n-1);
    } else {
        makeTriangle(a, b, c);
    }
}

void OctahedronBall::octahedronUnitBall() {
    QVector3D v0{0, 0, 1};
    QVector3D v1{1, 0, 0};
    QVector3D v2{0, 1, 0};
    QVector3D v3{-1, 0, 0};
    QVector3D v4{0, -1, 0};
    QVector3D v5{0, 0, -1};


    subDivide(v0, v1, v2, _mRecursions);
    subDivide(v0, v2, v3, _mRecursions);
    subDivide(v0, v3, v4, _mRecursions);
    subDivide(v0, v4, v1, _mRecursions);
    subDivide(v5, v2, v1, _mRecursions);
    subDivide(v5, v3, v2, _mRecursions);
    subDivide(v5, v4, v3, _mRecursions);
    subDivide(v5, v1, v4, _mRecursions);
}

OctahedronBall::OctahedronBall(int n) : VisualObject(), _mRecursions(n), _mIndex(0) {
    mVertices.reserve(static_cast<std::vector<Vertex>::size_type>(3 * 8 * pow(4, _mRecursions)));
    octahedronUnitBall();
}

OctahedronBall::~OctahedronBall() = default;

void OctahedronBall::init(GLint matrixUniform) {
    mMatrixUniform = matrixUniform;
    initializeOpenGLFunctions();


    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );


    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );


    glBufferData( GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(mVertices.size()*sizeof(Vertex)), mVertices.data(), GL_STATIC_DRAW );


    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE,sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex), reinterpret_cast<const GLvoid*>(3 * sizeof(GLfloat)));  // NOLINT(performance-no-int-to-ptr)
    glEnableVertexAttribArray(1);


    glBindVertexArray(0);
}

void OctahedronBall::draw() {
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(mVertices.size()));//mVertices.size());
}
