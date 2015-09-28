//
//  display.cpp
//  OpenGLModernTutorial
//
//  Created by Adam Kopeć on 9/8/15.
//  Copyright (c) 2015 Adam Kopec. All rights reserved.
//

#include "display.h"
#include <GL/glew.h>

Display::Display(int width, int height, const std::string& title){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glcontext = SDL_GL_CreateContext(m_window);
    glewExperimental= GL_TRUE;
    
    GLenum status = glewInit();
    if (status != GLEW_OK) {
        std::cerr<<"GLEW failed to initilize!"<<std::endl;
    }
    
    printf("Open GL version: %s", glGetString(GL_VERSION));
    
    m_isClosed=false;
}

Display::~Display(){
    SDL_GL_DeleteContext(m_glcontext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed(){
    return m_isClosed;
}

void Display::Update(){
    SDL_GL_SwapWindow(m_window);
    
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            m_isClosed=true;
        }
    }
}