#ifndef HEAD_H
#define HEAD_H

#include "jellyfish.h"

class head : public jellyfish
{
public:
    head();
    virtual ~head();
    GLfloat* getVertexData();
    void initializeShape();
    int getVertexNumber();
    void findVertices();
    void addVertices();
};

#endif // HEAD_H
