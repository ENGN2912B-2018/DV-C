#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "GL/glew.h"
#include <QGLWidget>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGlew();
    GLuint createShaderProgram(const char *vertFilePath, const char *fragFilePath);
    GLuint createShader(GLenum shaderType, const char *filepath);
    void setCameraMatrices();

private:
    GLuint m_program;
    glm::mat4x4 m_model;
    glm::mat4x4 m_view;
    glm::mat4x4 m_projection;
};

#endif // GLWIDGET_H
