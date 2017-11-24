#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "error";

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[6] = {	//these are the vertices of the triangle to be created 
		-0.5f, -0.5f,
		-0.5f,  0.5f,
		 0.5f, -0.5f
	};	

	unsigned int buffer;		// the buffer for storing the buffer names 
	
	glGenBuffers(1, &buffer);	// generates 10 buffer object names and stores them to the buffer array

	glBindBuffer(GL_ARRAY_BUFFER, buffer);	//bindes all the buffer names with	Vertex attributes
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	//index, number of entities in a single vertex, type of the entiey, normalized (true, false), size of a vertex, offset of the entiy from the vertext 
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);	//appends the data once and also used once (STATIC)

	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)* 2, 0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);	


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}