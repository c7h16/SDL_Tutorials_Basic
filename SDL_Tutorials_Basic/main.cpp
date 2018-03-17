//
//  main.cpp
//  SDL_Tutorials_Basic
//
//  Created by Developer on 3/16/18.
//  Copyright © 2018 Developer. All rights reserved.
//

#include <iostream>

#include <SDL2/SDL.h>

//initialize the width and height for use elsewhere
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
        
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }
    
    SDL_Window *window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    
    //if window doesn't get completed
    if (NULL == window) {
        // send a message to the console and capture the error
        std::cout << "Could not Create Window" << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }
    
    SDL_Event windowEvent;
    
    //this loop runs until we exit the window.
    while (true) {
    
        //checks to see if there is an event, it the event equals quit the application breaks from this statement
        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT == windowEvent.type) {
                break;
            }
        }
    }
    
    //clean up windows
    SDL_DestroyWindow(window);
    
    //quit clean
    SDL_Quit();
    
    
    return EXIT_SUCCESS;
}
