#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "visualobject.h"

class LineSegment : public VisualObject {
public:
    LineSegment();
    ~LineSegment() override;
    LineSegment(class std::initializer_list<float> vals);

    void init(GLint shader) override;
    void draw() override;
};

#endif // LINESEGMENT_H
