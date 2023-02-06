#include "vertex.h"

Vertex::Vertex() {
    for (int i = 0; i < 3; ++i) {
        m_xyz[i] = 0;
        m_normal[i] = 0;

        if (i > 1) continue;
        m_st[i] = 0;
    }
}

// initialize from arbitrary number of floats
Vertex::Vertex(std::initializer_list<float> initList) : Vertex() {
    size_t count = initList.size();
    if (count > 8) throw std::range_error("To many arguments in initializer list.");

    auto iterator = initList.begin();

    // fill up xyz, then normals, then st.
    for (size_t i = 0; i < count; ++i) {
        if (i < 3) {
            m_xyz[i] = *iterator;
        }
        else if (i < 6) {
            m_normal[i - 3] = *iterator;
        }
        else {
            m_st[i - 6] = *iterator;
        }

        ++iterator;
    }
}

std::ostream& operator<<(std::ostream& os, const Vertex& v) {
    os << std::fixed;
    os << "(" << v.m_xyz[0] << ", " << v.m_xyz[1] << ", " << v.m_xyz[2] << ") | ";
    os << "(" << v.m_normal[0] << ", " << v.m_normal[1] << ", " << v.m_normal[2] << ") | ";
    os << "(" << v.m_st[0] << ", " << v.m_st[1] << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vertex& v) {
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> v.m_xyz[0] >> dum2 >> v.m_xyz[1] >> dum3 >> v.m_xyz[2] >> dum4;
    is >> dum >> v.m_normal[0] >> dum2 >> v.m_normal[1] >> dum3 >> v.m_normal[2] >> dum4;
    is >> dum >> v.m_st[0] >> dum2 >> v.m_st[1] >> dum3;
    return is;
}
