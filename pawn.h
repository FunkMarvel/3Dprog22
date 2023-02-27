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


    // VisualObject interface
public:
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z) override;
    void Rotate(float l, float r, float u, float d) override;
};

#endif // PAWN_H
