#ifndef PAWN_H
#define PAWN_H

#include "spherecollider.h"
#include "visualobject.h"

class Pawn : public VisualObject
{
public:
    Pawn();
    ~Pawn() = default;


private:
    std::unordered_map<std::string, VisualObject*> _visualComponents{};
    physics::SphereCollider _collider;
    QVector4D _lastPos;
//    Camera _camera{};


    // VisualObject interface
public:
    void init(GLint matrixUniform) override;
    void draw() override;
    void move(float x, float y, float z) override;
    void rotate(float l, float r, float u, float d) override;
    QVector3D rotatePoint(QVector3D Point);
    float getRadius() const;
    QVector3D getLastPos() const;

    void collisionChecker(std::unordered_map<std::string, VisualObject*>& objectsToCheck);

    QVector3D velocity{0.f, 0.f, 0.f};
    float speed{4};
    float turningSpeed{2};
    float jumpHeight{1.5f};

    bool InRangeForDoor{false};

    int score{};
};

#endif // PAWN_H
