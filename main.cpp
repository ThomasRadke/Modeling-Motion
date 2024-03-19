#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include"VertexArrayObject.h"
#include"VertexBufferObject.h"
#include"ShaderClass.h"
#include"ElementsBufferObject.h"


int main(void)
{
    GLFWwindow* window;

    GLfloat vertices[] = {
        -0.5,-0.5,0,
        -0.5,0.5,0,
        0.5,0.5,0,
        0.5,-0.5,0
    };

    GLuint indices[] = {
        0,1,2,
        1,2,3
    };

    

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    Shader program("vsource.glsl","fsource.glsl");

    VertexArrayObject VAO1;
    VAO1.Bind();

    ElementsBufferObject EBO1(indices,sizeof(indices));

    VertexBufferObject VBO1(vertices, sizeof(vertices));

    VAO1.Link(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.Link(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.Link(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 1.0f, 0.8f, 0.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        program.Activate();

        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    program.Delete();

    glfwTerminate();
    return 0;
}