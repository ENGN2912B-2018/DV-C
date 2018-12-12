#include "head.h"

head::head()
    :jellyfish()
{

}

head::~head(){

}

GLfloat* head::getVertexData(){
    return m_vertices.data();
}

int head::getVertexNumber(){
    return 243;
}

void head::initializeShape(){

    findVertices();
    addVertices();
}

void head::findVertices(){
    int count = 0;
    for(int i=0; i<NUM_VERTICES; i++){
        for(int j=0; j<NUM_VERTICES; j++){
            glm::vec3 vertices;
            GLfloat phi = M_PI/NUM_VERTICES;
            GLfloat theta = 2.0f*M_PI/NUM_VERTICES;
            vertices.y = 0.5f*glm::cos(j*phi);
            vertices.x = 0.5f*glm::sin(j*phi)*glm::cos(i*theta);
            vertices.z = 0.5f*glm::sin(j*phi)*glm::sin(i*theta);
            m_vertexMap[count] = vertices;
            count++;
        }
    }
}

void head::addVertices(){
    int skipCount = NUM_VERTICES;
    int endCount = m_vertexMap.size()-(NUM_VERTICES+2);
    for(int i=0; i<endCount; i++){
        if(i == skipCount){
            i++;
            skipCount += NUM_VERTICES+1;
        }
        m_vertices.push_back(m_vertexMap[i][0]);
        m_vertices.push_back(m_vertexMap[i][1]);
        m_vertices.push_back(m_vertexMap[i][2]);

        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+1][0]);
        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+1][1]);
        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+1][2]);

        m_vertices.push_back(m_vertexMap[i+1][0]);
        m_vertices.push_back(m_vertexMap[i+1][1]);
        m_vertices.push_back(m_vertexMap[i+1][2]);

        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+1][0]);
        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+1][1]);
        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+1][2]);

        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+2][0]);
        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+2][1]);
        m_vertices.push_back(m_vertexMap[i+NUM_VERTICES+2][2]);

        m_vertices.push_back(m_vertexMap[i+1][0]);
        m_vertices.push_back(m_vertexMap[i+1][1]);
        m_vertices.push_back(m_vertexMap[i+1][2]);

    }
}
