#ifndef JELLYFISH_H
#define JELLYFISH_H

#include "GL/glew.h"

#include "glData/vbo.h"

#include "glData/vao.h"

class jellyfish
{
public:
    jellyfish();
    ~jellyfish();
    void setVertexData(GLfloat *data, int size);
    void setAttribute(GLuint index, GLuint numberOfElement);
    void buildVAO();
    void draw();
private:
    GLfloat *m_data;
    GLsizeiptr m_size;
    int m_numberOfVertices;
    std::unique_ptr<VAO> m_VAO;
};

#endif // JELLYFISH_H
