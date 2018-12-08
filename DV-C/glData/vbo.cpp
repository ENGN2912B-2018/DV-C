#include "vbo.h"

VBO::VBO(const float *data, int size):
    m_handle(-1),
    m_size(size)
{

}

VBO::VBO(VBO &&that) :
    m_handle(that.m_handle),
    m_size(that.m_size)
{
    that.m_handle = 0;
}

VBO& VBO::operator=(VBO &&that) {
    this->~VBO();
    m_handle = that.m_handle;
    m_size = that.m_size;
    that.m_handle = 0;
    return *this;
}

VBO::~VBO(){
    glDeleteBuffers(1, &m_handle);
}

void VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
}

void VBO::bindAndEnable() const {
    bind();

}

void VBO::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int VBO::sizeOfFloats() const {
}

int VBO::numberOfVertices() const {

}
