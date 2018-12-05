#include "glwidget.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

GLWidget::~GLWidget() {

}

void GLWidget::initializeGL() {
    initializeGlew();
    resizeGL(width(), height());

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(0.09f, 0.6f, 0.8f, 0.0f);

    m_program = createShaderProgram(":/shaders/shader.vert", ":/shaders/shader.frag");
    setCameraMatrices();
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_program);

    glUniformMatrix4fv(glGetUniformLocation(m_program, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(m_model));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "projMatrix"), 1, GL_FALSE, glm::value_ptr(m_projection));

    glUseProgram(0);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    setCameraMatrices();
}

void GLWidget::initializeGlew() {
    glewExperimental = GL_TRUE;
    GLenum error = glewInit();
    if (GLEW_OK != error) {
        std::cerr<< "Error " << glewGetErrorString(error)<< std::endl;
    }
}

GLuint GLWidget::createShaderProgram(const char *vertFilePath, const char *fragFilePath) {
    GLuint vertShaderID = createShader(GL_VERTEX_SHADER, vertFilePath);
    GLuint fragShaderID = createShader(GL_FRAGMENT_SHADER, fragFilePath);
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertShaderID);
    glAttachShader(programID, fragShaderID);
    glLinkProgram(programID);
    glDeleteShader(vertShaderID);
    glDeleteShader(fragShaderID);
    return programID;
}

GLuint GLWidget::createShader(GLenum shaderType, const char *filepath){
    GLuint shaderID = glCreateShader(shaderType);
    std::string shaderCode;
    QString filepathString = QString(filepath);
    QFile file(filepathString);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    shaderCode = stream.readAll().toStdString();
    const char *codePointer = shaderCode.c_str();
    glShaderSource(shaderID, 1, &codePointer, nullptr);
    glCompileShader(shaderID);
    return shaderID;
}

void GLWidget::setCameraMatrices() {
    m_model = glm::mat4x4(1.f);
    update();
}
