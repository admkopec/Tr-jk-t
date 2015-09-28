//
//  main.cpp
//  OpenGLModernTutorial
//
//  Created by Adam Kopeć on 9/8/15.
//  Copyright (c) 2015 Adam Kopec. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"

int main(int argc, const char * argv[]) {
    
    Display display(800, 600, "OpenGL");
    
    Shader shader("/Users/adamkopec/Documents/Projects/OpenGLModernTutorial/OpenGLModernTutorial/res/basicShader");
    //Texture texture("/Users/adamkopec/Documents/Projects/OpenGLModernTutorial/OpenGLModernTutorial/res/bricks.jpg");
    
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
                          Vertex(glm::vec3(0, 0.5, 0)),
                          Vertex(glm::vec3(0.5, -0.5, 0)) };
    
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    
    while (!display.IsClosed()) {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
        shader.Bind();
        //texture.Bind(0);
        mesh.Draw();
        
        display.Update();
    }
    
    return 0;
}
