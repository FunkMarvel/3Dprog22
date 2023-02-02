#include "octahedronball.h"
#include "vertex.h"

void OctahedronBall::makeTriangle(const QVector3D& v1, const QVector3D& v2, const QVector3D& v3) {
    Vertex v{v1.x(), v1.y(), v1.z(), v1.x(), v1.y(), v1.z()};
    mVertices.push_back(v);
    v = Vertex{v2.x(), v2.y(), v2.z(), v2.x(), v2.y(), v2.z()};
    mVertices.push_back(v);
    v = Vertex{v3.x(), v3.y(), v3.z(), v3.x(), v3.y(), v3.z()};
}

void OctahedronBall::subDivide(const QVector3D& a, const QVector3D& b, const QVector3D& c, int n) {

}

void OctahedronBall::octahedronUnitBall() {

}

OctahedronBall::OctahedronBall(int n) {
    mVertices.reserve(3 * 8 * pow(4, m_rekursjoner));
    octahedronUnitBall();
}

OctahedronBall::~OctahedronBall() {

}

void OctahedronBall::init(GLint matrixUniform) {

}

void OctahedronBall::draw() {

}
