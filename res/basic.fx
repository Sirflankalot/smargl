#version 150 core
out vec4 outColor;
uniform float a;
void main() {
   outColor = a * vec4(1.0, 0.0, 0.0, 1.0);
}