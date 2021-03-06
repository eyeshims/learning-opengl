#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>

#include "Shader_Loader.h"
#include "GameModels.h"

using namespace Core;

Models::GameModels *gameModels;
GLuint program;

void renderScene(void)
{
    // Clear OpenGL's color and depth buffers.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the color buffer to dark turquoise.
    glClearColor(0.0, 0.3, 0.3, 1.0);

    glBindVertexArray(gameModels->GetModel("triangle1"));

    // Use the created program.
    glUseProgram(program);

    // Draw 3 vertices as triangles.
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Move the back buffer to the front.
    glutSwapBuffers();
}

void closeCallback()
{
    std::cout << "GLUT:\t Finished" << std::endl;
    glutLeaveMainLoop();
}

void Init()
{
    glEnable(GL_DEPTH_TEST);

    gameModels = new Models::GameModels();
    gameModels->CreateTriangleModel("triangle1");

    // Load and compile shaders.
    Core::Shader_Loader shaderLoader;
    program = shaderLoader.CreateProgram(
        "Vertex_Shader.glsl",
        "Fragment_Shader.glsl"
    );

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    // Create window to render in.
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL 3.1");
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

    glewInit();

    // Check which if OpenGL version 3.1 is supported on this machine.
    if (glewIsSupported("GL_VERSION_3_1")) {
        std::cout << "GLEW Version is 3.1\n";
    }
    else {
        std::cout << "Glew 3.1 not supported\n";
    }

    Init();

    // Register a callback that renders the scene.
    glutDisplayFunc(renderScene);
    glutCloseFunc(closeCallback);
    
    glutMainLoop();

    delete gameModels;
    glDeleteProgram(program);

    return 0;
}