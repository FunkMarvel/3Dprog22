#pragma once
#include "interactiveobject.h"
class Tetrahedron : public InteractiveObject
{
public:
	Tetrahedron();

    void init(GLint matrixUniform) override;
    void draw() override;
};

