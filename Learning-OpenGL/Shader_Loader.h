#pragma once

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>

namespace Core
{
    class Shader_Loader
    {

        public:
            Shader_Loader(void);
            ~Shader_Loader(void);
            GLuint CreateProgram(char* vertexShaderFilename, char* fragmentShaderFilename);

        private:
            std::string ReadShader(char *filename);
            GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);

    };
}