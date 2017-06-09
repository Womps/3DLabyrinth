#version 330

// Données entrantes depuis le vertex shader
in vec2 textureCoordinate;

// Données uniform
uniform sampler2D diffuseTexture;
uniform vec3 diffuseColor;
uniform int useTexture;

layout(location = 0) out vec3 outColor;

void main(void)
{
	if(useTexture == 1)
		outColor = texture(diffuseTexture, textureCoordinate).rgb;

	else
		outColor = diffuseColor;
}
