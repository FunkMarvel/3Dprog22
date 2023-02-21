#include "points.h"
#include <fstream>

Points::Points()
{

}

Points::Points(std::string file, int pointSize) : m_pointSize(pointSize) {
    mVertices.clear();
    readFile(file);
    mMatrix.setToIdentity();
}

void Points::readFile(std::string filnavn) {
    std::fstream inn;
    inn.open(filnavn, std::fstream::in);

    if (inn.is_open()) {
        qDebug() << "file open\n";
        int n;
        Vertex vertex;
        inn >> n;
        mVertices.reserve(n);
        for (int i = 0; i < n; i++) {
            inn >> vertex;
            mVertices.push_back(vertex);
            //           qDebug() << mVertices[i][0] << ", " << mVertices[i][1] << ", " << mVertices[i][2] << ", " << mVertices[i][3] << ", " << mVertices[i][4] << ", " << mVertices[i][5];
        }
        inn.close();
    }
    else {
        qDebug() << "file not open\n";
    }
}

void Points::init(GLint matrixUniform) {
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

void Points::draw() {
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glPointSize(m_pointSize);
    glDrawArrays(GL_POINTS, 0, mVertices.size());
}
