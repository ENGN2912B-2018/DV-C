#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec4 weight;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
uniform vec4 color;
uniform float pi;
uniform float time;

out vec4 fragC;
out vec4 worldNormal;

void main(void)
{
    float currTime = mod(time+position.y, 6.f*pi);
    float offset = smoothstep(0.0, 1.0, max(0.f, -position.y-0.8f)/10.f);
    vec3 animate = (vec3(position.x, position.y, position.z)/8.f*sin(currTime)) * (1.f-offset);
    //vec3 animate = (vec3(normal.x, normal.y, normal.z)/8.f*sin(currTime)) * (1.f-offset);
    vec3 pos = position + animate;
    pos = pos*weight.x + pos*weight.y + pos*weight.z + pos*weight.w;
    worldNormal = projMatrix * viewMatrix * modelMatrix * vec4(normal, 0.0);
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(pos, 1.0);
    fragC = color;
}
