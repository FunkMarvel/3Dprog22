#ifndef PAWN_H
#define PAWN_H

#include "visualobject.h"

class Pawn : public VisualObject
{
public:
    Pawn();
    ~Pawn() = default;


private:
    std::unordered_map<std::string, VisualObject*> _visualComponents{};
//    Camera _camera{};


    // VisualObject interface
public:
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z) override;
    void rotate(float l, float r, float u, float d) override;

    float getRadius() const;

    QVector3D velocity{0.f, 0.f, 0.f};
    float jumpHeight{1.5f};
};

#endif // PAWN_H
