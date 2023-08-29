#version 330 core

in vec2 uv;
out vec4 outColor;

uniform float aspect;
uniform vec2 mouse;
uniform float time;

vec2 compMult(vec2 a,vec2 b){
	return vec2(a.x*b.x - a.y*b.y,a.x*b.y + a.y*b.x);
}

void main()
{
	vec2 s = 2.0*(uv) - 1.0;
	float amp = 2.0;
	s*=amp * (1.1 + sin(time));

	int numIters = 50;
	vec2 z = vec2(0);

	for(int i = 0;i< numIters;i++){
		z  = compMult(z,z) + s;
	}

	float n2 = dot(z,z);
	vec3 col = vec3(0);
	if(n2 < 0.01){
		col = vec3(1,0,0);
	}else if(n2 > 0.01){
		col = vec3(0,1,0);
	}
	col = smoothstep(n2,0.01,.010)*vec3(n2,0.0,1.0);

	outColor = vec4(col,0.0);
}