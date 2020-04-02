#version 330 core

in vec3 colorlerp;
out vec4 color;

vec2 resolution = vec2(800, 600);

void main()
{
    vec2 norm = gl_FragCoord.xy / resolution;
    color = vec4(norm, 0.0, 1.0);
}
