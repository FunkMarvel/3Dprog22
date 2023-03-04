#include "door.h"

Door::Door()
{

   //DOOOR
   mVertices.push_back(Vertex{-1.2, 0.1, -5.0, 0.4, 0.2, 0.1});
   mVertices.push_back(Vertex{-1.2, -5.0, -5.0,0.4, 0.2, 0.1});
   mVertices.push_back(Vertex{1.2, 0.1, -5.0,0.4, 0.2, 0.1});
   mVertices.push_back(Vertex{-1.2, -5.0, -5.0,0.4, 0.2, 0.1});
   mVertices.push_back(Vertex{1.2, -5.0, -5.0, 0.4, 0.2, 0.1});
   mVertices.push_back(Vertex{1.2, 0.1, -5.0,0.4, 0.2, 0.1});

    mMatrix.setToIdentity();
}
void Door::init(GLint matrixUniform) {
    mMatrixUniform = matrixUniform;

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

void Door::draw() {
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void Door::rotate(QMatrix4x4 matrix) {
    mMatrix = matrix;
}

/*
void Door::onOverlap(const QVector3D& hitPos)
{

  qDebug() << "Overlap with door";

   //mVertices.push_back(Vertex{-1.2, 0.1, -5.0, 0.4, 0.2, 0.1});
   //mVertices.push_back(Vertex{-1.2, -5.0, -5.0,0.4, 0.2, 0.1});
   //mVertices.push_back(Vertex{1.2, 0.1, -5.0,0.4, 0.2, 0.1});
   //mVertices.push_back(Vertex{-1.2, -5.0, -5.0,0.4, 0.2, 0.1});
   //mVertices.push_back(Vertex{1.2, -5.0, -5.0, 0.4, 0.2, 0.1});
   //mVertices.push_back(Vertex{1.2, 0.1, -5.0,0.4, 0.2, 0.1});
}
*/
