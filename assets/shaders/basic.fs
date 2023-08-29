#version 330 core

in vec2 uv;
out vec4 outColor;

uniform float aspect;
uniform vec2 mouse;
uniform float time;

void main()
{
	vec2 s = uv * vec2(1.0,aspect);
	outColor = vec4(uv.x,uv.y*aspect,0.0,0.0);
}