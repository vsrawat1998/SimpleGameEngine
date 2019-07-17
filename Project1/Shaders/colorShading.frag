#version 400

in vec4 fragmentColor;
in vec2 fragmentPosition;
// flat in vec4 fragmentColor; will not interpolate the colours

out vec4 color;

// Global variable for the entire mesh
uniform float time;

void main(){
	
	color = vec4(fragmentColor.r*(cos(fragmentPosition.x*4.0 + time) +1.0)*0.5,
				fragmentColor.g*(cos(fragmentPosition.y*8.0 + time) +1.0)*0.5,
				fragmentColor.b*(cos(fragmentPosition.x*2.0 + time) +1.0)*0.5,
				1.0);
}