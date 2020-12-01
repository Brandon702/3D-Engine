#version 430 core

in vec3 fs_color;
out vec4 out_color;

void main()
{
   out_color = vec4(fs_color, 1.0);
}