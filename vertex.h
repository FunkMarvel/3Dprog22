#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>



class Vertex
{
public:
    Vertex();
    Vertex(std::initializer_list<float> initList);

    friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
    friend std::istream& operator>>(std::istream& os, Vertex& v);

private:
    float m_xyz[3];
    float m_normal[3];
    float m_st[2];

public:

};

#endif // VERTEX_H
