#pragma once

#include <glm\glm.hpp>
#include <glew\GL\glew.h>

#include "obj_loader.h"

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normals = glm::vec3(0, 0, 0))
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normals = normals;
	}

	inline glm::vec3* GetPos(){ return &pos; }
	inline glm::vec2* GetTexCoord(){ return &texCoord; }
	inline glm::vec3* GetNormal(){ return &normals; }
protected:
private:
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normals;
};

class Mesh
{
public:
	Mesh(Vertex * vertices, unsigned int numVertices, unsigned int * indices, unsigned int numIndices);
	Mesh(const std::string& fileName);

	void Draw();

	virtual ~Mesh();

protected:
private:

	void InitMesh(const IndexedModel& model);

	enum
	{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,

		INDEX_VB,

		NUM_BUFFERS
	};

	GLuint			m_vertexArrayObject;
	GLuint			m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int	m_drawCount;
};

