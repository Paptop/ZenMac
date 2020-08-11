#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 mvp;

out vec3 colorlerp;

void main()
{
    gl_Position = mvp * vec4(aPos, 1.0);
    colorlerp = clamp(aPos, 0.0, 1.0);
}
