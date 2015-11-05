#version 150 core

void main(void)
{
	const vec4 triangles[6] = vec4[6](vec4(-0.25, 0.25, 0.5, 1.0), vec4( 0.25, 0.25, 0.5, 1.0), vec4( 0.00, 0.00, 0.5, 1.0));
	gl_Position = triangles[gl_VertexID];
}