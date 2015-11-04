#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>

void renderScene(void)
{
    // Clear OpenGL's color and depth buffers.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the color buffer to red.
    glClearColor(1.0, 0.0, 0.0, 1.0);

    // Move the back buffer to the front.
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    // Create window to render in.
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL First Windw");

    glEnable(GL_DEPTH_TEST);

    // Register a callback that renders the scene.
    // In this case it turns the scene red.
    glutDisplayFunc(renderScene);

    glutMainLoop();

    return 0;
}