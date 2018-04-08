#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    kh = new keyboardHandler();
    b = new Ball(0,0);
    p = new Paddle();
}

App::~App()
{
    delete kh;
    delete b;
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    


    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
        glBegin(GL_LINES);
    
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);
    
    glEnd();
    b->draw();
    p->draw();
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::idle()
{
    b->move();
    p->checkCollision(b);
    if(kh->getHold('a'))
        p->update('a');
    if(kh->getHold('d'))
        p->update('d');
    redraw();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
}

void App::mouseMove(float x, float y)
{
    mx = x;
    my = y;
}

void App::keyUp(unsigned char key)
{
    kh->keyUp(key);
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
    kh->keyDown(key);

}


