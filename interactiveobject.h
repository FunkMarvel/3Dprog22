#ifndef INTERACTIVEOBJECT_H
#define INTERACTIVEOBJECT_H

#include "visualobject.h"

class InteractiveObject : public VisualObject
{
public:
   InteractiveObject();
   ~InteractiveObject() override;

   virtual void init(GLint matrixUniform) override;
   virtual void draw() override;

   virtual void move(float x, float y, float z);

private:
   float mx, my, mz; // posisjon
};

#endif // INTERACTIVEOBJECT_H
