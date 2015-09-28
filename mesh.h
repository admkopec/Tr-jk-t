//
//  mesh.h
//  OpenGLModernTutorial
//
//  Created by Adam Kopeć on 9/15/15.
//  Copyright (c) 2015 Adam Kopec. All rights reserved.
//
#pragma once
#ifndef __OpenGLModernTutorial__mesh__
#define __OpenGLModernTutorial__mesh__

#include <stdio.h>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
    Vertex(const glm::vec3& pos) {
        this->pos = pos;
    }
private:
    glm::vec3 pos;
};

class Mesh
{
public:
    Mesh(Vertex* vertices, unsigned int numVertices);
    virtual ~Mesh();
    
    void Draw();
    
private:
    Mesh(const Mesh& other){}
    void operator=(const Mesh& other){}
    
    enum
    {
        POSITION_VB,
        
        NUM_BUFFERS
    };
    
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif /* defined(__OpenGLModernTutorial__mesh__) */
