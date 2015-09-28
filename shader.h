//
//  shader.h
//  OpenGLModernTutorial
//
//  Created by Adam Kopeć on 9/9/15.
//  Copyright (c) 2015 Adam Kopec. All rights reserved.
//

#ifndef __OpenGLModernTutorial__shader__
#define __OpenGLModernTutorial__shader__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <GL/glew.h>

class Shader{
public:
    Shader(const std::string& fileName);
    virtual ~Shader();
    
    void Bind();
    GLuint m_program;
private:
    static const unsigned int NUM_SHADERS = 2;
    
    GLuint m_shaders[NUM_SHADERS];
    
    static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    static std::string LoadShader(const std::string& fileName);
    static GLuint CreateShader(const std::string& text, GLenum shaderType);
};

#endif /* defined(__OpenGLModernTutorial__shader__) */
