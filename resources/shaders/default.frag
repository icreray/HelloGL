#version 450 core

in vec3 Normal;
in vec2 TexCoord;
in vec3 FragPosition;

out vec4 FragColor;

uniform sampler2D Texture;

void main() {
    vec3 lightPos = vec3(0, 1, -10);
    vec3 lightDirection = normalize(lightPos - FragPosition);
    float diff = max(dot(Normal, lightDirection), 0.0);
    FragColor = texture(Texture, TexCoord) * diff;
}
