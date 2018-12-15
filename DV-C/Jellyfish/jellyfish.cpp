#include "jellyfish.h"

#include <iostream>
#include <fstream>

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
    return m_vertices.size()/3;
}

int jellyfish::getVertexSize(){
    return m_vertices.size();
}

void jellyfish::readOBJ(const char *path){
    std::vector<unsigned int> vertexIndices;
    FILE *file = std::fopen(path, "r");
    if (file == NULL){
        std::cerr<< "File not open"<< std::endl;
        return;
    }
    while(1){
        char lineHeader[1000];
        int res = std::fscanf(file, "%s", lineHeader);
        if(res == EOF){
            break;
        }
        if(std::strcmp(lineHeader, "v") == 0){
            glm::vec3 vertex;
            std::fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            //std::cout<< vertex.z<< std::endl;
            m_vert.push_back(vertex);
        }
        else if(std::strcmp(lineHeader, "f") == 0){
            unsigned int vert1, vert2, vert3;
            int matches = std::fscanf(file, "%d %d %d\n", &vert1, &vert2, &vert3);
            vertexIndices.push_back(vert3);
            vertexIndices.push_back(vert2);
            vertexIndices.push_back(vert1);

        }
        else {
            char commentBuffer[1000];
            std::fgets(commentBuffer, 1000, file);
        }
    }
    for(unsigned int i=0; i<vertexIndices.size(); i++){
        unsigned int vertexIndex = vertexIndices[i];
        glm::vec3 vertex = m_vert[vertexIndex-1];
        m_vertices.push_back(vertex.x);
        m_vertices.push_back(vertex.y);
        m_vertices.push_back(vertex.z);
    }
    std::fclose(file);
}

void jellyfish::initializeShape(){
    readOBJ("/Users/senademir/Desktop/Jellyfish/DV-C/DV-C/Jellyfish/esen.obj");
//    for(int i=0; i<m_vertices.size(); i++){
//        std::cout<<m_vertices[i]<<std::endl;
//    }
}
