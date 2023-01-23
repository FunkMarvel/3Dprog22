#include "visualobject.h"

VisualObject::VisualObject()
{

}

VisualObject::~VisualObject() {
   glDeleteVertexArrays( 1, &mVAO );
   glDeleteBuffers( 1, &mVBO );
}

void VisualObject::rotate(float deg, float x, float y, float z)
{
   mMatrix.rotate(deg, x, y, z);
}
