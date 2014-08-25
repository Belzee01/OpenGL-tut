#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <glew\GL\glew.h>

#include "transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);

	void Bind();
	void Update(const Transform& transform, const Camera& camera);

	virtual ~Shader();

protected:

private:
	static std::string LoadShader(const std::string& fileName);
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	static GLuint CreateShader(const std::string& text, GLenum shaderType);

private:
	static const unsigned int NUM_SHADER = 2;

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADER];
	GLuint m_uniforms[NUM_UNIFORMS];
};

