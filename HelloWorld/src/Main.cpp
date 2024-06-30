#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "shader.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
    // install git, cmake, g++
    // https://www.pragmaticlinux.com/2022/05/how-to-install-build-essential-on-fedora/ - dependencies
    // install this - sudo dnf install glew-devel SDL2-devel SDL2_image-devel glm-devel freetype-devel - https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Linux
    // https://stackoverflow.com/questions/17768008/how-to-build-install-glfw-3-and-use-it-in-a-linux-project/17772217#17772217 - install glfw with the flag shared libraries on

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err;
    err = glewInit();

    if(err != GLEW_OK){
        std::cout << "GLEW ERROR!" << std::endl;
        std::cout << glewGetErrorString(err) << std::endl; 
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);
    glEnableVertexAttribArray(0);

    GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        // glBegin(GL_TRIANGLES);
        // glVertex2f(-0.5f,-0.5f);
        // glVertex2f(0.0f,  0.5f);
        // glVertex2f(0.5f, -0.5f);       
        // glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
