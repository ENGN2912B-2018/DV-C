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
uniform vec3 center;

out vec4 fragC;
out vec4 worldNormal;

void main(void)
{
    float dist= abs(distance(position.xz, center.xz));
    float currTime = time+position.y;
    float offset = smoothstep(0.0, 1.0, max(0.f, -position.y-0.8f)/5.f);
    vec3 animate = (vec3(position.x, 10.f-position.y, position.z)/70.f*sin(currTime)) * (1.f-offset);
    vec3 pos = position;
    float xTime = time+dist;
    pos.x += pos.x/10.f*sin(xTime);
    pos.z += pos.z/10.f*sin(xTime);
    pos = pos*weight.x + pos*weight.y + pos*weight.z + pos*weight.w;
    //find the center coordinates and calculate the distance and currTime according to that distance
    pos.y += 0.5*time;
    worldNormal = projMatrix * viewMatrix * modelMatrix * vec4(normal, 0.0);
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(pos, 1.0);
    fragC = color;
}
