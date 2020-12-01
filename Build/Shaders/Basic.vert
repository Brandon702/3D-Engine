#version 430 core

layout (location = 0) in vec3 vs_position;
//layout (location = 1) in vec3 vs_color;
layout (location = 1) in vec2 vs_uv;

//out vec3 fs_color;
out vec2 fs_uv;

uniform mat4 transform;

void main()
{
	//fs_color = vs_color;
	fs_uv = vs_uv;
    gl_Position = transform * vec4(vs_position.x, vs_position.y, vs_position.z, 1.0);
}