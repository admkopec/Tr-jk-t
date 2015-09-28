//
//  texture.h
//  OpenGLModernTutorial
//
//  Created by Adam Kopeć on 9/16/15.
//  Copyright (c) 2015 Adam Kopeć. All rights reserved.
//

#ifndef __OpenGLModernTutorial__texture__
#define __OpenGLModernTutorial__texture__

#include <stdio.h>
#include <string>
#include <GL/glew.h>

class Texture {
public:
    Texture(const std::string& fileName);
    virtual ~Texture();
    
    void Bind(unsigned int unit);
    
private:
    Texture(const Texture& other) {}
    void operator=(const Texture& other) {}
    
    GLuint m_texture;
};

#endif /* defined(__OpenGLModernTutorial__texture__) */
