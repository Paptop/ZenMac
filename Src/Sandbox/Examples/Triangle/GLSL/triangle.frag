#version 330 core

out vec4 color;
uniform vec3 zColor;

void main()
{
    color = vec4(zColor, 1.0f);
}
