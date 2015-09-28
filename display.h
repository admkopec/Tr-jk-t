//
//  display.h
//  OpenGLModernTutorial
//
//  Created by Adam Kopeć on 9/8/15.
//  Copyright (c) 2015 Adam Kopec. All rights reserved.
//
#pragma once
#ifndef __OpenGLModernTutorial__display__
#define __OpenGLModernTutorial__display__

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

class Display{
public:
    Display(int width, int height, const std::string& title);
    virtual ~Display();
    
    void Clear(float r, float g, float b, float a);
    void Update();
    
    bool IsClosed();
    
protected:
private:
    Display(const Display& other) {}
    void operator=(const Display& other) {}
    
    SDL_Window* m_window;
    SDL_GLContext m_glcontext;
    bool m_isClosed;
};

#endif /* defined(__OpenGLModernTutorial__display__) */
