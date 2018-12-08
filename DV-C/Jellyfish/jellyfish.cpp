#include "jellyfish.h"

jellyfish::jellyfish():
    m_size(0),
    m_numberOfVertices(0),
    m_VAO(nullptr)
{

}

jellyfish::~jellyfish(){

}

void jellyfish::setVertexData(GLfloat *data, int size){
    m_data = data;
    m_size = size;
}

void jellyfish::setAttribute(GLuint index, GLuint numberOfElement){

}

void jellyfish::buildVAO(){
    VBO vbo = VBO(m_data, m_size);
    m_VAO = std::make_unique<VAO>(vbo, m_numberOfVertices);
}

void jellyfish::draw(){
    if(m_VAO != nullptr){
        m_VAO->bind();
        m_VAO->draw();
        m_VAO->unbind();
    }
}
