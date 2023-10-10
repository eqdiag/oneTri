#version 330 core

in vec2 uv;
out vec4 outColor;

uniform float aspect;
uniform vec2 mouse;
uniform float time;

void main()
{
	float c = 0.5*(sin(time*4.0)+1.0);
	outColor = vec4(vec3(c),1.0);
}