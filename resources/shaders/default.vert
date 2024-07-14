#version 450 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 ModelView;
uniform mat4 Projection;

out vec3 Normal;
out vec2 TexCoord;
out vec3 FragPosition;

void main() {
    gl_Position = Projection * ModelView * vec4(aPosition, 1.0);
    Normal = (Projection * ModelView * vec4(aNormal, 1.0)).xyz;
    TexCoord = aTexCoord;
    FragPosition = (ModelView * gl_Position).xyz;
}
