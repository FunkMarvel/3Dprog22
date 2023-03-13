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

    pathObject->init(mMatrixUniform);

    if (_paths.empty()) {
        _currentPath = pathName;

        auto startPos = pathObject->getPoint(0);
        move(startPos.x(), startPos.y(), startPos.z());
    }

    _paths[pathName] = pathObject;
}

void NPC::drawPath(bool bDraw)
{
    _bDrawPaths = bDraw;
}

void NPC::switchToNextPath()
{
    if (_paths.size() <= 1) return;
    if ((--_paths.end())->first == _currentPath) {
        _currentPath = _paths.begin()->first;
        return;
    }

    for (auto it = _paths.begin(); it != _paths.end(); ++it) {
        if (it->first == _currentPath) {
            _currentPath = (++it)->first;
            return;
        }
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
    auto posDelta = (_paths[_currentPath]->getPoint(dt) - position());
    Tetrahedron::move(posDelta.x(),posDelta.y(),posDelta.z());
}

Curve *NPC::getPath()
{
    return getPath(_currentPath);
}

Curve* NPC::getPath(std::string pathName)
{
    return _paths[pathName];
}
