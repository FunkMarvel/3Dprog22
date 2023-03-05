#include "curve.h"


Curve::Curve() {
}

Curve::Curve(std::string file) {
    mVertices.clear();
    readFile(file);
    mMatrix.setToIdentity();
}

void Curve::init(GLint matrixUniform) {
    this->mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers(1, &mVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), nullptr);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );

    glBindVertexArray(0);
}

void Curve::draw() {
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_LINE_STRIP, 0, mVertices.size());
}

QVector3D Curve::getPoint(float t)
{
    if (t > 1.f) t = 1.f;
    else if (t < 0.f) t = 0.f;

    size_t idx = static_cast<size_t>(t*mVertices.size());

    if (idx >= mVertices.size()) idx = mVertices.size() - 1;
    else if (idx < 0) idx = 0;

    auto vertex = mVertices[idx];
    auto pos = QVector4D{vertex[0], vertex[1], vertex[2], 1};
    pos = mMatrix * pos;

    return QVector3D{pos.x(), pos.y(), pos.z()};
}
