#pragma once

#include <string>
#include <glew\GL\glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);

	void BindTexture(unsigned int unit);

	virtual ~Texture();

protected:
private:
	GLuint m_texture;
};

