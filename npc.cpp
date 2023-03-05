#include "npc.h"
#include "curve.h"

NPC::NPC()
{

}

void NPC::move(float dx, float dy, float dz)
{
    Tetrahedron::move(dx,dy,dz);
}

void NPC::addPath(std::string pathName, Curve *pathObject)
{
    _paths[pathName] = pathObject;
    pathObject->init(mMatrixUniform);

    if (_currentPath.empty()) _currentPath = pathName;
}

void NPC::drawPath(bool bDraw)
{
    _bDrawPaths = bDraw;
}

void NPC::switchToNextPath()
{
    bool bFound{false};
    for (auto& path : _paths) {
        if (bFound) {
            _currentPath = path.first;
            return;
        }
        if (path.first == _currentPath) bFound = true;
    }
}

void NPC::init(GLint matrixUniform)
{
    Tetrahedron::init(matrixUniform);

    if (!_paths.empty()) return;

    for (auto& path : _paths) {
        path.second->init(matrixUniform);
    }
}

void NPC::draw()
{
    Tetrahedron::draw();

    if (!_bDrawPaths || _paths.empty()) return;

    _paths[_currentPath]->draw();
}

void NPC::onOverlap(const QVector3D &hitPos)
{

}

void NPC::move(float dt)
{
    interpVal += dt;
    interpVal = std::sin(interpVal);
    auto posDelta = (_paths[_currentPath]->getPoint(interpVal) - position());
    Tetrahedron::move(posDelta.x(),posDelta.y(),posDelta.z());
}
