#include "TitleScreenState.h"

void TitleScreenState::update(){
    count++;

    // To prevent overflow, reset count after 2pi * divisor
    if (count > 2*PI*divisor){
        count = 0;
    }

    startButton->update();
    quitButton->update();
}

void TitleScreenState::draw(){
    logo.draw(
        ofGetWidth()/2 - logo.getWidth()/2, 
        ofGetHeight()/4 - logo.getHeight()/2 + amplitude*sin(1.0*count/divisor)
    );

    startButton->draw();
    quitButton->draw();
}

void TitleScreenState::reset(){

    State::reset();

    count = 0;
    amplitude = 10;
    divisor = 50;

    startButton = new Button(
        ofGetWidth()/2, 
        ofGetHeight()/2 + 100, 
        200, 
        100, 
        "Start"
    );

    quitButton = new Button(
        ofGetWidth()/2, 
        ofGetHeight()/2 + 250, 
        200, 
        100, 
        "Quit"
    );

}

void TitleScreenState::mousePressed(int x, int y, int button){

    if (button != 0){ // Only respond to left clicks
        return;
    }
    startButton->mousePressed(x, y);
    quitButton->mousePressed(x, y);

    if (startButton->wasPressed()){
        setFinished(true);
        setNextState(MAZE_SELECTION);
    }

    if (quitButton->wasPressed()){
        setFinished(true);
        setNextState(UNKNOWN);
    }
}