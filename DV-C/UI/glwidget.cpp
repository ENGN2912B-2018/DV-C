#include "glwidget.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

GLWidget::GLWidget(QGLFormat format, QWidget *parent) : QGLWidget(format, parent)
{

}

GLWidget::~GLWidget() {

}

void GLWidget::initializeGL() {

    initializeGlew();

    resizeGL(width(), height());

    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

    glClearColor(0.f, 0.5f, 0.5f, 0.f);

    m_program = createShaderProgram(":/shader/shader.vert", ":/shader/shader.frag");
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    m_jelly = std::make_unique<head>();
    m_jelly->initializeShape();
    m_jelly->setVertexData(m_jelly->getVertexData(), m_jelly->getVertexSize(), m_jelly->getVertexNumber());
    m_jelly->buildVAO();

    setCameraMatrices();

}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_program);

    glUniformMatrix4fv(glGetUniformLocation(m_program, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(m_model));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(glGetUniformLocation(m_program, "projMatrix"), 1, GL_FALSE, glm::value_ptr(m_projection));

    glm::vec4 color = glm::vec4(1.f, 1.f, 1.f, 1.f);
    glUniform4fv(glGetUniformLocation(m_program, "color"), 1, glm::value_ptr(color));

    m_jelly->draw();
    glUseProgram(0);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    setCameraMatrices();
}

void GLWidget::initializeGlew() {

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cerr<< "Error " << glewGetErrorString(err)<< std::endl;
    }

}

GLuint GLWidget::createShaderProgram(const char *vertFilePath, const char *fragFilePath) {
    GLuint vertShaderID = createShader(GL_VERTEX_SHADER, vertFilePath);
    GLuint fragShaderID = createShader(GL_FRAGMENT_SHADER, fragFilePath);
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertShaderID);
    glAttachShader(programID, fragShaderID);
    glLinkProgram(programID);
    int success;
    int info;

    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &info);
    if( info > 0){
        std::vector<char> infoLog(info);
        glGetProgramInfoLog(programID, info, NULL, &infoLog[0]);
        for(int i=0; i< info; i++){
            std::cout<< infoLog[i];
        }
        std::cout<<std::endl;
    }
    glDeleteShader(vertShaderID);
    glDeleteShader(fragShaderID);
    return programID;
}

GLuint GLWidget::createShader(GLenum shaderType, const char *filepath){
    GLuint shaderID = glCreateShader(shaderType);
    std::string shaderCode;
    QString filepathString = QString(filepath);
    QFile file(filepathString);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    shaderCode = stream.readAll().toStdString();
    const char *codePointer = shaderCode.c_str();
    glShaderSource(shaderID, 1, &codePointer, nullptr);
    glCompileShader(shaderID);
    GLint val = GL_FALSE;
    int info;
    //glGetShaderiv(shaderID, GL_COMPILE_STATUS, &val);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &info);
    if(info > 0){
        std::vector<char> infoLog(info);
        glGetShaderInfoLog(shaderID, info, NULL, &infoLog[0]);
        for(int i=0; i<info; i++){
            std::cout<< infoLog[i];
        }
        std::cout<<std::endl;
    }
    return shaderID;
}

void GLWidget::setCameraMatrices() {
    m_model = glm::mat4x4(1.f);
    m_view = glm::translate(glm::vec3(0, 6.f, -10.f)) * glm::rotate(0.5f, glm::vec3(1,0,0))*
            glm::rotate(0.f, glm::vec3(0,1,0));
    m_projection = glm::perspective(0.8f, static_cast<float>(width()/height()), 0.1f, 100.f);
    update();
}
