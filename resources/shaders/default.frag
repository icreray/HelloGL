#version 450 core

in vec2 texCoord;
out vec4 fragColor;

uniform sampler2D ourTexture;

void main() {
    fragColor = texture(ourTexture, texCoord);
}
