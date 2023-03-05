#include "cube.h"

Cube::Cube() {

    //Furthest Back of building in Z
    mVertices.push_back(Vertex{10.0, 5.0, 10.0, 0, 0, 1});
    mVertices.push_back(Vertex{10.0, -5.0, 10.0, 0, 1, 0});
    mVertices.push_back(Vertex{-10.0, -5.0, 10.0, 1, 0, 0});
     mVertices.push_back(Vertex{10.0, 5.0, 10.0, 0, 0, 1});
     mVertices.push_back(Vertex{-10.0, -5.0, 10.0, 0, 1, 0});
     mVertices.push_back(Vertex{-10.0, 5.0, 10.0, 1, 0, 0});

    //Left wall of the building
    mVertices.push_back(Vertex{-10.0, -5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{-10.0, -5.0, 10.0, 0, 1, 0});
    mVertices.push_back(Vertex{-10.0, 5.0, 10.0, 0, 0, 1});
    mVertices.push_back(Vertex{-10.0, -5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{-10.0, 5.0, 10.0, 0, 1, 0});
    mVertices.push_back(Vertex{-10.0, 5.0, -5.0, 0, 0, 1});
    //Floor if needed
    mVertices.push_back(Vertex{10.0, -4.9, 10.0, 1, 0, 0});
    mVertices.push_back(Vertex{-10.0, -4.9, -5.0, 0, 1, 0});
    mVertices.push_back(Vertex{10.0, -4.9, -5.0, 0, 0, 1});
    mVertices.push_back(Vertex{10.0, -4.9, 10.0, 0, 0, 1});
    mVertices.push_back(Vertex{-10.0, -4.9, 10.0, 0, 1, 0});
    mVertices.push_back(Vertex{-10.0, -4.9, -5.0, 1, 0, 0});

    //Right side of the house
    mVertices.push_back(Vertex{10.0, 5.0, 10.0, 0, 0, 1});
    mVertices.push_back(Vertex{10.0, -5.0, -5.0, 0, 1, 0});
    mVertices.push_back(Vertex{10.0, 5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{10.0, -5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{10.0, 5.0, 10.0, 0, 1, 0});
    mVertices.push_back(Vertex{10.0, -5.0, 10.0, 0, 0, 1});

        // Roof/top plane
    mVertices.push_back(Vertex{10.0, 5.0, 10.0, 0, 0, 1});
    mVertices.push_back(Vertex{10.0, 5.0, -5.0, 0, 1, 0});
    mVertices.push_back(Vertex{-10.0, 5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{10.0, 5.0, 10.0, 1, 0, 0});
    mVertices.push_back(Vertex{-10.0, 5.0, -5.0, 0, 1, 0});
    mVertices.push_back(Vertex{-10.0, 5.0, 10.0, 0, 0, 1});

    //Left of door, front
    mVertices.push_back(Vertex{-10.0, 5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{-10.0, -5.0, -5.0, 0, 1, 0});
    mVertices.push_back(Vertex{-1.2, -5.0, -5.0, 0, 0, 1});
    mVertices.push_back(Vertex{-10.0, 5.0, -5.0, 1, 0, 0});
    mVertices.push_back(Vertex{-1.2, 5.0, -5.0, 0, 1, 0});
    mVertices.push_back(Vertex{-1.2, -5.0, -5.0, 0, 0, 1});


    //Right of door , front
   mVertices.push_back(Vertex{10.0, 5.0, -5.0, 0, 0, 1});
   mVertices.push_back(Vertex{10.0, -5.0, -5.0, 0, 1, 0});
   mVertices.push_back(Vertex{1.2, -5.0, -5.0, 1, 0, 0});
   mVertices.push_back(Vertex{10.0, 5.0, -5.0, 0, 0, 1});
   mVertices.push_back(Vertex{1.2, 5.0, -5.0, 0, 1, 0});
   mVertices.push_back(Vertex{1.2, -5.0, -5.0, 1, 0, 0});


   //Above door , front
   mVertices.push_back(Vertex{-1.2, 5.0, -5.0, 0, 0, 1});
   mVertices.push_back(Vertex{-1.2, 0.1, -5.0, 0, 1, 0});
   mVertices.push_back(Vertex{1.2, 5.0, -5.0, 1, 0, 0});
   mVertices.push_back(Vertex{-1.2, 0.1, -5.0, 0, 0, 1});
   mVertices.push_back(Vertex{1.2, 0.1,-5.0, 0, 1, 0});
   mVertices.push_back(Vertex{1.2, 5.0, -5.0, 1, 0, 0});



    mMatrix.setToIdentity();
}

void Cube::init(GLint matrixUniform) {
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

void Cube::draw() {
    glBindVertexArray(mVAO);
    glUniformMatrix4fv(mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void Cube::rotate(QMatrix4x4 matrix) {
    mMatrix = matrix;
}

bool Cube::ContainsPoint(QVector3D Point)
{
   return (Point.x() <= 10 && Point.x() >= -10 &&
    Point.y() <= 10 && Point.y() >= -0 &&
    Point.z() <= 30 && Point.z() >= 15);
}


