#version 400 core

layout(location = 0) in vec3 position;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
uniform vec4 color;

out vec4 fragC;

void main(void)
{
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);
    //gl_Position = vec4(position, 1.0);
    fragC = color;
}
