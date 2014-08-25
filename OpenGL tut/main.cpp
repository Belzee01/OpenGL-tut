#include <iostream>
#include <glew\GL\glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "Camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv)
{
	Display display(800, 600, "Hello World");
	Shader shader("./res/basicShader");
	Vertex vertices[] = {Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
						Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
						Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0))};
	
	unsigned int indices[] = { 0, 1, 2 };
	
	//Mesh mesh(vertices, sizeof(vertices)/ sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh mesh("./res/monkey3.obj");

	Texture texture("./res/bricks.jpg");
	Camera camera(glm::vec3(0, 0, -6), 70.0, (float)display.GetWidth()/(float)display.GetHeight(), 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.1f, 0.5f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinf(counter/10);
		transform.GetRot().y = counter * 10;

		shader.Bind();

		texture.BindTexture(0);
		shader.Update(transform, camera);
		mesh.Draw();

		display.Update();
		counter += 0.05f;
	}

	return 0;
}