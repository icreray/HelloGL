#version 450 core

in vec3 color;
out vec4 fragColor;

void main() {
    fragColor = vec4(color.rgb, 1.0);
}
