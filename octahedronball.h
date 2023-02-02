#pragma once
#include "visualobject.h"
class OctahedronBall :
    public VisualObject
{
private:
   int m_rekursjoner;        
   int m_indeks;               // brukes i rekursjon, til � bygge m_vertices
   void makeTriangle(const QVector3D& v1, const QVector3D& v2, const QVector3D& v3);
   void subDivide(const QVector3D& a, const QVector3D& b, const QVector3D& c, int n);
   void octahedronUnitBall();
    
public:
   OctahedronBall(int n=0);
   ~OctahedronBall();
   void init(GLint matrixUniform);
   void draw();
};

