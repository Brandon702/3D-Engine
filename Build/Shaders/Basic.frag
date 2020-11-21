#version 430 core

in vec3 fs_color;
in vec2 fs_uv;

out vec4 out_color;

uniform sampler2D baseTexture;

void main()
{
   out_color = texture(baseTexture, fs_uv);
}