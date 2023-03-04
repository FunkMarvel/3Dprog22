#ifndef NPC_H
#define NPC_H

#include "tetrahedron.h"

class NPC : public Tetrahedron
{
public:
    NPC();
    NPC(const NPC &) = delete;
    NPC(NPC &&) = delete;
    NPC &operator=(const NPC &) = delete;
    NPC &operator=(NPC &&) = delete;
    ~NPC() = default;

    virtual void move(float dx, float dy, float dz) override;
    void addPath(std::string pathName, class Curve* pathObject);

    void drawPath(bool bDraw);
    void switchToNextPath();

private:
    std::map<std::string, class Curve*> _paths;
    std::string _currentPath;
    bool _bDrawPaths{false};

    // VisualObject interface
public:
    void init(GLint matrixUniform) override;
    void draw() override;
    void onOverlap(const QVector3D &hitPos) override;
};

#endif // NPC_H
