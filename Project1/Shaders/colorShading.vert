#version 400

in vec2 vertexPosition;
in vec4 vertexColor;

out vec4 fragmentColor;
// flat out vec4 fragmentColor; will not interpolate the colours
out vec2 fragmentPosition;

void main(){
	gl_Position.xy = vertexPosition;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	
	fragmentPosition = vertexPosition;
	
	fragmentColor = vertexColor;
}