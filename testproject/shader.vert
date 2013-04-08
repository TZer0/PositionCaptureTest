#version 330
in vec3 Position;
uniform mat4 projection_matrix;
uniform mat4 modelview_matrix;
out vec4 posOut;
void main(void) {
	gl_Position = projection_matrix * modelview_matrix * vec4(Position, 1.0);
}
