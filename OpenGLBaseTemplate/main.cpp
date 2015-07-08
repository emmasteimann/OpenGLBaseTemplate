//
//  main.cpp
//  OpenGLBaseTemplate
//
//  Created by Emma Steimann on 7/8/15.
//  Copyright (c) 2015 Emma Steimann. All rights reserved.
//

// GLEW
#include <cstdlib>
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


using std::cerr;
using std::endl;

//----------------------------------------------------------------------

static void errorCallback(int error, const char* description)
{
    cerr << description << endl;
    //fputs(description, stderr);
}

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    GLFWwindow* window;
    glfwSetErrorCallback(errorCallback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    
    // Create a GLFWwindow object that we can use for GLFW's functions
    window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL - Base", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    
    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);
    
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}