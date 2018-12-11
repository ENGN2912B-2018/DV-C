#include "jellyfish.h"

#include <iostream>

jellyfish::jellyfish():
    m_size(0),
    m_numberOfVertices(0),
    m_VAO(nullptr),
    m_vertices()
{

}

jellyfish::~jellyfish(){

}

void jellyfish::setVertexData(GLfloat *data, int size, int numVertices){
    m_data = data;
    m_size = size;
    std::cout<< m_size<< std::endl;
    m_numberOfVertices = numVertices;
}

void jellyfish::setAttribute(GLuint index, GLuint numberOfElement){

}

void jellyfish::buildVAO(){
    VBO vbo = VBO(m_data, m_size);
    //VBO vbo(m_data, m_size);
    m_VAO = std::make_unique<VAO>(vbo, m_numberOfVertices);
}

void jellyfish::draw(){
    if(m_VAO != nullptr){
        m_VAO->bind();
        m_VAO->draw();
        m_VAO->unbind();
    }
}

GLfloat* jellyfish::getVertexData(){
    return m_vertices.data();
}

int jellyfish::getVertexNumber(){
    return 2*NUM_VERTICES*NUM_VERTICES*3;
}

int jellyfish::getVertexSize(){
    return m_vertices.size();
}
