#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>


class Vertex {
public:
    Vertex();
    Vertex(const Vertex &) = default;
    Vertex(Vertex &&) = default;
    Vertex &operator=(const Vertex &) = default;
    Vertex &operator=(Vertex &&) = default;
    Vertex(std::initializer_list<float> initList);

    friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
    friend std::istream& operator>>(std::istream& os, Vertex& v);

    float& operator[](size_t index) {
        if (index >= 8) throw std::range_error("Index " + std::to_string(index) + " for vertex.");

        if (index < 3) {
            return m_xyz[index];
        }
        if (index < 6) {
            return m_normal[index - 3];
        }
        return m_st[index - 6];
    }

private:
    float m_xyz[3];
    float m_normal[3];
    float m_st[2];

public:
};

#endif // VERTEX_H
