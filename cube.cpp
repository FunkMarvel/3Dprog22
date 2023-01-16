#include "cube.h"

Cube::Cube()
{
    // ABCD
    mVertices.push_back(Vertex{0.5,0.5,-0.5,1,1,1});
    mVertices.push_back(Vertex{0.5,-0.5,-0.5,1,1,1});
    mVertices.push_back(Vertex{-0.5,-0.5,-0.5,1,1,1});

    mVertices.push_back(Vertex{-0.5,-0.5,-0.5,1,1,1});
    mVertices.push_back(Vertex{-0.5,0.5,-0.5,1,1,1});
    mVertices.push_back(Vertex{0.5,0.5,-0.5,1,1,1});

    // CBFG
    mVertices.push_back(Vertex{0.5,-0.5,-0.5,0.5373,0.0706,0.0784});
    mVertices.push_back(Vertex{0.5,0.5,-0.5,0.5373,0.0706,0.0784});
    mVertices.push_back(Vertex{0.5,0.5,0.5,0.5373,0.0706,0.0784});

    mVertices.push_back(Vertex{0.5,-0.5,-0.5,0.5373,0.0706,0.0784});
    mVertices.push_back(Vertex{0.5,0.5,0.5,0.5373,0.0706,0.0784});
    mVertices.push_back(Vertex{0.5,-0.5,0.5,0.5373,0.0706,0.0784});

    // DCGH
    mVertices.push_back(Vertex{-0.5,0.5,-0.5,0.0510,0.2824,0.6745});
    mVertices.push_back(Vertex{0.5,0.5,-0.5,0.0510,0.2824,0.6745});
    mVertices.push_back(Vertex{0.5,0.5,0.5,0.0510,0.2824,0.6745});

    mVertices.push_back(Vertex{-0.5,0.5,-0.5,0.0510,0.2824,0.6745});
    mVertices.push_back(Vertex{0.5,0.5,0.5,0.0510,0.2824,0.6745});
    mVertices.push_back(Vertex{-0.5,0.5,0.5,0.0510,0.2824,0.6745});

    // DAHE
    mVertices.push_back(Vertex{-0.5,0.5,-0.5,1,0.3333,0.1451});
    mVertices.push_back(Vertex{-0.5,-0.5,-0.5,1,0.3333,0.1451});
    mVertices.push_back(Vertex{-0.5,-0.5,0.5,1,0.3333,0.1451});

    mVertices.push_back(Vertex{-0.5,0.5,-0.5,1,0.3333,0.1451});
    mVertices.push_back(Vertex{-0.5,-0.5,0.5,1,0.3333,0.1451});
    mVertices.push_back(Vertex{-0.5,0.5,0.5,1,0.3333,0.1451});

    // ABFE
    mVertices.push_back(Vertex{-0.5,-0.5,-0.5,0.0980,0.6078,0.2980});
    mVertices.push_back(Vertex{0.5,-0.5,-0.5,0.0980,0.6078,0.2980});
    mVertices.push_back(Vertex{0.5,-0.5,0.5,0.0980,0.6078,0.2980});

    mVertices.push_back(Vertex{-0.5,-0.5,-0.5,0.0980,0.6078,0.2980});
    mVertices.push_back(Vertex{0.5,-0.5,0.5,0.0980,0.6078,0.2980});
    mVertices.push_back(Vertex{-0.5,-0.5,0.5,0.0980,0.6078,0.2980});

    // EFGH
    mVertices.push_back(Vertex{-0.5,-0.5,0.5,0.9961,0.8353,0.1843});
    mVertices.push_back(Vertex{0.5,-0.5,0.5,0.9961,0.8353,0.1843});
    mVertices.push_back(Vertex{0.5,0.5,0.5,0.9961,0.8353,0.1843});

    mVertices.push_back(Vertex{-0.5,-0.5,0.5,0.9961,0.8353,0.1843});
    mVertices.push_back(Vertex{0.5,0.5,0.5,0.9961,0.8353,0.1843});
    mVertices.push_back(Vertex{-0.5,0.5,0.5,0.9961,0.8353,0.1843});

    mMatrix.setToIdentity();
}

void Cube::init(GLint matrixUniform)
{
    mMatrixUniform = matrixUniform;

    initializeOpenGLFunctions();

    //Vertex Array Object - VAO
    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

    // 1rst attribute buffer : vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof( Vertex ),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    //enable the matrixUniform
    // mMatrixUniform = glGetUniformLocation( matrixUniform, "matrix" );

    glBindVertexArray(0);
}

void Cube::draw()
{
    glBindVertexArray( mVAO );
    glUniformMatrix4fv( mMatrixUniform, 1, GL_FALSE, mMatrix.constData());
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
}

void Cube::rotate(QMatrix4x4 matrix)
{
    mMatrix = matrix;
}
